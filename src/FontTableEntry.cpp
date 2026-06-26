// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "FontTableEntry.h"
#include "private/FontTableEntry_p.h"

#include <QString>

namespace QRtfReader
{

FontTableEntry::FontTableEntry()
    : d(new FontTableEntryPrivate)
{
}

FontTableEntry::FontTableEntry(const FontTableEntry &other)
{
    d = other.d;
}

FontTableEntry::~FontTableEntry() = default;

FontTableEntry &FontTableEntry::operator=(const FontTableEntry &other)
{
    d = other.d;
    return *this;
}

FontFamily FontTableEntry::fontFamily() const
{
    return d->m_fontFamily;
}

void FontTableEntry::setFontFamily(FontFamily fontFamily)
{
    d->m_fontFamily = fontFamily;
}

FontPitch FontTableEntry::fontPitch() const
{
    return d->m_fontPitch;
}

void FontTableEntry::setFontPitch(FontPitch fontPitch)
{
    d->m_fontPitch = fontPitch;
}

QString FontTableEntry::fontName() const
{
    return d->m_fontName;
}

void FontTableEntry::setFontName(const QString &fontName)
{
    d->m_fontName = fontName;
}

QString FontTableEntry::encoding() const
{
    return d->m_encoding;
}

void FontTableEntry::setEncoding(const QString &encoding)
{
    d->m_encoding = encoding;
}
}
