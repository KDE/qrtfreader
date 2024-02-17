/*
    SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>

    SPDX-License-Identifier: BSD-2-Clause
*/

#include "textformattingtest.h"
#include "qrtfreadertestsconfig.h"

#include <QTest>

#include "Reader.h"
#include "TextDocumentRtfOutput.h"

using namespace QRtfReader;

QString TextFormattingTest::testFilePath(const QString &fileName) const
{
    return QStringLiteral(TESTS_SAMPLE_FILES_PATH) + QLatin1Char('/') + fileName;
}

void TextFormattingTest::parseTextFormattingFile()
{
    Reader *reader = new Reader;

    QVERIFY(reader->fileName().isEmpty());

    QString fileName = testFilePath("rtf_formatting.rtf");

    bool result = reader->open(fileName);
    QVERIFY(result);
    QCOMPARE(reader->fileName(), fileName);

    QTextDocument doc;
    TextDocumentRtfOutput output(&doc);

    reader->parseTo(&output);

    QVERIFY(!doc.isEmpty());

    QString expectedText("Rich Text Format Test\n\n");
    expectedText.append("Created in Word 2010\n\n");
    expectedText.append("Some left aligned text. This should be the default.\n");
    expectedText.append("Some right aligned text. Not exactly default stuff.\n");
    expectedText.append("Some centred text. Usually for headings and posters, etc.\n");
    expectedText.append(QString("Some fully justified text. You"));
    expectedText.append(QChar(0x2019)); // right quote
    expectedText.append(QString("ll need a couple of lines for this to show up correctly. It"));
    expectedText.append(QChar(0x2019));
    expectedText.append(QString("s a bit hard to see the difference if there isn"));
    expectedText.append(QChar(0x2019));
    expectedText.append(QString("t enough text to show this.\n"));
    expectedText.append(QString("Some text with an indent from the left. You"));
    expectedText.append(QChar(0x2019));
    expectedText.append(QString("ll need a couple of lines for this to show up correctly. It"));
    expectedText.append(QChar(0x2019));
    expectedText.append(QString("s a bit hard to see the difference if there isn"));
    expectedText.append(QChar(0x2019));
    expectedText.append(QString("t enough text to show this.\n"));
    expectedText.append(QString("Some text with a bigger indent from the left. You"));
    expectedText.append(QChar(0x2019));
    expectedText.append(QString("ll need a couple of lines for this to show up correctly. It"));
    expectedText.append(QChar(0x2019));
    expectedText.append(QString("s a bit hard to see the difference if there isn"));
    expectedText.append(QChar(0x2019));
    expectedText.append(QString("t enough text to show this.\n"));
    expectedText.append(QString("Some text with an indent from the right. You"));
    expectedText.append(QChar(0x2019));
    expectedText.append(QString("ll need a couple of lines for this to show up correctly. It"));
    expectedText.append(QChar(0x2019));
    expectedText.append(QString("s a bit hard to see the difference if there isn"));
    expectedText.append(QChar(0x2019));
    expectedText.append(QString("t enough text to show this.\n"));
    expectedText.append(QString("Some text with an indent from the left and right. You"));
    expectedText.append(QChar(0x2019));
    expectedText.append(QString("ll need a couple of lines for this to show up correctly. It"));
    expectedText.append(QChar(0x2019));
    expectedText.append(QString("s a bit hard to see the difference if there isn"));
    expectedText.append(QChar(0x2019));
    expectedText.append(QString("t enough text to show this.\n"));
    expectedText.append("Some more standard text.\n");
    expectedText.append("A stray heading1\n");
    expectedText.append("Or heading2.\n\n");

    // QCOMPARE( doc.toPlainText(), expectedText );
    QVERIFY(doc.toPlainText().startsWith(expectedText));

    QCOMPARE(output.author(), QString("win7work;Brad Hards"));
    QCOMPARE(output.operatorName(), QString("win7work"));
    QCOMPARE(output.title(), QString("RTF Test of Formatting"));
    QCOMPARE(output.subject(), QString("Test Case"));
    QCOMPARE(output.managerName(), QString("Tha' boss.;Another boss."));
    QCOMPARE(output.category(), QString("Test, Example, Formatting"));
    QCOMPARE(output.comment(), QString(""));
    QCOMPARE(output.companyName(), QString("Konqi Enterprises"));
    QCOMPARE(output.documentComment(), QString("A quick test case knocked up to check the format operations."));
    QCOMPARE(output.keywords(), QString("Test Tag1, Tag2"));
    QCOMPARE(output.generatorInformation(), QString(""));
    QCOMPARE(output.hLinkBase(), QString("http://www.example.com"));
    QCOMPARE(output.totalEditingTime(), 18);
    QCOMPARE(output.versionNumber(), 3);
    QCOMPARE(output.internalVersionNumber(), 49247);
    QCOMPARE(output.numberOfPages(), 1);
    QCOMPARE(output.numberOfWords(), 174);
    QCOMPARE(output.numberOfCharacters(), 993);
    QCOMPARE(output.numberOfCharactersWithoutSpaces(), 1165);
    QCOMPARE(output.userPropNames().count(), 5);
    QVERIFY(output.userPropNames().contains("Department"));
    QCOMPARE(output.userProp("Department").toString(), QString("Development"));
    QVERIFY(output.userPropNames().contains("Editor"));
    QCOMPARE(output.userProp("Editor").toString(), QString("Brad"));
    QVERIFY(output.userPropNames().contains("MyProp"));
    QCOMPARE(output.userProp("MyProp").toString(), QString("Special Property Value"));
    QVERIFY(output.userPropNames().contains("License"));
    // It is really LGPL version 2 or later, I just made a typo in the example file.
    QCOMPARE(output.userProp("License").toString(), QString("LPGLv2+"));
    QVERIFY(output.userPropNames().contains("Project"));
    QCOMPARE(output.userProp("Project").toString(), QString("RTF Parsing"));

    delete reader;
}

QTEST_GUILESS_MAIN(TextFormattingTest)

#include "moc_textformattingtest.cpp"
