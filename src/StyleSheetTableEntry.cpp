// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "StyleSheetTableEntry.h"
#include "private/StyleSheetTableEntry_p.h"

#include <QString>
#include <Qt>

namespace QRtfReader
{
StyleSheetTableEntry::StyleSheetTableEntry()
    : d(new StyleSheetTableEntryPrivate)
{
}

StyleSheetTableEntry::StyleSheetTableEntry(const StyleSheetTableEntry &other)
{
    d = other.d;
}

StyleSheetTableEntry::~StyleSheetTableEntry() = default;

StyleSheetTableEntry &StyleSheetTableEntry::operator=(const StyleSheetTableEntry &other)
{
    d = other.d;
    return *this;
}

TextAlignment StyleSheetTableEntry::textAlignment() const
{
    return d->m_textAlignment;
}

void StyleSheetTableEntry::setTextAlignment(TextAlignment textAlignment)
{
    d->m_textAlignment = textAlignment;
}

int StyleSheetTableEntry::leftIndent() const
{
    return d->m_leftIndent;
}

void StyleSheetTableEntry::setLeftIndent(const int leftIndent)
{
    d->m_leftIndent = leftIndent;
}

int StyleSheetTableEntry::rightIndent() const
{
    return d->m_rightIndent;
}

void StyleSheetTableEntry::setRightIndent(const int rightIndent)
{
    d->m_rightIndent = rightIndent;
}

int StyleSheetTableEntry::topMargin() const
{
    return d->m_topMargin;
}

void StyleSheetTableEntry::setTopMargin(const int topMargin)
{
    d->m_topMargin = topMargin;
}

Qt::LayoutDirection StyleSheetTableEntry::layoutDirection() const
{
    return d->m_layoutDirection;
}

void StyleSheetTableEntry::setLayoutDirection(const Qt::LayoutDirection layoutDirection)
{
    d->m_layoutDirection = layoutDirection;
}

QString StyleSheetTableEntry::styleName() const
{
    return d->m_styleName;
}

void StyleSheetTableEntry::setStyleName(const QString &styleName)
{
    d->m_styleName = styleName;
}
}
