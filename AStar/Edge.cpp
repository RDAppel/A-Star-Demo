#include "AStar.h"

uint32_t Edge::s_count = 0;


Edge::Edge(Vertex *pVertex1, Vertex *pVertex2, const float weight)
{
	m_index = s_count;
	s_count++;

	m_vertices[0] = pVertex1;
	m_vertices[1] = pVertex2;

	m_vertices[0]->AddEdge(this);
	m_vertices[1]->AddEdge(this);

	SetWeight(weight);
}

Vertex *Edge::GetVertex(const int index)
{
	if (index < 0 || index > 1) return nullptr;
	return m_vertices[index];
}

Vertex *Edge::GetAdjacentVertex(Vertex *pVertex)
{
	return m_vertices[pVertex == m_vertices[0] ? 1 : 0];
}

Vector2 Edge::Lerp(const float value) const
{
	return Vector2::Lerp(m_vertices[0]->GetPosition(), m_vertices[1]->GetPosition(), value);
}