
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
	/** @brief Defines a cubic bezier curve. */
	class Bezier : public Primitive
	{

	public:

		/** @brief Instantiates a bezier curve.
			@param points An array of four points that define the
			start, end, and two control points of the curve. */
		Bezier(Vector2 points[4])
			: Bezier(points[0], points[1], points[2], points[3])
		{ }

		/** @brief Instantiates a bezier curve.
			@param p0 The starting point of the curve.
			@param p1 The first control point.
			@param p2 The second control point.
			@param p3 The end point of the curve.
			
			@overload */
		Bezier(Vector2 p0 = Vector2::ZERO, Vector2 p1 = Vector2::ZERO,
			Vector2 p2 = Vector2::ZERO, Vector2 p3 = Vector2::ZERO)
		{
			P0 = p0; P1 = p1; P2 = p2; P3 = p3;
		}

		/** @brief Linearly interpolate between across the curve.
			@param start The result when the value is zero.
			@param end The result when the value is one.
			@param value A value that will indicate the resulting weight between start and end vectors.
			@return Returns the interpolated value. */
		virtual Vector2 Lerp(const float value) const
		{
			const float t = value;
			const float t2 = t * t;
			const float t3 = t2 * t;
			const float s0 = -t3 + 3 * t2 - 3 * t + 1;
			const float s1 = 3 * t3 - 6 * t2 + 3 * t;
			const float s2 = -3 * t3 + 3 * t2;
			const float s3 = t3;
			return s0 * P0 + s1 * P1 + s2 * P2 + s3 * P3;
		}

		/** @brief Calculates the velocity for a specific point on the curve.
			@param value The t value representing a liner position on the curve.
			@return Returns the velocity vector for the specified t value. */
		virtual Vector2 CalculateVelocity(const float value) const
		{
			const float t = value;
			const float t2 = t * t;
			const float s0 = -3 * t2 + 6 * t - 3;
			const float s1 = 9 * t2 - 12 * t + 3;
			const float s2 = -9 * t2 + 6 * t;
			const float s3 = 3 * t2;
			return s0 * P0 + s1 * P1 + s2 * P2 + s3 * P3;
		}

		/** @brief Calculates the acceleration for a specific point on the curve.
			@param value The t value representing a liner position on the curve.
			@return Returns the acceleration vector for the specified t value. */
		virtual Vector2 CalculateAcceleration(const float value) const
		{
			const float t = value;
			const float s0 = -6 * t + 6;
			const float s1 = 18 * t - 12;
			const float s2 = -18 * t + 6;
			const float s3 = 6 * t;
			return s0 * P0 + s1 * P1 + s2 * P2 + s3 * P3;
		}

		/** @brief Calculates the curvature for a specific point on the curve.
			@param value The t value representing a liner position on the curve.
			@return Returns the curvature k for the specified t value. */
		virtual float CalculateCurvature(const float value) const
		{
			Vector2 v = CalculateVelocity(value);
			float vLength = v.Length();

			if (vLength == 0) return 0;

			Vector2 a = CalculateAcceleration(value);
			float det = v.X * a.Y - v.Y * a.X;
			return det / (powf(vLength, 3));
		}

		/** @brief Renders the curve to the target buffer. */
		virtual void DrawPrimitive() const
		{
			DrawPrimitive(Color::WHITE, 1);
		}

		/** @brief Renders the curve to the target buffer.
			@param width The stroke width of the curve. */
		virtual void DrawPrimitive(const float width) const
		{
			DrawPrimitive(Color::WHITE, width);
		}

		/** @brief Renders the curve to the target buffer.
			@param color The color to render the curve.
			@param width The stroke width of the curve.

			@overload */
		virtual void DrawPrimitive(const Color &color, const float width = 1) const
		{
			if (width > 0 && color.A > 0)
			{
				float points[8] =
				{ P0.X, P0.Y, P1.X, P1.Y, P2.X, P2.Y, P3.X, P3.Y };
				al_draw_spline(points, color.ToAllegroColor(), width);
			}
		}

		/** @brief Translates the position of the curve.
			@param offset The vector to translate by. */
		virtual void Translate(const Vector2 &offset)
		{
			P0 += offset;
			P1 += offset;
			P2 += offset;
			P3 += offset;
		}

		/** @brief Calculates the tight rectangle that contains the curve.
			@return Returns the tight bounding rectangle. */
		virtual Rectangle CalculateBoundingRectangle() const
		{
			// start region around start and end points
			Vector2 min =
				Vector2(Math::Min(P0.X, P3.X), Math::Min(P0.Y, P3.Y));
			Vector2 max =
				Vector2(Math::Max(P0.X, P3.X), Math::Max(P0.Y, P3.Y));

			// derivitive in terms of t
			Vector2 a = -3 * P0 + 9 * P1 - 9 * P2 + 3 * P3;
			Vector2 b = 6 * P0 - 12 * P1 + 6 * P2;
			Vector2 c = -3 * P0 + 3 * P1;

			// quadratic formula to calculate local extrema
			float sqx = sqrtf(b.X * b.X - 4 * a.X * c.X);
			float sqy = sqrtf(b.Y * b.Y - 4 * a.Y * c.Y);

			float tValues[4];
			int count = 0;

			// check if values are on the curve
			Vector2 p;
			if (a.X != 0)
			{
				float txP = (-b.X + sqx) / (2 * a.X);
				if (0 < txP && txP < 1)
				{
					tValues[count] = txP;
					count++;
				}

				float txM = (-b.X - sqx) / (2 * a.X);
				if (0 < txM && txM < 1)
				{
					tValues[count] = txM;
					count++;
				}
			}

			if (a.Y != 0)
			{
				float tyP = (-b.Y + sqy) / (2 * a.Y);
				if (0 < tyP && tyP < 1)
				{
					tValues[count] = tyP;
					count++;
				}

				float tyM = (-b.Y - sqy) / (2 * a.Y);
				if (0 < tyM && tyM < 1)
				{
					tValues[count] = tyM;
					count++;
				}
			}

			// loop throug the t values and see which ones expand the region
			for (int i = 0; i < count; i++)
			{
				Vector2 p = Lerp(tValues[i]);

				max.X = Math::Max(max.X, p.X);
				min.X = Math::Min(min.X, p.X);
				max.Y = Math::Max(max.Y, p.Y);
				min.Y = Math::Min(min.Y, p.Y);
			}

			return Rectangle(max - min, min);
		}

		/** @brief Assigns the reference of a bezier.
			@param bezier The reference bezier.
			@return Returns the resulting bezier. */
		Bezier &operator= (const Bezier &bezier)
		{
			if (this != &bezier)
			{
				P0 = bezier.P0;
				P1 = bezier.P1;
				P2 = bezier.P2;
				P3 = bezier.P3;
			}

			return *this;
		}

		/** @brief Determines if two beziers are equal.
			@param bezier The bezier to compare.
			@return Returns true if the beziers are equal, false otherwise. */
		bool operator==(const Bezier &bezier) const
		{
			return (P0 == bezier.P0 && P1 == bezier.P1
				&& P2 == bezier.P2 && P3 == bezier.P3);
		}

		/** @brief Determines if two beziers are not equal.
			@param bezier The bezier to compare.
			@return Returns true if the beziers are not equal, false otherwise. */
		bool operator!=(const Bezier &bezier) const
		{
			return (P0 != bezier.P0 || P1 != bezier.P1
				|| P2 != bezier.P2 || P3 != bezier.P3);
		}

		Vector2 P0;
		Vector2 P1;
		Vector2 P2;
		Vector2 P3;
	};
}