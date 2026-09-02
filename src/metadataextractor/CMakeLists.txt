# SPDX-FileCopyrightText: 2026 Carl Schwan <carl@carlschwan.eu>
# SPDX-License-Identifier: BSD-2-Clause

add_library(kfilemetadata_rtfextractor MODULE rtfextractor.cpp)

target_link_libraries(kfilemetadata_rtfextractor
    KF6::FileMetaData
    Qt6::Core
    Qt6::Gui
    QRtfReader
)

set_target_properties(kfilemetadata_rtfextractor PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/kf6/kfilemetadata")
install(TARGETS kfilemetadata_rtfextractor
    DESTINATION ${KDE_INSTALL_PLUGINDIR}/kf6/kfilemetadata)

if (BUILD_TESTING)
    add_subdirectory(autotests)
endif()
