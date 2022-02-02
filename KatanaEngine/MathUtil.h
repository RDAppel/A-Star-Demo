
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
	/** @brief Provides commonly used floating point functions and constants. */
	class Math
	{

	public:

		static const float PI;					/**< @brief Represents the value of pi. */
		static const float PI_OVER2;			/**< @brief Represents the value of pi divided by two. */
		static const float PI_OVER4;			/**< @brief Represents the value of pi divided by four. */
		static const float INVERSE_PI;			/**< @brief Represents the value of one divided by pi. */
		static const float NORMALIZE_PI_OVER4;	/**< @brief Represents the value of each component in a pi/4 unit vector. */
		static const float INVERSE_180;			/**< @brief Represents the value of one divided by 180. */


		/** @brief Linearly interpolate between two values.
			@param start The starting value.
			@param end The end value.
			@param value A value (t) that will indicate the resulting weight between start and end.
			@param clamp If set to true the input value will be clamped between zero and one. If the input
			value is not clamped, the return value may not be between start and end.
			@return Returns the interpolated value. */
		static float Lerp(const float start, const float end,
			const float value, const bool clamp = false);

		/** @brief Calculates the inverse of Lerp.
			@param start The starting value.
			@param end The end value.
			@param value A value (usually between start and end) used to find the percentage.
			@param clamp If set to true the input value will be clamped between start and end. If the input
			value is not clamped, the return value may not be between one and zero.
			@return Returns the inverse interpolated (t) value. */
		static float InverseLerp(const float start, const float end,
			const float value, const bool clamp = false);

		/** @brief Get a random integer.
			@param min The inclusive minimum number.
			@param max The inclusive maximum number.
			@return Returns a random integer between min and max. */
		static int GetRandomInt(const int min = 0, const int max = RAND_MAX);

		/** @brief Get a random number between zero and one.
			@return Returns a random floating point number between zero and one. */
		static float GetRandomFloat() { return ((float)rand() / RAND_MAX); }

		/** @brief Get the lessor of two numbers.
			@param value1 The first value.
			@param value2 The second value.
			@return Returns the lessor number between two values. */
		static float Min(const float value1, const float value2);

		/** @brief Get the greator of two numbers.
			@param value1 The first value.
			@param value2 The second value.
			@return Returns the greator number between two values. */
		static float Max(const float value1, const float value2);

		/** @brief Get the absolute value of a number.
			@param value The positive or negative value.
			@return Returns the absolute value. */
		static float Abs(const float value);

		/** @brief Restricts a value to be within a specified range.
			@param min The minimum value. If value is less than min, min will be returned.
			@param max The maximum value. If value is greater than max, max will be returned.
			@param value The value to clamp.
			@return Returns the clamped value between min and max. */
		static float Clamp(const float min, const float max, const float value);

		/** @brief Converts degrees to radians.
			@param degrees The angle in degrees.
			@return Returns the angle in radians. */
		static float ToRadians(const float degrees) { return degrees * PI * INVERSE_180; }

		/** @brief Converts radians to degrees.
			@param radians The angle in radians.
			@return Returns the angle in degrees. */
		static float ToDegrees(const float radians) { return radians * 180 * INVERSE_PI; }
	};
}