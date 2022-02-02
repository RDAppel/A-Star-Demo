#pragma once

#include "KatanaEngine.h"

using namespace KatanaEngine;

class Grid
{
public: 

	Grid() { }

	virtual ~Grid() { }

	virtual void Draw(SpriteBatch *pSpriteBatch) = 0;

};

