// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_TEXTDOCUMENTRTFOUTPUT_H
#define RTFREADER_TEXTDOCUMENTRTFOUTPUT_H

#include "AbstractRtfOutput.h"

#include "qrtfreader_export.h"

class QImage;
class QTextCursor;
class QTextDocument;
class QTextImageFormat;

namespace QRtfReader
{
class TextDocumentRtfOutputPrivate;
class QRTFREADER_EXPORT TextDocumentRtfOutput : public AbstractRtfOutput
{
public:
    explicit TextDocumentRtfOutput(QTextDocument *document);

    ~TextDocumentRtfOutput() override;

    void startGroup() override;

    void endGroup() override;

    QString convertText(const QByteArray &text) const override;
    void appendText(const QByteArray &text) override;
    void appendText(const QString &text) override;

    void insertPar() override;

    void insertTab() override;

    void insertLeftQuote() override;
    void insertRightQuote() override;
    void insertLeftDoubleQuote() override;
    void insertRightDoubleQuote() override;

    void insertEnDash() override;
    void insertEmDash() override;

    void insertEnSpace() override;
    void insertEmSpace() override;

    void insertBullet() override;

    void setFontItalic(int value) override;

    void setFontBold(int value) override;

    void setFontUnderline(int value) override;

    void setFontStrikeout(bool value) override;

    void setFontPointSize(int pointSize) override;

    void setForegroundColour(int colourIndex) override;
    void setHighlightColour(int colourIndex) override;
    void setParagraphPatternBackgroundColour(int colourIndex) override;

    void setFont(int fontIndex) override;

    void setDefaultFont(int fontIndex) override;

    void setFontSuperscript() override;
    void setFontSubscript() override;

    void setTextDirectionLeftToRight() override;
    void setTextDirectionRightToLeft() override;

    void appendToColourTable(const QColor &colour) override;

    void insertFontTableEntry(FontTableEntry fontTableEntry, quint32 fontTableIndex) override;
    void insertStyleSheetTableEntry(quint32 stylesheetTableIndex, StyleSheetTableEntry stylesheetTableEntry) override;

    void resetParagraphFormat() override;
    void resetCharacterProperties() override;

    void setParagraphAlignmentLeft() override;
    void setParagraphAlignmentCentred() override;
    void setParagraphAlignmentJustified() override;
    void setParagraphAlignmentRight() override;

    void setFirstLineIndent(int twips) override;
    void setLeftIndent(int twips) override;
    void setRightIndent(int twips) override;

    void createImage(const QByteArray &data, const QTextImageFormat &format) override;

    void setPageHeight(int pageHeight) override;
    void setPageWidth(int pageWidth) override;

    void setSpaceBefore(int twips) override;
    void setSpaceAfter(int twips) override;

private:
    const QScopedPointer<TextDocumentRtfOutputPrivate> d;
};
}

#endif
