#
#   SPDX-FileCopyrightText: 2024 Sergey Katunin <sulmpx60@yandex.ru>
#
#   SPDX-License-Identifier: BSD-2-Clause
#

find_package(Qt6 ${REQUIRED_QT_VERSION} CONFIG REQUIRED Test)

remove_definitions(-DQT_NO_CAST_FROM_ASCII)

configure_file(qrtfreadertestsconfig.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/qrtfreadertestsconfig.h @ONLY)

set(QRtfReaderAutotest_SRCS)
ecm_qt_declare_logging_category(QRtfReaderAutotest_SRCS
    HEADER qrtfreader_debug.h
    IDENTIFIER lcRtf
    CATEGORY_NAME qrtfreader
)

#
# Basic test
#
ecm_add_test(basictest.cpp
    TEST_NAME "basictest"
    LINK_LIBRARIES Qt6::Test QRtfReader
)

#
# Picture test
#
ecm_add_test(picturetest.cpp
    TEST_NAME "picturetest"
    LINK_LIBRARIES Qt6::Test QRtfReader
)

#
# Text color test
#
ecm_add_test(textcolortest.cpp
    TEST_NAME "textcolortest"
    LINK_LIBRARIES Qt6::Test QRtfReader
)

#
# Text formatting test
#
ecm_add_test(textformattingtest.cpp
    TEST_NAME "textformattingtest"
    LINK_LIBRARIES Qt6::Test QRtfReader
)

#
# Encoding test
#
ecm_add_test(encodingtest.cpp
    TEST_NAME "encodingtest"
    LINK_LIBRARIES Qt6::Test QRtfReader
)





