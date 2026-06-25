// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "IgnoredDestination_p.h"

#include "Reader.h"

namespace QRtfReader
{
IgnoredDestination::IgnoredDestination(AbstractRtfOutput *output, const QString &name)
    : Destination(output, name)
{
}

IgnoredDestination::~IgnoredDestination() = default;

void IgnoredDestination::handleControlWord(const QByteArray &controlWord, bool hasValue, const int value)
{
    Q_UNUSED(controlWord);
    Q_UNUSED(hasValue);
    Q_UNUSED(value);
}

void IgnoredDestination::handlePlainText(const QByteArray &plainText)
{
    Q_UNUSED(plainText);
}

void IgnoredDestination::aboutToEndDestination()
{
}
}
