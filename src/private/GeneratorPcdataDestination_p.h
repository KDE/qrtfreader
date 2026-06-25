// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_GENERATORPCDATADESTINATION_H
#define RTFREADER_GENERATORPCDATADESTINATION_H

#include <QColor>
#include <QString>

#include "PcdataDestination_p.h"
#include "qrtfreader_export.h"
namespace QRtfReader
{
class QRTFREADER_EXPORT GeneratorPcdataDestination : public PcdataDestination
{
public:
    GeneratorPcdataDestination(AbstractRtfOutput *output, const QString &name);

    ~GeneratorPcdataDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
