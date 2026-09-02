// SPDX-FileCopyrightText: 2024 Sergey Katunin <sulmpx60@yandex.ru>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "rtfextractor.h"

#include <QDebug>
#include <QRtfReader/Reader>
#include <QRtfReader/TextDocumentRtfOutput>
#include <QTextBlock>
#include <QTextDocument>

using namespace KFileMetaData;
using namespace Qt::StringLiterals;

RtfExtractor::RtfExtractor(QObject *parent)
    : ExtractorPlugin(parent)
{
}

QStringList RtfExtractor::mimetypes() const
{
    return {u"application/rtf"_s};
}

void RtfExtractor::extract(ExtractionResult *result)
{
    QRtfReader::Reader reader;
    if (!reader.open(result->inputUrl())) {
        qWarning() << "The file cannot be loaded, as it seems not to be an RTF document.";
        return;
    }

    result->addType(Type::Document);

    QTextDocument doc;
    QRtfReader::TextDocumentRtfOutput output(&doc);
    reader.parseTo(&output);

    if (result->inputFlags() & ExtractionResult::ExtractMetaData) {
        parseMetaData(output, result);
    }

    if (result->inputFlags() & ExtractionResult::ExtractPlainText) {
        extractPlainText(doc, result);
    }
}

void RtfExtractor::parseMetaData(const QRtfReader::TextDocumentRtfOutput &output, ExtractionResult *result)
{
    const QString author = output.author();
    if (!author.isEmpty()) {
        result->add(Property::Author, author);
    }

    const QString title = output.title();
    if (!title.isEmpty()) {
        result->add(Property::Title, title);
    }

    const QString subject = output.subject();
    if (!subject.isEmpty()) {
        result->add(Property::Subject, subject);
    }

    const QString description = output.documentComment();
    if (!description.isEmpty()) {
        result->add(Property::Description, description);
    }

    const QString keywords = output.keywords();
    if (!keywords.isEmpty()) {
        result->add(Property::Keywords, keywords);
    }

    const QString generator = output.generatorInformation();
    if (!generator.isEmpty()) {
        result->add(Property::Generator, generator);
    }

    const QDateTime creationDate = output.created();
    if (!creationDate.isNull()) {
        result->add(Property::CreationDate, creationDate);
    }

    const int numPages = output.numberOfPages();
    if (numPages > 0) {
        result->add(Property::PageCount, numPages);
    }

    const int numWords = output.numberOfWords();
    if (numWords > 0) {
        result->add(Property::WordCount, numWords);
    }
}

void RtfExtractor::extractPlainText(const QTextDocument &doc, ExtractionResult *result)
{
    for (QTextBlock it = doc.begin(); it != doc.end(); it = it.next()) {
        result->append(it.text());
    }
}

#include "moc_rtfextractor.cpp"
