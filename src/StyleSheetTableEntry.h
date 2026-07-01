// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_STYLESHEETTABLEENTRY_H
#define RTFREADER_STYLESHEETTABLEENTRY_H

#include <QSharedDataPointer>
#include <QString>
#include <Qt>
#include <QtTypes>

#include "qrtfreader_export.h"

/**
   Namespace for the public interface for the QRtfReader classes
*/
namespace QRtfReader
{
enum class TextAlignment : quint8 {
    LeftAligned,
    CentreAligned,
    RightAligned,
    Justified,
    Distributed,
};
class StyleSheetTableEntryPrivate;
/**
   Entry in the style sheet table
*/
class QRTFREADER_EXPORT StyleSheetTableEntry
{
public:
    StyleSheetTableEntry();
    StyleSheetTableEntry(const StyleSheetTableEntry &);
    virtual ~StyleSheetTableEntry();

    StyleSheetTableEntry &operator=(const StyleSheetTableEntry &);

    /**
      The text alignment.
    */
    [[nodiscard]] TextAlignment textAlignment() const;
    void setTextAlignment(TextAlignment textAlignment);

    /**
      The left margin (indentation).
    */
    [[nodiscard]] int leftIndent() const;
    void setLeftIndent(int leftIndent);

    /**
      The right margin (indentation).
    */
    [[nodiscard]] int rightIndent() const;
    void setRightIndent(int rightIndent);

    /**
      The top margin.
    */
    [[nodiscard]] int topMargin() const;
    void setTopMargin(int topMargin);

    /**
      Layout directions (Left-To-Right, Right-To-Left).
    */
    [[nodiscard]] Qt::LayoutDirection layoutDirection() const;
    void setLayoutDirection(Qt::LayoutDirection layoutDirection);

    /**
      The name of the style.
    */
    [[nodiscard]] QString styleName() const;
    void setStyleName(const QString &styleName);

private:
    QSharedDataPointer<StyleSheetTableEntryPrivate> d;
};
}

#endif
