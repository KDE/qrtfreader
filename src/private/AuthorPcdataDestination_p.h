// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_AUTHORPCDATADESTINATION_H
#define RTFREADER_AUTHORPCDATADESTINATION_H

#include <QColor>
#include <QString>

#include "PcdataDestination_p.h"
#include "qrtfreader_export.h"
namespace QRtfReader
{
class QRTFREADER_EXPORT AuthorPcdataDestination : public PcdataDestination
{
public:
    AuthorPcdataDestination(AbstractRtfOutput *output, const QString &name);

    ~AuthorPcdataDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
