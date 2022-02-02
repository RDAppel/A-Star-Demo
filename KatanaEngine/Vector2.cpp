
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
	const Vector2 Vector2::ZERO = Vector2(0, 0);
	const Vector2 Vector2::ONE = Vector2(1, 1);
	const Vector2 Vector2::UNIT_X = Vector2(1, 0);
	const Vector2 Vector2::UNIT_Y = Vector2(0, 1);
	
	float Vector2::LengthSquared() const
	{
		return ((X * X) + (Y * Y));
	}

	float Vector2::Length() const
	{
		return sqrtf(X * X + Y * Y);
	}

	void Vector2::Normalize()
	{
		if (!IsZero())
		{
			float length = Length();
			X /= length;
			Y /= length;
		}
	}
	
	float Vector2::DotProduct(const Vector2 &vector) const
	{
		return (X * vector.X) + (Y * vector.Y);
	}

	float Vector2::CrossProduct(const Vector2 &vector) const
	{
		return (X * vector.Y) - (Y * vector.X);
	}

	float Vector2::Distance(const Vector2 &vector1, const Vector2 &vector2)
	{
		return sqrtf(pow((vector2.X - vector1.X), 2) + pow((vector2.Y - vector1.Y), 2));
	}

	float Vector2::DistanceSquared(const Vector2 &vector1, const Vector2 &vector2)
	{
		return pow((vector2.X - vector1.X), 2) + pow((vector2.Y - vector1.Y), 2);
	}

	Vector2 Vector2::Lerp(const Vector2 &start, const Vector2 &end,
		const float value, const bool clamp)
	{
		float t = clamp ? Math::Clamp(0, 1, value) : value;
		return start * (1 - t) + end * t;
	}

	Vector2 Vector2::GetRandom(bool normalize)
	{
		float x = Math::GetRandomFloat() * 2 - 1;
		float y = Math::GetRandomFloat() * 2 - 1;

		Vector2 result(x, y);
		if (normalize) result.Normalize();

		return result;
	}

	Vector2 Vector2::GetNormal() const
	{
		if (IsZero()) return Vector2::ZERO;

		float length = Length();
		return Vector2(X / length, Y / length);
	}

	std::string Vector2::ToString() const
	{
		std::ostringstream ss;
		ss << "{ " << X << ", " << Y << " }";
		return ss.str();
	}

	const Point Vector2::ToPoint() const
	{
		return Point((int)X, (int)Y);
	}

	Vector2 &Vector2::operator=(const Vector2 &vector)
	{
		if (this != &vector)
		{
			X = vector.X;
			Y = vector.Y;
		}

		return *this;
	}

	Vector2 &Vector2::operator+=(const Vector2 &vector)
	{
		X += vector.X;
		Y += vector.Y;

		return *this;
	}

	Vector2 &Vector2::operator-=(const Vector2 &vector)
	{
		X -= vector.X;
		Y -= vector.Y;

		return *this;
	}

	Vector2 &Vector2::operator*=(const Vector2 &vector)
	{
		X *= vector.X;
		Y *= vector.Y;

		return *this;
	}

	Vector2 &Vector2::operator/=(const Vector2 &vector)
	{
		X /= vector.X;
		Y /= vector.Y;

		return *this;
	}

	Vector2 &Vector2::operator*=(const float &scalar)
	{
		X *= scalar;
		Y *= scalar;

		return *this;
	}

	Vector2 &Vector2::operator/=(const float &scalar)
	{
		X /= scalar;
		Y /= scalar;

		return *this;
	}

	const Vector2 Vector2::operator+(const Vector2 &vector) const
	{
		return Vector2(*this) += vector;
	}

	const Vector2 Vector2::operator-(const Vector2 &vector) const
	{
		return Vector2(*this) -= vector;
	}

	bool Vector2::operator==(const Vector2 &vector) const
	{
		return (X == vector.X && Y == vector.Y);
	}

	bool Vector2::operator!=(const Vector2 &vector) const
	{
		return (X != vector.X || Y != vector.Y);
	}

	// Scalar Operator Functions

	/** @brief Multiplies a vector by a scalar.
		@param scalar The scalar to multiply by.
		@param vector The vector to scale.
		@return Returns the resulting vector. */
	Vector2 operator*(const float &scalar, const Vector2 &vector)
	{
		return Vector2(vector.X * scalar, vector.Y * scalar);
	}

	/** @brief Multiplies a vector by a scalar.
		@param vector The vector to scale.
		@param scalar The scalar to multiply by.
		@return Returns the resulting vector. */
	Vector2 operator*(const Vector2 &vector, const float &scalar)
	{
		return Vector2(vector.X * scalar, vector.Y * scalar);
	}

	/** @brief Divides a vector by a scalar.
		@param scalar The scalar to divided by.
		@param vector The vector to scale.
		@return Returns the resulting vector. */
	Vector2 operator/(const float &scalar, const Vector2 &vector)
	{
		return Vector2(vector.X / scalar, vector.Y / scalar);
	}

	/** @brief Divides a vector by a scalar.
		@param vector The vector to scale.
		@param scalar The scalar to divided by.
		@return Returns the resulting vector. */
	Vector2 operator/(const Vector2 &vector, const float &scalar)
	{
		return Vector2(vector.X / scalar, vector.Y / scalar);
	}
}