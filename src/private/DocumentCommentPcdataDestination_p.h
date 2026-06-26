// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_DOCUMENTCOMMENTPCDATADESTINATION_H
#define RTFREADER_DOCUMENTCOMMENTPCDATADESTINATION_H

#include "PcdataDestination_p.h"

#include <QString>

#include "qrtfreader_export.h"
namespace QRtfReader
{
class QRTFREADER_EXPORT DocumentCommentPcdataDestination : public PcdataDestination
{
public:
    DocumentCommentPcdataDestination(AbstractRtfOutput *output, const QString &name);

    ~DocumentCommentPcdataDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
