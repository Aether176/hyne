/****************************************************************************
 ** Hyne Final Fantasy VIII Save Editor
 ** Copyright (C) 2009-2012 Arzel J�r�me <myst6re@gmail.com>
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#ifndef PAGEWIDGET_H
#define PAGEWIDGET_H

#include <QtGui>
#include "Data.h"
#include "Config.h"
#include "SaveData.h"

class PageWidget : public QWidget
{
	Q_OBJECT
public:
	explicit PageWidget(QWidget *parent = 0);
	void load(MAIN *data, HEADER *descData, int freq_value, bool jp, bool pc);
	void unload();
	bool isLoaded() const;
	bool isBuilded() const;
	virtual void updateMode(bool mode);
	virtual void updateTime();
public slots:
	virtual void fillPage() = 0;
	virtual void savePage() = 0;
protected:
	virtual void buildWidget() = 0;
	static void selectAll(QTreeWidget *, bool);
	static void setCurrentIndex(QComboBox *comboBox, int value);
	bool builded, loaded;
	MAIN *data;
	HEADER *descData;
	int freq_value;
	bool jp;
	bool pc;
};

#endif // PAGEWIDGET_H