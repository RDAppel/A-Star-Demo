
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
	/** @brief Defines a line segment. */
	class Line : public Primitive
	{

	public:

		/** @brief Instantiates a line segment.
			@param start The starting point of the line segment.
			@param end The end point of the line segment. */
		Line(const Vector2 start = Vector2::ZERO, const Vector2 end = Vector2::ZERO)
		{
			Start = start;
			End = end;
		}

		/** @brief Sets the end points of the line segment.
			@param start The starting point of the line segment.
			@param end The end point of the line segment. */
		void Set(const Vector2 start = Vector2::ZERO, const Vector2 end = Vector2::ZERO)
		{
			Start = start;
			End = end;
		}

		/** @brief Linearly interpolate between across the curve.
			@param start The result when the value is zero.
			@param end The result when the value is one.
			@param value A value that will indicate the resulting weight between start and end vectors.
			@return Returns the interpolated value. */
		virtual Vector2 Lerp(const float value) const
		{
			return Vector2::Lerp(Start, End, value);
		}

		/** @brief Renders a white line segment to the target buffer. */
		virtual void DrawPrimitive() const
		{
			DrawPrimitive(Color::WHITE, 1);
		}

		/** @brief Renders a white line segment to the target buffer.
			@param width The stroke width of the line segment. */
		virtual void DrawPrimitive(const float width) const
		{
			DrawPrimitive(Color::WHITE, width);
		}

		/** @brief Renders the line segment to the target buffer.
			@param color The color to render the line segment.
			@param width The stroke width of the line segment.
			
			@overload */
		virtual void DrawPrimitive(const Color &color, const float width = 1) const
		{
			if (width > 0 && color.A > 0)
				al_draw_line(Start.X, Start.Y, End.X, End.Y, color.ToAllegroColor(), width);
		}

		/** @brief Translates the position of the line segment.
			@param offset The vector to translate by. */
		virtual void Translate(const Vector2 &offset)
		{
			Start += offset;
			End += offset;
		}


		/** @brief Assigns the reference of a line segment.
			@param line The reference line segment.
			@return Returns the resulting line segment. */
		Line &operator= (const Line &line)
		{
			if (this != &line)
			{
				Start = line.Start;
				End = line.End;
			}

			return *this;
		}

		/** @brief Determines if two line segments are equal.
			@param line The line segment to compare.
			@return Returns true if the line segments are equal, false otherwise. */
		bool operator==(const Line &line) const
		{
			return (Start == line.Start && End == line.End);
		}

		/** @brief Determines if two line segments are not equal.
			@param line The line segment to compare.
			@return Returns true if the line segments are not equal, false otherwise. */
		bool operator!=(const Line &line) const
		{
			return (Start != line.Start || End != line.End);
		}


		Vector2 Start = Vector2::ZERO;	/**< @brief The starting point of the line segment. */
		Vector2 End = Vector2::ZERO;	/**< @brief The end point of the line segment. */

	};
}