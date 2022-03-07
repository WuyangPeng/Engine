// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 17:33)

#ifndef PHYSICS_INTERSECTION_EXTREMAL_QUERY3PRJ_DETAIL_H
#define PHYSICS_INTERSECTION_EXTREMAL_QUERY3PRJ_DETAIL_H

#include "ExtremalQuery3PRJ.h"
#include "Mathematics/Objects3D/ConvexPolyhedron3Detail.h"

namespace Physics
{
	template <typename Real>
	ExtremalQuery3PRJ<Real>::ExtremalQuery3PRJ(const ConvexPolyhedron3* polytope)
		:ExtremalQuery3<Real>(polytope)
	{
		mCentroid = mPolytope->ComputeVertexAverage();
	}

	template <typename Real>
	ExtremalQuery3PRJ<Real>::~ExtremalQuery3PRJ()
	{
	}

	template <typename Real>
	void ExtremalQuery3PRJ<Real>::GetExtremeVertices(const ExtremalQuery3<Real>::Vector3D& direction, int& positiveDirection,int& negativeDirection)
	{
		typename ExtremalQuery3<Real>::Vector3D diff = mPolytope->GetVertex(0) - ExtremalQuery3<Real>::mCentroid;
		Real minValue = Mathematics::Vector3Tools<Real>::DotProduct(direction, diff);
		Real maxValue = minValue;
		negativeDirection = 0;
		positiveDirection = 0;

		const int numVertices = mPolytope->GetNumVertices();
		for (int i = 1; i < numVertices; ++i)
		{
			diff = mPolytope->GetVertex(i) - mCentroid;
			Real dot = Mathematics::Vector3Tools<Real>::DotProduct(direction, diff);
			if (dot < minValue)
			{
				negativeDirection = i;
				minValue = dot;
			}
			else if (dot > maxValue)
			{
				positiveDirection = i;
				maxValue = dot;
			}
		}
	}
}


#endif // PHYSICS_INTERSECTION_EXTREMAL_QUERY3PRJ_DETAIL_H