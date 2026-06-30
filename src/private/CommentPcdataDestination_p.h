// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_COMMENTPCDATADESTINATION_P_H
#define RTFREADER_COMMENTPCDATADESTINATION_P_H

#include "PcdataDestination_p.h"

#include "qrtfreader_export.h"

class QString;

namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT CommentPcdataDestination : public PcdataDestination
{
public:
    CommentPcdataDestination(AbstractRtfOutput *output, const QString &name);

    ~CommentPcdataDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
