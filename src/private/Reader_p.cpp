// SPDX-FileCopyrightText: 2008, 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "Reader_p.h"

#include "AbstractRtfOutput.h"
#include "private/AuthorPcdataDestination_p.h"
#include "private/CategoryPcdataDestination_p.h"
#include "private/ColorTableDestination_p.h"
#include "private/CommentPcdataDestination_p.h"
#include "private/CompanyPcdataDestination_p.h"
#include "private/ControlWord_p.h"
#include "private/DocumentCommentPcdataDestination_p.h"
#include "private/DocumentDestination_p.h"
#include "private/FontTableDestination_p.h"
#include "private/GeneratorPcdataDestination_p.h"
#include "private/HLinkBasePcdataDestination_p.h"
#include "private/IgnoredDestination_p.h"
#include "private/InfoCreatedTimeDestination_p.h"
#include "private/InfoDestination_p.h"
#include "private/InfoPrintedTimeDestination_p.h"
#include "private/InfoRevisedTimeDestination_p.h"
#include "private/KeywordsPcdataDestination_p.h"
#include "private/ManagerPcdataDestination_p.h"
#include "private/OperatorPcdataDestination_p.h"
#include "private/PictDestination_p.h"
#include "private/RtfGroupState_p.h"
#include "private/StyleSheetDestination_p.h"
#include "private/SubjectPcdataDestination_p.h"
#include "private/TitlePcdataDestination_p.h"
#include "private/Tokenizer_p.h"
#include "private/UserPropsDestination_p.h"

#include <QStack>
#include <QTextCursor>
#include <QUrl>

#include "qrtfreader_debug.h"

namespace QRtfReader
{
ReaderPrivate::ReaderPrivate() = default;

ReaderPrivate::~ReaderPrivate()
{
    close();

    // Clean up any remaining objects
    qDeleteAll(m_destinationStack);
}

bool ReaderPrivate::open(const QString &filename)
{
    m_inputDevice = new QFile(filename);

    bool result = m_inputDevice->open(QIODevice::ReadOnly);

    return result;
}

void ReaderPrivate::close()
{
    if (!m_inputDevice)
        return;
    m_inputDevice->close();
    delete m_inputDevice;
    m_inputDevice = nullptr;
}

QString ReaderPrivate::fileName() const
{
    if (m_inputDevice && m_inputDevice->exists()) {
        return m_inputDevice->fileName();
    } else {
        return QString();
    }
}

bool ReaderPrivate::parseTo(AbstractRtfOutput *output)
{
    if ((!m_inputDevice) || (!m_inputDevice->isOpen())) {
        return false;
    }

    m_output = output;

    parseFile();

    return true;
}

void ReaderPrivate::parseFile()
{
    Tokenizer tokenizer(m_inputDevice);

    if (parseFileHeader(tokenizer)) {
        parseDocument(tokenizer);
    }
}

bool ReaderPrivate::parseFileHeader(Tokenizer &tokenizer)
{
    bool result = true;

    Token token = tokenizer.fetchToken();
    if (token.type != OpenGroup) {
        qCDebug(lcRtf) << "Not an RTF file";
        result = false;
    }

    token = tokenizer.fetchToken();
    if (token.type != Control) {
        qCDebug(lcRtf) << "Not an RTF file - wrong document type";
        result = false;
    }

    if (!headerFormatIsKnown(QString::fromUtf8(token.name), token.parameter.toInt())) {
        qCDebug(lcRtf) << "Not a valid RTF file - unknown header";
        result = false;
    }

    return result;
}

bool ReaderPrivate::headerFormatIsKnown(const QString &tokenName, int tokenValue)
{
    if (tokenName != QLatin1String("rtf")) {
        qCDebug(lcRtf) << "unknown / unexpected header token name:" << tokenName;
        return false;
    }

    if (tokenValue != 1) {
        qCDebug(lcRtf) << "unknown / unexpected header token value:" << tokenValue;
        return false;
    }

    return true;
}

Destination *ReaderPrivate::makeDestination(const QString &destinationName)
{
    if (destinationName == QLatin1String("colortbl")) {
        return new ColorTableDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("creatim")) {
        return new InfoCreatedTimeDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("printim")) {
        return new InfoPrintedTimeDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("revtim")) {
        return new InfoRevisedTimeDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("author")) {
        return new AuthorPcdataDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("company")) {
        return new CompanyPcdataDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("operator")) {
        return new OperatorPcdataDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("comment")) {
        return new CommentPcdataDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("doccomm")) {
        return new DocumentCommentPcdataDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("title")) {
        return new TitlePcdataDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("subject")) {
        return new SubjectPcdataDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("manager")) {
        return new ManagerPcdataDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("category")) {
        return new CategoryPcdataDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("keywords")) {
        return new KeywordsPcdataDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("hlinkbase")) {
        return new HLinkBasePcdataDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("generator")) {
        return new GeneratorPcdataDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("pict")) {
        return new PictDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("fonttbl")) {
        return new FontTableDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("stylesheet")) {
        return new StyleSheetDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("rtf")) {
        return new DocumentDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("info")) {
        return new InfoDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("userprops")) {
        return new UserPropsDestination(m_output, destinationName);
    } else if (destinationName == QLatin1String("ignorable")) {
        return new IgnoredDestination(m_output, destinationName);
    }
    qCDebug(lcRtf) << "creating plain old Destination for" << destinationName;
    return new Destination(m_output, destinationName);
}

void ReaderPrivate::changeDestination(const QString &destinationName)
{
    if (m_destinationStack.top()->name() == QLatin1StringView("ignorable")) {
        // we don't change destinations inside ignored groups
        return;
    }
    // qCDebug(lcRtf) << m_debugIndent << "about to change destination to: " << destinationName;

    Destination *dest = makeDestination(destinationName);

    m_destinationStack.push(dest);
    m_stateStack.top().didChangeDestination = true;
    QStringList destStackElementNames;
    for (int i = 0; i < m_destinationStack.size(); ++i) {
        destStackElementNames << m_destinationStack.at(i)->name();
    }
    qCDebug(lcRtf) << m_debugIndent << "destinationStack after changeDestination (" << destStackElementNames << ")";
}

void ReaderPrivate::parseDocument(Tokenizer &tokenizer)
{
    RtfGroupState state;

    // Push an end-of-file marker onto the stack
    state.endOfFile = true;
    m_stateStack.push(state);

    // Set up the outer part of the destination stack
    Destination *dest = makeDestination(QStringLiteral("rtf"));
    m_destinationStack.push(dest);
    m_stateStack.top().didChangeDestination = true;

    m_debugIndent = QLatin1Char('\t');
    // Parse RTF document
    bool atEndOfFile = false;
    bool nextSymbolMightBeDestination = false;
    bool nextSymbolIsIgnorable = false;

    QRtfReader::ControlWord controlWord(QLatin1String(""));

    while (!atEndOfFile) {
        Token token = tokenizer.fetchToken();
        // token.dump();
        switch (token.type) {
        case Invalid:
            atEndOfFile = true;
            break;
        case OpenGroup: {
            // Store the current state on the stack
            RtfGroupState state;
            m_stateStack.push(state);
            nextSymbolMightBeDestination = true;
            m_output->startGroup();
            // qCDebug(lcRtf) << m_debugIndent << "opengroup";
            m_debugIndent.append(QLatin1Char('\t'));
            break;
        }
        case CloseGroup: {
            QStringList destStackElementNames;
            for (int i = 0; i < m_destinationStack.size(); ++i) {
                destStackElementNames << m_destinationStack.at(i)->name();
            }
            // qCDebug(lcRtf) << m_debugIndent << "closegroup ( destinationStack:" << destStackElementNames << ")";
            m_debugIndent.remove(0, 1);
            state = m_stateStack.pop();
            if (state.endOfFile) {
                atEndOfFile = true;
            } else {
                m_output->endGroup();
            }

            if (state.didChangeDestination) {
                m_destinationStack.top()->aboutToEndDestination();
                delete m_destinationStack.top();
                m_destinationStack.pop();
            }

            destStackElementNames.clear();
            for (int i = 0; i < m_destinationStack.size(); ++i) {
                destStackElementNames << m_destinationStack.at(i)->name();
            }
            // qCDebug(lcRtf) << m_debugIndent << "destinationStack after CloseGroup: (" << destStackElementNames << ")";
            nextSymbolMightBeDestination = true;
            break;
        }
        case Control:
            controlWord = ControlWord(QString::fromUtf8(token.name));
            if (!controlWord.isKnown()) {
                qCDebug(lcRtf) << "*** Unrecognised control word (not in spec 1.9.1): " << token.name;
            }

            // LibreOffice put "*" token before this controlWord, so \ud destination
            // and inner destinations will be ignored (for example \title inside \ud).
            // But we want to keep inner content of this destination for metadata extraction.
            //
            // P.S Eventually unicode \ud inner data will rewrite latin encoding data
            // from \upr that can be in wrong encoding.
            if (token.name == "ud") {
                nextSymbolMightBeDestination = true;
                nextSymbolIsIgnorable = false;
            }

            // qCDebug(lcRtf) << m_debugIndent << "got controlWord: " << token.name;
            // qCDebug(lcRtf) << m_debugIndent << "isDestination:" << controlWord.isDestination();
            // qCDebug(lcRtf) << m_debugIndent << "isIgnorable:" << nextSymbolIsIgnorable;
            if (nextSymbolMightBeDestination && controlWord.isSupportedDestination()) {
                nextSymbolMightBeDestination = false;
                nextSymbolIsIgnorable = false;
                changeDestination(QString::fromUtf8(token.name));
            } else if (nextSymbolMightBeDestination && nextSymbolIsIgnorable) {
                // This is a control word we don't understand
                nextSymbolMightBeDestination = false;
                nextSymbolIsIgnorable = false;
                qCDebug(lcRtf) << "ignorable destination word:" << token.name;
                changeDestination(QStringLiteral("ignorable"));
            } else {
                nextSymbolMightBeDestination = false;
                if (token.name == "*") {
                    nextSymbolMightBeDestination = true;
                    nextSymbolIsIgnorable = true;
                }
                m_destinationStack.top()->handleControlWord(token.name, token.hasParameter, token.parameter.toInt());
            }
            break;
        case Plain:
            m_destinationStack.top()->handlePlainText(token.name);
            break;
        case Binary:
            qCDebug(lcRtf) << "binary data:" << token.name;
            break;
        default:
            qCDebug(lcRtf) << "Unexpected token Type";
        }
    }
}
}
