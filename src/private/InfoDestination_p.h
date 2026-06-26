// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_INFODESTINATION_H
#define RTFREADER_INFODESTINATION_H

#include "Destination_p.h"

#include <QByteArray>
#include <QString>

#include "qrtfreader_export.h"
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
