
#pragma once

enum class DrawableVertexShape
{
	Circle,
	Square,
	Hexagon
};

class DrawableVertex : public Vertex, public IDrawable
{

private:

	static Font *s_pFont;

	Circle m_circle;

	Rectangle m_rectangle;

	Color m_color = Color::WHITE;

	Color m_borderColor = Color::WHITE;

	std::string m_label = "";
	std::string m_traversalDistance = "";

	bool m_drawWeight = true;

	bool m_drawTraversalDistance = false;

	Color m_previousColor = Color::WHITE;

	bool m_isClosed = false;

	DrawableVertex *m_pPreviousVertex = nullptr;

	DrawableVertexShape m_shape = DrawableVertexShape::Circle;


public:

	DrawableVertex(const Vector2 position)
		: Vertex(position)
	{
		int i = GetIndex();
		m_label = (char)('A' + i);
		m_circle.Radius = 30;
		m_rectangle.Size.Set(50, 50);
	}

	static void SetFont(Font *pFont) { s_pFont = pFont; }

	virtual void Draw(SpriteBatch * pSpriteBatch)
	{
		if (m_shape == DrawableVertexShape::Circle)
		{
			m_circle.Position = GetPosition();
			m_circle.DrawPrimitive(m_color, m_borderColor, 5);
		}
		else if (m_shape == DrawableVertexShape::Square)
		{
			m_rectangle.Position = GetPosition() - m_rectangle.Size / 2;
			m_rectangle.DrawPrimitive(m_color, m_borderColor, 10);
		}

		if (s_pFont && m_drawWeight)
		{
			Vector2 position = GetPosition();
			Vector2 textPosition = position - Vector2::UNIT_Y * 28;
			pSpriteBatch->DrawString(s_pFont, &m_label, textPosition, Color::BLACK, TextAlign::CENTER);

			if (m_drawTraversalDistance)
			{
				textPosition = position - Vector2::ONE * -50;
				std::string parent = m_pPreviousVertex ? m_pPreviousVertex->GetLabel() : "-";
				std::string distance = (GetTraversalDistance() == INFINITY) ? "INF" : std::to_string((int)GetTraversalDistance());
				m_traversalDistance = distance + " (" + parent + ")";
				pSpriteBatch->DrawString(s_pFont, &m_traversalDistance, textPosition, Color::RED, TextAlign::CENTER);
			}
		}
	}

	virtual Color GetColor() const { return m_color; }

	virtual void SetColor(const Color color)
	{
		m_previousColor = m_color;
		m_color = color;
	}

	virtual void RestoreColor() { SetColor(m_previousColor); }

	virtual void SetBorderColor(const Color color) { m_borderColor = color; }

	virtual Color GetBorderColor() const { return m_borderColor; }

	virtual void SetRadius(const float radius) { m_circle.Radius = radius; }

	virtual float GetRadius() const { return m_circle.Radius; }

	virtual void SetSize(const float size) { m_rectangle.Size.Set(size, size); }

	virtual void SetDrawTraversalDistance(const bool draw = true) { m_drawTraversalDistance = draw; }

	virtual void SetIsClosed(const bool closed = true) { m_isClosed = closed; }

	virtual bool IsClosed() const { return m_isClosed; }

	virtual void SetPreviousVertex(DrawableVertex *pVertex) { m_pPreviousVertex = pVertex; }

	virtual DrawableVertex *GetPreviousVertex() { return m_pPreviousVertex; }

	virtual std::string &GetLabel() { return m_label; }

	virtual void SetShape(const DrawableVertexShape shape) { m_shape = shape; }
};
