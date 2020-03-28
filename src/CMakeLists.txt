add_definitions(-DTRANSLATION_DOMAIN=\"jetbrainsdolphinplugin\")

add_subdirectory(jetbrains-api)

add_library(jetbrainsdolphinplugin MODULE jetbrainsdolphinplugin.cpp)
target_link_libraries(jetbrainsdolphinplugin KF5::KIOCore KF5::KIOWidgets)
target_link_libraries(jetbrainsdolphinplugin jetbrains_api_static)

install(FILES jetbrainsdolphinplugin.desktop DESTINATION ${KDE_INSTALL_KSERVICES5DIR})
install(TARGETS jetbrainsdolphinplugin DESTINATION ${KDE_INSTALL_QTPLUGINDIR})

#Icon downloaded from https://icon-icons.com/icon/jetbrains-toolbox/93803#64
set(JETBRAINS_ICON_INSTALL_DIR "/usr/share/pixmaps/" CACHE STRING "Default icon directory")
install(FILES jetbrains.png DESTINATION ${JETBRAINS_ICON_INSTALL_DIR})
