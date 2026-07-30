#
#   SPDX-FileCopyrightText: 2010 Brad Hards <bradh@frogmouth.net>
#   SPDX-FileCopyrightText: 2026 Sergey Katunin <sulmpx60@yandex.ru>
#
#   SPDX-License-Identifier: BSD-2-Clause
#

cmake_minimum_required(VERSION 3.16)

project(QRtfReader VERSION 1.0.0)

set(REQUIRED_KF6_VERSION "6.0.0")
set(REQUIRED_QT_VERSION 6.5.0)

set(CMAKE_CXX_STANDARD 20)

find_package(ECM ${REQUIRED_KF6_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ECM_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")

include(FeatureSummary)
include(KDEInstallDirs)
include(KDECMakeSettings NO_POLICY_SCOPE)
set(KDE_COMPILERSETTINGS_LEVEL 5.84.0) # set before including
include(KDECompilerSettings NO_POLICY_SCOPE)
include(ECMGenerateHeaders)
include(ECMGenerateExportHeader)
include(ECMQtDeclareLoggingCategory)
include(ECMAddTests)

include(KDEClangFormat)
file(GLOB_RECURSE ALL_CLANG_FORMAT_SOURCE_FILES *.cpp *.h)
kde_clang_format(${ALL_CLANG_FORMAT_SOURCE_FILES})

include(KDEGitCommitHooks)
kde_configure_git_pre_commit_hook(CHECKS CLANG_FORMAT)

set(CMAKECONFIG_NAME "QRtfReader")

include(ECMSetupVersion)
ecm_setup_version(PROJECT
    VARIABLE_PREFIX QRTFREADER
    VERSION_HEADER "${CMAKE_CURRENT_BINARY_DIR}/src/qrtfreader_version.h"
    PACKAGE_VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/${CMAKECONFIG_NAME}ConfigVersion.cmake"
    SOVERSION 1
)

find_package(Qt6 ${REQUIRED_QT_VERSION} REQUIRED Core Gui)

set(CMAKECONFIG_INSTALL_DIR "${KDE_INSTALL_CMAKEPACKAGEDIR}/${CMAKECONFIG_NAME}")

include(CMakePackageConfigHelpers)
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/${CMAKECONFIG_NAME}Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${CMAKECONFIG_NAME}Config.cmake"
    INSTALL_DESTINATION ${CMAKECONFIG_INSTALL_DIR}
)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)

add_subdirectory(src)

if (BUILD_TESTING)
    add_subdirectory(autotests)
endif()

