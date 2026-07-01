// SPDX-FileCopyrightText: 2008, 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_ABSTRACTRTFOUTPUT_H
#define RTFREADER_ABSTRACTRTFOUTPUT_H

#include "FontTableEntry.h"
#include "StyleSheetTableEntry.h"

#include <QDateTime>
#include <QList>
#include <QScopedPointer>
#include <QString>
#include <QVariant>
#include <QtTypes>

#include "qrtfreader_export.h"

class QColor;
class QTextImageFormat;

/**
   Namespace for the public interface for the QRtfReader classes
*/
namespace QRtfReader
{
class AbstractRtfOutputPrivate;
/**
  Abstract output strategy for RTF Parser
*/
class QRTFREADER_EXPORT AbstractRtfOutput
{
public:
    AbstractRtfOutput();
    virtual ~AbstractRtfOutput();

    /**
      The author of this RTF file

      \note This may not be valid - applications may not set this,
      or may not update it.
    */
    [[nodiscard]] virtual QString author() const;
    virtual void setAuthor(const QString &author);

    /**
      The company of the author of this RTF file

      \note This may not be valid - applications may not set this,
      or may not update it.
    */
    [[nodiscard]] virtual QString companyName() const;
    virtual void setCompanyName(const QString &companyName);

    /**
      The title of this RTF file

      \note This may not be valid - applications may not set this,
      or may not update it.
    */
    [[nodiscard]] virtual QString title() const;
    virtual void setTitle(const QString &title);

    /**
      The subject of this RTF file

      \note This may not be valid - applications may not set this,
      or may not update it.
    */
    [[nodiscard]] virtual QString subject() const;
    virtual void setSubject(const QString &subject);

    /**
      The last person make changes to this RTF file

      \note This may not be valid - applications may not set this,
      or may not update it.
    */
    [[nodiscard]] virtual QString operatorName() const;
    virtual void setOperatorName(const QString &operatorName);

    /**
      The manager(s) of the author of this RTF file

      \note This may not be valid - applications may not set this,
      or may not update it.
    */
    [[nodiscard]] virtual QString managerName() const;
    virtual void setManagerName(const QString &managerName);

    /**
      The comment associated with this RTF file

      This is often something related to the application that wrote the file

      \note This may not be valid - applications may not set this,
      or may not update it.

      \sa documentComment
    */
    [[nodiscard]] virtual QString comment() const;
    virtual void setComment(const QString &comment);

    /**
      The document comment associated with this RTF file

      This is often from the "Summary Info" or "Properties" dialog box

      \note This may not be valid - applications may not set this,
      or may not update it.
    */
    [[nodiscard]] virtual QString documentComment() const;
    virtual void setDocumentComment(const QString &documentComment);

    /**
      The keywords associated with this RTF file

      \note This may not be valid - applications may not set this,
      or may not update it.
    */
    [[nodiscard]] virtual QString keywords() const;
    virtual void setKeywords(const QString &keywords);

    /**
      The category information associated with this RTF file

      \note This may not be valid - applications may not set this,
      or may not update it.
    */
    [[nodiscard]] virtual QString category() const;
    virtual void setCategory(const QString &category);

    /**
      The base address for all relative hyperlinks inserted in the document.

      This can be a path or a URL

      \note This may not be valid - applications may not set this,
      or may not update it.
    */
    [[nodiscard]] virtual QString hLinkBase() const;
    virtual void setHLinkBase(const QString &hLinkBase);

    /**
      The generator of this RTF file

      This is usually something like the name of the program and the version of
      that program.

      \note This may not be valid - applications may not set this,
      or may not update it.
    */
    [[nodiscard]] virtual QString generatorInformation() const;
    virtual void setGeneratorInformation(const QString &generatorInformation);

    /**
      When this RTF file was created

      \note This may not be valid - applications may not set this,
      or time may not be set, or it may be set to something silly.
    */
    [[nodiscard]] virtual QDateTime created() const;
    virtual void setCreatedDateTime(const QDateTime &dateTime);

    /**
      When this RTF file was revised / edited

      \note This may not be valid - applications may not set this,
      or time may not be set, or it may be set to something silly.
    */
    [[nodiscard]] virtual QDateTime revised() const;
    virtual void setRevisedDateTime(const QDateTime &dateTime);

    /**
      When this RTF file was printed

      \note This may not be valid - applications may not set this,
      or time may not be set, or it may be set to something silly.
    */
    [[nodiscard]] virtual QDateTime printed() const;
    virtual void setPrintedDateTime(const QDateTime &dateTime);

    /**
      The total editing time for this file (in minutes)

      \note This may not be valid - applications may not set this,
      or it may be set to something silly.
    */
    [[nodiscard]] virtual int totalEditingTime() const;
    virtual void setTotalEditingTime(int totalEditingTime);

    /**
      The number of pages in this document (from the document metadata)

      \note This may not be valid - applications may not set this,
      or it may be set to something silly.
    */
    [[nodiscard]] virtual int numberOfPages() const;
    virtual void setNumberOfPages(int numberOfPages);

    /**
      The number of words in this document (from the document metadata)

      \note This may not be valid - applications may not set this,
      or it may be set to something silly.
    */
    [[nodiscard]] virtual int numberOfWords() const;
    virtual void setNumberOfWords(int numberOfWords);

    /**
      The number of characters in this document (from the document metadata)

      \note This may not be valid - applications may not set this,
      or it may be set to something silly.
    */
    [[nodiscard]] virtual int numberOfCharacters() const;
    virtual void setNumberOfCharacters(int numberOfCharacters);

    /**
      The number of characters (not including spaces) in this document
      (from the document metadata)

      \note This may not be valid - applications may not set this,
      or it may be set to something silly.
    */
    [[nodiscard]] virtual int numberOfCharactersWithoutSpaces() const;
    virtual void setNumberOfCharactersWithoutSpaces(int numberOfCharactersWithoutSpaces);

    /**
      The version number for this document (from the document metadata)

      \note This may not be valid - applications may not set this,
      or it may be set to something silly.
    */
    [[nodiscard]] virtual int versionNumber() const;
    virtual void setVersionNumber(int versionNumber);

    /**
      The version number for this document (from the document metadata)

      \note This may not be valid - applications may not set this,
      or it may be set to something silly.
    */
    [[nodiscard]] virtual int internalVersionNumber() const;
    virtual void setInternalVersionNumber(int internalVersionNumber);

    /**
      Custom user property for this document (from the document metadata)

      \param propertyName the name of the custom user property

      \note This may not be valid - applications may not set this,
      or it may be set to something silly.
    */
    [[nodiscard]] QVariant userProp(const QString &propertyName) const;
    [[nodiscard]] QList<QString> userPropNames() const;
    void addUserProp(const QString &propertyName, const QVariant &propertyValue);

    /**
      Convert text from the encoding specified in an RTF document for content and metadata.

      \param text the text to be converted

      TODO: consider adding default implementation for this
    */
    [[nodiscard]] virtual QString convertText(const QByteArray &text) const = 0;

    /**
      Append text to the output.

      \param text the text to be appended

      \note The passed text will be converted before appending it.
    */
    virtual void appendText(const QByteArray &text) = 0;

    /**
      Append text to the output.

      \param text the text to be appended
    */
    virtual void appendText(const QString &text) = 0;

    /**
      Insert a paragraph (block).
    */
    virtual void insertPar() = 0;

    /**
      Insert a tab.
    */
    virtual void insertTab() = 0;

    /**
      Insert the left single quotation mark.
    */
    virtual void insertLeftQuote() = 0;

    /**
      Insert the right single quotation mark.
    */
    virtual void insertRightQuote() = 0;

    /**
      Insert the right double quotation mark.
    */
    virtual void insertLeftDoubleQuote() = 0;

    /**
      Insert the right double quotation mark.
    */
    virtual void insertRightDoubleQuote() = 0;

    /**
      Insert the En Dash character.
    */
    virtual void insertEnDash() = 0;

    /**
      Insert the Em Dash character.
    */
    virtual void insertEmDash() = 0;

    /**
      Insert the En Space character.
    */
    virtual void insertEnSpace() = 0;

    /**
      Insert the Em Space character.
    */
    virtual void insertEmSpace() = 0;

    /**
      Insert the Bullet character.
    */
    virtual void insertBullet() = 0;

    /**
      Reset the paragraph formatting (alignment, indentation, margins).
    */
    virtual void resetParagraphFormat() = 0;

    /**
      Set the paragraph alignment to the left.
    */
    virtual void setParagraphAlignmentLeft() = 0;

    /**
      Set the paragraph alignment to the center.
    */
    virtual void setParagraphAlignmentCentred() = 0;

    /**
      Set the paragraph text justified.
    */
    virtual void setParagraphAlignmentJustified() = 0;

    /**
      Set the paragraph justified alignment to the right.
    */
    virtual void setParagraphAlignmentRight() = 0;

    /**
      Set the indentation of the first line.
    */
    virtual void setFirstLineIndent(int twips) = 0;

    /**
      Set the margin to the left.
    */
    virtual void setLeftIndent(int twips) = 0;

    /**
      Set the margin to the right.
    */
    virtual void setRightIndent(int twips) = 0;

    /**
      Set the italic font.
    */
    virtual void setFontItalic(int value) = 0;

    /**
      Set the bold font.
    */
    virtual void setFontBold(int value) = 0;

    /**
      Set the font underline.
    */
    virtual void setFontUnderline(int value) = 0;

    /**
      Set the font size.
    */
    virtual void setFontPointSize(int value) = 0;

    /**
      Set the font's superscript.
    */
    virtual void setFontSuperscript() = 0;

    /**
      Set the font's subscript.
    */
    virtual void setFontSubscript() = 0;

    /**
      Set the font's strikeout.
    */
    virtual void setFontStrikeout(bool value) = 0;

    /**
      Set the foreground color.
    */
    virtual void setForegroundColour(int value) = 0;

    /**
      Set the highlight color.
    */
    virtual void setHighlightColour(int value) = 0;

    /**
      Set the background pattern color of the paragraph.
    */
    virtual void setParagraphPatternBackgroundColour(int value) = 0;

    /**
      Set the font by font index from the font table.

      \sa FontTableEntry
    */
    virtual void setFont(int fontIndex) = 0;

    /**
      Set the default font by font index from the font table.

      \sa FontTableEntry
    */
    virtual void setDefaultFont(int fontIndex) = 0;

    /**
      Set the text Direction from Left to Right.
    */
    virtual void setTextDirectionLeftToRight() = 0;

    /**
      Set the text Direction from Right to Left.
    */
    virtual void setTextDirectionRightToLeft() = 0;

    /**
      Reset character properties (size, weight, italic, underline).
    */
    virtual void resetCharacterProperties() = 0;

    /**
      Create and insert image to the output.

      \param data binary image data

      \param format format for image (name, width, height)
    */
    virtual void createImage(const QByteArray &data, const QTextImageFormat &format) = 0;

    /**
      Set the page height.
    */
    virtual void setPageHeight(int pageHeight) = 0;

    /**
      Set the page width.
    */
    virtual void setPageWidth(int pageWidth) = 0;

    /**
      Set the margin to the top.
    */
    virtual void setSpaceBefore(int value) = 0;

    /**
      Set the margin to the bottom.
    */
    virtual void setSpaceAfter(int value) = 0;

    /**
      Append to the color table.

      \param colour color
    */
    virtual void appendToColourTable(const QColor &colour) = 0;

    /**
      Insert an entry into the font table.

      \param fontTableEntry entry, managed by the document's control word

      \param fontTableIndex index, specified by the document's control word
    */
    virtual void insertFontTableEntry(FontTableEntry fontTableEntry, quint32 fontTableIndex) = 0;

    /**
      Insert an entry into the style sheet table.

      \param stylesheetTableIndex index, specified by the document's control word

      \param stylesheetTableEntry entry, managed by the document's control word
    */
    virtual void insertStyleSheetTableEntry(quint32 stylesheetTableIndex, StyleSheetTableEntry stylesheetTableEntry) = 0;

    /**
      Start a group (in RTF group starts with a '{' character).
    */
    virtual void startGroup();

    /**
      Close a group (in RTF group ends with a '}' character).
    */
    virtual void endGroup();

private:
    const QScopedPointer<AbstractRtfOutputPrivate> d;
};
}

#endif
