#ifndef CoreApplication_SlotInfo
#define CoreApplication_SlotInfo

#include <QtCore/qnamespace.h>

class QObject;

class SlotInfo
{
public:

	SlotInfo();

	SlotInfo(QObject* receiver,
		const char* slot,
		Qt::ConnectionType connectionType);

	QObject* getReceiver() const;

	const char* getSlot() const;

	Qt::ConnectionType getConnectionType() const;

private:

	QObject* mReceiver;

	const char* mSlot;

	Qt::ConnectionType mConnectionType;
};

#endif