
#pragma once

#include "AStar.h"

class DrawableGraph : public Graph, public IDrawable
{

private:

	bool m_isDraggable = false;

	DrawableVertex *m_pDraggedVertex = nullptr;

	DrawableVertex *m_pStartVertex = nullptr;
	DrawableVertex *m_pDestinationVertex = nullptr;

	Color m_vertexColor = Color::WHITE;
	Color m_draggedVertexColor = Color::BLUE;

	Line m_newEdgeLine;

	DrawableVertex *m_pNewEdgeStartVertex = nullptr;

	Vector2 m_mousePosition;

	int m_dijkstraStep = 0;
	DrawableVertex *m_pCurrentVertex = nullptr;

public:

	static DrawableGraph *GenerateGraph1()
	{
		DrawableGraph *pGraph = new DrawableGraph();

		DrawableVertex *pA = new DrawableVertex(Vector2(265, 227));
		pGraph->AddVertex(pA);
		DrawableVertex *pB = new DrawableVertex(Vector2(336, 557));
		pGraph->AddVertex(pB);
		DrawableVertex *pC = new DrawableVertex(Vector2(647, 361));
		pGraph->AddVertex(pC);
		DrawableVertex *pD = new DrawableVertex(Vector2(642, 640));
		pGraph->AddVertex(pD);
		DrawableVertex *pE = new DrawableVertex(Vector2(907, 509));
		pGraph->AddVertex(pE);
		DrawableVertex *pF = new DrawableVertex(Vector2(1108, 698));
		pGraph->AddVertex(pF);
		DrawableVertex *pG = new DrawableVertex(Vector2(1070, 161));
		pGraph->AddVertex(pG);
		DrawableVertex *pH = new DrawableVertex(Vector2(1311, 369));
		pGraph->AddVertex(pH);

		pGraph->AddEdge(new DrawableEdge(pA, pB, 1));
		pGraph->AddEdge(new DrawableEdge(pA, pC, 4));
		pGraph->AddEdge(new DrawableEdge(pB, pC, 2));
		pGraph->AddEdge(new DrawableEdge(pB, pD, 3));
		pGraph->AddEdge(new DrawableEdge(pC, pE, 1));
		pGraph->AddEdge(new DrawableEdge(pD, pE, 1));
		pGraph->AddEdge(new DrawableEdge(pD, pF, 6));
		pGraph->AddEdge(new DrawableEdge(pC, pG, 2));
		pGraph->AddEdge(new DrawableEdge(pF, pG, 1));
		pGraph->AddEdge(new DrawableEdge(pF, pH, 3));
		pGraph->AddEdge(new DrawableEdge(pG, pH, 5));

		return pGraph;
	}

	static DrawableGraph *GenerateGraph2()
	{
		DrawableGraph *pGraph = new DrawableGraph();

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 16; x++)
			{
				Vector2 position(x * 100 + 50, y * 100 + 50);
				DrawableVertex *pV = new DrawableVertex(position);
				pV->SetDrawTraversalDistance(false);
				pV->SetFont(nullptr);
				pV->SetShape(DrawableVertexShape::Square);
				pGraph->AddVertex(pV);


				DrawableEdge *pE = nullptr;

				if (x > 0)
				{
					Vertex *pLeft = pGraph->GetClosestVertex(position - Vector2::UNIT_X * 100);
					pE = new DrawableEdge(pV, pLeft);
					pE->SetDrawWeight(false);
					pGraph->AddEdge(pE);
				}

				if (y > 0)
				{
					Vertex *pAbove = pGraph->GetClosestVertex(position - Vector2::UNIT_Y * 100);
					pE = new DrawableEdge(pV, pAbove);
					pE->SetDrawWeight(false);
					pGraph->AddEdge(pE);
				}
			}
		}



		return pGraph;
	}

	virtual void HandleInput(const InputState *pInput)
	{
		m_mousePosition = pInput->GetMousePosition();

		if (pInput->IsNewKeyRelease(Key::RIGHT)) StepDijkstra();

		if (pInput->IsNewKeyRelease(Key::V))
		{
			DrawableVertex *pDV = new DrawableVertex(m_mousePosition);
			AddVertex(pDV);
		}
		else
		{
			DrawableVertex *pClosestVertex = (DrawableVertex *)GetClosestVertex(m_mousePosition);
			DrawableEdge *pClosestEdge = (DrawableEdge *)GetClosestEdge(m_mousePosition);

			bool sPressed = pInput->IsNewKeyPress(Key::S);
			bool dPressed = pInput->IsNewKeyPress(Key::D);

			if (m_pNewEdgeStartVertex)
			{
				if (pInput->IsNewMouseButtonRelease(MouseButton::LEFT))
				{
					if (pClosestVertex && pClosestVertex != m_pNewEdgeStartVertex)
					{
						float r = pClosestVertex->GetRadius();
						float distSquared = Vector2::DistanceSquared(m_mousePosition, pClosestVertex->GetPosition());

						if (distSquared <= r * r)
						{
							DrawableEdge *pDE = new DrawableEdge(m_pNewEdgeStartVertex, pClosestVertex);
							m_pNewEdgeStartVertex = nullptr;
							AddEdge(pDE);
						}
					}
				}

				if (pInput->IsNewKeyRelease(Key::ESCAPE)) m_pNewEdgeStartVertex = nullptr;
			}
			else if (pClosestVertex && (sPressed || dPressed))
			{
				float r = pClosestVertex->GetRadius();
				float dist2 = Vector2::DistanceSquared(m_mousePosition, pClosestVertex->GetPosition());
				if (dist2 <= r * r)
				{
					if (sPressed) SetStartVertex(pClosestVertex);
					if (dPressed) SetDestinationVertex(pClosestVertex);
				}
			}
			else
			{
				bool newLeftClick = pInput->IsNewMouseButtonPress(MouseButton::LEFT);
				bool newRightClick = pInput->IsNewMouseButtonPress(MouseButton::RIGHT);

				if (newLeftClick || newRightClick)
				{
					uint32_t vertDist2 = -1;
					uint32_t edgeDist2 = -1;

					if (pClosestVertex)
						vertDist2 = Vector2::DistanceSquared(m_mousePosition, pClosestVertex->GetPosition());

					if (pClosestEdge)
						edgeDist2 = Vector2::DistanceSquared(m_mousePosition, pClosestEdge->Lerp(0.5f));

					if (pClosestVertex && pClosestEdge)
					{
						if (vertDist2 < edgeDist2 && newLeftClick) pClosestEdge = nullptr;
						else pClosestVertex = nullptr;
					}

					if (pClosestVertex && newLeftClick)
					{
						float r = pClosestVertex->GetRadius();
						if (vertDist2 <= r * r) SetDraggedVertex(pClosestVertex);
					}
					else if (pClosestEdge)
					{
						float r = pClosestEdge->GetDisplayCircleRadius();
						float weight = pClosestEdge->GetWeight() + (newLeftClick ? 1 : -1);
						if (edgeDist2 < r * r) pClosestEdge->SetWeight(Math::Clamp(0, 9, weight));
					}
				}
				else if (pInput->IsMouseButtonDown(MouseButton::LEFT))
				{
					if (m_isDraggable && m_pDraggedVertex)
					{
						m_pDraggedVertex->SetPosition(m_mousePosition);
						m_mousePosition.Display();
					}
				}
				else
				{
					SetDraggedVertex(nullptr);

					if (pInput->IsNewKeyRelease(Key::E) && !m_pNewEdgeStartVertex)
					{
						if (pClosestVertex)
						{
							m_pNewEdgeStartVertex = pClosestVertex;
						}
					}
				}
			}
		}
	}

	virtual void Draw(SpriteBatch *pSpriteBatch)
	{
		DrawableEdge *pDE = nullptr;
		DrawableVertex *pDV = nullptr;

		for (Edge *pE : GetEdges())
		{
			pDE = (DrawableEdge *)pE;
			if (pDE) pDE->Draw(pSpriteBatch);
		}

		if (m_pNewEdgeStartVertex)
		{
			m_newEdgeLine.Set(m_pNewEdgeStartVertex->GetPosition(), m_mousePosition);
			m_newEdgeLine.DrawPrimitive(Color::GREEN, 3);
		}

		for (Vertex *pV : GetVertices())
		{
			pDV = (DrawableVertex *)pV;
			if (pDV) pDV->Draw(pSpriteBatch);
		}
	}

	virtual void SetIsDraggable(const bool draggable = true) { m_isDraggable = draggable; }

	virtual void SetDraggedVertex(DrawableVertex *pVertex)
	{
		if (m_pDraggedVertex != pVertex)
		{
			UpdateDraggedVertexColor(m_vertexColor);
			m_pDraggedVertex = pVertex;
			UpdateDraggedVertexColor(m_draggedVertexColor);
		}
	}

	virtual void UpdateDraggedVertexColor(const Color color)
	{
		if (m_pDraggedVertex) m_pDraggedVertex->SetColor(color);
	}

	virtual void SetStartVertex(DrawableVertex *pVertex)
	{
		if (m_pStartVertex == pVertex)
		{
			m_pStartVertex->SetBorderColor(Color::WHITE);
			m_pStartVertex = nullptr;
		}
		else if (pVertex)
		{
			if (m_pStartVertex) m_pStartVertex->SetBorderColor(Color::WHITE);
			m_pStartVertex = pVertex;
			if (m_pStartVertex) m_pStartVertex->SetBorderColor(Color::GREEN);
		}
	}

	virtual void SetDestinationVertex(DrawableVertex *pVertex)
	{
		if (m_pDestinationVertex == pVertex)
		{
			m_pDestinationVertex->SetBorderColor(Color::WHITE);
			m_pDestinationVertex = nullptr;
		}
		else if (pVertex)
		{
			if (m_pDestinationVertex) m_pDestinationVertex->SetBorderColor(Color::WHITE);
			m_pDestinationVertex = pVertex;
			if (m_pDestinationVertex) m_pDestinationVertex->SetBorderColor(Color::RED);
		}
	}

	virtual void StepDijkstra()
	{
		m_dijkstraStep++;

		if (!m_pStartVertex || !m_pDestinationVertex) return;

		if (m_dijkstraStep == 1)
		{
			for (Vertex *pV : GetVertices())
			{
				DrawableVertex *pDV = (DrawableVertex *)pV;
				pDV->SetTraversalDistance();
				pDV->SetDrawTraversalDistance();
				pDV->SetIsClosed(false);
			}

			m_pCurrentVertex = m_pStartVertex;
			m_pCurrentVertex->SetTraversalDistance(0);
		}
		else if (m_pDestinationVertex->IsClosed())
		{
			if (m_pCurrentVertex->GetPreviousVertex())
			{
				DrawableVertex *pPrevious = m_pCurrentVertex->GetPreviousVertex();
				pPrevious->SetBorderColor(Color::PURPLE);

				for (Edge *pE : m_pCurrentVertex->GetEdges())
				{
					DrawableVertex *pAdjacent = (DrawableVertex *)pE->GetAdjacentVertex(m_pCurrentVertex);
					if (pAdjacent == pPrevious)
					{
						((DrawableEdge *)pE)->SetColor(Color::PURPLE);
					}
				}

				m_pCurrentVertex = pPrevious;
			}
		}
		else if (m_dijkstraStep % 2 == 0)
		{
			for (Edge *pE : m_pCurrentVertex->GetEdges())
			{
				DrawableVertex *pAdjacent = (DrawableVertex *)pE->GetAdjacentVertex(m_pCurrentVertex);

				float distance = m_pCurrentVertex->GetTraversalDistance() + pE->GetWeight();
				float current = pAdjacent->GetTraversalDistance();

				if (distance < current)
				{
					pAdjacent->SetTraversalDistance(distance);
					pAdjacent->SetPreviousVertex(m_pCurrentVertex);
				}
			}

			m_pCurrentVertex->SetIsClosed();
			m_pCurrentVertex->SetColor(Color::GREEN);

			if (m_pCurrentVertex == m_pDestinationVertex)
			{
				m_pCurrentVertex->SetBorderColor(Color::PURPLE);
			}
		}
		else
		{
			float lowest = INFINITY;
			for (Vertex *pV : GetVertices())
			{
				DrawableVertex *pDV = (DrawableVertex *)pV;
				if (pDV->IsClosed()) continue;

				float distance = pDV->GetTraversalDistance();
				if (distance < lowest)
				{
					lowest = distance;
					m_pCurrentVertex = pDV;
				}
			}

			m_pCurrentVertex->SetColor(Color::PURPLE);
		}
	}
};

