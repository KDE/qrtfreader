// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "CompanyPcdataDestination.h"

#include "Reader.h"

namespace QRtfReader
{
CompanyPcdataDestination::CompanyPcdataDestination(AbstractRtfOutput *output, const QString &name)
    : PcdataDestination(output, name)
{
}

CompanyPcdataDestination::~CompanyPcdataDestination() = default;

void CompanyPcdataDestination::aboutToEndDestination()
{
    m_output->setCompanyName(m_pcdata);
}
}
