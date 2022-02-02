
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

	/** @brief Interface for a game service. Game services can be added to a Service Container
		which will call all of the update and rendering functions.
		@see ServiceContainer */
	class IService
	{

	public:

		virtual ~IService() { }

		/** @brief Gets the service id.
			@returns The id of the service. */
		virtual std::string GetID() const = 0;

		/** @brief Called when the game has determined that player input needs to be processed.
			@param pInput The current state of all player input devices. */
		virtual void HandleInput(const InputState *pInput) { }

		/** @brief Called when the game has determined that screen logic needs to be processed.
			@param pGameTime Timing values including time since last update. */
		virtual void Update(const GameTime *pGameTime) { }

		/** @brief Called when the game determines it is time to draw a frame.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch) { }

		/** @brief Stores a pointer to the game. */
		virtual void SetGame(Game *pGame) { m_pGame = pGame; }

		/** @brief Gets a pointer to the game. */
		virtual Game *GetGame() { return m_pGame; }

	private:

		Game *m_pGame = nullptr;

	};
}
