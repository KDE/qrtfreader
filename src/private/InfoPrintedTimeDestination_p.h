// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_INFOPRINTEDTIMEDESTINATION_H
#define RTFREADER_INFOPRINTEDTIMEDESTINATION_H

#include "InfoTimeDestination_p.h"

#include <QString>

#include "qrtfreader_export.h"
namespace QRtfReader
{
class QRTFREADER_EXPORT InfoPrintedTimeDestination : public InfoTimeDestination
{
public:
    InfoPrintedTimeDestination(AbstractRtfOutput *output, const QString &name);

    ~InfoPrintedTimeDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
