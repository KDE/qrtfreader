// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "ManagerPcdataDestination_p.h"

#include "AbstractRtfOutput.h"

namespace QRtfReader
{
ManagerPcdataDestination::ManagerPcdataDestination(AbstractRtfOutput *output, const QString &name)
    : PcdataDestination(output, name)
{
}

ManagerPcdataDestination::~ManagerPcdataDestination() = default;

void ManagerPcdataDestination::aboutToEndDestination()
{
    m_output->setManagerName(m_pcdata);
}
}
