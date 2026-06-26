// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_DOCUMENTDESTINATION_H
#define RTFREADER_DOCUMENTDESTINATION_H

#include "Destination_p.h"

#include <QByteArray>
#include <QString>

#include "qrtfreader_export.h"
namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT DocumentDestination : public Destination
{
public:
    DocumentDestination(AbstractRtfOutput *output, const QString &name);

    ~DocumentDestination() override;

    void handleControlWord(const QByteArray &controlWord, bool hasValue, int value) override;
    void handlePlainText(const QByteArray &plainText) override;
    void aboutToEndDestination() override;

protected:
    int m_charactersToSkip;
    int m_unicodeSkip;
};
}

#endif
