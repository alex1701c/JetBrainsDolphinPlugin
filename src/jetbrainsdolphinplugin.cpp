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


JetBrainsDolphinPlugin::JetBrainsDolphinPlugin(QObject *parent, const QVariantList &args)
        : KAbstractFileItemActionPlugin(parent)
{
    Q_UNUSED(args)
}

JetBrainsDolphinPlugin::~JetBrainsDolphinPlugin()
{
}

QList<QAction *> JetBrainsDolphinPlugin::actions(const KFileItemListProperties &fileItemInfos, QWidget *parentWidget)
{
    Q_UNUSED(fileItemInfos)
    Q_UNUSED(parentWidget)

    QList<QAction *> actions;
    auto *menuAction = new KActionMenu(this);
    menuAction->setIcon(QIcon::fromTheme("kdevelop"));
    menuAction->setText("JetBrainsDolphinPlugin");
    auto action = new QAction(QIcon::fromTheme("planetkde"), "Hello There!", this);
    connect(action, &QAction::triggered, this, &JetBrainsDolphinPlugin::helloThere);
    menuAction->addAction(action);
    actions.append(menuAction);
    return {actions};
}
void JetBrainsDolphinPlugin::helloThere()
{
    // Only for demo purposes, use KNotifications for real applications
    QProcess::startDetached("notify-send", {"Hello There!", "--icon", "planetkde"});
}

K_PLUGIN_CLASS_WITH_JSON(JetBrainsDolphinPlugin, "jetbrainsdolphinplugin.json")

#include "jetbrainsdolphinplugin.moc"
