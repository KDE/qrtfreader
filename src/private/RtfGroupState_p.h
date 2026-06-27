// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_RTFGROUPSTATE_H
#define RTFREADER_RTFGROUPSTATE_H
#include "qrtfreader_export.h"
namespace QRtfReader
{
class QRTFREADER_EXPORT RtfGroupState
{
public:
    RtfGroupState() = default;
    bool didChangeDestination = false;
    bool endOfFile = false;
};
}

#endif
