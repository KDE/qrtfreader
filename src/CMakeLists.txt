#
#   SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
#   SPDX-FileCopyrightText: 2024 Sergey Katunin <sulmpx60@yandex.ru>
#
#   SPDX-License-Identifier: BSD-2-Clause
#

ecm_qt_declare_logging_category(debug_SRCS
    HEADER qrtfreader_debug.h
    IDENTIFIER lcRtf
    CATEGORY_NAME qrtfreader
    DESCRIPTION "QRtfReader"
    EXPORT QRTFREADER
)

# To hide all the warnings from the generated itex2MML code
if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_GNUC)
    add_definitions(-Wno-unused-parameter)
endif ()

add_library(QRtfReader SHARED)
set_target_properties(QRtfReader PROPERTIES
    VERSION     ${QRTFREADER_VERSION}
    SOVERSION   ${QRTFREADER_SOVERSION}
    EXPORT_NAME QRtfReader
)

target_sources(QRtfReader PRIVATE
#public classes
    AbstractRtfOutput.h
    AbstractRtfOutput.cpp
    Reader.h
    Reader.cpp
    TextDocumentRtfOutput.h
    TextDocumentRtfOutput.cpp

    FontTableEntry.h
    FontTableEntry.cpp
    StyleSheetTableEntry.h
    StyleSheetTableEntry.cpp

#private parts of public classes
    private/AbstractRtfOutput_p.h
    private/Reader_p.h
    private/Reader_p.cpp
    private/TextDocumentRtfOutput_p.h
    private/TextDocumentRtfOutput_p.cpp

    private/FontTableEntry_p.h
    private/StyleSheetTableEntry_p.h

#private classes
    private/AuthorPcdataDestination_p.h
    private/AuthorPcdataDestination.cpp
    private/CategoryPcdataDestination_p.h
    private/CategoryPcdataDestination.cpp
    private/ColorTableDestination_p.h
    private/ColorTableDestination.cpp
    private/CommentPcdataDestination_p.h
    private/CommentPcdataDestination.cpp
    private/CompanyPcdataDestination_p.h
    private/CompanyPcdataDestination.cpp
    private/ControlWord_p.h
    private/ControlWord.cpp
    private/Destination_p.h
    private/Destination.cpp
    private/DocumentCommentPcdataDestination_p.h
    private/DocumentCommentPcdataDestination.cpp
    private/DocumentDestination_p.h
    private/DocumentDestination.cpp
    private/FontTableDestination_p.h
    private/FontTableDestination.cpp
    private/GeneratorPcdataDestination_p.h
    private/GeneratorPcdataDestination.cpp
    private/HLinkBasePcdataDestination_p.h
    private/HLinkBasePcdataDestination.cpp
    private/IgnoredDestination_p.h
    private/IgnoredDestination.cpp
    private/InfoDestination_p.h
    private/InfoDestination.cpp
    private/InfoTimeDestination_p.h
    private/InfoTimeDestination.cpp
    private/InfoCreatedTimeDestination_p.h
    private/InfoCreatedTimeDestination.cpp
    private/InfoPrintedTimeDestination_p.h
    private/InfoPrintedTimeDestination.cpp
    private/InfoRevisedTimeDestination_p.h
    private/InfoRevisedTimeDestination.cpp
    private/KeywordsPcdataDestination_p.h
    private/KeywordsPcdataDestination.cpp
    private/ManagerPcdataDestination_p.h
    private/ManagerPcdataDestination.cpp
    private/OperatorPcdataDestination_p.h
    private/OperatorPcdataDestination.cpp
    private/PcdataDestination_p.h
    private/PcdataDestination.cpp
    private/PictDestination_p.h
    private/PictDestination.cpp
    private/RtfGroupState_p.h
    private/StyleSheetDestination_p.h
    private/StyleSheetDestination.cpp
    private/SubjectPcdataDestination_p.h
    private/SubjectPcdataDestination.cpp
    private/TitlePcdataDestination_p.h
    private/TitlePcdataDestination.cpp
    private/Token_p.h
    private/Token.cpp
    private/Tokenizer_p.h
    private/Tokenizer.cpp
    private/UserPropsDestination_p.h
    private/UserPropsDestination.cpp
    ${debug_SRCS}
)

ecm_generate_export_header(QRtfReader
    VERSION ${QRTFREADER_VERSION}
    USE_VERSION_HEADER
)

target_include_directories(QRtfReader
    INTERFACE "$<INSTALL_INTERFACE:${KDE_INSTALL_INCLUDEDIR}/QRtfReader>"
)

target_link_libraries(QRtfReader
    PUBLIC
    Qt6::Core
    Qt6::Gui
)

ecm_generate_headers(QRtfReader_HEADERS
    ORIGINAL CAMELCASE
    HEADER_NAMES Reader
                 TextDocumentRtfOutput
                 AbstractRtfOutput
                 FontTableEntry
                 StyleSheetTableEntry
    REQUIRED_HEADERS QRtfReader_HEADERS
)

install(TARGETS QRtfReader EXPORT QRtfReaderTargets ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/qrtfreader_export.h
    ${CMAKE_CURRENT_BINARY_DIR}/qrtfreader_version.h
    ${QRtfReader_HEADERS}
    DESTINATION ${KDE_INSTALL_INCLUDEDIR}/QRtfReader COMPONENT Devel
)

install(FILES
    "${PROJECT_BINARY_DIR}/QRtfReaderConfig.cmake"
    "${PROJECT_BINARY_DIR}/QRtfReaderConfigVersion.cmake"
    DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
    COMPONENT Devel
)

install(EXPORT QRtfReaderTargets
    DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
    FILE QRtfReaderTargets.cmake
)

ecm_qt_install_logging_categories(
    EXPORT QRTFREADER
    FILE qrtfreader.categories
    DESTINATION ${KDE_INSTALL_LOGGINGCATEGORIESDIR}
)
