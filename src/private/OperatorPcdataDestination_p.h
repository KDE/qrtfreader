// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_OPERATORPCDATADESTINATION_H
#define RTFREADER_OPERATORPCDATADESTINATION_H

#include <QColor>
#include <QString>

#include "PcdataDestination_p.h"
#include "qrtfreader_export.h"
namespace QRtfReader
{
class QRTFREADER_EXPORT OperatorPcdataDestination : public PcdataDestination
{
public:
    OperatorPcdataDestination(AbstractRtfOutput *output, const QString &name);

    ~OperatorPcdataDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
