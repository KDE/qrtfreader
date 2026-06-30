// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_IGNOREDDESTINATION_P_H
#define RTFREADER_IGNOREDDESTINATION_P_H

#include "Destination_p.h"

#include "qrtfreader_export.h"

class QString;
class QByteArray;

namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT IgnoredDestination : public Destination
{
public:
    IgnoredDestination(AbstractRtfOutput *output, const QString &name);

    ~IgnoredDestination() override;

    void handleControlWord(const QByteArray &controlWord, bool hasValue, int value) override;
    void handlePlainText(const QByteArray &plainText) override;
    void aboutToEndDestination() override;
};
}

#endif
