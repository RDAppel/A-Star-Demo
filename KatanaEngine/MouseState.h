
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

	/** @brief Defines the buttons for a mouse. */
	enum class MouseButton
	{
		NONE	= 0,
		LEFT	= 1 << 0,	/**< Represents the Left mouse button. */
		RIGHT	= 1 << 1,	/**< Represents the Right mouse button. */
		CENTER	= 1 << 2,	/**< Represents the Center mouse button. */
		BACK	= 1 << 3,	/**< Represents the Back mouse button. */
		FORWARD	= 1 << 4,	/**< Represents the Foreward mouse button. */

		MAX		= 1 << 5	/**< Represents the Max value for all mouse buttons. */
	};

	/** @brief Defines the system cursors for the mouse pointer. */
	enum class MouseCursor
	{
		NONE = 0,		/**< Represents the no cursor. */
		DEFAULT,		/**< Represents the default cursor. */
		ARROW,			/**< Represents the arrow cursor. */
		BUSY,			/**< Represents the busy cursor. */
		QUESTION,		/**< Represents the question cursor. */
		EDIT,			/**< Represents the edit cursor. */
		MOVE,			/**< Represents the move cursor. */
		RESIZE_N,		/**< Represents the resize north cursor. */
		RESIZE_W,		/**< Represents the resize west cursor. */
		RESIZE_S,		/**< Represents the resize south cursor. */
		RESIZE_E,		/**< Represents the resize east cursor. */
		RESIZE_NW,		/**< Represents the resize north-west cursor. */
		RESIZE_SW,		/**< Represents the resize south-west cursor. */
		RESIZE_SE,		/**< Represents the resize south-east cursor. */
		RESIZE_NE,		/**< Represents the resize north-east cursor. */
		PROGRESS,		/**< Represents the progress cursor. */
		PRECISION,		/**< Represents the precision cursor. */
		LINK,			/**< Represents the link hand cursor. */
		ALT_SELECT,		/**< Represents the alternate select cursor. */
		UNAVAILABLE,	/**< Represents the unavailable cursor. */

		MAX				/**< Represents the Max value for all cursors. */
	};
}