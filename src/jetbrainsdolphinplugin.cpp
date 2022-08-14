/*
 * Copyright 2020  <Alex1701c> <alex1701c.dev@gmx.net>
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
#include <KActionMenu>
#include <KSharedConfig>
#include <KShell>
#include <QDir>
#include <QProcess>

#include "jetbrains-api/export.h"

inline bool containsPath(JetbrainsApplication *app, const QString &path)
{
    return std::any_of(app->recentlyUsed.begin(), app->recentlyUsed.end(), [&path](const Project &p){
        return p.path == path;
    });
}

JetBrainsDolphinPlugin::JetBrainsDolphinPlugin(QObject *parent, const QVariantList &args)
    : KAbstractFileItemActionPlugin(parent)
{
    Q_UNUSED(args)
}

JetBrainsDolphinPlugin::~JetBrainsDolphinPlugin()
{
    qDeleteAll(apps);
}

QList<QAction *> JetBrainsDolphinPlugin::actions(const KFileItemListProperties &fileItemInfos, QWidget *parentWidget)
{
    Q_UNUSED(parentWidget)

    if (fileItemInfos.urlList().count() != 1) {
        return {};
    }
    projectPath = fileItemInfos.urlList().first().path();
    if (QDir(projectPath + "/.idea").exists()) {
        // Only now the apps have to be loaded
        const auto config = KSharedConfig::openConfig(QStringLiteral("krunnerplugins/jetbrainsrunnerrc"))
            ->group("Config");
        apps = JetbrainsAPI::fetchApplications(config, false, false);

        QList<QAction *> actionList;
        for (int i = 0; i < apps.count(); ++i) {
            const auto app = apps.at(i);
            if (containsPath(app, projectPath)) {
                auto action = new QAction(QIcon::fromTheme(app->iconPath), "Open with " + app->shortName, this);
                action->setData(i);
                connect(action, &QAction::triggered, this, &JetBrainsDolphinPlugin::openIDE);
                actionList.append(action);
            }
        }
        // If the project was not opened in the other ides, add them in submenu
        if (actionList.size() != apps.size()) {
            auto *menuAction = new KActionMenu(this);
            menuAction->setIcon(QIcon::fromTheme(QStringLiteral("jetbrains")));
            menuAction->setText(QStringLiteral("Jetbrains"));
            for (int i = 0; i < apps.count(); ++i) {
                const auto app = apps.at(i);
                if (containsPath(app, projectPath)) {
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

    return getDefaultActions();
}

void JetBrainsDolphinPlugin::openIDE()
{
    int appIndex = reinterpret_cast<QAction *>(this->sender())->data().toInt();
    const QString exec = apps.at(appIndex)->executablePath + QLatin1Char(' ') + projectPath;
    QStringList split = KShell::splitArgs(exec);
    const QString program = split.takeFirst();
    QProcess::startDetached(program, split);
}
QList<QAction *> JetBrainsDolphinPlugin::getDefaultActions()
{
    // Because the folder has no subfolder called .idea we can be sure that it is not a project
    const auto config = KSharedConfig::openConfig(QStringLiteral("krunnerplugins/jetbrainsrunnerrc"))
        ->group("Config");
    apps = JetbrainsAPI::fetchRawApplications(config);
    // create default menu
    auto *menuAction = new KActionMenu(this);
    menuAction->setIcon(QIcon::fromTheme(QStringLiteral("jetbrains")));
    menuAction->setText(QStringLiteral("Jetbrains"));
    for (int i = 0; i < apps.count(); ++i) {
        const auto app = apps.at(i);
        auto action = new QAction(QIcon::fromTheme(app->iconPath), app->shortName, this);
        action->setData(i);
        connect(action, &QAction::triggered, this, &JetBrainsDolphinPlugin::openIDE);
        menuAction->addAction(action);
    }
    return {menuAction};
}

K_PLUGIN_CLASS_WITH_JSON(JetBrainsDolphinPlugin, "jetbrainsdolphinplugin.json")

#include "jetbrainsdolphinplugin.moc"
