// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_KEYWORDSPCDATADESTINATION_H
#define RTFREADER_KEYWORDSPCDATADESTINATION_H

#include "PcdataDestination_p.h"

#include <QString>

#include "qrtfreader_export.h"
namespace QRtfReader
{
class QRTFREADER_EXPORT KeywordsPcdataDestination : public PcdataDestination
{
public:
    KeywordsPcdataDestination(AbstractRtfOutput *output, const QString &name);

    ~KeywordsPcdataDestination() override;

    void aboutToEndDestination() override;
};
}

#endif
