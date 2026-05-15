#
#   SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>    
#   SPDX-FileCopyrightText: 2024 Sergey Katunin <sulmpx60@yandex.ru>
#
#   SPDX-License-Identifier: BSD-2-Clause
#

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
install(TARGETS QRtfReader ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

target_sources(QRtfReader PRIVATE
    rtfdebug.cpp
    Reader.cpp
    controlword.cpp
    AbstractRtfOutput.cpp
    AuthorPcdataDestination.cpp
    CategoryPcdataDestination.cpp
    ColorTableDestination.cpp
    CommentPcdataDestination.cpp
    CompanyPcdataDestination.cpp
    Destination.cpp
    DocumentCommentPcdataDestination.cpp
    DocumentDestination.cpp
    FontTableDestination.cpp
    GeneratorPcdataDestination.cpp
    HLinkBasePcdataDestination.cpp
    IgnoredDestination.cpp
    InfoDestination.cpp
    InfoTimeDestination.cpp
    InfoCreatedTimeDestination.cpp
    InfoPrintedTimeDestination.cpp
    InfoRevisedTimeDestination.cpp
    KeywordsPcdataDestination.cpp
    ManagerPcdataDestination.cpp
    OperatorPcdataDestination.cpp
    PcdataDestination.cpp
    PictDestination.cpp
    SubjectPcdataDestination.cpp
    StyleSheetDestination.cpp
    TextDocumentRtfOutput.cpp
    TitlePcdataDestination.cpp
    Token.cpp
    Tokenizer.cpp
    UserPropsDestination.cpp
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
