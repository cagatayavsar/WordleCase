#include <CoreApplication/SignalInfo.h>

SignalInfo::SignalInfo()
	: mSender(0)
	, mSignal(0)
{
}

SignalInfo::SignalInfo(QObject * sender, const char * signal)
	: mSender(sender)
	, mSignal(signal)
{
}

QObject * SignalInfo::getSender() const
{
	return mSender;
}

const char * SignalInfo::getSignal() const
{
	return mSignal;
}
