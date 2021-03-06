// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 16:17)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_H
#define MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Ellipse2.h"
#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{	
	// The input points are fit with a Gaussian distribution.  The center C of the
	// ellipsoid is chosen to be the mean of the distribution.  The axes of the
	// ellipsoid are chosen to be the eigenvectors of the covariance matrix M.
	// The shape of the ellipsoid is determined by the absolute values of the
	// eigenvalues.
	//
	// WARNING.  The construction is ill-conditioned if the points are (nearly)
	// collinear.  In this case M has a (nearly) zero eigenvalue, so inverting M
	// is problematic.
	template <typename Real>
	Ellipse2<Real> ContEllipse (const std::vector<Vector2D<Real> >& points);
	
	// Project an ellipse onto a line.  The projection interval is [smin,smax]
	// and corresponds to the line segment P+s*D, where smin <= s <= smax.
	template <typename Real>
	void ProjectEllipse (const Ellipse2<Real>& ellipse, const Line2<Real>& line, Real& smin, Real& smax);
	
	// Construct a bounding ellipse for the two input ellipses.
	template <typename Real>
	const Ellipse2<Real> MergeEllipses (const Ellipse2<Real>& ellipse0,  const Ellipse2<Real>& ellipse1);
}

#endif // MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_H
