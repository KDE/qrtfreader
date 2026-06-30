// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_COLORTABLEDESTINATION_P_H
#define RTFREADER_COLORTABLEDESTINATION_P_H

#include "Destination_p.h"

#include <QColor>

#include "qrtfreader_export.h"

class QString;
class QByteArray;

namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT ColorTableDestination : public Destination
{
public:
    ColorTableDestination(AbstractRtfOutput *output, const QString &name);

    ~ColorTableDestination() override;

    void handleControlWord(const QByteArray &controlWord, bool hasValue, int value) override;
    void handlePlainText(const QByteArray &plainText) override;

private:
    void resetCurrentColor();

    // The colour that is currently being built
    QColor m_currentColor;
    bool m_colorSet;
};
}

#endif
