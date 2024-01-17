add_definitions(-DTRANSLATION_DOMAIN=\"jetbrainsdolphinplugin\")

add_subdirectory(jetbrains-api)

kcoreaddons_add_plugin(jetbrainsdolphinplugin SOURCES jetbrainsdolphinplugin.cpp INSTALL_NAMESPACE kf${QT_MAJOR_VERSION}/kfileitemaction)
target_link_libraries(jetbrainsdolphinplugin KF${QT_MAJOR_VERSION}::KIOCore KF${QT_MAJOR_VERSION}::KIOWidgets)
target_link_libraries(jetbrainsdolphinplugin jetbrains_api_static)

#Icon downloaded from https://icon-icons.com/icon/jetbrains-toolbox/93803#64
install(FILES jetbrains.png DESTINATION ${KDE_INSTALL_DATADIR}/jetbrainsdolphinplugin)
