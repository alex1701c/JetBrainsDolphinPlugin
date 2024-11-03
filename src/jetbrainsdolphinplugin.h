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

#pragma once

#include <KAbstractFileItemActionPlugin>
#include <KFileItem>
#include <KFileItemListProperties>
#include <QAction>

class JetbrainsApplication;

class JetBrainsDolphinPlugin : public KAbstractFileItemActionPlugin
{
    Q_OBJECT

public:
    explicit JetBrainsDolphinPlugin(QObject *parent, const QVariantList &args);
    ~JetBrainsDolphinPlugin() override;
    QList<QAction *> actions(const KFileItemListProperties &fileItemInfos, QWidget *parentWidget) override;
    QList<QAction *> getDefaultActions();

private:
    Q_SLOT void openIDE(JetbrainsApplication *app);
    QList<JetbrainsApplication *> apps;
    QString projectPath;
    const QIcon jetbrainsIcon;
};
