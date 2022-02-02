
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
	class Vector2;

	/** @brief 	Defines a point in 2d space. */
	class Point
	{

	public:


		static const Point ORIGIN;	/**< @brief A point located at the origin. */

		/** @brief Instantiates a point.
			@param x The X component
			@param y The Y component */
		Point(const int x = 0, const int y = 0) { X = x; Y = y; }

		/** @brief Instantiates a point.
			@param array An array which first two elements will be used to
			initialize X, and Y respectively.

			@overload */
		Point(const int array[2]) : Point(array[0], array[1]) { }

		/** @brief Sets the components of the point.
			@param x The X component.
			@param y The Y component. */
		void Set(const int x, const int y);

		/** @brief Sets the components of the point.
			@param point The point whose components to copy.
			
			@overload */
		void Set(const Point &point);

		// todo: comment
		void Set(const int array[2]);

		/** @brief Determines if the point is located at the origin.
			@return Returns true if both components are zero, false otherwise. */
		bool IsOrigin() const { return (X == 0 && Y == 0); }

		/** @brief Converts the point into a vector.
			@return Returns a displacement vector to the point. */
		const Vector2 ToVector2() const;

		/** @brief Gets a string representation of the point.
			@return Returns a string displaying the components of the point. */
		std::string ToString() const;

		/** @brief Prints the point to the console. */
		void Display() const { std::cout << ToString() << std::endl; }


		/** @brief Assigns the reference of a point.
			@param point The reference point.
			@return Returns the resulting point. */
		Point &operator= (const Point &point);

		/** @brief Adds a point.
			@param point The point to add.
			@return Returns the resulting point. */
		Point &operator+=(const Point &point);

		/** @brief Subtracts a point.
			@param point The point to subtract.
			@return Returns the resulting point. */
		Point &operator-=(const Point &point);

		/** @brief Adds two points.
			@param point The point to add.
			@return Returns the resulting point. */
		const Point operator+(const Point &point) const;

		/** @brief Subtracts a point from another.
			@param point The point to subtract.
			@return Returns the resulting point. */
		const Point operator-(const Point &point) const;

		/** @brief Determines if two points are equal.
			@param point The point to compare.
			@return Returns true if the points are equal, false otherwise. */
		bool operator==(const Point &point) const;

		/** @brief Determines if two points are not equal.
			@param point The point to compare.
			@return Returns true if the points are not equal, false otherwise. */
		bool operator!=(const Point &point) const;

		/** @brief Allows for implicit cast to Vector2 type.
			@return Returns true if the points are not equal, false otherwise. */
		operator Vector2() const;


		int X = 0;	/**< @brief The x-coordinate of the point. */
		int Y = 0;	/**< @brief The y-coordinate of the point. */

	};
}