/*
    SPDX-FileCopyrightText: 2008 Brad Hards <bradh@frogmouth.net>

    SPDX-License-Identifier: BSD-2-Clause
*/

#ifndef PICTURETEST_H
#define PICTURETEST_H

#include <QObject>

class PictureTest : public QObject
{
    Q_OBJECT

private:
    QString testFilePath(const QString &fileName) const;

private Q_SLOTS:
    void parsePictureFile();
};

#endif
