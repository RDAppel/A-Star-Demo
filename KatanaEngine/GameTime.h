
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
	/** @brief Contains timing values for game updates. */
	class GameTime
	{
		friend class Game;

	public:

		GameTime();

		/** @brief Gets the time in seconds since last frame.
			@return Returns the number of seconds since the last frame. */
		double GetTimeElapsed() const { return m_elapsedTime; }

		/** @brief Gets the time in seconds since the game started.
			@return Returns the number of seconds since the game started. */
		double GetTotalTime() const { return m_currentTotalTime; }



	private:

		void Update();

		double m_currentTotalTime = 0;
		double m_previousTotalTime = 0;
		double m_elapsedTime = 0;
	};
}