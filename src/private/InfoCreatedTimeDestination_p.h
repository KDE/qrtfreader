// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_INFOCREATEDTIMEDESTINATION_P_H
#define RTFREADER_INFOCREATEDTIMEDESTINATION_P_H

#include "InfoTimeDestination_p.h"

#include <QString>

#include "qrtfreader_export.h"
namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT InfoCreatedTimeDestination : public InfoTimeDestination
{
public:
    InfoCreatedTimeDestination(AbstractRtfOutput *output, const QString &name);

    ~InfoCreatedTimeDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
