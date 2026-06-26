// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_INFOREVISEDTIMEDESTINATION_H
#define RTFREADER_INFOREVISEDTIMEDESTINATION_H

#include "InfoTimeDestination_p.h"

#include <QString>

#include "qrtfreader_export.h"
namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT InfoRevisedTimeDestination : public InfoTimeDestination
{
public:
    InfoRevisedTimeDestination(AbstractRtfOutput *output, const QString &name);

    ~InfoRevisedTimeDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
