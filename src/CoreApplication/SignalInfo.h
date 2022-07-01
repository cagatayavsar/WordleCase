#ifndef CoreApplication_SignalInfo
#define CoreApplication_SignalInfo

class QObject;

class SignalInfo
{
public:
	
	SignalInfo();

	SignalInfo(QObject* sender, const char* signal);

	QObject* getSender() const;

	const char* getSignal() const;

private:

	QObject* mSender;

	const char* mSignal;
};
#endif