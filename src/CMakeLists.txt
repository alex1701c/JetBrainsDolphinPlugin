add_definitions(-DTRANSLATION_DOMAIN=\"jetbrainsdolphinplugin\")

set(jetbrainsdolphinplugin_SRCS jetbrainsdolphinplugin.cpp jetbrains-api/JetbrainsApplication.cpp jetbrains-api/SettingsDirectory.cpp)
add_library(jetbrainsdolphinplugin MODULE ${jetbrainsdolphinplugin_SRCS})
target_link_libraries(jetbrainsdolphinplugin KF5::KIOCore KF5::KIOWidgets)

install(FILES jetbrainsdolphinplugin.desktop DESTINATION ${KDE_INSTALL_KSERVICES5DIR})
install(TARGETS jetbrainsdolphinplugin DESTINATION ${KDE_INSTALL_QTPLUGINDIR})

#Icon downloaded from https://icon-icons.com/icon/jetbrains-toolbox/93803#64
set(JETBRAINS_ICON_INSTALL_DIR "/usr/share/pixmaps/" CACHE STRING "Default icon directory")
install(FILES jetbrains.png DESTINATION ${JETBRAINS_ICON_INSTALL_DIR})
