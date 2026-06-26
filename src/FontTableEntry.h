// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_FONTTABLEENTRY_H
#define RTFREADER_FONTTABLEENTRY_H

#include <QSharedDataPointer>
#include <QString>

#include "qrtfreader_export.h"

namespace QRtfReader
{
enum class FontFamily {
    Nil,
    Roman,
    Swiss,
    Modern,
    Script,
    Decor,
    Tech,
    Bidi
};

enum class FontPitch {
    Default = 0,
    Fixed = 1,
    Variable = 2
};
class FontTableEntryPrivate;
class QRTFREADER_EXPORT FontTableEntry
{
public:
    FontTableEntry();
    FontTableEntry(const FontTableEntry &);
    virtual ~FontTableEntry();

    FontTableEntry &operator=(const FontTableEntry &);

    FontFamily fontFamily() const;
    void setFontFamily(FontFamily fontFamily);

    FontPitch fontPitch() const;
    void setFontPitch(FontPitch fontPitch);

    QString fontName() const;
    void setFontName(const QString &fontName);

    QString encoding() const;
    void setEncoding(const QString &encoding);

private:
    QSharedDataPointer<FontTableEntryPrivate> d;
};
}

#endif
