#pragma once

using namespace KatanaEngine;

class Vertex;

class Edge
{

private:

	static uint32_t s_count;

	uint32_t m_index = 0;

	Vertex *m_vertices[2];

	float m_weight = 1;

public:

	Edge(Vertex *pVertex1, Vertex *pVertex2, const float weight = 1);

	virtual ~Edge() { }

	virtual float GetWeight() const { return m_weight; }

	virtual void SetWeight(const float weight) { m_weight = weight; }

	virtual Vertex *GetVertex(const int index);

	virtual Vertex *GetAdjacentVertex(Vertex *pVertex);

	virtual uint32_t GetIndex() const { return m_index; }

	virtual Vector2 Lerp(const float value) const;

};

