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

#ifndef DEF_SAVECARD
#define DEF_SAVECARD

#include <QtGui>
#include "LZS.h"
#include "SaveWidget.h"
#include "HeaderDialog.h"

class SaveWidget;

class Savecard : public QListWidget
{
	Q_OBJECT

public:
	enum Type {
		Pc, Ps, Vgs, Gme, Vmp, Psv, PcDir, Unknown, Undefined
	};

	Savecard(const QString &path, QWidget *parent=0, bool slot=false);
	Savecard(int saveCount, QWidget *parent=0);
	virtual ~Savecard();

	void updateSaveWidget(int saveID, bool saved=false, bool allUpdate=false);
	void updateSaveWidgets();
	const QList<SaveData *> &getSaves() const;
	bool save2PC(qint8 num, QString path=QString());
	bool save2PSV(qint8 id, QString path=QString());
	bool save2PS(QList<int> ids, const QString &path, Type newType);
	void saveDir();
	void saveDir(quint8);

	SaveWidget *saveWidget(int row) const;

	QString dirname() const;
	QString name() const;
	QString extension() const;
	const QString &path() const;
	void setName(const QString &name);
	bool ok() const;
	Type type() const;
	bool hasPath() const;
	bool isOneSaveType() const;
	bool isModified() const;
	void setModified(bool modified);
	void setSlotOrder(const QList<int> &order);
	static void compare(const QByteArray &oldData, const QByteArray &newData);

	bool save(const QString &saveAs=QString(), Type newType=Pc);

	void moveCursor(int);
	void setDragStart(int saveID);
	void moveDraggedSave(int saveID);
	void replaceSaveData(int saveID, const QByteArray &mimeData);
	void setDropIndicatorIsVisible(int saveID, bool onTop, bool isVisible);
	void scrollToDrag(int saveID, const QPoint &pos);
private slots:
	void notifyFileChanged(const QString &path);
signals:
	void modified();
private:
	QString _path;
	bool _ok;
	Type _type;
	bool _hasPath;
	int _dragStart;

	void setWidget();
	void setPath(const QString &path);
	void setType(Type type);
	bool ps();
	bool ps3();
	bool pc();
	bool getFormatFromRaw();
	bool sstate_ePSXe();
	bool sstate_pSX();
	void directory();
	void addSave(const QByteArray &data=QByteArray(), const QByteArray &header=QByteArray());
	QByteArray header(QFile *srcFile, Type newType, bool saveAs, bool *abort);
	QByteArray descGme(const QString &desc, bool *abort);

	quint16 start;//D�part de la sauvegarde <=> taille du header rajout�
	QFileSystemWatcher fileWatcher;
	bool notify;
	QList<SaveData *> saves;
	bool _isModified;
};

#endif
