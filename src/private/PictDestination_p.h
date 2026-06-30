// SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_PICTDESTINATION_P_H
#define RTFREADER_PICTDESTINATION_P_H

#include "Destination_p.h"

#include <QByteArray>
#include <QString>
#include <QTextImageFormat>
#include <QtTypes>

#include "qrtfreader_export.h"
namespace QRtfReader
{
class AbstractRtfOutput;
class QRTFREADER_EXPORT PictDestination : public Destination
{
public:
    PictDestination(AbstractRtfOutput *output, const QString &name);

    ~PictDestination() override;

    void handleControlWord(const QByteArray &controlWord, bool hasValue, int value) override;
    void handlePlainText(const QByteArray &plainText) override;
    void aboutToEndDestination() override;

private:
    // The hexadecimal version of the data for the image that is currently being built
    QByteArray m_pictData;

    // The format information for the current image
    QTextImageFormat m_imageFormat;
    const char *m_format = nullptr;
    qreal m_xScale = 1.;
    qreal m_yScale = 1.;
    qreal m_goalWidth = 0.;
    qreal m_goalHeight = 0.;
};
}

#endif
