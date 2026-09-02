// SPDX-FileCopyrightText: 2024 Sergey Katunin <sulmpx60@yandex.ru>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "../rtfextractor.h"
#include "../../../autotests/qrtfreadertestsconfig.h"

#include <KFileMetaData/MimeUtils>
#include <KFileMetaData/SimpleExtractionResult>

#include <QMimeDatabase>
#include <QObject>
#include <QTest>

using namespace KFileMetaData;

class RtfExtractorTest : public QObject
{
    Q_OBJECT
private:
    QString testFilePath(const QString &fileName) const;

private Q_SLOTS:
    void testNoExtraction_data();
    void testNoExtraction();

    void testLibreOffice();
    void testLibreOfficeCyrillic();

    void testWin1251Text();

    void testWin1251Cyrillic_data();
    void testWin1251Cyrillic();

    void testLibreOfficeMetaDataOnly_data();
    void testLibreOfficeMetaDataOnly();

    void testWin1251MetaDataOnly_data();
    void testWin1251MetaDataOnly();

private:
    QMimeDatabase mimeDb;
};

QString RtfExtractorTest::testFilePath(const QString &fileName) const
{
    return QLatin1String(TESTS_SAMPLE_FILES_PATH) + QLatin1Char('/') + fileName;
}

void RtfExtractorTest::testNoExtraction_data()
{
    QTest::addColumn<QString>("fileName");

    QTest::newRow("libreoffice file with unicode latin text") << QStringLiteral("test_libreoffice.rtf");
    QTest::newRow("libreoffice file with unicode cyrillic text") << QStringLiteral("test_libreoffice_cyrillic.rtf");
    QTest::newRow("unicode file with win-1251 latin text") << QStringLiteral("test_win1251_text.rtf");
    QTest::newRow("unicode file with win-1251 cyrillic text") << QStringLiteral("test_win1251_text_cyrillic.rtf");
}

void RtfExtractorTest::testNoExtraction()
{
    QFETCH(QString, fileName);

    RtfExtractor plugin{this};

    const QString path = testFilePath(fileName);
    const QString mimeType = MimeUtils::strictMimeType(path, mimeDb).name();
    QVERIFY(plugin.mimetypes().contains(mimeType));

    SimpleExtractionResult result(path, mimeType, ExtractionResult::ExtractNothing);
    plugin.extract(&result);

    QCOMPARE(result.types().size(), 1);
    QCOMPARE(result.types().at(0), Type::Document);
    QCOMPARE(result.properties().size(), 0);
}

void RtfExtractorTest::testLibreOffice()
{
    RtfExtractor plugin{this};

    const QString path = testFilePath(QStringLiteral("test_libreoffice.rtf"));
    const QString mimeType = MimeUtils::strictMimeType(path, mimeDb).name();
    QVERIFY(plugin.mimetypes().contains(mimeType));

    SimpleExtractionResult result(path, mimeType);
    plugin.extract(&result);

    QCOMPARE(result.types().size(), 1);
    QCOMPARE(result.types().at(0), Type::Document);

    QCOMPARE(result.properties().value(Property::Title), QVariant(QStringLiteral("KFileMetaData Title")));
    QCOMPARE(result.properties().value(Property::Subject), QVariant(QStringLiteral("KFileMetaData Subject")));
    QCOMPARE(result.properties().value(Property::Keywords), QVariant(QStringLiteral("KFileMetaData keyword")));
    QCOMPARE(result.properties().value(Property::Description), QVariant(QStringLiteral("KFileMetaData description")));
    QVERIFY(result.properties().value(Property::Generator).toString().contains(QStringLiteral("LibreOffice")));

    QDateTime dt(QDate(2024, 02, 13), QTime(21, 35, 00, 000));
    QCOMPARE(result.properties().value(Property::CreationDate), QVariant(dt));

    QCOMPARE(result.text().trimmed(), QStringLiteral("Test file for KFileMetaData."));
    QCOMPARE(result.properties().size(), 6);
}

void RtfExtractorTest::testLibreOfficeCyrillic()
{
    RtfExtractor plugin{this};

    const QString path = testFilePath(QStringLiteral("test_libreoffice_cyrillic.rtf"));
    const QString mimeType = MimeUtils::strictMimeType(path, mimeDb).name();
    QVERIFY(plugin.mimetypes().contains(mimeType));

    SimpleExtractionResult result(path, mimeType);
    plugin.extract(&result);

    QCOMPARE(result.types().size(), 1);
    QCOMPARE(result.types().at(0), Type::Document);

    QCOMPARE(result.properties().value(Property::Title), QVariant(QStringLiteral("KFileMetaData Название")));
    QCOMPARE(result.properties().value(Property::Subject), QVariant(QStringLiteral("KFileMetaData Тема")));
    QCOMPARE(result.properties().value(Property::Keywords), QVariant(QStringLiteral("KFileMetaData теги")));
    QCOMPARE(result.properties().value(Property::Description), QVariant(QStringLiteral("KFileMetaData описание")));
    QVERIFY(result.properties().value(Property::Generator).toString().contains(QStringLiteral("LibreOffice")));

    QDateTime dt(QDate(2024, 02, 13), QTime(21, 35, 00, 000));
    QCOMPARE(result.properties().value(Property::CreationDate), QVariant(dt));

    QCOMPARE(result.text().trimmed(), QStringLiteral("Тестовый файл для KFileMetaData."));
    QCOMPARE(result.properties().size(), 6);
}

void RtfExtractorTest::testWin1251Text()
{
    RtfExtractor plugin{this};

    const QString path = testFilePath(QStringLiteral("test_win1251_text.rtf"));
    const QString mimeType = MimeUtils::strictMimeType(path, mimeDb).name();
    QVERIFY(plugin.mimetypes().contains(mimeType));

    SimpleExtractionResult result(path, mimeType);
    plugin.extract(&result);

    QCOMPARE(result.types().size(), 1);
    QCOMPARE(result.types().at(0), Type::Document);

    QCOMPARE(result.properties().value(Property::Author), QVariant(QStringLiteral("KFileMetaData Author")));
    QCOMPARE(result.properties().value(Property::Title), QVariant(QStringLiteral("KFileMetaData Title")));
    QCOMPARE(result.properties().value(Property::Subject), QVariant(QStringLiteral("KFileMetaData Subject")));
    QCOMPARE(result.properties().value(Property::Keywords), QVariant(QStringLiteral("KFileMetaData keyword")));
    QCOMPARE(result.properties().value(Property::Description), QVariant(QStringLiteral("KFileMetaData description")));

    // TODO: 1
    QDateTime dt(QDate(2024, 02, 14), QTime(17, 51, 00, 000));
    QCOMPARE(result.properties().value(Property::CreationDate), QVariant(dt));

    QCOMPARE(result.properties().value(Property::PageCount), QVariant(1));
    QCOMPARE(result.properties().value(Property::WordCount), QVariant(4));

    QCOMPARE(result.text().trimmed(), QStringLiteral("Test file for KFileMetaData."));
    QCOMPARE(result.properties().size(), 8);
}

void RtfExtractorTest::testWin1251Cyrillic_data()
{
    QTest::addColumn<QString>("fileName");

    QTest::newRow("unicode file with win-1251 cyrillic text") << QStringLiteral("test_win1251_text_cyrillic.rtf");
    QTest::newRow("file with windows-1251 encoding and cyrillic text") << QStringLiteral("test_win1251_file_cyrillic.rtf");
}

void RtfExtractorTest::testWin1251Cyrillic()
{
    QFETCH(QString, fileName);

    RtfExtractor plugin{this};

    const QString path = testFilePath(fileName);
    const QString mimeType = MimeUtils::strictMimeType(path, mimeDb).name();
    QVERIFY(plugin.mimetypes().contains(mimeType));

    SimpleExtractionResult result(path, mimeType);
    plugin.extract(&result);

    QCOMPARE(result.types().size(), 1);
    QCOMPARE(result.types().at(0), Type::Document);

    QCOMPARE(result.properties().value(Property::Author), QVariant(QStringLiteral("KFileMetaData Автор")));
    QCOMPARE(result.properties().value(Property::Title), QVariant(QStringLiteral("KFileMetaData Название")));
    QCOMPARE(result.properties().value(Property::Subject), QVariant(QStringLiteral("KFileMetaData Тема")));
    QCOMPARE(result.properties().value(Property::Keywords), QVariant(QStringLiteral("KFileMetaData теги")));
    QCOMPARE(result.properties().value(Property::Description), QVariant(QStringLiteral("KFileMetaData описание")));

    // TODO: 2
    QDateTime dt(QDate(2024, 02, 14), QTime(17, 52, 00, 000));
    QCOMPARE(result.properties().value(Property::CreationDate), QVariant(dt));

    QCOMPARE(result.properties().value(Property::PageCount), QVariant(1));
    QCOMPARE(result.properties().value(Property::WordCount), QVariant(4));

    QCOMPARE(result.text().trimmed(), QStringLiteral("Тестовый файл для KFileMetaData."));
    QCOMPARE(result.properties().size(), 8);
}

void RtfExtractorTest::testLibreOfficeMetaDataOnly_data()
{
    QTest::addColumn<QString>("fileName");

    QTest::newRow("libreoffice file with unicode latin text") << QStringLiteral("test_libreoffice.rtf");
    QTest::newRow("libreoffice file with unicode cyrillic text") << QStringLiteral("test_libreoffice_cyrillic.rtf");
}

void RtfExtractorTest::testLibreOfficeMetaDataOnly()
{
    QFETCH(QString, fileName);

    RtfExtractor plugin{this};

    SimpleExtractionResult result(testFilePath(fileName), QStringLiteral("application/rtf"), ExtractionResult::ExtractMetaData);
    plugin.extract(&result);

    QCOMPARE(result.types().size(), 1);
    QCOMPARE(result.properties().size(), 6);
    QVERIFY(result.text().isEmpty());
}

void RtfExtractorTest::testWin1251MetaDataOnly_data()
{
    QTest::addColumn<QString>("fileName");

    QTest::newRow("unicode file with win-1251 cyrillic text") << QStringLiteral("test_win1251_text_cyrillic.rtf");
    QTest::newRow("file with windows-1251 encoding and cyrillic text") << QStringLiteral("test_win1251_file_cyrillic.rtf");
}

void RtfExtractorTest::testWin1251MetaDataOnly()
{
    QFETCH(QString, fileName);

    RtfExtractor plugin{this};

    SimpleExtractionResult result(testFilePath(fileName), QStringLiteral("application/rtf"), ExtractionResult::ExtractMetaData);
    plugin.extract(&result);

    QCOMPARE(result.types().size(), 1);
    QCOMPARE(result.properties().size(), 8);
    QVERIFY(result.text().isEmpty());
}

QTEST_GUILESS_MAIN(RtfExtractorTest)

#include "rtfextractortest.moc"
