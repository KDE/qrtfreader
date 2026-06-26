// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "PcdataDestination_p.h"

#include "AbstractRtfOutput.h"
#include "DocumentDestination_p.h"

#include <QByteArray>
#include <QChar>
#include <QLoggingCategory>
#include <QString>

#include "qrtfreader_debug.h"

namespace QRtfReader
{
PcdataDestination::PcdataDestination(AbstractRtfOutput *output, const QString &name)
    : DocumentDestination(output, name)
{
}

PcdataDestination::~PcdataDestination() = default;

void PcdataDestination::handleControlWord(const QByteArray &controlWord, bool hasValue, const int value)
{
    if ((controlWord == "u") && hasValue) {
        m_pcdata += QString(1, QChar(value));
        m_charactersToSkip = m_unicodeSkip;
    } else if (controlWord == "uc" && hasValue) {
        m_unicodeSkip = value;
    } else if ((controlWord == "\'") && hasValue) {
        qCDebug(lcRtf) << "special character value:" << value;
    } else {
        qCDebug(lcRtf) << "unexpected control word in" << m_name << ": " << controlWord;
    }
}

void PcdataDestination::handlePlainText(const QByteArray &plainText)
{
    if (m_charactersToSkip > 0) {
        qCDebug(lcRtf) << "skipping" << m_charactersToSkip << "of" << plainText;
        if (m_charactersToSkip >= plainText.size()) {
            m_charactersToSkip -= plainText.size();
            return;
        } else if (plainText.size() > m_charactersToSkip) {
            QByteArray partiallySkippedText(plainText);
            partiallySkippedText.remove(0, m_charactersToSkip);
            m_pcdata += m_output->convertText(partiallySkippedText);
            m_charactersToSkip = 0;
            return;
        }
    }

    m_pcdata += m_output->convertText(plainText);
}
}
