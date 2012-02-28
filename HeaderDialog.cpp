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

#include "HeaderDialog.h"

HeaderDialog::HeaderDialog(SaveData *saveData, QWidget *parent, ViewType viewType)
	: QDialog(parent, Qt::Dialog | Qt::WindowCloseButtonHint), saveData(saveData), viewType(viewType)
{
	setWindowTitle(tr("Propri�t�s"));

	group1 = new QGroupBox(tr("Memory card header"), this);

	exists_lbl = new QLabel(tr("Existe :"));
	exists_lbl->setTextFormat(Qt::PlainText);
	exists = new QCheckBox;

	QLabel *country_lbl = new QLabel(tr("R�gion :"));
	country_lbl->setTextFormat(Qt::PlainText);
	country = new QComboBox;
	country->addItem(QIcon(":/images/jp.png"), tr("Japon"), COUNTRY_JP);
	country->addItem(QIcon(":/images/us.png"), tr("Am�rique"), COUNTRY_US);
	country->addItem(QIcon(":/images/eu.png"), tr("Europe"), COUNTRY_EU);
	country->addItem(tr("Invalide"), '\x00');

	country->setCurrentIndex(Config::valueVar("lastCountry").toInt());

	QLabel *code_lbl = new QLabel(tr("Code :"));
	code_lbl->setTextFormat(Qt::PlainText);
	code = new QComboBox;
	code->setEditable(true);
	code->lineEdit()->setMaxLength(10);
	fillCode(code);

	QString lastGameCode = Config::value("lastGameCode");
	if(!lastGameCode.isEmpty()) {
		setCode(lastGameCode);
	}

	id_lbl = new QLabel(tr("Identifiant :"));
	id_lbl->setTextFormat(Qt::PlainText);
	id = new QComboBox;
	id->setEditable(true);
	id->lineEdit()->setMaxLength(8);
	fillId(id);

	QGridLayout *layout1 = new QGridLayout(group1);
	layout1->addWidget(exists_lbl, 0, 0);
	layout1->addWidget(exists, 0, 1);
	layout1->addWidget(country_lbl, 1, 0);
	layout1->addWidget(country, 1, 1);
	layout1->addWidget(code_lbl, 2, 0);
	layout1->addWidget(code, 2, 1);
	layout1->addWidget(id_lbl, 3, 0);
	layout1->addWidget(id, 3, 1);

	group2 = new QGroupBox(tr("Save header"), this);

	desc = new QLabel();
	desc->setTextFormat(Qt::PlainText);

	QLabel *bloc_lbl = new QLabel(tr("Blocs utilis�s :"));
	bloc = new QLabel();
	bloc->setTextFormat(Qt::PlainText);

	QLabel *desc_lbl = new QLabel(tr("Description :"));
	desc_lbl->setTextFormat(Qt::PlainText);

	QLabel *icon1_lbl = new QLabel(tr("Ic�ne :"));
	icon1_lbl->setTextFormat(Qt::PlainText);
	icon1 = new QLabel();
	QPushButton *icon1_saveButton = new QPushButton();
	QIcon saveIcon(QApplication::style()->standardIcon(QStyle::SP_DialogSaveButton));
	icon1_saveButton->setIcon(saveIcon);
	icon1_saveButton->setFlat(true);
	icon2_lbl = new QLabel(tr("Ic�ne additionnel :"));
	icon2_lbl->setTextFormat(Qt::PlainText);
	icon2 = new QLabel();
	icon2_saveButton = new QPushButton();
	icon2_saveButton->setIcon(saveIcon);
	icon2_saveButton->setFlat(true);

	QGridLayout *layout2 = new QGridLayout(group2);
	layout2->addWidget(bloc_lbl, 0, 0);
	layout2->addWidget(bloc, 0, 1, 1, 2);
	layout2->addWidget(desc_lbl, 1, 0);
	layout2->addWidget(desc, 1, 1, 1, 2);
	layout2->addWidget(icon1_lbl, 2, 0);
	layout2->addWidget(icon1, 2, 1);
	layout2->addWidget(icon1_saveButton, 2, 2, Qt::AlignRight);
	layout2->addWidget(icon2_lbl, 3, 0);
	layout2->addWidget(icon2, 3, 1);
	layout2->addWidget(icon2_saveButton, 3, 2, Qt::AlignRight);

	QPushButton *buttonSave = new QPushButton(tr("OK"));
	QPushButton *button = new QPushButton(tr("Fermer"));
	connect(buttonSave, SIGNAL(released()), SLOT(save()));
	connect(button, SIGNAL(released()), SLOT(close()));
	connect(icon1_saveButton, SIGNAL(released()), SLOT(saveIcon1()));
	connect(icon2_saveButton, SIGNAL(released()), SLOT(saveIcon2()));

	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(group1, 0, 0, 1, 2);
	layout->addWidget(group2, 1, 0, 1, 2);
	layout->setRowStretch(2, 1);
	layout->addWidget(buttonSave, 3, 0, Qt::AlignRight);
	layout->addWidget(button, 3, 1, Qt::AlignLeft);

	fill();
}

void HeaderDialog::fillCode(QComboBox *code)
{
	QIcon jp(":/images/jp.png");
	code->addItem(jp, "SLPSP01880");//japanese
	code->addItem(jp, "SCPSP45375");//japanese (???)
	code->addItem(jp, "SLPMP87384");//japanese (Ultimate Hits)
	code->addItem(QIcon(":/images/us.png"), "SLUSP00892");//american
	code->addItem(QIcon(":/images/uk.png"), "SLESP02080");//english
	code->addItem(QIcon(":/images/fr.png"), "SLESP02081");//french
	code->addItem(QIcon(":/images/de.png"), "SLESP02082");//german
	code->addItem(QIcon(":/images/it.png"), "SLESP02083");//italian
	code->addItem(QIcon(":/images/sp.png"), "SLESP02084");//spanish
}

void HeaderDialog::fillId(QComboBox *id)
{
	id->addItem(QIcon(":/images/jp.png"), "FF0800");
	id->addItem(QIcon(":/images/us.png"), "042600");
	id->addItem(QIcon(":/images/eu.png"), "052000");
}

void HeaderDialog::fill()
{
	setWindowIcon(QIcon(saveData->icon()));

	if(viewType == NormalView && !saveData->hasMCHeader()) {
		group1->hide();
	}
	else {
		// Fill group1 (MCHeader)

		if(viewType != NormalView) {
			exists->setChecked(true);
		}
		else {
			exists->setChecked(!saveData->isDelete());
			setId(saveData->MCHeaderId());
		}

		if(viewType != CreateView || saveData->hasMCHeader()) {
			setCountry(saveData->MCHeaderCountry());
			setCode(saveData->MCHeaderCode());
		}
	}

	if(saveData->isVmp()) {
		exists->hide();
		exists_lbl->hide();
	}

	if(viewType == RestoreView || viewType == CreateView) {
		group2->hide();

		exists->hide();
		exists_lbl->hide();
		id_lbl->hide();
		id->hide();
		country->setMaxCount(3);
	}
	else {
		// Fill group2 (SC_header)

		QString short_desc = saveData->getShortDescription();
		if(!short_desc.isEmpty()) {
			desc->setText(short_desc);
		}

		bloc->setText(QString::number((quint8)saveData->header().at(3)));
		icon1->setPixmap(saveData->icon());
		connect(saveData->saveIcon(), SIGNAL(nextIcon(QPixmap)), icon1, SLOT(setPixmap(QPixmap)));
		if(saveData->isFF8()) {
			icon2->setPixmap(saveData->icon(true));
		}
		else {
			icon2_lbl->hide();
			icon2->hide();
			icon2_saveButton->hide();
		}
	}
}

void HeaderDialog::setCountry(char c)
{
	int index;
	if((index=country->findData(c)) != -1)
	{
		country->setCurrentIndex(index);
		if(index != 3)		country->setMaxCount(3);
	}
	else
	{
		if(viewType == RestoreView) {
			country->setCurrentIndex(0);
		}
		else {
			country->setItemData(3, c);
			country->setCurrentIndex(3);//Invalid
		}
	}
}

void HeaderDialog::setCode(const QString &codestr)
{
	int index;
	if(codestr.size()==10 && (index=code->findText(codestr)) != -1)
	{
		code->setCurrentIndex(index);
	}
	else if(viewType == NormalView) {
		code->insertItem(0, codestr);
		code->setCurrentIndex(0);
	}
}

void HeaderDialog::setId(const QString &idStr)
{
	if(idStr.startsWith("FF08")) {
		id->setCurrentIndex(0);
	} else if(idStr.startsWith("0426")) {
		id->setCurrentIndex(1);
	} else if(idStr.startsWith("0520")) {
		id->setCurrentIndex(2);
	} else {
		id->addItem(idStr);
		id->setCurrentIndex(id->count()-1);
	}
	id->lineEdit()->setText(idStr);
}

void HeaderDialog::save()
{
	if(viewType == NormalView && !saveData->hasMCHeader()) {
		close();
		return;
	}

	Config::setValue("lastCountry", country->currentIndex());
	Config::setValue("lastGameCode", code->currentText());

	saveData->setMCHeader(exists->isChecked(),
						  country->itemData(country->currentIndex()).toInt(),
						  code->currentText(),
						  id->isVisible() ? id->currentText() : QString());

	accept();
}

void HeaderDialog::saveIcon(bool chocobo_world_icon)
{
	QString path = Config::value("savePathIcon").isEmpty() ? QString() : Config::value("savePathIcon") % "/";
	path = QFileDialog::getSaveFileName(this, tr("Enregistrer sous"), path % QString("icon%1%2.png").arg(saveData->id()+1).arg(chocobo_world_icon ? "b" : ""), tr("Image PNG (*.png);;Image JPG (*.jpg *.jpeg);;Image BMP (*.bmp)"));
	if(path.isEmpty())		return;

	int index = path.lastIndexOf('/');
	Config::setValue("savePathIcon", index == -1 ? path : path.left(index));

	if(!saveData->icon(chocobo_world_icon).save(path))
		QMessageBox::warning(this, tr("Erreur"), tr("Format incorrect."));
}

void HeaderDialog::saveIcon1()
{
	saveIcon();
}

void HeaderDialog::saveIcon2()
{
	saveIcon(true);
}