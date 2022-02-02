#pragma once

#include "KatanaEngine.h"

using namespace KatanaEngine;

class DrawableCollection : public IDrawable
{

public:

	virtual ~DrawableCollection() { }

	virtual void Draw(SpriteBatch *pSpriteBatch)
	{
		m_it = m_items.begin();
		for (; m_it != m_items.end(); m_it++) (*m_it)->Draw(pSpriteBatch);
	}

	virtual void Add(IDrawable *pItem)
	{
		m_items.push_back(pItem);
	}

	virtual std::vector<IDrawable *>::const_iterator begin() const { return m_items.begin(); }

	virtual std::vector<IDrawable *>::const_iterator end() const { return m_items.end(); }

private:

	std::vector<IDrawable *> m_items;
	std::vector<IDrawable *>::iterator m_it;

};

