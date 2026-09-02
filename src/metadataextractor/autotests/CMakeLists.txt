# SPDX-FileCopyrightText: 2024 Sergey Katunin <sulmpx60@yandex.ru>
# SPDX-License-Identifier: BSD-2-Clause

ecm_add_test(rtfextractortest.cpp ../rtfextractor.cpp
    TEST_NAME "rtfextractortest"
    LINK_LIBRARIES
        Qt6::Test
        KF6::FileMetaData
        Qt6::Core
        Qt6::Gui
        QRtfReader
)
