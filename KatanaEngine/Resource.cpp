
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

	void Resource::Unload()
	{
		m_pResourceManager->Unload(this);
	}

	void Resource::StripComments(std::string &line)
	{
		if (line.empty()) return;

		std::size_t position = line.find("//");
		if (position == std::string::npos) return;

		line = line.substr(0, position);
	}

	void Resource::TrimLine(std::string &line)
	{
		if (line.empty()) return;

		std::size_t pos;

		pos = line.find_first_not_of(" \t");
		if (pos != std::string::npos) line = line.substr(pos);

		pos = line.find_last_not_of(" \t");
		if (pos != std::string::npos) line = line.substr(0, pos + 1);
	}
}