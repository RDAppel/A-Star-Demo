
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
	/** @brief Defines a vector with 2 components (x and y).
		This is additional information... */
	class Vector2
	{

	public:


		static const Vector2 ZERO;		/**< @brief A vector with both of its components set to zero. */
		static const Vector2 ONE;		/**< @brief A vector with both of its components set to one. */
		static const Vector2 UNIT_X;	/**< @brief A unit vector on the x-axis. */
		static const Vector2 UNIT_Y;	/**< @brief A unit vector on the y-axis. */

		/** @brief Instantiates a new Vector2 object.
			@param x The X component.
			@param y The Y component. */
		Vector2(const float x = 0, const float y = 0) { X = x, Y = y; }

		/** @brief Instantiates a new Vector2 object.
			@param array An array which first two elements will be used to
			initialize X, and Y respectively.
			
			@overload */
		Vector2(const float array[2]) : Vector2(array[0], array[1]) { }

		/** @brief Calculates the length of the vector squared.
			@return float The length of the vector squared. */
		float LengthSquared() const;

		/** @brief Calculates the length of the vector.
			@return The length of the vector. */
		float Length() const;

		/** @brief Sets the components of the vector.
			@param x The X component.
			@param y The Y component. */
		void Set(const float x, const float y) { X = x; Y = y; }

		/** @brief Sets the components of the vector.
			@param vector The vector whose components to copy.

			@overload */
		void Set(const Vector2 vector) { Set(vector.X, vector.Y); }

		/** @brief Resize a vector to a length of one unit. If the starting vector is the
			zero vector, the call will be ignored. */
		void Normalize();

		/** @brief Determines if the vector is the zero vector.
			@return Returns true if both components are zero, false otherwise. */
		bool IsZero() const { return (X == 0 && Y == 0); }

		/** @brief Calculates the dot product of two vectors.
			@param vector The other vector.
			@return The calculated dot product.
			@remark If the two vectors are unit vectors, the dot product returns a floating
			point value between -1 and 1 that can be used to determine some properties of the
			angle between two vectors. For example, it can show whether the vectors are
			orthogonal, parallel, or have an acute or obtuse angle between them. */
		float DotProduct(const Vector2 &vector) const;

		/** @brief Calculates the cross product between two vectors.
			@param vector The other vector.
			@return The calculated cross product. */
		float CrossProduct(const Vector2 &vector) const;

		/** @brief Calculates the distance between two vectors.
			@param vector1 The first vector.
			@param vector2 The second vector.
			@return The calculated distance. */
		static float Distance(const Vector2 &vector1, const Vector2 &vector2);

		/** @brief Calculates the distance squared between two vectors.
			@param vector1 The first vector.
			@param vector2 The second vector.
			@return The calculated distance squared. */
		static float DistanceSquared(const Vector2 &vector1, const Vector2 &vector2);

		/** @brief Linearly interpolate between two vectors.
			@param start The result when the value is zero.
			@param end The result when the value is one.
			@param value A value that will indicate the resulting weight between start and end.
			@param clamp If set to true the input value will be clamped between zero and one. If the input
			value is not clamped, the return value may not be between start and end.
			@return Returns the interpolated value. */
		static Vector2 Lerp(const Vector2 &start, const Vector2 &end,
			const float value, const bool clamp = false);

		/** @brief Creates a random vector.
			@param normalize Specify true to generate a unit vector. False will generate
			a vector with a random length.
			@return The random vector. */
		static Vector2 GetRandom(bool normalize = false);

		/** @brief Calculates the left-hand orthogonal vector.
			@return Returns the left vector. */
		Vector2 Left() const { return Vector2(-Y, X); }

		/** @brief Calculates the right-hand orthogonal vector.
			@return Returns the right vector. */
		Vector2 Right() const { return Vector2(Y, -X); }

		/** @brief Calculates normal of this vector.
			@return Returns a new vector of unit length.
			@remark If the source vector is the zero vector, a new zero
			vector will be returned. */
		Vector2 GetNormal() const;

		/** @brief Converts the vector into a point.
			@return Returns the closest point to the vector displacement. */
		const Point ToPoint() const;

		/** @brief Gets a string representation of the vector.
			@return Returns a string displaying the components of the vector. */
		std::string ToString() const;

		/** @brief Prints the vector to the console. */
		void Display() const { std::cout << ToString() << std::endl; }

		/** @brief Assigns the reference of a vector.
			@param vector The reference vector.
			@return Returns the resulting vector. */
		Vector2 &operator= (const Vector2 &vector);

		/** @brief Adds a vector.
			@param vector The vector to add.
			@return Returns the resulting vector. */
		Vector2 &operator+=(const Vector2 &vector);

		/** @brief Subtracts a vector.
			@param vector The vector to subtract.
			@return Returns the resulting vector. */
		Vector2 &operator-=(const Vector2 &vector);

		/** @brief Multiplies a vector.
			@param vector The vector to multiply by.
			@return Returns the resulting vector. */
		Vector2 &operator*=(const Vector2 &vector);

		/** @brief Divides a vector.
			@param vector The vector to multiply by.
			@return Returns the resulting vector. */
		Vector2 &operator/=(const Vector2 &vector);

		/** @brief Multiplies by a scalar.
			@param scalar The scalar to multiply by.
			@return Returns the resulting vector. */
		Vector2 &operator*=(const float &scalar);

		/** @brief Divides by a scalar.
			@param scalar The scalar to divide by.
			@return Returns the resulting vector. */
		Vector2 &operator/=(const float &scalar);

		/** @brief Negates the vector.
			@return Returns the resulting vector. */
		const Vector2 operator-() const { return Vector2(-X, -Y); }

		/** @brief Adds two vectors.
			@param vector The vector to add.
			@return Returns the resulting vector. */
		const Vector2 operator+(const Vector2 &vector) const;

		/** @brief Subtracts a vector from another.
			@param vector The vector to subtract.
			@return Returns the resulting vector. */
		const Vector2 operator-(const Vector2 &vector) const;

		/** @brief Determines if two vectors are equal.
			@param vector The vector to compare.
			@return Returns true if the vectors are equal, false otherwise. */
		bool operator==(const Vector2 &vector) const;

		/** @brief Determines if two vectors are not equal.
			@param vector The vector to compare.
			@return Returns true if the vectors are not equal, false otherwise. */
		bool operator!=(const Vector2 &vector) const;


		float X = 0;	/**< @brief The x-coordinate of the vector. */
		float Y = 0;	/**< @brief The y-coordinate of the vector. */

	};

	// Scalar Operator Functions

	/** @brief Multiplies a vector by a scalar.
		@param scalar The scalar to multiply by.
		@param vector The vector to scale.
		@return Returns the resulting vector. */
	Vector2 operator*(const float &scalar, const Vector2 &vector);

	/** @brief Multiplies a vector by a scalar.
		@param vector The vector to scale.
		@param scalar The scalar to multiply by.
		@return Returns the resulting vector. */
	Vector2 operator*(const Vector2 &vector, const float &scalar);

	/** @brief Divides a vector by a scalar.
		@param scalar The scalar to divided by.
		@param vector The vector to scale.
		@return Returns the resulting vector. */
	Vector2 operator/(const float &scalar, const Vector2 &vector);

	/** @brief Divides a vector by a scalar.
		@param vector The vector to scale.
		@param scalar The scalar to divided by.
		@return Returns the resulting vector. */
	Vector2 operator/(const Vector2 &vector, const float &scalar);
}