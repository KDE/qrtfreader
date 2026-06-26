// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_TEXTDOCUMENTRTFOUTPUT_P_H
#define RTFREADER_TEXTDOCUMENTRTFOUTPUT_P_H

#include "AbstractRtfOutput.h"

#include <QStack>
#include <QTextCharFormat>

#include "qrtfreader_export.h"

class QTextCursor;
class QTextDocument;

namespace QRtfReader
{
class QRTFREADER_EXPORT TextDocumentRtfOutputPrivate
{
public:
    TextDocumentRtfOutputPrivate(QTextDocument *document);
    virtual ~TextDocumentRtfOutputPrivate();

    /**
      Convenience routine to convert a size in twips into pixels
    */
    qreal pixelsFromTwips(const int twips) const;

    /////////////////////////////////////////////////
    //
    // Implementation details
    //
    ////////////////////////////////////////////////

    void startGroup();
    void endGroup();

    void setForegroundColour(const int colourIndex);
    void setHighlightColour(const int colourIndex);
    void setParagraphPatternBackgroundColour(const int colourIndex);

    void setFont(const int fontIndex);

    void resetParagraphFormat();
    void resetCharacterProperties();

    /////////////////////////////////////////////////
    //
    // Member variables below
    //
    ////////////////////////////////////////////////

    // The text cursor on the document being generated
    QTextCursor *m_cursor = nullptr;

    QStack<QTextCharFormat> m_textCharFormatStack;

    QTextBlockFormat m_paragraphFormat;

    QList<QColor> m_colourTable;

    QHash<int, FontTableEntry> m_fontTable;
    int m_defaultFontIndex = 0;
    bool m_haveSetFont = false;

    QHash<int, StyleSheetTableEntry> m_stylesheetTable;

    QTextDocument *m_document = nullptr;
    QString m_encoding;
};
}

#endif
