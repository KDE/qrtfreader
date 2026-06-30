// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_INFOPRINTEDTIMEDESTINATION_P_H
#define RTFREADER_INFOPRINTEDTIMEDESTINATION_P_H

#include "InfoTimeDestination_p.h"

#include "qrtfreader_export.h"

class QString;

namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT InfoPrintedTimeDestination : public InfoTimeDestination
{
public:
    InfoPrintedTimeDestination(AbstractRtfOutput *output, const QString &name);

    ~InfoPrintedTimeDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
