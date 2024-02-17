/*
    SPDX-FileCopyrightText: 2008 Brad Hards <bradh@frogmouth.net>

    SPDX-License-Identifier: BSD-2-Clause
*/

#ifndef TEXTCOLORTEST_H
#define TEXTCOLORTEST_H

#include <QObject>

class TextColorTest : public QObject
{
    Q_OBJECT

private:
    QString testFilePath(const QString &fileName) const;

private Q_SLOTS:
    void parseTextColorFile();
};

#endif
