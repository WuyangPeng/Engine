// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:17)

#ifndef MATHEMATICS_CONTAINMENT_CONT_LOZENGE3_H
#define MATHEMATICS_CONTAINMENT_CONT_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Lozenge3.h"  

namespace Mathematics
{
	// Compute plane of lozenge rectangle using least-squares fit.  Parallel
	// planes are chosen close enough together so that all the data points lie
	// between them.  The radius is half the distance between the two planes.
	// The half-cylinder and quarter-cylinder side pieces are chosen using a
	// method similar to that used for fitting by capsules.
	template <typename Real>
	Lozenge3<Real> ContLozenge(const std::vector<Vector3D<Real> >& points);
	
	// Test for containment of a point x by a lozenge.
	template <typename Real>
	bool InLozenge (const Vector3D<Real>& point, const Lozenge3<Real>& lozenge);
}

#endif // MATHEMATICS_CONTAINMENT_CONT_LOZENGE3_H
