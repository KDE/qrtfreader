/*
    SPDX-FileCopyrightText: 2008 Brad Hards <bradh@frogmouth.net>

    SPDX-License-Identifier: BSD-2-Clause
*/

#ifndef BASICTEST_H
#define BASICTEST_H

#include <QObject>

class BasicTest : public QObject
{
    Q_OBJECT

private:
    QString testFilePath(const QString &fileName) const;

private Q_SLOTS:
    void create();
    void createViaNew();
    void openDocument();
    void closeDocument();
    void openNonExistentFile();
    void parseSimpleFile();
    void parseDecoratedFile();
    void parseNonExistentMetadataValues();
};

#endif
