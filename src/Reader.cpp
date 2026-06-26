// SPDX-FileCopyrightText: 2008, 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "Reader.h"
#include "private/Reader_p.h"

#include "AbstractRtfOutput.h"

#include <QObject>
#include <QString>

namespace QRtfReader
{
Reader::Reader(QObject *parent)
    : QObject(parent)
    , d(new ReaderPrivate)
{
}

Reader::~Reader() = default;

bool Reader::open(const QString &filename)
{
    return d->open(filename);
}

void Reader::close()
{
    d->close();
}

QString Reader::fileName() const
{
    return d->fileName();
}

bool Reader::parseTo(AbstractRtfOutput *output)
{
    return d->parseTo(output);
}
}
