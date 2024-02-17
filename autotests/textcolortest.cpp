/*
    SPDX-FileCopyrightText: 2008 Brad Hards <bradh@frogmouth.net>

    SPDX-License-Identifier: BSD-2-Clause
*/

#include "textcolortest.h"
#include "qrtfreadertestsconfig.h"

#include <QTest>

#include "Reader.h"
#include "TextDocumentRtfOutput.h"

using namespace QRtfReader;

QString TextColorTest::testFilePath(const QString &fileName) const
{
    return QStringLiteral(TESTS_SAMPLE_FILES_PATH) + QLatin1Char('/') + fileName;
}

void TextColorTest::parseTextColorFile()
{
    Reader reader;

    QVERIFY(reader.fileName().isEmpty());

    QString fileName = testFilePath("text_color.rtf");

    bool result = reader.open(fileName);
    QVERIFY(result);
    QCOMPARE(reader.fileName(), fileName);

    QTextDocument doc;
    TextDocumentRtfOutput output(&doc);

    reader.parseTo(&output);

    QVERIFY(!doc.isEmpty());

    QString expectedText("The quick brown fox jumps over the lazy dog.\n\n");
    expectedText.append("This text is colored Brown.\n");
    expectedText.append("This text is colored Olive Green.\n");
    expectedText.append("This text is colored Dark Green.\n");
    expectedText.append("This text is colored Dark Teal.\n");
    expectedText.append("This text is colored Dark Blue.\n");
    expectedText.append("This text is colored Indigo.\n");
    expectedText.append("This text is colored Gray-80%.\n");
    expectedText.append("This text is colored Dark Red.\n");
    expectedText.append("This text is colored Orange.\n");
    expectedText.append("This text is colored Dark Yellow.\n");
    expectedText.append("This text is colored Green.\n");
    expectedText.append("This text is colored Teal.\n");
    expectedText.append("This text is colored Blue.\n");
    expectedText.append("This text is colored Blue-Gray.\n");
    expectedText.append("This text is colored Gray-50%.\n");
    expectedText.append("This text is colored Red.\n");
    expectedText.append("This text is colored Light Orange.\n");
    expectedText.append("This text is colored Lime.\n");
    expectedText.append("This text is colored Sea Green.\n");
    expectedText.append("This text is colored Aqua.\n");
    expectedText.append("This text is colored Light Blue.\n");
    expectedText.append("This text is colored Violet.\n");
    expectedText.append("This text is colored Gray-40%.\n");
    expectedText.append("This text is colored Pink.\n");
    expectedText.append("This text is colored Gold.\n");
    expectedText.append("This text is colored Yellow.\n");
    expectedText.append("This text is colored Bright Green.\n");
    expectedText.append("This text is colored turquoise.\n");
    expectedText.append("This text is colored Sky Blue.\n");
    expectedText.append("This text is colored Plum.\n");
    expectedText.append("This text is colored Gray-25%.\n");
    expectedText.append("This text is colored Rose.\n");
    expectedText.append("This text is colored Tan.\n");
    expectedText.append("This text is colored Light Yellow.\n");
    expectedText.append("This text is colored Light Green.\n");
    expectedText.append("This text is colored Light Turquoise.\n");
    expectedText.append("This text is colored Pale Blue.\n");
    expectedText.append("This text is colored Lavender.\n");
    expectedText.append("This text is colored White.\n");
    expectedText.append("\nEnd colored text.\n");

    QCOMPARE(doc.toPlainText(), expectedText);

    QCOMPARE(output.author(), QString("daines"));
    QCOMPARE(output.operatorName(), QString("daines"));
    QCOMPARE(output.title(), QString("The quick brown fox jumps over the lazy dog"));
    QCOMPARE(output.generatorInformation(), QString("Microsoft Word 11.0.6359"));
    QCOMPARE(output.totalEditingTime(), 12);
    QCOMPARE(output.versionNumber(), 1);
    QCOMPARE(output.internalVersionNumber(), 24703);
    QCOMPARE(output.numberOfPages(), 1);
    QCOMPARE(output.numberOfWords(), 187);
    QCOMPARE(output.numberOfCharacters(), 1066);
    QCOMPARE(output.numberOfCharactersWithoutSpaces(), 1251);
}

QTEST_GUILESS_MAIN(TextColorTest)

#include "moc_textcolortest.cpp"
