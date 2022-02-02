#pragma once

#include "AStar.h"

using namespace KatanaEngine;

class DemoScreen : public Screen
{
public:

	DemoScreen() { }
		
	virtual void HandleInput(const InputState *pInput);

	virtual void LoadContent(ResourceManager *pResourceManager);

	virtual void Update(const GameTime *pGameTime) { }

	virtual void Draw(SpriteBatch *pSpriteBatch);

private:

	DrawableGraph *m_pGraph;
};

