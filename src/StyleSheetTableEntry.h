// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_STYLESHEETTABLEENTRY_H
#define RTFREADER_STYLESHEETTABLEENTRY_H

#include <QSharedDataPointer>
#include <QString>
#include <Qt>

#include "qrtfreader_export.h"

namespace QRtfReader
{
enum class TextAlignment {
    LeftAligned,
    CentreAligned,
    RightAligned,
    Justified,
    Distributed
};
class StyleSheetTableEntryPrivate;
class QRTFREADER_EXPORT StyleSheetTableEntry
{
public:
    StyleSheetTableEntry();
    StyleSheetTableEntry(const StyleSheetTableEntry &);
    virtual ~StyleSheetTableEntry();

    StyleSheetTableEntry &operator=(const StyleSheetTableEntry &);

    [[nodiscard]] TextAlignment textAlignment() const;
    void setTextAlignment(TextAlignment textAlignment);

    [[nodiscard]] int leftIndent() const;
    void setLeftIndent(int leftIndent);

    [[nodiscard]] int rightIndent() const;
    void setRightIndent(int rightIndent);

    [[nodiscard]] int topMargin() const;
    void setTopMargin(int topMargin);

    [[nodiscard]] Qt::LayoutDirection layoutDirection() const;
    void setLayoutDirection(Qt::LayoutDirection layoutDirection);

    [[nodiscard]] QString styleName() const;
    void setStyleName(const QString &styleName);

private:
    QSharedDataPointer<StyleSheetTableEntryPrivate> d;
};
}

#endif
