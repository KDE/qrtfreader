// SPDX-FileCopyrightText: 2008, 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "AbstractRtfOutput.h"
#include "private/AbstractRtfOutput_p.h"

/**
   Namespace for the public interface for the QRtfReader classes
*/
namespace QRtfReader
{
AbstractRtfOutput::AbstractRtfOutput()
    : d(new AbstractRtfOutputPrivate)
{
}

AbstractRtfOutput::~AbstractRtfOutput() = default;

QString AbstractRtfOutput::author() const
{
    return d->m_author;
}

void AbstractRtfOutput::setAuthor(const QString &author)
{
    d->m_author = author;
}

QString AbstractRtfOutput::companyName() const
{
    return d->m_companyName;
}

void AbstractRtfOutput::setCompanyName(const QString &companyName)
{
    d->m_companyName = companyName;
}

QString AbstractRtfOutput::operatorName() const
{
    return d->m_operatorName;
}

void AbstractRtfOutput::setOperatorName(const QString &operatorName)
{
    d->m_operatorName = operatorName;
}

QString AbstractRtfOutput::title() const
{
    return d->m_title;
}

void AbstractRtfOutput::setTitle(const QString &title)
{
    d->m_title = title;
}

QString AbstractRtfOutput::subject() const
{
    return d->m_subject;
}

void AbstractRtfOutput::setSubject(const QString &subject)
{
    d->m_subject = subject;
}

QString AbstractRtfOutput::comment() const
{
    return d->m_comment;
}

void AbstractRtfOutput::setComment(const QString &comment)
{
    d->m_comment = comment;
}

QString AbstractRtfOutput::documentComment() const
{
    return d->m_documentComment;
}

void AbstractRtfOutput::setDocumentComment(const QString &documentComment)
{
    d->m_documentComment = documentComment;
}

QString AbstractRtfOutput::managerName() const
{
    return d->m_managerName;
}

void AbstractRtfOutput::setManagerName(const QString &managerName)
{
    d->m_managerName = managerName;
}

QString AbstractRtfOutput::category() const
{
    return d->m_category;
}

void AbstractRtfOutput::setCategory(const QString &category)
{
    d->m_category = category;
}

QString AbstractRtfOutput::keywords() const
{
    return d->m_keywords;
}

void AbstractRtfOutput::setKeywords(const QString &keywords)
{
    d->m_keywords = keywords;
}

QString AbstractRtfOutput::hLinkBase() const
{
    return d->m_hlinkbase;
}

void AbstractRtfOutput::setHLinkBase(const QString &hLinkBase)
{
    d->m_hlinkbase = hLinkBase;
}

QString AbstractRtfOutput::generatorInformation() const
{
    return d->m_generatorInformation;
}

void AbstractRtfOutput::setGeneratorInformation(const QString &generatorInformation)
{
    d->m_generatorInformation = generatorInformation;
}

QDateTime AbstractRtfOutput::created() const
{
    return d->m_created;
}

void AbstractRtfOutput::setCreatedDateTime(const QDateTime &dateTime)
{
    d->m_created = dateTime;
}

QDateTime AbstractRtfOutput::revised() const
{
    return d->m_revised;
}

void AbstractRtfOutput::setRevisedDateTime(const QDateTime &dateTime)
{
    d->m_revised = dateTime;
}

QDateTime AbstractRtfOutput::printed() const
{
    return d->m_printed;
}

void AbstractRtfOutput::setPrintedDateTime(const QDateTime &dateTime)
{
    d->m_printed = dateTime;
}

int AbstractRtfOutput::totalEditingTime() const
{
    return d->m_totalEditingTime;
}

void AbstractRtfOutput::setTotalEditingTime(const int totalEditingTime)
{
    d->m_totalEditingTime = totalEditingTime;
}

int AbstractRtfOutput::numberOfPages() const
{
    return d->m_numberOfPages;
}

void AbstractRtfOutput::setNumberOfPages(const int numberOfPages)
{
    d->m_numberOfPages = numberOfPages;
}

int AbstractRtfOutput::numberOfWords() const
{
    return d->m_numberOfWords;
}

void AbstractRtfOutput::setNumberOfWords(const int numberOfWords)
{
    d->m_numberOfWords = numberOfWords;
}

int AbstractRtfOutput::numberOfCharacters() const
{
    return d->m_numberOfCharacters;
}

void AbstractRtfOutput::setNumberOfCharacters(const int numberOfCharacters)
{
    d->m_numberOfCharacters = numberOfCharacters;
}

int AbstractRtfOutput::numberOfCharactersWithoutSpaces() const
{
    return d->m_numberOfCharactersWithoutSpaces;
}

void AbstractRtfOutput::setNumberOfCharactersWithoutSpaces(const int numberOfCharactersWithoutSpaces)
{
    d->m_numberOfCharactersWithoutSpaces = numberOfCharactersWithoutSpaces;
}

int AbstractRtfOutput::versionNumber() const
{
    return d->m_versionNumber;
}

void AbstractRtfOutput::setVersionNumber(const int versionNumber)
{
    d->m_versionNumber = versionNumber;
}

int AbstractRtfOutput::internalVersionNumber() const
{
    return d->m_internalVersionNumber;
}

void AbstractRtfOutput::setInternalVersionNumber(const int internalVersionNumber)
{
    d->m_internalVersionNumber = internalVersionNumber;
}

QVariant AbstractRtfOutput::userProp(const QString &propertyName) const
{
    return d->m_userProps.value(propertyName);
}

QList<QString> AbstractRtfOutput::userPropNames() const
{
    return d->m_userProps.keys();
}

void AbstractRtfOutput::addUserProp(const QString &propertyName, const QVariant &propertyValue)
{
    d->m_userProps.insert(propertyName, propertyValue);
}

void AbstractRtfOutput::startGroup()
{
}

void AbstractRtfOutput::endGroup()
{
}
}
