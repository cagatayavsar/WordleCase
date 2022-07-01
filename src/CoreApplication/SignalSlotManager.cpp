#include <CoreApplication/SignalSlotManager.h>

#include <QtCore/QDebug>

void SignalSlotManager::initialize()
{
}

void SignalSlotManager::finalize()
{
}

void SignalSlotManager::registerSignal(const QString & eventName, QObject * sender, const char * signal)
{
	SignalInfo signalInfo(sender, signal);
	mSignals.insert(eventName, signalInfo);

	signalConnection(eventName, sender, signal, true);
}

void SignalSlotManager::registerSlot(const QString & eventName, QObject * receiver, const char * slot, Qt::ConnectionType connectionType)
{
	SlotInfo slotInfo(receiver, slot, connectionType);
	mSlots.insert(eventName, slotInfo);

	slotConnection(eventName, receiver, slot, connectionType, true);
}

void SignalSlotManager::deregisterSignal(const QString & eventName, QObject * sender, const char * signal)
{
	signalConnection(eventName, sender, signal, false);

	QMultiHash<QString, SignalInfo>::Iterator itor = mSignals.begin();
	bool found = false;
	for (; !found && (itor != mSignals.end()); ++itor)
	{
		SignalInfo signalInfo = itor.value();

		if ((itor.key() == eventName) && (signalInfo.getSender() == sender))
		{
			if (QString(signalInfo.getSignal()) == QString(signal))
			{
				mSignals.erase(itor);
				found = true;
				break;
			}
		}
	}
}

void SignalSlotManager::deregisterSlot(const QString & eventName, QObject * receiver, const char * slot)
{
	slotConnection(eventName, receiver, slot, Qt::AutoConnection, false);

	QMultiHash<QString, SlotInfo>::Iterator itor = mSlots.begin();
	bool found = false;
	for (; !found && (itor != mSlots.end()); ++itor)
	{
		SlotInfo slotInfo = itor.value();

		if ((itor.key() == eventName) && (slotInfo.getReceiver() == receiver))
		{
			if (QString(slotInfo.getSlot()) == QString(slot))
			{
				mSlots.erase(itor);
				found = true;
				break;
			}
		}
	}
}

void SignalSlotManager::connectSignalsToSlots()
{
	QMultiHash <QString, SignalInfo>::ConstIterator itor = mSignals.begin();
	for (; itor != mSignals.end(); ++itor)
	{
		QString eventName = itor.key();
		SignalInfo signalInfo = itor.value();

		signalConnection(eventName, signalInfo.getSender(), signalInfo.getSignal(), true);
	}
}

void SignalSlotManager::signalConnection(const QString & eventName, QObject * sender, const char * signal, bool isConnect)
{
	QList<SlotInfo> slotList = mSlots.values(eventName);
	for (qint32 i = 0; i < slotList.size(); i++)
	{
		SlotInfo slotInfo = slotList.at(i);

		if (isConnect)
		{
			bool connected = QObject::connect(sender,
				signal,
				slotInfo.getReceiver(),
				slotInfo.getSlot(),
				slotInfo.getConnectionType());

			if (!connected)
			{
				qWarning() <<
					QString("Could not connect signal(%1) to slot(%2)")
					.arg(signal)
					.arg(slotInfo.getSlot());
			}
		}
		else
		{
			bool disconnected = QObject::disconnect(sender,
				signal,
				slotInfo.getReceiver(),
				slotInfo.getSlot());

			if (!disconnected)
			{
				qWarning() <<
					QString("Could not disconnect signal(%1) from slot(%2)")
					.arg(signal)
					.arg(slotInfo.getSlot());
			}
		}
	}
}

void SignalSlotManager::slotConnection(const QString & eventName, QObject * receiver, const char * slot, Qt::ConnectionType connectionType, bool isConnect)
{
	QList<SignalInfo> signalList = mSignals.values(eventName);

	for (qint32 i = 0; i < signalList.size(); i++)
	{
		SignalInfo signalInfo = signalList.at(i);

		if (isConnect)
		{
			bool connected = QObject::connect(signalInfo.getSender(),
				signalInfo.getSignal(),
				receiver,
				slot,
				connectionType);

			if (!connected)
			{
				qWarning() <<
					QString("Could not connect signal(%1) to slot(%2).")
					.arg(signalInfo.getSignal())
					.arg(slot);
			}
		}
		else
		{
			bool disconnected = QObject::disconnect(signalInfo.getSender(),
				signalInfo.getSignal(),
				receiver,
				slot);

			if (!disconnected)
			{
				qWarning() <<
					QString("Could not disconnect signal(%1) from slot(%2).")
					.arg(signalInfo.getSignal())
					.arg(slot);
			}
		}
	}
}
