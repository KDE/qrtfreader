// SPDX-FileCopyrightText: 2008 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: BSD-2-Clause

#pragma once

#include <QString>

#include "qrtfreader_export.h"
namespace QRtfReader
{

/**
   Representation of an RTF Control Word
*/
class QRTFREADER_EXPORT ControlWord
{
public:
    /**
       Constructor
    */
    explicit ControlWord(const QString &name);

    /**
       Test whether this control word is a supported destination
    */
    [[nodiscard]] bool isSupportedDestination() const;

    /**
       Test whether a control word name is a destination (even if we don't support it)
    */
    static bool isDestination(const QString &controlword);

    /**
       Test whether this control word is one we recognise
    */
    [[nodiscard]] bool isKnown() const;

private:
    QString m_name;
};

}
