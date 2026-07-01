// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_FONTTABLEENTRY_H
#define RTFREADER_FONTTABLEENTRY_H

#include <QSharedDataPointer>
#include <QString>
#include <QtTypes>

#include "qrtfreader_export.h"

/**
   Namespace for the public interface for the QRtfReader classes
*/
namespace QRtfReader
{
enum class FontFamily : quint8 {
    Nil,
    Roman,
    Swiss,
    Modern,
    Script,
    Decor,
    Tech,
    Bidi,
};

enum class FontPitch : quint8 {
    Default = 0,
    Fixed = 1,
    Variable = 2,
};
class FontTableEntryPrivate;
/**
   Entry in the font table
*/
class QRTFREADER_EXPORT FontTableEntry
{
public:
    FontTableEntry();
    FontTableEntry(const FontTableEntry &);
    virtual ~FontTableEntry();

    FontTableEntry &operator=(const FontTableEntry &);

    /**
      Font family.
    */
    [[nodiscard]] FontFamily fontFamily() const;
    void setFontFamily(FontFamily fontFamily);

    /**
      Font pitch (fprq).
    */
    [[nodiscard]] FontPitch fontPitch() const;
    void setFontPitch(FontPitch fontPitch);

    /**
      Font name.
    */
    [[nodiscard]] QString fontName() const;
    void setFontName(const QString &fontName);

    /**
      Text encoding (fcharset).
    */
    [[nodiscard]] QString encoding() const;
    void setEncoding(const QString &encoding);

private:
    QSharedDataPointer<FontTableEntryPrivate> d;
};
}

#endif
