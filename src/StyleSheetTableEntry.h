// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_STYLESHEETTABLEENTRY_H
#define RTFREADER_STYLESHEETTABLEENTRY_H
#include "qrtfreader_export.h"

#include <QSharedDataPointer>
#include <Qt>

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

    TextAlignment textAlignment() const;
    void setTextAlignment(TextAlignment textAlignment);

    int leftIndent() const;
    void setLeftIndent(const int leftIndent);

    int rightIndent() const;
    void setRightIndent(const int rightIndent);

    int topMargin() const;
    void setTopMargin(const int topMargin);

    Qt::LayoutDirection layoutDirection() const;
    void setLayoutDirection(const Qt::LayoutDirection layoutDirection);

    QString styleName() const;
    void setStyleName(const QString &styleName);

private:
    QSharedDataPointer<StyleSheetTableEntryPrivate> d;
};
}

#endif
