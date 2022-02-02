
#include "AStar.h"

using namespace KatanaEngine;

Demo::Demo()
{
	SetScreenResolution(1600, 900);

	SetResourceDirectory("..\\AStar\\Content\\");

	m_pScreenManager = InitializeScreenManager();
	
	m_pScreenManager->AddScreen(new DemoScreen);
}