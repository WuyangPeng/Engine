// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:17)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_H
#define MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ellipsoid3.h" 
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
	// The input points are fit with a Gaussian distribution.  The center C of the
	// ellipsoid is chosen to be the mean of the distribution.  The axes of the
	// ellipsoid are chosen to be the eigenvectors of the covariance matrix M.
	// The shape of the ellipsoid is determined by the absolute values of the
	// eigenvalues.
	//
	// WARNING.  The construction is ill-conditioned if the points are (nearly)
	// collinear or (nearly) planar.  In this case M has a (nearly) zero
	// eigenvalue, so inverting M is problematic.
	template <typename Real>
	Ellipsoid3<Real> ContEllipsoid (const std::vector<Vector3D<Real> >& points);
	
	// Project an ellipsoid onto a line.  The projection interval is [smin,smax]
	// and corresponds to the line segment P+s*D, where smin <= s <= smax.
	template <typename Real> 
	void ProjectEllipsoid (const Ellipsoid3<Real>& ellipsoid, const Line3<Real>& line, Real& smin, Real& smax);
	
	// Construct a bounding ellipsoid for the two input ellipsoids.
	template <typename Real> 
	const Ellipsoid3<Real> MergeEllipsoids (const Ellipsoid3<Real>& ellipsoid0,   const Ellipsoid3<Real>& ellipsoid1);
}

#endif // MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_H
