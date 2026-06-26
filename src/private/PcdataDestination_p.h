// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_PCDATADESTINATION_H
#define RTFREADER_PCDATADESTINATION_H

#include "DocumentDestination_p.h"

#include <QByteArray>
#include <QString>

#include "qrtfreader_export.h"
namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT PcdataDestination : public DocumentDestination
{
public:
    PcdataDestination(AbstractRtfOutput *output, const QString &name);

    ~PcdataDestination() override;

    void handleControlWord(const QByteArray &controlWord, bool hasValue, int value) override;
    void handlePlainText(const QByteArray &plainText) override;
    void aboutToEndDestination() override = 0;

protected:
    QString m_pcdata;
};
}

#endif
