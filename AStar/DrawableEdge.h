
#pragma once

class DrawableEdge : public Edge, public IDrawable
{

private:

	static Font *s_pFont;

	Line m_line;

	bool m_drawWeight = true;

	std::string m_text;

	Color m_color = Color::WHITE;

	Circle m_circle;

	virtual void updateText()
	{
		m_text = std::to_string(((int)(GetWeight() * 100)) / 100);
	}

public:

	DrawableEdge(Vertex *pVertexA, Vertex *pVertexB)
		: Edge(pVertexA, pVertexB)
	{
		m_text = "1";
		m_circle.Radius = 20;
	}

	DrawableEdge(Vertex * pVertexA, Vertex * pVertexB, const float weight)
		: Edge(pVertexA, pVertexB, weight)
	{
		updateText();
		m_circle.Radius = 20;
	}

	static void SetFont(Font *pFont) { s_pFont = pFont; }

	virtual void Draw(SpriteBatch * pSpriteBatch)
	{
		Vector2 a = GetVertex(0)->GetPosition();
		Vector2 b = GetVertex(1)->GetPosition();

		m_line.Set(a, b);

		m_line.DrawPrimitive(m_color, 5);

		if (s_pFont && m_drawWeight)
		{
			m_circle.Position = Lerp(0.5f);
			
			m_circle.DrawPrimitive(Color::BLACK, m_color, 5);

			Vector2 textPosition = m_circle.Position - Vector2::UNIT_Y * 19;
			pSpriteBatch->DrawString(s_pFont, &m_text, textPosition, Color::WHITE, TextAlign::CENTER);
		}
	}

	virtual float GetDisplayCircleRadius() const { return m_drawWeight ? m_circle.Radius : 0; }

	virtual void SetWeight(const float weight)
	{
		Edge::SetWeight(weight);
		updateText();
	}

	virtual void SetColor(const Color color) { m_color = color; }

	virtual void SetDrawWeight(const bool draw = true) { m_drawWeight = draw; }
};