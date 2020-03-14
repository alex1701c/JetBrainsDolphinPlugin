/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright 2020  <copyright holder> <email>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "jetbrainsdolphinplugin.h"

#include <KPluginFactory>
#include <KPluginLoader>
#include <QDebug>
#include <KCoreAddons/KAboutData>
#include <KWidgetsAddons/KActionMenu>
#include <QtCore/QProcess>
#include <KSharedConfig>

#include "jetbrains-api/JetbrainsApplication.h"
#include "jetbrains-api/SettingsDirectory.h"
#include "jetbrains-api/ConfigKeys.h"
#include "jetbrains-api/export.h"


JetBrainsDolphinPlugin::JetBrainsDolphinPlugin(QObject *parent, const QVariantList &args)
    : KAbstractFileItemActionPlugin(parent)
{
    Q_UNUSED(args)
    apps = JetbrainsAPI::fetchApplications(KSharedConfig::openConfig(
        QDir::homePath() + "/.config/krunnerplugins/jetbrainsrunnerrc")->group("Config"), false);

    // create default menu
    auto *menuAction = new KActionMenu(this);
    menuAction->setIcon(QIcon::fromTheme("jetbrains"));
    menuAction->setText("Jetbrains");
    for (int i = 0; i < apps.count(); ++i) {
        const auto app = apps.at(i);
        auto action = new QAction(QIcon::fromTheme(app->iconPath), app->shortName, this);
        action->setData(i);
        connect(action, &QAction::triggered, this, &JetBrainsDolphinPlugin::openIDE);
        menuAction->addAction(action);
    }
}

JetBrainsDolphinPlugin::~JetBrainsDolphinPlugin()
{
}

QList<QAction *> JetBrainsDolphinPlugin::actions(const KFileItemListProperties &fileItemInfos, QWidget *parentWidget)
{
    Q_UNUSED(fileItemInfos)
    Q_UNUSED(parentWidget)

    if (!fileItemInfos.isDirectory() || fileItemInfos.urlList().count() != 1) {
        return {};
    }
    projectPath = fileItemInfos.urlList().first().path();
    if (QDir(projectPath + "/.idea").exists()) {
        QList<QAction *> actionList;
        for (int i = 0; i < apps.count(); ++i) {
            const auto app = apps.at(i);
            if (app->recentlyUsed.contains(projectPath)) {
                auto action = new QAction(QIcon::fromTheme(app->iconPath), "Open with " + app->shortName, this);
                action->setData(i);
                connect(action, &QAction::triggered, this, &JetBrainsDolphinPlugin::openIDE);
                actionList.append(action);
            }
        }
        // If the project was not opened in the other ides, add them in submenu
        if (actionList.size() != apps.size()) {
            auto *menuAction = new KActionMenu(this);
            menuAction->setIcon(QIcon::fromTheme("jetbrains"));
            menuAction->setText("Jetbrains");
            for (int i = 0; i < apps.count(); ++i) {
                const auto app = apps.at(i);
                if (app->recentlyUsed.contains(projectPath)) {
                    continue;
                }
                auto action = new QAction(QIcon::fromTheme(app->iconPath), app->shortName, this);
                action->setData(i);
                connect(action, &QAction::triggered, this, &JetBrainsDolphinPlugin::openIDE);
                menuAction->addAction(action);
            }
            actionList.append(menuAction);
        }
        return actionList;
    }
    return defaultActions;
}

void JetBrainsDolphinPlugin::openIDE()
{
    int appIndex = reinterpret_cast<QAction *>(this->sender())->data().toInt();
    QProcess::startDetached(apps.at(appIndex)->executablePath + projectPath);
}

K_PLUGIN_CLASS_WITH_JSON(JetBrainsDolphinPlugin, "jetbrainsdolphinplugin.json")

#include "jetbrainsdolphinplugin.moc"
