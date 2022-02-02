
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

#pragma message(">")
#pragma message(">")
#pragma message(">        ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ ")
#pragma message(">        ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗")
#pragma message(">        █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║")
#pragma message(">        ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║")
#pragma message(">        ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║")
#pragma message(">        ╚═╝  ╚═╝ ╚═╝  ╚═╝/\\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝")
#pragma message(">      /vvvvvvvvvvvvvvvvvvv \\====================== Game Engine ======,")
#pragma message(">      `^^^^^^^^^^^^^^^^^^^ /----------------- © 2012 - Ryan Appel -\"")
#pragma message(">                         \\/")
#pragma message(">")

/* Standard Headers */
#include <stdlib.h>
#include <malloc.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <map>
#include <unordered_map>
#include <typeindex>


/* Allegro */
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_primitives.h>


/* Timing */
#include "GameTime.h"


/* Math */
#include "MathUtil.h"
#include "Color.h"
#include "Point.h"
#include "Vector2.h"
#include "Region.h"
#include "Primitive.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Bezier.h"


/* Input Handling */
#include "KeyState.h"
#include "GamepadState.h"
#include "MouseState.h"
#include "InputState.h"


/* Resource Management */
#include "Resource.h"
#include "Font.h"
#include "Texture.h"
#include "Animation.h"
#include "ResourceManager.h"


/* Graphics Management */
#include "RenderTarget.h"
#include "SpriteBatch.h"


/* Interfaces */
#include "IService.h"


/* Event Handling */
#include "EventHandlers.h"


/* Screen Management */
#include "MenuItem.h"
#include "Screen.h"
#include "MenuScreen.h"
#include "ScreenManager.h"


/* Game Engine */
#include "GameTime.h"
#include "ServiceContainer.h"
#include "Game.h"
