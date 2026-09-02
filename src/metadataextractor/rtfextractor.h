// SPDX-FileCopyrightText: 2024 Sergey Katunin <sulmpx60@yandex.ru>
// SPDX-License-Identifier: LGPL-2.1-or-later

#pragma once

#include <KFileMetaData/ExtractorPlugin>

namespace QRtfReader
{
class TextDocumentRtfOutput;
}

class QTextDocument;

namespace KFileMetaData
{
class RtfExtractor : public ExtractorPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID kfilemetadata_extractor_iid FILE "rtfextractor.json")
    Q_INTERFACES(KFileMetaData::ExtractorPlugin)

public:
    explicit RtfExtractor(QObject *parent = nullptr);

    QStringList mimetypes() const override;
    void extract(ExtractionResult *result) override;

private:
    void parseMetaData(const QRtfReader::TextDocumentRtfOutput &output, ExtractionResult *result);
    void extractPlainText(const QTextDocument &doc, ExtractionResult *result);
};
}
