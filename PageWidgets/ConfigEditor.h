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

#ifndef DEF_CONFIGEDITOR
#define DEF_CONFIGEDITOR

#include "PageWidget.h"

class ConfigEditor : public PageWidget
{
	Q_OBJECT
public:
	explicit ConfigEditor(QWidget *parent=0);
	void updateMode(bool mode);
public slots:
	void fillPage();
	void savePage();

private slots:
	void joystickS();
	void touchesDefault();
protected:
	void buildWidget();
private:
	void setJoystickLbl();

	QRadioButton *son1E, *son2E;
	QRadioButton *pointeur1E, *pointeur2E;
	QRadioButton *ATB1E, *ATB2E;
	QRadioButton *scan1E, *scan2E;
	QRadioButton *targetMenu1E, *targetMenu2E;
	QRadioButton *vibration1E, *vibration2E;
	QSlider *cameraE, *vts_combatE;
	QSlider *vts_msg_combatE, *vts_msgE;
	QSpinBox *analog_volumeE;
	QList<QSpinBox *> touchesE;
	QLabel *joystickLbl;
	QGroupBox *manetteGroupE;
	QCheckBox *inconnu1E;
};

#endif