// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "CommentPcdataDestination_p.h"

namespace QRtfReader
{
CommentPcdataDestination::CommentPcdataDestination(AbstractRtfOutput *output, const QString &name)
    : PcdataDestination(output, name)
{
}

CommentPcdataDestination::~CommentPcdataDestination() = default;

void CommentPcdataDestination::aboutToEndDestination()
{
    m_output->setComment(m_pcdata);
}
}
