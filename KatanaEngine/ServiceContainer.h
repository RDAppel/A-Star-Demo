
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
	/** @brief A collection of game services.
		@see IService */
	class ServiceContainer
	{
		
	public:

		/** @brief Adds a service to the container.
			@param pService The service to add.
			@returns True if the service was added, false if a service with the same id
			has already been added. */
		virtual bool AddService(IService *pService)
		{
			std::pair<std::string, IService *> pair(pService->GetID(), pService);
			return m_services.insert(pair).second;
		}

		/** @brief Gets a reference to the requested service.
			@param serviceId The id of the service to get.
			@returns The requested service or nullptr if the service was not found. */
		virtual IService *GetService(const std::string &serviceId)
		{
			m_it = m_services.find(serviceId);
			if (m_it == m_services.end()) return nullptr;
			return m_it->second;
		}

		/** @brief Calls HandleInput and Update on each of the services.
			@param pGameTime A reference to the game's timing values.
			@param pInput The current state of all player input devices. */
		virtual void Update(const GameTime *pGameTime, const InputState *pInput)
		{
			m_it = m_services.begin();
			for (; m_it != m_services.end(); m_it++)
			{
				m_it->second->HandleInput(pInput);
				m_it->second->Update(pGameTime);
			}
		}

		/** @brief Calls Draw on each of the services.
			@param pSpriteBatch The game's sprite batch, used for rendering. */
		virtual void Draw(SpriteBatch *pSpriteBatch)
		{
			m_it = m_services.begin();
			for (; m_it != m_services.end(); m_it++)
			{
				m_it->second->Draw(pSpriteBatch);
			}
		}


	private:

		std::map<std::string, IService *> m_services;
		std::map<std::string, IService *>::iterator m_it;
	};
}