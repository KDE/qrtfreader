<!--
SPDX-FileCopyrightText: 2011 Brad Hards <bradh@frogmouth.net>
SPDX-FileCopyrightText: 2024 Sergey Katunin <sulmpx60@yandex.ru>

SPDX-License-Identifier: CC-BY-SA-4.0
-->

QRtfReader is a library for reading Rtf documents.

### How to use

```
#include <QCoreApplication>
#include <QTextBlock>

#include <QRtfReader/Reader>
#include <QRtfReader/TextDocumentRtfOutput>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path("test.rtf");

    QRtfReader::Reader reader;
    if (!reader.open(path)) {
        qWarning() << "The file cannot be loaded, as it seems not to be an RTF document";
        a.quit();
    }

    QTextDocument doc;
    QRtfReader::TextDocumentRtfOutput output(&doc);
    reader.parseTo(&output);

    // Metadata.
    qDebug() << output.title();

    QString text;
    
    // Text content.
    for (QTextBlock it = doc.begin(); it != doc.end(); it = it.next()) {
        text.append(it.text());
    }

    qDebug() << text;

    return a.exec();
}

```

### History

Imported from the Calligra project where there was a temporary copy of Brad Hards' rtf-qt library.

https://invent.kde.org/office/calligra

Original location:

https://launchpad.net/rtf-qt
