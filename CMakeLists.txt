cmake_minimum_required(VERSION 3.16.0)

project(jetbrainsservicemenu)

set(CMAKE_PROJECT_VERSION "1.4.0")
set(KF_MIN_VERSION "5.105.0")
set(KDE_COMPILERSETTINGS_LEVEL "5.82.0")

find_package(ECM ${KF_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(QtVersionOption)
include(KDEClangFormat)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(FeatureSummary)

find_package(KF${QT_MAJOR_VERSION} REQUIRED COMPONENTS KIO)

add_subdirectory(src)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)

# CPack configuration
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Plugin to open folders in Dolphin with the Jetbrains IDEs")
set(CPACK_PACKAGE_NAME dolphin-${CMAKE_PROJECT_NAME})
set(CPACK_PACKAGE_VERSION "1.2.0")
set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "alex1701c")
set(CPACK_RPM_PACKAGE_ARCHITECTURE "x86_64")
SET(CPACK_GENERATOR "DEB;RPM")

set(KIO_VERSION "${KF${QT_MAJOR_VERSION}KIO_VERSION}")
set(CPACK_PACKAGE_FILE_NAME ${CMAKE_PROJECT_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_OS}-plasma${QT_MAJOR_VERSION})
# Then names of dependencies and paths might differ
if (CPACK_OS STREQUAL "ubuntu")
	set(CPACK_DEBIAN_PACKAGE_DEPENDS "libkf${QT_MAJOR_VERSION}kiowidgets${QT_MAJOR_VERSION} (>=${KIO_VERSION})")
	set(CPACK_GENERATOR "DEB")
elseif(CPACK_OS STREQUAL "fedora" OR CPACK_OS STREQUAL "opensuse")
	set(CPACK_RPM_PACKAGE_REQUIRES "kf${QT_MAJOR_VERSION}-kio-widgets >= ${KIO_VERSION}")
	set(CPACK_GENERATOR "RPM")
else()
  unset(CPACK_PACKAGE_FILE_NAME)
endif()

INCLUDE(CPack)
