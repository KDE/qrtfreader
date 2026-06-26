// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "AuthorPcdataDestination_p.h"

#include "AbstractRtfOutput.h"

namespace QRtfReader
{
AuthorPcdataDestination::AuthorPcdataDestination(AbstractRtfOutput *output, const QString &name)
    : PcdataDestination(output, name)
{
}

AuthorPcdataDestination::~AuthorPcdataDestination() = default;

void AuthorPcdataDestination::aboutToEndDestination()
{
    m_output->setAuthor(m_pcdata);
}
}
