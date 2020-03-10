// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 13:27)

#ifndef MATHEMATICS_MISCELLANEOUS_PERS_PPROJ_ELLIPSOID_H
#define MATHEMATICS_MISCELLANEOUS_PERS_PPROJ_ELLIPSOID_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{

	// Input
	//   ellipsoid:   specified by center, axis directions, and extents
	//   eye point:   E
	//   view plane:  Dot(N,X) = D, planar vectors U and V so that {U,V,N} is an
	//                orthonormal set of vectors
	// The ellipsoid should be between the eye point and the view plane in the
	// sense that all rays from the eye point that intersect the ellipsoid must
	// also intersect the view plane.
	//
	// Output
	//   plane origin:       P = E + (D - Dot(N,E))*N
	//   projected ellipse:  The projected ellipse coordinates Y = (y0,y1) are the
	//                       view plane coordinates of the actual 3D ellipse
	//                       points X = P + y0*U + y1*V.

	template <typename Real>
	void PerspectiveProjectEllipsoid(const Ellipsoid3<Real>& ellipsoid,const Vector3D<Real>& eye, const Plane3<Real>& plane,
									 const Vector3D<Real>& U, const Vector3D<Real>& V, Vector3D<Real>& P,Ellipse2<Real>& ellipse);

}

#endif // MATHEMATICS_MISCELLANEOUS_PERS_PPROJ_ELLIPSOID_H
