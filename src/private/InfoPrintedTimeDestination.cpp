// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "InfoPrintedTimeDestination_p.h"

#include "AbstractRtfOutput.h"
#include "InfoTimeDestination_p.h"

#include <QString>

namespace QRtfReader
{
InfoPrintedTimeDestination::InfoPrintedTimeDestination(AbstractRtfOutput *output, const QString &name)
    : InfoTimeDestination(output, name)
{
}

InfoPrintedTimeDestination::~InfoPrintedTimeDestination() = default;

void InfoPrintedTimeDestination::aboutToEndDestination()
{
    m_output->setPrintedDateTime(dateTime());
}
}
