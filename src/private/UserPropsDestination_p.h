// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_USERPROPSDESTINATION_H
#define RTFREADER_USERPROPSDESTINATION_H

#include "Destination_p.h"

#include <QColor>
#include <QMetaType>
#include <QString>
#include <QVariant>

#include "qrtfreader_export.h"
namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT UserPropsDestination : public Destination
{
public:
    UserPropsDestination(AbstractRtfOutput *output, const QString &name);

    ~UserPropsDestination() override;

    void handleControlWord(const QByteArray &controlWord, bool hasValue, int value) override;
    void handlePlainText(const QByteArray &plainText) override;

private:
    bool m_nextPlainTextIsPropertyName;
    QMetaType::Type m_propertyType;
    QString m_propertyName;
};
}

#endif
