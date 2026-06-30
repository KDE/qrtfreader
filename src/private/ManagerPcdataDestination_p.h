// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_MANAGERPCDATADESTINATION_P_H
#define RTFREADER_MANAGERPCDATADESTINATION_P_H

#include "PcdataDestination_p.h"

#include "qrtfreader_export.h"

class QString;

namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT ManagerPcdataDestination : public PcdataDestination
{
public:
    ManagerPcdataDestination(AbstractRtfOutput *output, const QString &name);

    ~ManagerPcdataDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
