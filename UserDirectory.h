#ifndef USERDIRECTORY_H
#define USERDIRECTORY_H

#include <QtCore>
#include "Metadata.h"

class UserDirectory
{
public:
	UserDirectory();
	explicit UserDirectory(const QString &dirname);
	inline const Metadata &metadata() const {
		return _metadata;
	}
	bool openMetadata();
	void updateMetadata(quint8 slot, quint8 num, const QByteArray &saveData);
	bool saveMetadata();
	const QString &errorString() const;
private:
	QString extractUserID() const;

	Metadata _metadata;
	QString _dirname;
	QString _userID;
};

#endif // USERDIRECTORY_H