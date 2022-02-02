#pragma once

#include "KatanaEngine.h"

using namespace KatanaEngine;

class IDrawable
{

public:

	virtual void Draw(SpriteBatch *pSpriteBatch) = 0;

};