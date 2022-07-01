#ifndef Initializable_Initializable
#define Initializable_Initializable

class Initializable
{
public:

	virtual ~Initializable()
	{

	}

	virtual void initialize() = 0;

	virtual void endInitialize()
	{

	}

	virtual void finalize() = 0;
};
#endif