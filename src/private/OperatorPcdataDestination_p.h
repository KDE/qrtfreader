// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_OPERATORPCDATADESTINATION_P_H
#define RTFREADER_OPERATORPCDATADESTINATION_P_H

#include "PcdataDestination_p.h"

#include "qrtfreader_export.h"

class QString;

namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT OperatorPcdataDestination : public PcdataDestination
{
public:
    OperatorPcdataDestination(AbstractRtfOutput *output, const QString &name);

    ~OperatorPcdataDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
