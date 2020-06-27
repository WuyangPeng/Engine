// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:49)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"  
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
	// Miscellaneous support	

	// The input and output polygons are stored in P.  The size of P is
	// assumed to be large enough to store the clipped convex polygon vertices.
	// For now the maximum array size is 8 to support the current intersection
	// algorithms.
	template <typename Real>
	MATHEMATICS_TEMPLATE_DEFAULT_DECLARE void ClipConvexPolygonAgainstPlane(const Vector3D<Real>& normal, Real bonstant, int& quantity, Vector3D<Real>* P);

	// Translates an index into the box back into real coordinates.
	template <typename Real>
	MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3D<Real> GetPointFromIndex(int index, const Box3<Real>& box);
}

#endif // MATHEMATICS_INTERSECTION_INTERSECTOR_UTILITY3_H
