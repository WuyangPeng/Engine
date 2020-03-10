// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:19)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS2_H
#define MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS2_H

// Separate two point sets, if possible, by computing a line for which the
// point sets lie on opposite sides.  The algorithm computes the convex hull
// of the point sets, then uses the method of separating axes to determine if
// the two convex polygons are disjoint.  The convex hull calculation is
// O(n*log(n)).  There is a randomized linear approach that takes O(n), but
// I have not yet implemented it.
//
// The return value of the function is 'true' if and only if there is a
// separation.  If 'true', the returned line is a separating line.

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{
	template <typename Real>
	class SeparatePoints2
	{
	public:
		SeparatePoints2(const std::vector<Vector2D<Real> >& points0, const std::vector<Vector2D<Real> >& points1, Line2<Real>& separatingLine);
		
		// Return the result of the constructor call.  If 'true', the output
		// line 'separatingLine' is valid.
		operator bool ();

	private:
		static int OnSameSide (const Vector2D<Real>& lineNormal, Real lineConstant, int numEdges, const int* edges, const std::vector<Vector2D<Real> >& points);
		
		static int WhichSide (const Vector2D<Real>& lineNormal, Real lineConstant, int numEdges, const int* edges, const std::vector<Vector2D<Real> >& points);
		
		bool mSeparated;
	};
	
	using SeparatePoints2f = SeparatePoints2<float>;
	using SeparatePoints2d = SeparatePoints2<double>;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS2_H
