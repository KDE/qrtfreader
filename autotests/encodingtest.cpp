/*
    SPDX-FileCopyrightText: 2024 Sergey Katunin <sulmpx60@yandex.ru>

    SPDX-License-Identifier: BSD-2-Clause
*/

#include "qrtfreadertestsconfig.h"

#include <QObject>
#include <QTest>
#include <QTextDocument>

#include "Reader.h"
#include "TextDocumentRtfOutput.h"

using namespace QRtfReader;

/**
    Three types of RTF documents is supported:

    Type A: the document is saved in UTF-8, the non-latin text is encoded
    using character escaping \u???? in a non-standard representation
    of UTF-16 encoding. For example, this is how LibreOffice saves it.

    Type B: the document is saved in UTF-8, the non-latin text is encoded
    using character escaping \'?? in non-unicode encoding (like windows-1251).
    For example, this is how Word or WordPad save it.

    Type C: the document is saved in non-unicode encoding (like windows-1251),
    the text is encoded directly in the form of Cyrillic
    (for windows-1251 case) characters.
*/

class EncodingTest : public QObject
{
    Q_OBJECT
private:
    QString testFilePath(const QString &fileName) const;

private Q_SLOTS:
    // Type A case
    void testLibreOffice();
    void testLibreOfficeCyrillic();

    // Type B case
    void testUnicodeFileWithWin1251Text();

    // Type B and C cases
    void testWin1251Cyrillic_data();
    void testWin1251Cyrillic();
};

using namespace QRtfReader;

QString EncodingTest::testFilePath(const QString &fileName) const
{
    return QStringLiteral(TESTS_SAMPLE_FILES_PATH) + QLatin1Char('/') + fileName;
}

void EncodingTest::testLibreOffice()
{
    Reader reader;

    QVERIFY(reader.fileName().isEmpty());

    QString fileName = testFilePath("test_libreoffice.rtf");

    bool result = reader.open(fileName);
    QVERIFY(result);
    QCOMPARE(reader.fileName(), fileName);

    QTextDocument doc;
    TextDocumentRtfOutput output(&doc);

    reader.parseTo(&output);

    QVERIFY(!doc.isEmpty());

    QCOMPARE(doc.toPlainText().trimmed(), QStringLiteral("Test file for KFileMetaData."));

    QCOMPARE(output.title(), QStringLiteral("KFileMetaData Title"));
    QCOMPARE(output.subject(), QStringLiteral("KFileMetaData Subject"));
    QCOMPARE(output.keywords(), QStringLiteral("KFileMetaData keyword"));
    QCOMPARE(output.documentComment(), QStringLiteral("KFileMetaData description"));
    QVERIFY(output.generatorInformation().contains(QStringLiteral("LibreOffice")));

    QDateTime dt(QDate(2024, 02, 13), QTime(21, 35, 00, 000));
    QCOMPARE(output.created(), dt);
    // This document has not 'nofwords' or 'nofpages' values,
    // so expect only '-1' here, but not random value.
    QCOMPARE(output.numberOfPages(), -1);
    QCOMPARE(output.numberOfWords(), -1);
}

void EncodingTest::testLibreOfficeCyrillic()
{
    Reader reader;

    QVERIFY(reader.fileName().isEmpty());

    QString fileName = testFilePath("test_libreoffice_cyrillic.rtf");

    bool result = reader.open(fileName);
    QVERIFY(result);
    QCOMPARE(reader.fileName(), fileName);

    QTextDocument doc;
    TextDocumentRtfOutput output(&doc);

    reader.parseTo(&output);

    QVERIFY(!doc.isEmpty());

    QCOMPARE(doc.toPlainText().trimmed(), QStringLiteral("Тестовый файл для KFileMetaData."));

    QCOMPARE(output.title(), QStringLiteral("KFileMetaData Название"));
    QCOMPARE(output.subject(), QStringLiteral("KFileMetaData Тема"));
    QCOMPARE(output.keywords(), QStringLiteral("KFileMetaData теги"));
    QCOMPARE(output.documentComment(), QStringLiteral("KFileMetaData описание"));
    QVERIFY(output.generatorInformation().contains(QStringLiteral("LibreOffice")));

    QDateTime dt(QDate(2024, 02, 13), QTime(21, 35, 00, 000));
    QCOMPARE(output.created(), dt);
}

void EncodingTest::testUnicodeFileWithWin1251Text()
{
    Reader reader;

    QVERIFY(reader.fileName().isEmpty());

    QString fileName = testFilePath("test_win1251_text.rtf");

    bool result = reader.open(fileName);
    QVERIFY(result);
    QCOMPARE(reader.fileName(), fileName);

    QTextDocument doc;
    TextDocumentRtfOutput output(&doc);

    reader.parseTo(&output);

    QVERIFY(!doc.isEmpty());

    QCOMPARE(doc.toPlainText().trimmed(), QStringLiteral("Test file for KFileMetaData."));

    QCOMPARE(output.author(), QStringLiteral("KFileMetaData Author"));
    QCOMPARE(output.title(), QStringLiteral("KFileMetaData Title"));
    QCOMPARE(output.subject(), QStringLiteral("KFileMetaData Subject"));
    QCOMPARE(output.keywords(), QStringLiteral("KFileMetaData keyword"));
    QCOMPARE(output.documentComment(), QStringLiteral("KFileMetaData description"));

    QDateTime dt(QDate(2024, 02, 14), QTime(17, 51, 00, 000));
    QCOMPARE(output.created(), dt);
    QCOMPARE(output.numberOfPages(), 1);
    QCOMPARE(output.numberOfWords(), 4);
}

void EncodingTest::testWin1251Cyrillic_data()
{
    QTest::addColumn<QString>("fileName");

    QTest::newRow("unicode file with win-1251 cyrillic text (type B)") << QStringLiteral("test_win1251_text_cyrillic.rtf");
    QTest::newRow("file with windows-1251 encoding and cyrillic text (type C)") << QStringLiteral("test_win1251_file_cyrillic.rtf");
}

void EncodingTest::testWin1251Cyrillic()
{
    QFETCH(QString, fileName);

    const QString path = testFilePath(fileName);

    Reader reader;

    QVERIFY(reader.fileName().isEmpty());

    bool result = reader.open(path);
    QVERIFY(result);
    QCOMPARE(reader.fileName(), path);

    QTextDocument doc;
    TextDocumentRtfOutput output(&doc);

    reader.parseTo(&output);

    QVERIFY(!doc.isEmpty());

    QCOMPARE(doc.toPlainText().trimmed(), QStringLiteral("Тестовый файл для KFileMetaData."));

    QCOMPARE(output.author(), QStringLiteral("KFileMetaData Автор"));
    QCOMPARE(output.title(), QStringLiteral("KFileMetaData Название"));
    QCOMPARE(output.subject(), QStringLiteral("KFileMetaData Тема"));
    QCOMPARE(output.keywords(), QStringLiteral("KFileMetaData теги"));
    QCOMPARE(output.documentComment(), QStringLiteral("KFileMetaData описание"));

    QDateTime dt(QDate(2024, 02, 14), QTime(17, 52, 00, 000));
    QCOMPARE(output.created(), dt);
}

QTEST_GUILESS_MAIN(EncodingTest)

#include "encodingtest.moc"
