#include "AStar.h"

Vertex *Graph::GetClosestVertex(Vector2 position)
{
	Vertex *pClosest = nullptr;
	uint32_t distSquared = -1;

	for (Vertex *pV : m_vertices)
	{
		if (!pClosest) pClosest = pV;

		float ds = Vector2::DistanceSquared(pV->GetPosition(), position);
		if (ds < distSquared)
		{
			distSquared = ds;
			pClosest = pV;
		}
	}

	return pClosest;
}

Edge *Graph::GetClosestEdge(Vector2 position)
{
	Edge *pClosest = nullptr;
	uint32_t distSquared = -1;

	for (Edge *pE : m_edges)
	{
		if (!pClosest) pClosest = pE;

		Vector2 center = pE->Lerp(0.5f);

		float ds = Vector2::DistanceSquared(center, position);
		if (ds < distSquared)
		{
			distSquared = ds;
			pClosest = pE;
		}
	}

	return pClosest;
}