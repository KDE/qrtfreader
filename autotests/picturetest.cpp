/*
    SPDX-FileCopyrightText: 2008 Brad Hards <bradh@frogmouth.net>

    SPDX-License-Identifier: BSD-2-Clause
*/

#include "picturetest.h"
#include "qrtfreadertestsconfig.h"

#include <QTest>
#include <QTextDocument>

#include "Reader.h"
#include "TextDocumentRtfOutput.h"

using namespace QRtfReader;

QString PictureTest::testFilePath(const QString &fileName) const
{
    return QStringLiteral(TESTS_SAMPLE_FILES_PATH) + QLatin1Char('/') + fileName;
}

void PictureTest::parsePictureFile()
{
    Reader *reader = new Reader;

    QVERIFY(reader->fileName().isEmpty());

    QString fileName = testFilePath("pict.rtf");

    bool result = reader->open(fileName);
    QVERIFY(result);
    QCOMPARE(reader->fileName(), fileName);

    QTextDocument doc;
    TextDocumentRtfOutput output(&doc);

    reader->parseTo(&output);

    QVERIFY(!doc.isEmpty());

    QVERIFY(doc.toPlainText().startsWith("Trying to include a picture.\n"));

    QCOMPARE(output.created(), QDateTime(QDate(2006, 6, 18), QTime(18, 18, 0)));
    QCOMPARE(output.revised(), QDateTime(QDate(1601, 1, 1), QTime(0, 0, 0)));
    QCOMPARE(output.printed(), QDateTime(QDate(1601, 1, 1), QTime(0, 0, 0)));
    QCOMPARE(output.author(), "Dave Davey");
    QCOMPARE(output.comment(), "StarWriter");

    delete reader;
}

QTEST_GUILESS_MAIN(PictureTest)

#include "moc_picturetest.cpp"
