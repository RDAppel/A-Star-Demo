
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
	Animation::Animation()
	{
		m_secondsPerFrame = 0;
		m_currentFrameTime = 0;
		m_currentIndex = 0;
		m_loopCounter = -1;
		m_isPlaying = true;
	}


	Animation::~Animation()
	{
		std::vector<Region *>::iterator it;
		for (it = m_frames.begin(); it != m_frames.end(); ++it)
		{
			delete *it;
		}
		m_frames.clear();
	}


	void Animation::Update(const GameTime *pGameTime)
	{
		if (m_isPlaying)
		{
			m_currentFrameTime -= pGameTime->GetTimeElapsed();

			if (m_currentFrameTime <= 0)
			{
				m_currentIndex++;
				m_currentFrameTime = m_secondsPerFrame;

				if (m_currentIndex == m_frames.size())
				{
					if (m_loopCounter > 0) m_loopCounter--;
					else if (m_loopCounter == 0) Stop();
					else m_currentIndex = 0;
				}
			}
		}
	}

	bool Animation::Load(const std::string &path, ResourceManager *pManager)
	{
		std::ifstream fileIn(path.c_str(), std::ifstream::in);

		if (fileIn.is_open() && fileIn.good())
		{
			std::string line;

			while (getline(fileIn, line))
			{
				StripComments(line);
				TrimLine(line);
				if (line.empty()) continue;

				if (m_secondsPerFrame == 0)
				{
					m_secondsPerFrame = atof(line.c_str());
					if (m_secondsPerFrame == 0) m_secondsPerFrame = 1.0f / 30.0f;
					SetCurrentFrame(0);
				}
				else
				{
					std::vector<int> elements;
					if (!TryParse<int>(line, elements)) return false;
					m_frames.push_back(new Region(&elements[0]));
				}
			}

			fileIn.close();
		}
		else return false;

		return true;
	}


	void Animation::SetCurrentFrame(const unsigned int index)
	{
		if (index < m_frames.size())
		{
			m_currentIndex = index;
			m_currentFrameTime = m_secondsPerFrame;
		}
	}


	void Animation::Stop()
	{
		Pause();
		SetCurrentFrame(0);
	}

	Resource *Animation::Clone()
	{
		Animation *pClone = new Animation;

		pClone->m_pTexture = m_pTexture;
		pClone->m_frames = m_frames;
		pClone->m_secondsPerFrame = m_secondsPerFrame;
		pClone->m_isPlaying = m_isPlaying;
		pClone->m_currentFrameTime = m_currentFrameTime;
		pClone->m_currentIndex = m_currentIndex;

		return pClone;
	}
}