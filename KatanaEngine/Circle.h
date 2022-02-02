
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
	/** @brief Defines a circle. */
	class Circle : public Primitive
	{

	public:

		/** @brief Instantiates a circle.
			@param radius The radius of the circle.
			@param position The position of the center of the circle. */
		Circle(const float radius = 1, const Vector2 position = Vector2::ZERO)
		{
			Radius = radius;
			Position = position;
		}

		/** @brief Sets the position and radius of the circle.
			@param radius The radius of the circle.
			@param position The position of the center of the circle. */
		void Set(const float radius = 1, const Vector2 position = Vector2::ZERO)
		{
			Radius = radius;
			Position = position;
		}

		/** @brief Renders a filled white circle to the target buffer.
			@param width The stroke width of the circle's outline. */
		virtual void DrawPrimitive() const
		{
			DrawPrimitive(Color::WHITE);
		}

		/** @brief Renders the circle to the target buffer.
			@param color The color to render the circle.

			@overload */
		virtual void DrawPrimitive(const Color &color) const
		{
			DrawPrimitive(color, Color::TRANSPARENT, 0);
		}

		/** @brief Renders the circle's white outline to the target buffer.
			@param width The stroke width of the circle's outline.

			@overload */
		virtual void DrawPrimitive(const float width) const
		{
			DrawPrimitive(Color::WHITE, width);
		}

		/** @brief Renders the circle's outline to the target buffer.
			@param strokeColor The stroke color of the circle's outline.
			@param width The stroke width of the circle's outline.

			@overload */
		virtual void DrawPrimitive(const Color &strokeColor, const float width) const
		{
			DrawPrimitive(Color::TRANSPARENT, strokeColor, width);
		}

		/** @brief Renders the circle to the target buffer.
			@param color The color to render the circle.
			@param strokeColor The stroke color of the circle's outline.
			@param width The stroke width of the circle's outline.

			@overload */
		virtual void DrawPrimitive(const Color &color, const Color &strokeColor,
			const float width = 1) const
		{
			if (color.A > 0 && Radius > 0)
				al_draw_filled_circle(Position.X, Position.Y, Radius, color.ToAllegroColor());

			if (strokeColor.A > 0 && Radius > 0 && width > 0)
				al_draw_circle(Position.X, Position.Y, Radius, strokeColor.ToAllegroColor(), width);
		}

		/** @brief Translates the position of the circle.
			@param offset The vector to translate by. */
		virtual void Translate(const Vector2 &offset)
		{
			Position += offset;
		}


		/** @brief Assigns the reference of a circle.
			@param circle The reference circle.
			@return Returns the resulting circle. */
		Circle &operator= (const Circle &circle)
		{
			if (this != &circle)
			{
				Radius = circle.Radius;
				Position = circle.Position;
			}

			return *this;
		}

		/** @brief Determines if two circles are equal.
			@param circle The circle to compare.
			@return Returns true if the circles are equal, false otherwise. */
		bool operator==(const Circle &circle) const
		{
			return (Radius == circle.Radius && Position == circle.Position);
		}

		/** @brief Determines if two circles are not equal.
			@param circle The circle to compare.
			@return Returns true if the circles are not equal, false otherwise. */
		bool operator!=(const Circle &circle) const
		{
			return (Radius != circle.Radius || Position != circle.Position);
		}


		float Radius = 1;					/**< @brief The radius of the circle. */
		Vector2 Position = Vector2::ZERO;	/**< @brief The position of the center of the circle. */

	};
}