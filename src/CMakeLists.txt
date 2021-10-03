add_definitions(-DTRANSLATION_DOMAIN=\"jetbrainsdolphinplugin\")

add_subdirectory(jetbrains-api)

kcoreaddons_add_plugin(jetbrainsdolphinplugin SOURCES jetbrainsdolphinplugin.cpp INSTALL_NAMESPACE kf5/kfileitemaction)
target_link_libraries(jetbrainsdolphinplugin KF5::KIOCore KF5::KIOWidgets)
target_link_libraries(jetbrainsdolphinplugin jetbrains_api_static)

#Icon downloaded from https://icon-icons.com/icon/jetbrains-toolbox/93803#64
set(JETBRAINS_ICON_INSTALL_DIR ${KDE_INSTALL_DATADIR}/pixmaps CACHE STRING "Default icon directory")
install(FILES jetbrains.png DESTINATION ${JETBRAINS_ICON_INSTALL_DIR})
