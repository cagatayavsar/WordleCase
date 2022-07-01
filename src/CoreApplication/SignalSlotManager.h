#ifndef CoreApplication_SignalSlotManager
#define CoreApplication_SignalSlotManager

#include <CoreApplication/SlotInfo.h>
#include <CoreApplication/SignalInfo.h>
#include <CoreApplication/Initializable.h>
#include <CoreApplication/CoreApplication_global.h>

#include <QtCore/QObject>
#include <QtCore/QMultiHash>

class COREAPPLICATION_EXPORT SignalSlotManager
	: public QObject
	, public Initializable
{
public:

	virtual void initialize();

	virtual void finalize();

	void registerSignal(const QString& eventName,
		QObject* sender,
		const char* signal);

	void registerSlot(const QString& eventName,
		QObject* receiver,
		const char* slot,
		Qt::ConnectionType connectionType = Qt::AutoConnection);

	void deregisterSignal(const QString& eventName,
		QObject* sender,
		const char* signal);

	void deregisterSlot(const QString& eventName,
		QObject* receiver,
		const char* slot);

	void connectSignalsToSlots();

private:

	QMultiHash<QString, SignalInfo> mSignals;

	QMultiHash<QString, SlotInfo> mSlots;

	void signalConnection(const QString& eventName, QObject* sender, const char* signal, bool isConnect);

	void slotConnection(const QString& eventName, QObject* receiver, const char* slot, Qt::ConnectionType connectionType, bool isConnect);

};
#endif