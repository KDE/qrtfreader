// SPDX-FileCopyrightText: 2008, 2010 Brad Hards <bradh@frogmouth.net>
// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef RTFREADER_ABSTRACTRTFOUTPUT_P_H
#define RTFREADER_ABSTRACTRTFOUTPUT_P_H

#include <QDateTime>
#include <QString>
#include <QVariant>

#include "qrtfreader_export.h"

namespace QRtfReader
{
class QRTFREADER_EXPORT AbstractRtfOutputPrivate
{
public:
    // The author of the document (from document meta-data, if any)
    QString m_author;

    // The company of the author of the document (from document meta-data, if any)
    QString m_companyName;

    // The operator of the document (from document meta-data, if any)
    QString m_operatorName;

    // The title of the document (from document meta-data, if any)
    QString m_title;

    // The subject of the document (from document meta-data, if any)
    QString m_subject;

    // The category (or categories) of the document (from document meta-data, if any)
    QString m_category;

    // The manager(s) of the author of the document (from document meta-data, if any)
    QString m_managerName;

    // The comment associated with the document (from document meta-data, if any)
    QString m_comment;

    // The document comment (from document meta-data, if any)
    QString m_documentComment;

    // The keywords associated with the document (from document meta-data, if any)
    QString m_keywords;

    // The hyperlink base associated with this document (path or URL)
    QString m_hlinkbase;

    // The date and time this document was created (from document meta-data, if any)
    QDateTime m_created;

    // The date and time this document was revised (from document meta-data, if any)
    QDateTime m_revised;

    // The generator of this document (from document meta-data, if any)
    QString m_generatorInformation;

    // The date and time this document was printed (from document meta-data, if any)
    QDateTime m_printed;

    // The total editing time for the document (from document meta-data, if any)
    int m_totalEditingTime = -1;

    // The number of pages in the document (from document meta-data, if any)
    int m_numberOfPages = -1;

    // The number of words in the document (from document meta-data, if any)
    int m_numberOfWords = -1;

    // The number of characters in the document (from document meta-data, if any)
    int m_numberOfCharacters = -1;

    // The number of characters (without spaces) in the document (from document meta-data, if any)
    int m_numberOfCharactersWithoutSpaces = -1;

    // The version of the document (from document meta-data, if any)
    int m_versionNumber = -1;

    // The internal version of the document (from document meta-data, if any)
    int m_internalVersionNumber = -1;

    // User properties dictionary (from document meta-data, if any)
    QHash<QString, QVariant> m_userProps;
};
}

#endif
