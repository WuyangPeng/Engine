// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:19)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS3_H
#define MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS3_H

// Separate two point sets, if possible, by computing a plane for which the
// point sets lie on opposite sides.  The algorithm computes the convex hull
// of the point sets, then uses the method of separating axes to determine if
// the two convex polyhedra are disjoint.  The convex hull calculation is
// O(n*log(n)).  There is a randomized linear approach that takes O(n), but
// I have not yet implemented it.
//
// The return value of the function is 'true' if and only if there is a
// separation.  If 'true', the returned plane is a separating plane.

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h"

namespace Mathematics
{
	
	// Assumes that both sets have at least 4 noncoplanar points.
	template <typename Real>
	class SeparatePoints3
	{
	public:
		SeparatePoints3 (const std::vector<Vector3D<Real> >& points0, const std::vector<Vector3D<Real> >& points1, Plane3<Real>& separatingPlane);
		
		// Return the result of the constructor call.  If 'true', the output
		// plane 'separatingPlane' is valid.
		operator bool ();
		
	private:
		static int OnSameSide(const Plane3<Real>& plane, int numTriangles, const int* indices, const std::vector<Vector3D<Real> >& points);
		
		static int WhichSide(const Plane3<Real>& plane, int numTriangles, const int* indices, const std::vector<Vector3D<Real> >& points);
		
		bool mSeparated;
	};
	
	using SeparatePoints3f = SeparatePoints3<float>;
	using SeparatePoints3d = SeparatePoints3<double>;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS3_H
