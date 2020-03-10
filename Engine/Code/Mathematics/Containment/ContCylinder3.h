// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:17)

#ifndef MATHEMATICS_CONTAINMENT_CONT_CYLINDER3_H
#define MATHEMATICS_CONTAINMENT_CONT_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Cylinder3.h"

namespace Mathematics
{
	// Compute the cylinder axis segment using least-squares fit.  The radius is
	// the maximum distance from points to the axis.  The height is determined by
	// projection of points onto the axis and determining the containing interval.
	template <typename Real>
	Cylinder3<Real> ContCylinder (const std::vector<Vector3D<Real> >& points);
}

#endif // MATHEMATICS_CONTAINMENT_CONT_CYLINDER3_H
