﻿
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
	ALLEGRO_DISPLAY *RenderTarget::s_pDisplay = nullptr;

	RenderTarget::RenderTarget(const int width, const int height)
	{
		ALLEGRO_BITMAP *pBitmap = al_create_bitmap(width, height);

		SetTexture(pBitmap);
	}

	void RenderTarget::Set(RenderTarget *pTarget)
	{
		if (pTarget) al_set_target_bitmap(pTarget->GetAllegroBitmap());
		else al_set_target_bitmap(al_get_backbuffer(s_pDisplay));
	}
}
