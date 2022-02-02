
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

#pragma once

namespace KatanaEngine
{
	class Game;

	/** @brief Updates, renders, and manages transitions between instances of the Screen class. */
	class ScreenManager : public IService
	{
		friend class Game;

	public:

		/** @brief Instantiate a screen manager object. */
		ScreenManager() { }

		virtual ~ScreenManager() { }

		virtual std::string GetID() const { return "ScreenManager"; }

		/** @brief Add a screen to be managed.
			@param pScreen A pointer to the screen to be managed. */
		virtual void AddScreen(Screen *pScreen);

		/** @brief Called when the game has determined that screen logic needs to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime);

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch);


	private:

		std::vector<Screen *> m_screens;
		std::vector<Screen *> m_screensToAdd;
		std::vector<Screen *> m_screensToRemove;
		std::vector<Screen *> m_screensToDraw;

		std::vector<Screen *>::iterator m_it;
		std::vector<Screen *>::reverse_iterator m_rit;

		virtual void HandleInput(const InputState *pInput);
	};
}