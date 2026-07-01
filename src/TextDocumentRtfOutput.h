// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_TEXTDOCUMENTRTFOUTPUT_H
#define RTFREADER_TEXTDOCUMENTRTFOUTPUT_H

#include "AbstractRtfOutput.h"

#include "FontTableEntry.h"
#include "StyleSheetTableEntry.h"

#include <QScopedPointer>
#include <QString>
#include <QtTypes>

#include "qrtfreader_export.h"

class QImage;
class QTextCursor;
class QTextDocument;
class QTextImageFormat;
class QByteArray;
class QColor;

/**
   Namespace for the public interface for the QRtfReader classes
*/
namespace QRtfReader
{
class TextDocumentRtfOutputPrivate;
/**
  QTextDocument output strategy for RTF Parser
*/
class QRTFREADER_EXPORT TextDocumentRtfOutput : public AbstractRtfOutput
{
public:
    /**
       Normal constructor
    */
    explicit TextDocumentRtfOutput(QTextDocument *document);

    ~TextDocumentRtfOutput() override;

    /**
      Start a group (in RTF group starts with a '{' character).
    */
    void startGroup() override;

    /**
      Close a group (in RTF group ends with a '}' character).
    */
    void endGroup() override;

    /**
      Convert text from the encoding specified in an RTF document for content and metadata.

      \param text the text to be converted
    */
    [[nodiscard]] QString convertText(const QByteArray &text) const override;

    /**
      Append text to the output.

      \param text the text to be appended

      \note The passed text will be converted before appending it.
    */
    void appendText(const QByteArray &text) override;

    /**
      Append text to the output.

      \param text the text to be appended
    */
    void appendText(const QString &text) override;

    /**
      Insert a paragraph (block).
    */
    void insertPar() override;

    /**
      Insert a tab.
    */
    void insertTab() override;

    /**
      Insert the left single quotation mark.
    */
    void insertLeftQuote() override;

    /**
      Insert the right single quotation mark.
    */
    void insertRightQuote() override;

    /**
      Insert the right double quotation mark.
    */
    void insertLeftDoubleQuote() override;

    /**
      Insert the right double quotation mark.
    */
    void insertRightDoubleQuote() override;

    /**
      Insert the En Dash character.
    */
    void insertEnDash() override;

    /**
      Insert the Em Dash character.
    */
    void insertEmDash() override;

    /**
      Insert the En Space character.
    */
    void insertEnSpace() override;

    /**
      Insert the Em Space character.
    */
    void insertEmSpace() override;

    /**
      Insert the Bullet character.
    */
    void insertBullet() override;

    /**
      Set the italic font.
    */
    void setFontItalic(int value) override;

    /**
      Set the bold font.
    */
    void setFontBold(int value) override;

    /**
      Set the font underline.
    */
    void setFontUnderline(int value) override;

    /**
      Set the font's strikeout.
    */
    void setFontStrikeout(bool value) override;

    /**
      Set the font size.
    */
    void setFontPointSize(int pointSize) override;

    /**
      Set the foreground color.
    */
    void setForegroundColour(int colourIndex) override;

    /**
      Set the highlight color.
    */
    void setHighlightColour(int colourIndex) override;

    /**
      Set the background pattern color of the paragraph.
    */
    void setParagraphPatternBackgroundColour(int colourIndex) override;

    /**
      Set the font by font index from the font table.

      \sa FontTableEntry
    */
    void setFont(int fontIndex) override;

    /**
      Set the default font by font index from the font table.

      \sa FontTableEntry
    */
    void setDefaultFont(int fontIndex) override;

    /**
      Set the font's superscript.
    */
    void setFontSuperscript() override;

    /**
      Set the font's subscript.
    */
    void setFontSubscript() override;

    /**
      Set the text Direction from Left to Right.
    */
    void setTextDirectionLeftToRight() override;

    /**
      Set the text Direction from Right to Left.
    */
    void setTextDirectionRightToLeft() override;

    /**
      Append to the color table.

      \param colour color
    */
    void appendToColourTable(const QColor &colour) override;

    /**
      Insert an entry into the font table.

      \param fontTableEntry entry, managed by the document's control word

      \param fontTableIndex index, specified by the document's control word
    */
    void insertFontTableEntry(FontTableEntry fontTableEntry, quint32 fontTableIndex) override;

    /**
      Insert an entry into the style sheet table.

      \param stylesheetTableIndex index, specified by the document's control word

      \param stylesheetTableEntry entry, managed by the document's control word
    */
    void insertStyleSheetTableEntry(quint32 stylesheetTableIndex, StyleSheetTableEntry stylesheetTableEntry) override;

    /**
      Reset the paragraph formatting (alignment, indentation, margins).
    */
    void resetParagraphFormat() override;

    /**
      Reset character properties (size, weight, italic, underline).
    */
    void resetCharacterProperties() override;

    /**
      Set the paragraph alignment to the left.
    */
    void setParagraphAlignmentLeft() override;

    /**
      Set the paragraph alignment to the center.
    */
    void setParagraphAlignmentCentred() override;

    /**
      Set the paragraph text justified.
    */
    void setParagraphAlignmentJustified() override;

    /**
      Set the paragraph justified alignment to the right.
    */
    void setParagraphAlignmentRight() override;

    /**
      Set the indentation of the first line.
    */
    void setFirstLineIndent(int twips) override;

    /**
      Set the margin to the left.
    */
    void setLeftIndent(int twips) override;

    /**
      Set the margin to the right.
    */
    void setRightIndent(int twips) override;

    /**
      Create and insert image to the output.

      \param data binary image data

      \param format format for image (name, width, height)
    */
    void createImage(const QByteArray &data, const QTextImageFormat &format) override;

    /**
      Set the page height.
    */
    void setPageHeight(int pageHeight) override;

    /**
      Set the page width.
    */
    void setPageWidth(int pageWidth) override;

    /**
      Set the margin to the top.
    */
    void setSpaceBefore(int twips) override;

    /**
      Set the margin to the bottom.
    */
    void setSpaceAfter(int twips) override;

private:
    const QScopedPointer<TextDocumentRtfOutputPrivate> d;
};
}

#endif
