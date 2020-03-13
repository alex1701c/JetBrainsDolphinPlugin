add_definitions(-DTRANSLATION_DOMAIN=\"jetbrainsdolphinplugin\")

set(jetbrainsdolphinplugin_SRCS jetbrainsdolphinplugin.cpp)
kcoreaddons_add_plugin(jetbrainsdolphinplugin SOURCES ${jetbrainsdolphinplugin_SRCS} INSTALL_NAMESPACE "kf5/kfileitemaction")
kcoreaddons_desktop_to_json(jetbrainsdolphinplugin jetbrainsdolphinplugin.desktop) # generate the json file with metadata
target_link_libraries(jetbrainsdolphinplugin KF5::KIOCore KF5::KIOWidgets)
