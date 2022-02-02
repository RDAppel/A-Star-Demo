#pragma once

#include "AStar.h"

using namespace KatanaEngine;

class Vertex : public IVertex
{

public:

	Vertex(const Vector2 position)
	{
		m_index = s_count;
		s_count++;

		SetPosition(position);
	}

	virtual ~Vertex() { }

	virtual void AddEdge(Edge *pEdge) { m_edges.push_back(pEdge); }

	virtual void SetPosition(const Vector2 position) { m_position = position; }

	virtual Vector2 GetPosition() const { return m_position; }

	virtual uint32_t GetIndex() const { return m_index; }

	virtual void SetTraversalDistance(const float distance = INFINITY) { m_traversalDistance = distance; }

	virtual float GetTraversalDistance() const { return m_traversalDistance; }

	virtual std::vector<Edge *> &GetEdges() { return m_edges; }

private:

	static uint32_t s_count;

	uint32_t m_index = 0;

	Vector2 m_position;

	std::vector<Edge *> m_edges;

	float m_traversalDistance = INFINITY;

};

