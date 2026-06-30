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

    [[nodiscard]] QVariant userProp(const QString &propertyName) const;
    [[nodiscard]] QList<QString> userPropNames() const;
    void addUserProp(const QString &propertyName, const QVariant &propertyValue);

    // TODO: consider adding default implementation for this
    [[nodiscard]] virtual QString convertText(const QByteArray &text) const = 0;
    virtual void appendText(const QByteArray &text) = 0;
    virtual void appendText(const QString &text) = 0;
    virtual void insertPar() = 0;
    virtual void insertTab() = 0;
    virtual void insertLeftQuote() = 0;
    virtual void insertRightQuote() = 0;
    virtual void insertLeftDoubleQuote() = 0;
    virtual void insertRightDoubleQuote() = 0;
    virtual void insertEnDash() = 0;
    virtual void insertEmDash() = 0;
    virtual void insertEnSpace() = 0;
    virtual void insertEmSpace() = 0;
    virtual void insertBullet() = 0;
    virtual void resetParagraphFormat() = 0;
    virtual void setParagraphAlignmentLeft() = 0;
    virtual void setParagraphAlignmentCentred() = 0;
    virtual void setParagraphAlignmentJustified() = 0;
    virtual void setParagraphAlignmentRight() = 0;
    virtual void setFirstLineIndent(int twips) = 0;
    virtual void setLeftIndent(int twips) = 0;
    virtual void setRightIndent(int twips) = 0;
    virtual void setFontItalic(int value) = 0;
    virtual void setFontBold(int value) = 0;
    virtual void setFontUnderline(int value) = 0;
    virtual void setFontPointSize(int value) = 0;
    virtual void setFontSuperscript() = 0;
    virtual void setFontSubscript() = 0;
    virtual void setFontStrikeout(bool value) = 0;
    virtual void setForegroundColour(int value) = 0;
    virtual void setHighlightColour(int value) = 0;
    virtual void setParagraphPatternBackgroundColour(int value) = 0;
    virtual void setFont(int fontIndex) = 0;
    virtual void setDefaultFont(int fontIndex) = 0;
    virtual void setTextDirectionLeftToRight() = 0;
    virtual void setTextDirectionRightToLeft() = 0;
    virtual void resetCharacterProperties() = 0;
    virtual void createImage(const QByteArray &data, const QTextImageFormat &format) = 0;
    virtual void setPageHeight(int pageHeight) = 0;
    virtual void setPageWidth(int pageWidth) = 0;
    virtual void setSpaceBefore(int value) = 0;
    virtual void setSpaceAfter(int value) = 0;
    virtual void appendToColourTable(const QColor &colour) = 0;
    virtual void insertFontTableEntry(FontTableEntry fontTableEntry, quint32 fontTableIndex) = 0;
    virtual void insertStyleSheetTableEntry(quint32 stylesheetTableIndex, StyleSheetTableEntry stylesheetTableEntry) = 0;

    virtual void startGroup();
    virtual void endGroup();

private:
    const QScopedPointer<AbstractRtfOutputPrivate> d;
};
}

#endif
