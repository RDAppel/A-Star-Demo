
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
	/** @brief Represents a four-component color using red, green, blue, and alpha data. */
	class Color
	{

	public:

		/** @brief Instantiate a color object.
			@param red The red value of the color.
			@param green The green value of the color.
			@param blue The blue value of the color.
			@param alpha The alpha value (opacity) of the color. */
		Color(const float red = 1.0f, const float green = 1.0f, const float blue = 1.0f, const float alpha = 1.0f);

		/** @brief Sets the values of a color object.
			@param red The red value of the color.
			@param green The green value of the color.
			@param blue The blue value of the color.
			@param alpha The alpha value (opacity) of the color. */
		void Set(const float red = 1.0f, const float green = 1.0f, const float blue = 1.0f, const float alpha = 1.0f);

		/** @brief Sets the values of a color object.
			@param array A float array containing the respective red, green, blue, and alpha values. */
		void Set(const float array[4]);

		/** @brief Linearly interpolate between two colors.
			@param start The result when the value is zero.
			@param end The result when the value is one.
			@param value A value between 0 and 1 that will indicate the resulting weight between start and end.
			@return Returns the interpolated color value between start and end. */
		static Color Lerp(const Color &start, const Color &end, const float value);

		/** @brief Gets a string representation of the color.
			@return Returns a string displaying the components of the color. */
		std::string ToString() const;

		/** @brief Prints the color to the console. */
		void Display() const { std::cout << ToString() << std::endl; }

		/** @brief Multiplies each component by a scale factor.
			@param scalar The scale factor.
			@return Returns the scaled color. */
		const Color operator*(const float scalar) const;

		/** @brief Determines if two colors are equal.
			@param color The color to compare.
			@return Returns true if the colors are equal, false otherwise. */
		bool operator==(const Color& color) const;

		/** @brief Determines if two colors are not equal.
			@param color The color to compare.
			@return Returns true if the colors are not equal, false otherwise. */
		bool operator!=(const Color& color) const;

		/** @brief Get the color-equivalent allegro color.
			@return Returns the mapped allegro color. */
		ALLEGRO_COLOR ToAllegroColor() const { return al_map_rgba_f(R, G, B, A); }

		#pragma region Static Colors
		static const Color ALICE_BLUE;			/**< @brief AliceBlue */
		static const Color ANTIQUE_WHITE;		/**< @brief AntiqueWHITE */
		static const Color AQUA;				/**< @brief Aqua */
		static const Color AQUAMARINE;			/**< @brief Aquamarine */
		static const Color AZURE;				/**< @brief Azure */
		static const Color BEIGE;				/**< @brief Beige */
		static const Color BISQUE;				/**< @brief Bisque */
		static const Color BLACK;				/**< @brief Black */
		static const Color BLANCHED_ALMOND;		/**< @brief BlanchedAlmond */
		static const Color BLUE;				/**< @brief Blue */
		static const Color BLUE_VIOLET;			/**< @brief BlueViolet */
		static const Color BROWN;				/**< @brief Brown */
		static const Color BURLYWOOD;			/**< @brief Burlywood */
		static const Color CADET_BLUE;			/**< @brief CadetBlue */
		static const Color CHARTREUSE;			/**< @brief Chartreuse */
		static const Color CHOCOLATE;			/**< @brief Chocolate */
		static const Color CORAL;				/**< @brief Coral */
		static const Color CORNFLOWER;			/**< @brief Cornflower */
		static const Color CORNSILK;			/**< @brief Cornsilk */
		static const Color CRIMSON;				/**< @brief Crimson */
		static const Color CYAN;				/**< @brief Cyan */
		static const Color DARK_BLUE;			/**< @brief DarkBlue */
		static const Color DARK_CYAN;			/**< @brief DarkCyan */
		static const Color DARK_GOLDENROD;		/**< @brief DarkGoldenrod */
		static const Color DARK_GRAY;			/**< @brief DarkGray */
		static const Color DARK_GREEN;			/**< @brief DarkGreen */
		static const Color DARK_KHAKI;			/**< @brief DarkKhaki */
		static const Color DARK_MAGENTA;		/**< @brief DarkMagenta */
		static const Color DARK_OLIVE_GREEN;	/**< @brief DarkOliveGreen */
		static const Color DARK_ORANGE;			/**< @brief DarkOrange */
		static const Color DARK_ORCHID;			/**< @brief DarkOrchid */
		static const Color DARK_RED;			/**< @brief DarkRed */
		static const Color DARK_SALMON;			/**< @brief DarkSalmon */
		static const Color DARK_SEA_GREEN;		/**< @brief DarkSeaGreen */
		static const Color DARK_SLATE_BLUE;		/**< @brief DarkSlateBlue */
		static const Color DARK_SLATE_GRAY;		/**< @brief DarkSlateGray */
		static const Color DARK_TURQUOISE;		/**< @brief DarkTurquoise */
		static const Color DARK_VIOLET;			/**< @brief DarkViolet */
		static const Color DEEP_PINK;			/**< @brief DeepPink */
		static const Color DEEP_SKY_BLUE;		/**< @brief DeepSkyBlue */
		static const Color DIM_GRAY;			/**< @brief DimGray */
		static const Color DODGER_BLUE;			/**< @brief DodgerBlue */
		static const Color FIREBRICK;			/**< @brief Firebrick */
		static const Color FLORAL_WHITE;		/**< @brief FloralWHITE */
		static const Color FOREST_GREEN;		/**< @brief ForestGreen */
		static const Color FUCHSIA;				/**< @brief Fuchsia */
		static const Color GAINSBORO;			/**< @brief Gainsboro */
		static const Color GHOST_WHITE;			/**< @brief GhostWHITE */
		static const Color GOLD;				/**< @brief Gold */
		static const Color GOLDENROD;			/**< @brief Goldenrod */
		static const Color GRAY;				/**< @brief Gray */
		static const Color WEB_GRAY;			/**< @brief WebGray */
		static const Color GREEN;				/**< @brief Green */
		static const Color WEB_GREEN;			/**< @brief WebGreen */
		static const Color GREEN_YELLOW;		/**< @brief GreenYellow */
		static const Color HONEYDEW;			/**< @brief Honeydew */
		static const Color HOT_PINK;			/**< @brief HotPink */
		static const Color INDIAN_RED;			/**< @brief IndianRed */
		static const Color INDIGO;				/**< @brief Indigo */
		static const Color IVORY;				/**< @brief Ivory */
		static const Color KHAKI;				/**< @brief Khaki */
		static const Color LAVENDER;			/**< @brief Lavender */
		static const Color LAVENDER_BLUSH;		/**< @brief LavenderBlush */
		static const Color LAWN_GREEN;			/**< @brief LawnGreen */
		static const Color LEMON_CHIFFON;		/**< @brief LemonChiffon */
		static const Color LIGHT_BLUE;			/**< @brief LightBlue */
		static const Color LIGHT_CORAL;			/**< @brief LightCoral */
		static const Color LIGHT_CYAN;			/**< @brief LightCyan */
		static const Color LIGHT_GOLDENROD;		/**< @brief LightGoldenrod */
		static const Color LIGHT_GRAY;			/**< @brief LightGray */
		static const Color LIGHT_GREEN;			/**< @brief LightGreen */
		static const Color LIGHT_PINK;			/**< @brief LightPink */
		static const Color LIGHT_SALMON;		/**< @brief LightSalmon */
		static const Color LIGHT_SEA_GREEN;		/**< @brief LightSeaGreen */
		static const Color LIGHT_SKY_BLUE;		/**< @brief LightSkyBlue */
		static const Color LIGHT_SLATE_GRAY;	/**< @brief LightSlateGray */
		static const Color LIGHT_STEEL_BLUE;	/**< @brief LightSteelBlue */
		static const Color LIGHT_YELLOW;		/**< @brief LightYellow */
		static const Color LIME;				/**< @brief Lime */
		static const Color LIME_GREEN;			/**< @brief LimeGreen */
		static const Color LINEN;				/**< @brief Linen */
		static const Color MAGENTA;				/**< @brief Magenta */
		static const Color MAROON;				/**< @brief Maroon */
		static const Color WEB_MAROON;			/**< @brief WebMaroon */
		static const Color MEDIUM_AQUAMARINE;	/**< @brief MediumAquamarine */
		static const Color MEDIUM_BLUE;			/**< @brief MediumBlue */
		static const Color MEDIUM_ORCHID;		/**< @brief MediumOrchid */
		static const Color MEDIUM_PURPLE;		/**< @brief MediumPurple */
		static const Color MEDIUM_SEA_GREEN;	/**< @brief MediumSeaGreen */
		static const Color MEDIUM_SLATE_BLUE;	/**< @brief MediumSlateBlue */
		static const Color MEDIUM_SPRING_GREEN;	/**< @brief MediumSpringGreen */
		static const Color MEDIUM_TURQUOISE;	/**< @brief MediumTurquoise */
		static const Color MEDIUM_VIOLET_RED;	/**< @brief MediumVioletRed */
		static const Color MIDNIGHT_BLUE;		/**< @brief MidnightBlue */
		static const Color MINT_CREAM;			/**< @brief MintCream */
		static const Color MISTY_ROSE;			/**< @brief MistyRose */
		static const Color MOCCASIN;			/**< @brief Moccasin */
		static const Color NAVAJO_WHITE;		/**< @brief NavajoWHITE */
		static const Color NAVY_BLUE;			/**< @brief NavyBlue */
		static const Color OLD_LACE;			/**< @brief OldLace */
		static const Color OLIVE;				/**< @brief Olive */
		static const Color OLIVE_DRAB;			/**< @brief OliveDrab */
		static const Color ORANGE;				/**< @brief Orange */
		static const Color ORANGE_RED;			/**< @brief OrangeRed */
		static const Color ORCHID;				/**< @brief Orchid */
		static const Color PALE_GOLDENROD;		/**< @brief PaleGoldenrod */
		static const Color PALE_GREEN;			/**< @brief PaleGreen */
		static const Color PALE_TURQUOISE;		/**< @brief PaleTurquoise */
		static const Color PALE_VIOLET_RED;		/**< @brief PaleVioletRed */
		static const Color PAPAYA_WHIP;			/**< @brief PapayaWhip */
		static const Color PEACH_PUFF;			/**< @brief PeachPuff */
		static const Color PERU;				/**< @brief Peru */
		static const Color PINK;				/**< @brief Pink */
		static const Color PLUM;			 	/**< @brief Plum */
		static const Color POWDER_BLUE;			/**< @brief PowderBlue */
		static const Color PURPLE;				/**< @brief Purple */
		static const Color WEB_PURPLE;			/**< @brief WebPurple */
		static const Color REBECCA_PURPLE;		/**< @brief RebeccaPurple */
		static const Color RED;					/**< @brief Red */
		static const Color ROSY_BROWN;			/**< @brief RosyBrown */
		static const Color ROYAL_BLUE;			/**< @brief RoyalBlue */
		static const Color SADDLE_BROWN;		/**< @brief SaddleBrown */
		static const Color SALMON;				/**< @brief Salmon */
		static const Color SANDY_BROWN;			/**< @brief SandyBrown */
		static const Color SEA_GREEN;			/**< @brief SeaGreen */
		static const Color SEASHELL;			/**< @brief Seashell */
		static const Color SIENNA;				/**< @brief Sienna */
		static const Color SILVER;				/**< @brief Silver */
		static const Color SKY_BLUE;			/**< @brief SkyBlue */
		static const Color SLATE_BLUE;			/**< @brief SlateBlue */
		static const Color SLATE_GRAY;			/**< @brief SlateGray */
		static const Color SNOW;				/**< @brief Snow */
		static const Color SPRING_GREEN;		/**< @brief SpringGreen */
		static const Color STEEL_BLUE;			/**< @brief SteelBlue */
		static const Color TAN;					/**< @brief Tan */
		static const Color TEAL;				/**< @brief Teal */
		static const Color THISTLE;				/**< @brief Thistle */
		static const Color TOMATO;				/**< @brief Tomato */
		static const Color TURQUOISE;			/**< @brief Turquoise */
		static const Color VIOLET;				/**< @brief Violet */
		static const Color WHEAT;				/**< @brief Wheat */
		static const Color WHITE;				/**< @brief WHITE */
		static const Color WHITE_SMOKE;			/**< @brief WHITESmoke */
		static const Color YELLOW;				/**< @brief Yellow */
		static const Color YELLOW_GREEN;		/**< @brief YellowGreen */

		static const Color TRANSPARENT;			/**< @brief Transparent */
		#pragma endregion

		float R = 1.0f;
		float G = 1.0f;
		float B = 1.0f;
		float A = 1.0f;

	};
}