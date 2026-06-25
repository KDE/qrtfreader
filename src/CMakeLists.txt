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
    Reader.cpp
    TextDocumentRtfOutput.cpp
    AbstractRtfOutput.cpp
    private/ControlWord.cpp
    private/AuthorPcdataDestination.cpp
    private/CategoryPcdataDestination.cpp
    private/ColorTableDestination.cpp
    private/CommentPcdataDestination.cpp
    private/CompanyPcdataDestination.cpp
    private/Destination.cpp
    private/DocumentCommentPcdataDestination.cpp
    private/DocumentDestination.cpp
    private/FontTableDestination.cpp
    private/GeneratorPcdataDestination.cpp
    private/HLinkBasePcdataDestination.cpp
    private/IgnoredDestination.cpp
    private/InfoDestination.cpp
    private/InfoTimeDestination.cpp
    private/InfoCreatedTimeDestination.cpp
    private/InfoPrintedTimeDestination.cpp
    private/InfoRevisedTimeDestination.cpp
    private/KeywordsPcdataDestination.cpp
    private/ManagerPcdataDestination.cpp
    private/OperatorPcdataDestination.cpp
    private/PcdataDestination.cpp
    private/PictDestination.cpp
    private/SubjectPcdataDestination.cpp
    private/StyleSheetDestination.cpp
    private/TitlePcdataDestination.cpp
    private/Token.cpp
    private/Tokenizer.cpp
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
