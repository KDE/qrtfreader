// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_COMPANYPCDATADESTINATION_H
#define RTFREADER_COMPANYPCDATADESTINATION_H

#include <QColor>
#include <QString>

#include "PcdataDestination.h"
#include "qrtfreader_export.h"
namespace QRtfReader
{
class QRTFREADER_EXPORT CompanyPcdataDestination : public PcdataDestination
{
public:
    CompanyPcdataDestination(AbstractRtfOutput *output, const QString &name);

    ~CompanyPcdataDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
