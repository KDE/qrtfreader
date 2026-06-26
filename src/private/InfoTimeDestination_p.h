// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_INFOTIMEDESTINATION_H
#define RTFREADER_INFOTIMEDESTINATION_H

#include "Destination_p.h"

#include <QByteArray>
#include <QString>

#include "qrtfreader_export.h"
namespace QRtfReader
{
class QRTFREADER_EXPORT InfoTimeDestination : public Destination
{
public:
    InfoTimeDestination(AbstractRtfOutput *output, const QString &name);

    ~InfoTimeDestination() override;

    void handleControlWord(const QByteArray &controlWord, bool hasValue, const int value) override;
    void handlePlainText(const QByteArray &plainText) override;
    void aboutToEndDestination() override = 0;

protected:
    QDateTime dateTime() const;

private:
    int m_year;
    int m_month;
    int m_day;
    int m_hour;
    int m_minute;
};
}

#endif
