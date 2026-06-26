// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "OperatorPcdataDestination_p.h"

#include "AbstractRtfOutput.h"
#include "PcdataDestination_p.h"

#include <QString>

namespace QRtfReader
{
OperatorPcdataDestination::OperatorPcdataDestination(AbstractRtfOutput *output, const QString &name)
    : PcdataDestination(output, name)
{
}

OperatorPcdataDestination::~OperatorPcdataDestination() = default;

void OperatorPcdataDestination::aboutToEndDestination()
{
    m_output->setOperatorName(m_pcdata);
}
}
