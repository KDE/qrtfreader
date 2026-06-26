// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_TITLEPCDATADESTINATION_H
#define RTFREADER_TITLEPCDATADESTINATION_H

#include "PcdataDestination_p.h"

#include <QColor>
#include <QString>

#include "qrtfreader_export.h"
namespace QRtfReader
{
class QRTFREADER_EXPORT TitlePcdataDestination : public PcdataDestination
{
public:
    TitlePcdataDestination(AbstractRtfOutput *output, const QString &name);

    ~TitlePcdataDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
