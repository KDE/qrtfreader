// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_HLINKBASEPCDATADESTINATION_H
#define RTFREADER_HLINKBASEPCDATADESTINATION_H

#include "PcdataDestination_p.h"

#include <QString>

#include "qrtfreader_export.h"
namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT HLinkBasePcdataDestination : public PcdataDestination
{
public:
    HLinkBasePcdataDestination(AbstractRtfOutput *output, const QString &name);

    ~HLinkBasePcdataDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
