// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_SUBJECTPCDATADESTINATION_H
#define RTFREADER_SUBJECTPCDATADESTINATION_H

#include <QColor>
#include <QString>

#include "PcdataDestination_p.h"
#include "qrtfreader_export.h"
namespace QRtfReader
{
class QRTFREADER_EXPORT SubjectPcdataDestination : public PcdataDestination
{
public:
    SubjectPcdataDestination(AbstractRtfOutput *output, const QString &name);

    ~SubjectPcdataDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
