#pragma once

#include "AStar.h"

class Graph
{
public:

	Graph() { }

	virtual ~Graph() { }

	virtual void AddEdge(Edge *pEdge) { m_edges.push_back(pEdge); }

	virtual void AddVertex(Vertex *pVertex) { m_vertices.push_back(pVertex); }

	virtual std::vector<Edge *> &GetEdges() { return m_edges; }

	virtual std::vector<Vertex *> &GetVertices() { return m_vertices; }

	virtual Edge *GetClosestEdge(Vector2 position);

	virtual Vertex *GetClosestVertex(Vector2 position);



private:

	std::vector<Edge *> m_edges;

	std::vector<Vertex *> m_vertices;

};

