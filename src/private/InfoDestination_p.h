// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_INFODESTINATION_P_H
#define RTFREADER_INFODESTINATION_P_H

#include "Destination_p.h"

#include "qrtfreader_export.h"

class QString;
class QByteArray;

namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT InfoDestination : public Destination
{
public:
    InfoDestination(AbstractRtfOutput *output, const QString &name);

    ~InfoDestination() override;

    void handleControlWord(const QByteArray &controlWord, bool hasValue, int value) override;
    void handlePlainText(const QByteArray &plainText) override;

private:
};
}

#endif
