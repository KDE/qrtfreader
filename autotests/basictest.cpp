/*
    SPDX-FileCopyrightText: 2008 Brad Hards <bradh@frogmouth.net>

    SPDX-License-Identifier: BSD-2-Clause
*/

#include "basictest.h"
#include "qrtfreadertestsconfig.h"

#include <QTest>
#include <QTextDocument>

#include "Reader.h"
#include "TextDocumentRtfOutput.h"

using namespace QRtfReader;

QString BasicTest::testFilePath(const QString &fileName) const
{
    return QStringLiteral(TESTS_SAMPLE_FILES_PATH) + QLatin1Char('/') + fileName;
}

void BasicTest::create()
{
    Reader reader;
}

void BasicTest::createViaNew()
{
    Reader *reader = new Reader;
    delete reader;
}

void BasicTest::openDocument()
{
    Reader reader;

    QVERIFY(reader.fileName().isEmpty());

    QString fileName = testFilePath("test0.rtf");

    bool result = reader.open(fileName);
    QVERIFY(result);
    QCOMPARE(reader.fileName(), fileName);
}

void BasicTest::closeDocument()
{
    Reader reader;

    // check nothing bad happens when we close a document that isn't open
    reader.close();

    QString fileName = testFilePath("test0.rtf");

    reader.open(fileName);
    QCOMPARE(reader.fileName(), fileName);

    reader.close();
    QVERIFY(reader.fileName().isEmpty());

    QTextDocument doc;
    TextDocumentRtfOutput output(&doc);

    reader.parseTo(&output);

    QVERIFY(doc.isEmpty());
}

void BasicTest::openNonExistentFile()
{
    Reader reader;

    bool result = reader.open("no such document.rtf");
    QVERIFY(!result);
    QVERIFY(reader.fileName().isEmpty());

    QTextDocument doc;
    TextDocumentRtfOutput output(&doc);

    reader.parseTo(&output);

    QVERIFY(doc.isEmpty());

    reader.close();
    QVERIFY(reader.fileName().isEmpty());
}

void BasicTest::parseSimpleFile()
{
    Reader reader;

    QVERIFY(reader.fileName().isEmpty());

    QString fileName = testFilePath("test0.rtf");

    bool result = reader.open(fileName);
    QVERIFY(result);
    QCOMPARE(reader.fileName(), fileName);

    QTextDocument doc;
    TextDocumentRtfOutput output(&doc);

    reader.parseTo(&output);

    QVERIFY(!doc.isEmpty());

    QCOMPARE(doc.toPlainText(), "Hello world\n");

    QCOMPARE(output.created(), QDateTime(QDate(2008, 3, 18), QTime(20, 4, 0)));
    QCOMPARE(output.revised().isValid(), false);
    QCOMPARE(output.printed().isValid(), false);
    QVERIFY(output.author().isEmpty());
    QCOMPARE(output.comment(), "StarWriter");
}

void BasicTest::parseDecoratedFile()
{
    Reader reader;

    QVERIFY(reader.fileName().isEmpty());

    QString fileName = testFilePath("test1.rtf");

    bool result = reader.open(fileName);
    QVERIFY(result);
    QCOMPARE(reader.fileName(), fileName);

    QTextDocument doc;
    TextDocumentRtfOutput output(&doc);

    reader.parseTo(&output);

    QVERIFY(!doc.isEmpty());

    QCOMPARE(doc.toPlainText(), QString("Hello bold new world\n"));

    QCOMPARE(output.created(), QDateTime(QDate(2008, 3, 18), QTime(20, 8, 0)));
    QCOMPARE(output.revised(), QDateTime(QDate(2008, 6, 25), QTime(17, 36, 0)));
    QCOMPARE(output.printed(), QDateTime(QDate(2008, 6, 25), QTime(17, 44, 0)));
    QVERIFY(output.author().isEmpty());
    QCOMPARE(output.comment(), QString("StarWriter and Xemacs"));
}

void BasicTest::parseNonExistentMetadataValues()
{
    Reader reader;

    QVERIFY(reader.fileName().isEmpty());

    QString fileName = testFilePath("test0.rtf");

    bool result = reader.open(fileName);
    QVERIFY(result);
    QCOMPARE(reader.fileName(), fileName);

    QTextDocument doc;
    TextDocumentRtfOutput output(&doc);

    reader.parseTo(&output);

    QVERIFY(!doc.isEmpty());

    // Non-empty values
    QCOMPARE(output.comment(), "StarWriter");
    QCOMPARE(output.created(), QDateTime(QDate(2008, 3, 18), QTime(20, 4, 0)));
    QCOMPARE(output.internalVersionNumber(), 6800);

    // Empty values
    QVERIFY(output.author().isEmpty());
    QVERIFY(output.companyName().isEmpty());
    QVERIFY(output.operatorName().isEmpty());
    QVERIFY(output.title().isEmpty());
    QVERIFY(output.subject().isEmpty());
    QVERIFY(output.category().isEmpty());
    QVERIFY(output.managerName().isEmpty());
    QVERIFY(output.documentComment().isEmpty());
    QVERIFY(output.keywords().isEmpty());
    QVERIFY(output.hLinkBase().isEmpty());
    QVERIFY(output.generatorInformation().isEmpty());

    QCOMPARE(output.revised().isValid(), false);
    QCOMPARE(output.printed().isValid(), false);

    QCOMPARE(output.totalEditingTime(), -1);
    QCOMPARE(output.numberOfPages(), -1);
    QCOMPARE(output.numberOfWords(), -1);
    QCOMPARE(output.numberOfCharacters(), -1);
    QCOMPARE(output.numberOfCharactersWithoutSpaces(), -1);
    QCOMPARE(output.versionNumber(), -1);

    QVERIFY(output.userProp(QStringLiteral("test")).isNull());
}

QTEST_GUILESS_MAIN(BasicTest)

#include "moc_basictest.cpp"
