// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_INFOCREATEDTIMEDESTINATION_H
#define RTFREADER_INFOCREATEDTIMEDESTINATION_H

#include <QColor>
#include <QString>

#include "InfoTimeDestination.h"
#include "qrtfreader_export.h"
namespace QRtfReader
{
class QRTFREADER_EXPORT InfoCreatedTimeDestination : public InfoTimeDestination
{
public:
    InfoCreatedTimeDestination(AbstractRtfOutput *output, const QString &name);

    ~InfoCreatedTimeDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
