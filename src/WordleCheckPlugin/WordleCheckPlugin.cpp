#include <WordleCheckPlugin/WordleCheckPlugin.h>
#include <WordleCheckPlugin/WordleChecker.h>

WordleCheckPlugin::WordleCheckPlugin()
{
	mWordleChecker = new WordleChecker();
}

WordleCheckPlugin::~WordleCheckPlugin()
{
}

void WordleCheckPlugin::initialize()
{
	mWordleChecker->initialize();
}

void WordleCheckPlugin::finalize()
{
}