// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/12 10:32)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"  
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE IntersectorConfiguration
	{
	public:
		IntersectorConfiguration();

		// ContactSide (order of the intervals of projection).
		enum
		{
			LEFT,
			RIGHT,
			NONE
		};
		
		// VertexProjectionMap (how the vertices are projected to the minimum
		// and maximum points of the interval).
		enum
		{
			m2, m11,             // segments
			m3, m21, m12, m111,  // triangles
			m44, m2_2, m1_1      // boxes
		};
		
		// The VertexProjectionMap value for the configuration.
		int mMap;
		
		// The order of the vertices.
		int mIndex[8];
		
		// Projection interval.
		Real mMin, mMax;
	};
}

#endif // MATHEMATICS_INTERSECTION_INTERSECTOR_CONFIGURATION_H
