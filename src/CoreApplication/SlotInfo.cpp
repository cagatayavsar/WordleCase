#include <CoreApplication/SlotInfo.h>

SlotInfo::SlotInfo()
	: mReceiver(0)
	, mSlot(0)
{
}

SlotInfo::SlotInfo(QObject * receiver, const char * slot, Qt::ConnectionType connectionType)
	: mReceiver(receiver)
	, mSlot(slot)
	, mConnectionType(connectionType)
{
}

QObject * SlotInfo::getReceiver() const
{
	return mReceiver;
}

const char * SlotInfo::getSlot() const
{
	return mSlot;
}

Qt::ConnectionType SlotInfo::getConnectionType() const
{
	return mConnectionType;
}
