// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "TextDocumentRtfOutput_p.h"

#include "FontTableEntry.h"

#include <QColor>
#include <QDebug>
#include <QFont>
#include <QLoggingCategory>
#include <QStringList>
#include <QTextCursor>
#include <QTextDocument>
#include <Qt>
#include <QtTypes>

#include "qrtfreader_debug.h"

namespace QRtfReader
{
TextDocumentRtfOutputPrivate::TextDocumentRtfOutputPrivate(QTextDocument *document)
    : m_document(document)
{
    m_cursor = new QTextCursor(m_document);
    QTextCharFormat defaultCharFormat;
    defaultCharFormat.setFontPointSize(12); // default of 24 "half-points"
    m_textCharFormatStack.push(defaultCharFormat);
}

TextDocumentRtfOutputPrivate::~TextDocumentRtfOutputPrivate()
{
    delete m_cursor;
}

qreal TextDocumentRtfOutputPrivate::pixelsFromTwips(const int twips)
{
    const qreal inches = twips / 1440.0;
    const qreal pixels = inches * 96.0;
    return pixels;
}

void TextDocumentRtfOutputPrivate::startGroup()
{
    if (!m_haveSetFont) {
        // TODO: think harder about how to deal with default font cases.
        setFont(m_defaultFontIndex);
    }
    const QTextCharFormat charFormat = m_textCharFormatStack.top(); // inherit all current properties
    m_textCharFormatStack.push(charFormat);
}

void TextDocumentRtfOutputPrivate::endGroup()
{
    m_textCharFormatStack.pop();
    m_cursor->setCharFormat(m_textCharFormatStack.top());
}

void TextDocumentRtfOutputPrivate::setForegroundColour(const int colourIndex)
{
    const QColor colour = m_colourTable.value(colourIndex);
    if (colour.isValid()) {
        m_textCharFormatStack.top().setForeground(colour);
    } else {
        m_textCharFormatStack.top().clearForeground();
    }
    m_cursor->setCharFormat(m_textCharFormatStack.top());
}

void TextDocumentRtfOutputPrivate::setHighlightColour(const int colourIndex)
{
    const QColor colour = m_colourTable.value(colourIndex);
    if (colour.isValid()) {
        m_textCharFormatStack.top().setBackground(colour);
    } else {
        m_textCharFormatStack.top().clearBackground();
    }
    m_cursor->setCharFormat(m_textCharFormatStack.top());
}

void TextDocumentRtfOutputPrivate::setParagraphPatternBackgroundColour(const int colourIndex)
{
    const QColor colour = m_colourTable.value(colourIndex);
    if (colour.isValid()) {
        m_paragraphFormat.setBackground(colour);
    } else {
        m_paragraphFormat.clearBackground();
    }
    m_cursor->setBlockFormat(m_paragraphFormat);
}

void TextDocumentRtfOutputPrivate::setFont(const int fontIndex)
{
    if (!m_fontTable.contains(fontIndex)) {
        qCDebug(lcRtf) << "attempted to select fontIndex" << fontIndex << "not in the font table";
        return;
    }
    const FontTableEntry fontEntry = m_fontTable.value(fontIndex);
    qCDebug(lcRtf) << "selecting font:" << fontEntry.fontName();
    m_textCharFormatStack.top().setFontFamilies(QStringList{fontEntry.fontName()});
    m_cursor->setCharFormat(m_textCharFormatStack.top());
    m_encoding = fontEntry.encoding();
    m_haveSetFont = true;
}

void TextDocumentRtfOutputPrivate::resetParagraphFormat()
{
    m_paragraphFormat.setAlignment(Qt::AlignLeft);
    m_paragraphFormat.setTextIndent(0);
    m_paragraphFormat.setLeftMargin(0);
    m_paragraphFormat.setRightMargin(0);
    m_cursor->setBlockFormat(m_paragraphFormat);
}

void TextDocumentRtfOutputPrivate::resetCharacterProperties()
{
    m_textCharFormatStack.top().setFontPointSize(12); // default of 24 "half-points"
    m_textCharFormatStack.top().setFontWeight(QFont::Normal);
    m_textCharFormatStack.top().setFontItalic(false);
    m_textCharFormatStack.top().setFontUnderline(false);
    m_cursor->setCharFormat(m_textCharFormatStack.top());
}

}
