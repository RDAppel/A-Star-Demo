
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
	const Point Point::ORIGIN = Point(0, 0);

	void Point::Set(const int x, const int y)
	{
		X = x;
		Y = y;
	}

	void Point::Set(const Point &point)
	{
		Set(point.X, point.Y);
	}

	void Point::Set(const int array[2])
	{
		Set(array[0], array[1]);
	}

	std::string Point::ToString() const
	{
		std::ostringstream ss;
		ss << "{ " << X << ", " << Y << " }";
		return ss.str();
	}

	const Vector2 Point::ToVector2() const
	{
		return Vector2(X, Y);
	}

	Point &Point::operator=(const Point &point)
	{
		if (this != &point)
		{
			X = point.X;
			Y = point.Y;
		}

		return *this;
	}

	Point &Point::operator+=(const Point &point)
	{
		X += point.X;
		Y += point.Y;

		return *this;
	}

	Point &Point::operator-=(const Point &point)
	{
		X -= point.X;
		Y -= point.Y;

		return *this;
	}

	const Point Point::operator+(const Point &point) const
	{
		return Point(*this) += point;
	}

	const Point Point::operator-(const Point &point) const
	{
		return Point(*this) -= point;
	}

	bool Point::operator== (const Point &point) const
	{
		return ((X == point.X) && (Y == point.Y));
	}

	bool Point::operator!= (const Point &point) const
	{
		return !((X == point.X) && (Y == point.Y));
	}

	Point::operator Vector2() const { return Vector2(X, Y); }
}