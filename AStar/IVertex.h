
#pragma once

class IVertex
{

public:

	virtual ~IVertex() { }

	virtual void SetPosition(Vector2 position) = 0;

};
