
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
	const float Math::PI = 3.14159265359f;
	const float Math::PI_OVER2 = Math::PI / 2;
	const float Math::PI_OVER4 = Math::PI / 4;
	const float Math::INVERSE_PI = 1.0f / Math::PI;
	const float Math::NORMALIZE_PI_OVER4 = 0.70710678119f;
	const float Math::INVERSE_180 = 1.0f / 180;

	float Math::Lerp(const float start, const float end,
		const float value, const bool clamp)
	{
		if (start == end) return start;

		float t = clamp ? Clamp(0, 1, value) : value;
		return start * (1 - t) + end * t;
	}

	float Math::InverseLerp(const float start, const float end,
		const float value, const bool clamp)
	{
		if (start == end) return start;

		float v = clamp ? Clamp(start, end, value) : value;
		return (v - start) / (end - start);
	}

	int Math::GetRandomInt(const int min, const int max)
	{
		return (rand() % (max - min + 1)) + min;
	}
	
	float Math::Min(const float value1, const float value2)
	{
		if (value1 < value2) return value1;
		return value2;
	}

	float Math::Max(const float value1, const float value2)
	{
		if (value1 > value2) return value1;
		return value2;
	}

	float Math::Abs(const float value)
	{
		if (value < 0) return -value;
		else return value;
	}

	float Math::Clamp(const float min, const float max, const float value)
	{
		if (value < min) return min;
		if (value > max) return max;

		return value;
	}
}