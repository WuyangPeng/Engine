// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:18)

#ifndef MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYGON2_H
#define MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYGON2_H

// Given a polygon as an order list of vertices (x[i],y[i]) for 0 <= i < N
// and a test point (xt,yt), return 'true' if (xt,yt) is in the polygon and
// 'false' if it is not.  All queries require that the number of vertices
// satisfies N >= 3.

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"

namespace Mathematics
{	
	template <typename Real>
	class PointInPolygon2
	{
	public:
		PointInPolygon2 (int numPoints, const Vector2D<Real>* points);
		
		// Simple polygons (ray-intersection counting).
		bool Contains (const Vector2D<Real>& p) const;
		
		// Algorithms for convex polygons.  The input polygons must have vertices
		// in counterclockwise order.
		
		// O(N) algorithm (which-side-of-edge tests)
		bool ContainsConvexOrderN (const Vector2D<Real>& p) const;
		
		// O(log N) algorithm (bisection and recursion, like BSP tree)
		bool ContainsConvexOrderLogN (const Vector2D<Real>& p) const;
		
		// The polygon must have exactly four vertices.  This method is like the
		// O(log N) and uses three which-side-of-segment test instead of four
		// which-side-of-edge tests.  If the polygon does not have four vertices,
		// the function returns false.
		bool ContainsQuadrilateral (const Vector2D<Real>& p) const;
		
	private:
		// For recursion in ContainsConvexOrderLogN.
		bool SubContainsPoint (const Vector2D<Real>& p, int i0, int i1) const;
		
		int mNumPoints;
		const Vector2D<Real>* mPoints;
	};
	
	using PointInPolygon2f = PointInPolygon2<float>;
	using PointInPolygon2d = PointInPolygon2<double>;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYGON2_H
