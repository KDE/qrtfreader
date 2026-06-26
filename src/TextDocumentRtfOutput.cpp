// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "TextDocumentRtfOutput.h"
#include "private/TextDocumentRtfOutput_p.h"

#include "AbstractRtfOutput.h"
#include "FontTableEntry.h"
#include "StyleSheetTableEntry.h"

#include <QByteArray>
#include <QChar>
#include <QColor>
#include <QDebug>
#include <QFont>
#include <QLoggingCategory>
#include <QRegularExpression>
#include <QString>
#include <QTextCursor>
#include <QTextDocument>
#include <QUrl>
#include <Qt>
#include <QtTypes>

#include "qrtfreader_debug.h"

namespace QRtfReader
{
TextDocumentRtfOutput::TextDocumentRtfOutput(QTextDocument *document)
    : AbstractRtfOutput()
    , d(new TextDocumentRtfOutputPrivate(document))
{
}

TextDocumentRtfOutput::~TextDocumentRtfOutput() = default;

void TextDocumentRtfOutput::startGroup()
{
    d->startGroup();
}

void TextDocumentRtfOutput::endGroup()
{
    d->endGroup();
}

QString TextDocumentRtfOutput::convertText(const QByteArray &text) const
{
    static const QRegularExpression controlCharacters(QStringLiteral("[\\x00-\\x08\\x0B\\x0C\\x0E-\\x1F]"));
    return (d->m_encoding != QStringLiteral("UTF-8") ? QStringDecoder(d->m_encoding).decode(text) : QString::fromLatin1(text)).remove(controlCharacters);
}

void TextDocumentRtfOutput::appendText(const QByteArray &text)
{
    d->m_cursor->insertText(this->convertText(text));
}

void TextDocumentRtfOutput::appendText(const QString &str)
{
    d->m_cursor->insertText(str);
}

void TextDocumentRtfOutput::insertPar()
{
    d->m_cursor->insertBlock();
}

void TextDocumentRtfOutput::insertTab()
{
    d->m_cursor->insertText(QStringLiteral("\t"));
}

void TextDocumentRtfOutput::insertLeftQuote()
{
    d->m_cursor->insertText(QChar(0x2018));
}

void TextDocumentRtfOutput::insertRightQuote()
{
    d->m_cursor->insertText(QChar(0x2019));
}

void TextDocumentRtfOutput::insertLeftDoubleQuote()
{
    d->m_cursor->insertText(QChar(0x201c));
}

void TextDocumentRtfOutput::insertRightDoubleQuote()
{
    d->m_cursor->insertText(QChar(0x201d));
}

void TextDocumentRtfOutput::insertEnDash()
{
    d->m_cursor->insertText(QChar(0x2013));
}

void TextDocumentRtfOutput::insertEmDash()
{
    d->m_cursor->insertText(QChar(0x2014));
}

void TextDocumentRtfOutput::insertEmSpace()
{
    d->m_cursor->insertText(QChar(0x2003));
}

void TextDocumentRtfOutput::insertEnSpace()
{
    d->m_cursor->insertText(QChar(0x2002));
}

void TextDocumentRtfOutput::insertBullet()
{
    d->m_cursor->insertText(QChar(0x2022));
}

void TextDocumentRtfOutput::setFontItalic(const int value)
{
    d->m_textCharFormatStack.top().setFontItalic(value != 0);
    d->m_cursor->setCharFormat(d->m_textCharFormatStack.top());
}

void TextDocumentRtfOutput::setFontBold(const int value)
{
    int weight = QFont::Normal;
    if (value != 0) {
        weight = QFont::Bold;
    }
    d->m_textCharFormatStack.top().setFontWeight(weight);
    d->m_cursor->setCharFormat(d->m_textCharFormatStack.top());
}

void TextDocumentRtfOutput::setFontUnderline(const int value)
{
    d->m_textCharFormatStack.top().setFontUnderline(value != 0);
    d->m_cursor->setCharFormat(d->m_textCharFormatStack.top());
}

void TextDocumentRtfOutput::setFontStrikeout(const bool value)
{
    d->m_textCharFormatStack.top().setFontStrikeOut(value);
    d->m_cursor->setCharFormat(d->m_textCharFormatStack.top());
}

void TextDocumentRtfOutput::setFontPointSize(const int pointSize)
{
    d->m_textCharFormatStack.top().setFontPointSize(pointSize);
    d->m_cursor->setCharFormat(d->m_textCharFormatStack.top());
}

void TextDocumentRtfOutput::setForegroundColour(const int colourIndex)
{
    d->setForegroundColour(colourIndex);
}

void TextDocumentRtfOutput::setHighlightColour(const int colourIndex)
{
    d->setHighlightColour(colourIndex);
}

void TextDocumentRtfOutput::setParagraphPatternBackgroundColour(const int colourIndex)
{
    d->setParagraphPatternBackgroundColour(colourIndex);
}

void TextDocumentRtfOutput::setFont(const int fontIndex)
{
    d->setFont(fontIndex);
}

void TextDocumentRtfOutput::setDefaultFont(const int fontIndex)
{
    d->m_defaultFontIndex = fontIndex;
}

void TextDocumentRtfOutput::appendToColourTable(const QColor &colour)
{
    d->m_colourTable.append(colour);
}

void TextDocumentRtfOutput::insertFontTableEntry(FontTableEntry fontTableEntry, quint32 fontTableIndex)
{
    // qCDebug(lcRtf) << "inserting font entry:" << fontTableIndex << "with name:" << fontTableEntry.fontName();
    d->m_fontTable.insert(fontTableIndex, fontTableEntry);
}

void TextDocumentRtfOutput::insertStyleSheetTableEntry(quint32 stylesheetTableIndex, StyleSheetTableEntry stylesheetTableEntry)
{
    qCDebug(lcRtf) << "inserting stylesheet entry:" << stylesheetTableIndex << "with name:" << stylesheetTableEntry.styleName();
    d->m_stylesheetTable.insert(stylesheetTableIndex, stylesheetTableEntry);
}

void TextDocumentRtfOutput::resetParagraphFormat()
{
    d->resetParagraphFormat();
}

void TextDocumentRtfOutput::resetCharacterProperties()
{
    d->resetCharacterProperties();
}

void TextDocumentRtfOutput::setParagraphAlignmentLeft()
{
    d->m_paragraphFormat.setAlignment(Qt::AlignLeft);
    d->m_cursor->setBlockFormat(d->m_paragraphFormat);
}

void TextDocumentRtfOutput::setParagraphAlignmentCentred()
{
    d->m_paragraphFormat.setAlignment(Qt::AlignHCenter);
    d->m_cursor->setBlockFormat(d->m_paragraphFormat);
}

void TextDocumentRtfOutput::setParagraphAlignmentJustified()
{
    d->m_paragraphFormat.setAlignment(Qt::AlignJustify);
    d->m_cursor->setBlockFormat(d->m_paragraphFormat);
}

void TextDocumentRtfOutput::setParagraphAlignmentRight()
{
    d->m_paragraphFormat.setAlignment(Qt::AlignRight);
    d->m_cursor->setBlockFormat(d->m_paragraphFormat);
}

void TextDocumentRtfOutput::setLeftIndent(const int twips)
{
    d->m_paragraphFormat.setLeftMargin(d->pixelsFromTwips(twips));
    d->m_cursor->setBlockFormat(d->m_paragraphFormat);
}

void TextDocumentRtfOutput::setRightIndent(const int twips)
{
    d->m_paragraphFormat.setRightMargin(d->pixelsFromTwips(twips));
    d->m_cursor->setBlockFormat(d->m_paragraphFormat);
}

void TextDocumentRtfOutput::setSpaceBefore(const int twips)
{
    d->m_paragraphFormat.setTopMargin(d->pixelsFromTwips(twips));
    d->m_cursor->setBlockFormat(d->m_paragraphFormat);
}

void TextDocumentRtfOutput::setSpaceAfter(const int twips)
{
    d->m_paragraphFormat.setBottomMargin(d->pixelsFromTwips(twips));
    d->m_cursor->setBlockFormat(d->m_paragraphFormat);
}

void TextDocumentRtfOutput::setFirstLineIndent(const int twips)
{
    d->m_paragraphFormat.setTextIndent(d->pixelsFromTwips(twips));
    d->m_cursor->setBlockFormat(d->m_paragraphFormat);
}

void TextDocumentRtfOutput::setFontSuperscript()
{
    d->m_textCharFormatStack.top().setVerticalAlignment(QTextCharFormat::AlignSuperScript);
    d->m_cursor->setCharFormat(d->m_textCharFormatStack.top());
}

void TextDocumentRtfOutput::setFontSubscript()
{
    d->m_textCharFormatStack.top().setVerticalAlignment(QTextCharFormat::AlignSubScript);
    d->m_cursor->setCharFormat(d->m_textCharFormatStack.top());
}

void TextDocumentRtfOutput::setTextDirectionLeftToRight()
{
    d->m_textCharFormatStack.top().setLayoutDirection(Qt::LeftToRight);
    d->m_cursor->setCharFormat(d->m_textCharFormatStack.top());
}

void TextDocumentRtfOutput::setTextDirectionRightToLeft()
{
    d->m_textCharFormatStack.top().setLayoutDirection(Qt::RightToLeft);
    d->m_cursor->setCharFormat(d->m_textCharFormatStack.top());
}

void TextDocumentRtfOutput::createImage(const QByteArray &data, const QTextImageFormat &format)
{
    d->m_document->addResource(QTextDocument::ImageResource, QUrl(format.name()), data);
    d->m_cursor->insertImage(format);
}

void TextDocumentRtfOutput::setPageHeight(const int pageHeight)
{
    qCDebug(lcRtf) << "setPageHeight: " << pageHeight << " (" << pageHeight / 1440.0 << ")";
}

void TextDocumentRtfOutput::setPageWidth(const int pageWidth)
{
    qCDebug(lcRtf) << "setPageWidth: " << pageWidth << " (" << pageWidth / 1440.0 << ")";
}
}
