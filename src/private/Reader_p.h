// SPDX-FileCopyrightText: 2008, 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_READER_P_H
#define RTFREADER_READER_P_H

#include <QStack>
#include <QString>

#include "qrtfreader_export.h"

class QFile;

namespace QRtfReader
{
class AbstractRtfOutput;
class Destination;
class RtfGroupState;
class Tokenizer;

class QRTFREADER_EXPORT ReaderPrivate
{
public:
    ReaderPrivate();
    virtual ~ReaderPrivate();

    /////////////////////////////////////////////////
    //
    // Implementation details
    //
    ////////////////////////////////////////////////

    bool open(const QString &filename);

    void close();

    [[nodiscard]] QString fileName() const;

    // parse the document
    bool parseTo(AbstractRtfOutput *output);

    // parse the RTF file, inserting elements into the document
    // being generated
    void parseFile();

    // parse the file header section, including sanity checks
    static bool parseFileHeader(Tokenizer &tokenizer);

    // check the file header for format / version compatibility
    static bool headerFormatIsKnown(const QString &tokenName, int tokenValue);

    // parse the body of the document
    void parseDocument(Tokenizer &tokenizer);

    // Change the destination
    void changeDestination(const QString &destinationName);

    // Destination factory
    [[nodiscard]] Destination *makeDestination(const QString &destinationName) const;

    /////////////////////////////////////////////////
    //
    // Member variables below
    //
    ////////////////////////////////////////////////

    // The name of the file that is open (if any)
    QFile *m_inputDevice = nullptr;

    // The output strategy
    AbstractRtfOutput *m_output = nullptr;

    // The destination stack
    QStack<Destination *> m_destinationStack;

    QStack<RtfGroupState> m_stateStack;

    // debug things
    QString m_debugIndent;
};
}

#endif
