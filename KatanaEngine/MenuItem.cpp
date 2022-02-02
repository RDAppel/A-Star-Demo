
/* ---------------------------------------------------------------  /

	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \====================== Game Engine ======,
   `^^^^^^^^^^^^^^^^^^^ /----------------- © 2012 - Ryan Appel -"
					  \/
/  --------------------------------------------------------------- */

#include "KatanaEngine.h"

namespace KatanaEngine
{
	MenuItem::MenuItem() : MenuItem("")	{ }

	MenuItem::MenuItem(std::string text)
	{
		m_onSelect = nullptr;
		m_pFont = nullptr;

		m_text = text;

		m_color = Color::WHITE;
		m_alpha = 1.0f;

		m_position = Vector2::ZERO;
		m_textOffset = Vector2::ZERO;

		m_textAlign = TextAlign::LEFT;
		m_isDisplayed = true;
	}

	void MenuItem::Draw(SpriteBatch *pSpriteBatch)
	{
		if (m_pFont && m_text != "")
		{
			Color color = m_isSelected ? m_selectedColor : m_color;
			pSpriteBatch->DrawString(m_pFont, &m_text, m_position + m_textOffset, color * m_alpha, m_textAlign);
		}
	}

	void MenuItem::Select()
	{
		if (m_onSelect) ((OnSelect)m_onSelect)(this);
	}
}