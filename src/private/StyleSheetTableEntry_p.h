// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_STYLESHEETTABLEENTRY_P_H
#define RTFREADER_STYLESHEETTABLEENTRY_P_H

#include <QSharedData>
#include <QString>

#include "StyleSheetTableEntry.h"
#include "qrtfreader_export.h"

namespace QRtfReader
{
class QRTFREADER_EXPORT StyleSheetTableEntryPrivate : public QSharedData
{
public:
    QString m_styleName;
    TextAlignment m_textAlignment = TextAlignment::LeftAligned;
    int m_leftIndent = 0;
    int m_rightIndent = 0;
    int m_topMargin = 0;
    Qt::LayoutDirection m_layoutDirection = Qt::LeftToRight;
};
}

#endif
