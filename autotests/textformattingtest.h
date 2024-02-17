/*
    SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>

    SPDX-License-Identifier: BSD-2-Clause
*/

#ifndef TEXTFORMATTINGTEST_H
#define TEXTFORMATTINGTEST_H

#include <QObject>

class TextFormattingTest : public QObject
{
    Q_OBJECT

private:
    QString testFilePath(const QString &fileName) const;

private Q_SLOTS:
    void parseTextFormattingFile();
};

#endif
