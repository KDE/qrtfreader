// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_COLORTABLEDESTINATION_H
#define RTFREADER_COLORTABLEDESTINATION_H

#include "Destination_p.h"

#include <QByteArray>
#include <QString>

#include "qrtfreader_export.h"
namespace QRtfReader
{
class QRTFREADER_EXPORT ColorTableDestination : public Destination
{
public:
    ColorTableDestination(AbstractRtfOutput *output, const QString &name);

    ~ColorTableDestination() override;

    void handleControlWord(const QByteArray &controlWord, bool hasValue, const int value) override;
    void handlePlainText(const QByteArray &plainText) override;

private:
    void resetCurrentColor();

    // The colour that is currently being built
    QColor m_currentColor;
    bool m_colorSet;
};
}

#endif
