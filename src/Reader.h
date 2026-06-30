// SPDX-FileCopyrightText: 2008, 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_READER_H
#define RTFREADER_READER_H

#include <QDebug>
#include <QObject>
#include <QScopedPointer>
#include <QTextDocument>

#include "qrtfreader_export.h"
/**
   Namespace for the public interface for the QRtfReader classes
*/
namespace QRtfReader
{
class AbstractRtfOutput;
class RtfProperty;
class Destination;
class RtfGroupState;
class Tokenizer;

class ReaderPrivate;
/**
   Reader for RTF formatted documents

   This class provides a simple API for reading documents
   encoded in the Microsoft Rich Text Format (RTF).

   TODO: add spec reference
*/
class QRTFREADER_EXPORT Reader : public QObject
{
    Q_OBJECT
public:
    /**
       Normal constructor
    */
    explicit Reader(QObject *parent = nullptr);

    /**
       Open a document

       \param filename the name of the document to open

       \return true if the document was successfully opened, otherwise false
    */
    bool open(const QString &filename);

    /**
       Close the open document

       This has no effect if the document is not open.
    */
    void close();

    /**
       The name of the file that is open.

       Will return an empty string if no file is open.
    */
    [[nodiscard]] QString fileName() const;

    /**
       Parse the document

       \param output pointer to an output implementation
    */
    bool parseTo(AbstractRtfOutput *output);

    ~Reader() override;

    /////////////////////////////////////////////////
    //
    // Callback functions
    //
    ////////////////////////////////////////////////
    void startInfo();

    void todo(QRtfReader::RtfProperty *property);
    void todoDest(QRtfReader::RtfProperty *property);

private:
    const QScopedPointer<ReaderPrivate> d;
};
}

#endif
