// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_AUTHORPCDATADESTINATION_P_H
#define RTFREADER_AUTHORPCDATADESTINATION_P_H

#include "PcdataDestination_p.h"

#include <QString>

#include "qrtfreader_export.h"
namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT AuthorPcdataDestination : public PcdataDestination
{
public:
    AuthorPcdataDestination(AbstractRtfOutput *output, const QString &name);

    ~AuthorPcdataDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
