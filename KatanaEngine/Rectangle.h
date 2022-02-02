
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
	/** @brief Defines a Rectangle. */
	class Rectangle : public Primitive
	{

	public:

		/** @brief Instantiates a rectangle.
			@param size The size of the rectangle.
			@param position The top left corner position. */
		Rectangle(Vector2 size = Vector2::ONE, Vector2 position = Vector2::ZERO)
		{
			Position = position;
			Size = size;
		}

		/** @brief Sets the end size and position of the rectangle.
			@param size The size of the Rectangle.
			@param position The top left corner position. */
		void Set(Vector2 size = Vector2::ONE, Vector2 position = Vector2::ZERO)
		{
			Position = position;
			Size = size;
		}

		/** @brief Renders a filled white rectangle to the target buffer.
			@param width The stroke width of the rectangle's outline. */
		virtual void DrawPrimitive() const
		{
			DrawPrimitive(Color::WHITE);
		}

		/** @brief Renders the rectangle to the target buffer.
			@param color The color to render the rectangle.

			@overload */
		virtual void DrawPrimitive(const Color &color) const
		{
			DrawPrimitive(color, Color::TRANSPARENT, 0);
		}

		/** @brief Renders the rectangle's white outline to the target buffer.
			@param width The stroke width of the rectangle's outline.

			@overload */
		virtual void DrawPrimitive(const float width) const
		{
			DrawPrimitive(Color::WHITE, width);
		}

		/** @brief Renders the rectangle's outline to the target buffer.
			@param strokeColor The stroke color of the rectangle's outline.
			@param width The stroke width of the rectangle's outline.

			@overload */
		virtual void DrawPrimitive(const Color &strokeColor, const float width) const
		{
			DrawPrimitive(Color::TRANSPARENT, strokeColor, width);
		}

		/** @brief Renders the rectangle to the target buffer.
			@param color The color to render the rectangle.
			@param strokeColor The stroke color of the rectangle's outline.
			@param width The stroke width of the rectangle's outline.

			@overload */
		virtual void DrawPrimitive(const Color &color, const Color &strokeColor,
			const float width = 1) const
		{
			if (Size.X <= 0 || Size.Y <= 0) return;

			Vector2 position2 = BottomRightCorner();

			if (color.A > 0)
				al_draw_filled_rectangle(Position.X, Position.Y,
					position2.X, position2.Y, color.ToAllegroColor());

			if (strokeColor.A > 0)
				al_draw_rectangle(Position.X, Position.Y,
					position2.X, position2.Y, strokeColor.ToAllegroColor(), width);
		}

		/** @brief Translates the position of the rectangle.
			@param offset The vector to translate by. */
		virtual void Translate(const Vector2 &offset)
		{
			Position += offset;
		}

		/** @brief Gets the top of the rectangle. */
		virtual float Top() const { return Position.Y; }

		/** @brief Gets the left side of the rectangle. */
		virtual float Left() const { return Position.X; }

		/** @brief Gets the right side of the rectangle. */
		virtual float Right() const { return Position.X + Size.X; }

		/** @brief Gets the bottom of the rectangle. */
		virtual float Bottom() const { return Position.Y + Size.Y; }

		/** @brief Gets the top left corner of the rectangle. */
		virtual Vector2 TopLeftCorner() const { return Position; }

		/** @brief Gets the top right corner of the rectangle. */
		virtual Vector2 TopRightCorner() const { return Position + WidthVector(); }

		/** @brief Gets the bottom left corner of the rectangle. */
		virtual Vector2 BottomLeftCorner() const { return Position + HeightVector(); }

		/** @brief Gets the bottom right corner of the rectangle. */
		virtual Vector2 BottomRightCorner() const { return Position + Size; }

		/** @brief Gets the width of the rectangle as a Vector2. */
		virtual Vector2 WidthVector() const { return Vector2::UNIT_X * Size.X; }

		/** @brief Gets the height of the rectangle as a Vector2. */
		virtual Vector2 HeightVector() const { return Vector2::UNIT_Y * Size.Y; }


		/** @brief Assigns the reference of a rectangle.
			@param rectangle The reference rectangle.
			@return Returns the resulting rectangle. */
		Rectangle &operator= (const Rectangle &rectangle)
		{
			if (this != &rectangle)
			{
				Size = rectangle.Size;
				Position = rectangle.Position;
			}

			return *this;
		}

		/** @brief Determines if two rectangles are equal.
			@param rectangle The rectangle to compare.
			@return Returns true if the rectangles are equal, false otherwise. */
		bool operator==(const Rectangle &rectangle) const
		{
			return (Size == rectangle.Size && Position == rectangle.Position);
		}

		/** @brief Determines if two rectangles are not equal.
			@param rectangle The rectangle to compare.
			@return Returns true if the rectangles are not equal, false otherwise. */
		bool operator!=(const Rectangle &rectangle) const
		{
			return (Size != rectangle.Size || Position != rectangle.Position);
		}

		
		Vector2 Size;		/**< @brief The size of the Rectangle. */
		Vector2 Position;	/**< @brief The top left corner position. */
	};
}