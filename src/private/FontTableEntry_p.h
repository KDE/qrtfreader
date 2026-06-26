// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_FONTTABLEENTRY_P_H
#define RTFREADER_FONTTABLEENTRY_P_H

#include <QSharedData>
#include <QString>

#include "FontTableEntry.h"

#include "qrtfreader_export.h"

namespace QRtfReader
{
class QRTFREADER_EXPORT FontTableEntryPrivate : public QSharedData
{
public:
    FontFamily m_fontFamily = FontFamily::Nil;
    FontPitch m_fontPitch = FontPitch::Default;
    QString m_fontName;
    QString m_encoding;
};
}

#endif
