
#pragma once

#include "AStar.h"

class Demo : public KatanaEngine::Game
{

public:

	Demo();
	virtual ~Demo() { }

	virtual std::string GetName() const { return "A-Star Demo"; }

private:

	KatanaEngine::ScreenManager *m_pScreenManager;
};

