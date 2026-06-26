// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "InfoCreatedTimeDestination_p.h"

#include "AbstractRtfOutput.h"
#include "InfoTimeDestination_p.h"

#include <QString>

namespace QRtfReader
{
InfoCreatedTimeDestination::InfoCreatedTimeDestination(AbstractRtfOutput *output, const QString &name)
    : InfoTimeDestination(output, name)
{
}

InfoCreatedTimeDestination::~InfoCreatedTimeDestination() = default;

void InfoCreatedTimeDestination::aboutToEndDestination()
{
    m_output->setCreatedDateTime(dateTime());
}
}
