// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_STYLESHEETDESTINATION_P_H
#define RTFREADER_STYLESHEETDESTINATION_P_H

#include "Destination_p.h"
#include "StyleSheetTableEntry.h"

#include <QtTypes>

#include "qrtfreader_export.h"

class QString;
class QByteArray;

namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT StyleSheetDestination : public Destination
{
public:
    StyleSheetDestination(AbstractRtfOutput *output, const QString &name);

    ~StyleSheetDestination() override;

    void handleControlWord(const QByteArray &controlWord, bool hasValue, int value) override;
    void handlePlainText(const QByteArray &plainText) override;
    void aboutToEndDestination() override;

protected:
    quint32 m_currentStyleHandleNumber;
    StyleSheetTableEntry m_style;
};
}

#endif
