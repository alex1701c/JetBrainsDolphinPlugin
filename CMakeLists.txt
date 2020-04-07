project(jetbrainsservicemenu)

cmake_minimum_required(VERSION 3.0.0)

set(KF5_MIN_VERSION "5.44.0")
find_package(ECM ${KF5_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_MODULE_PATH})

find_package(KF5 REQUIRED COMPONENTS KIO)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(FeatureSummary)

add_subdirectory(src)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)

# CPack configuration
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Plugin to open folders in Dolphin with the Jetbrains IDEs")
set(CPACK_PACKAGE_NAME dolphin-${CMAKE_PROJECT_NAME})
set(CPACK_PACKAGE_VERSION "1.0.1")
set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "alex1701c")
set(CPACK_RPM_PACKAGE_ARCHITECTURE "x86_64")
SET(CPACK_GENERATOR "DEB;RPM")
# KUbuntu 18.04 dependencies
set(CPACK_DEBIAN_PACKAGE_DEPENDS "kio (>= 5.44)")
set(CPACK_RPM_PACKAGE_ARCHITECTURE "x86_64")
set(CPACK_RPM_PACKAGE_REQUIRES "kio >= 5.44")

INCLUDE(CPack)
