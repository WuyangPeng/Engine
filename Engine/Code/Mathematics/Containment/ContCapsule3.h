// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:16)

#ifndef MATHEMATICS_CONTAINMENT_CONT_CAPSULE3_H
#define MATHEMATICS_CONTAINMENT_CONT_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Capsule3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{	
	// Compute axis of capsule segment using least-squares fit.  Radius is
	// maximum distance from points to axis.  Hemispherical caps are chosen
	// as close together as possible.
	template <typename Real>
	Capsule3<Real> ContCapsule(const std::vector<Vector3<Real> >& points);
	
	// Test for containment of a point by a capsule.
	template <typename Real>
	bool InCapsule (const Vector3<Real>& point, const Capsule3<Real>& capsule);
	
	// Test for containment of a sphere by a capsule.
	template <typename Real>
	bool InCapsule (const Sphere3<Real>& sphere, const Capsule3<Real>& capsule);
	
	// Test for containment of a capsule by a capsule.
	template <typename Real>
	bool InCapsule (const Capsule3<Real>& testCapsule,const Capsule3<Real>& capsule);
	
	// Compute a capsule that contains the input capsules.  The returned capsule
	// is not necessarily the one of smallest volume that contains the inputs.
	template <typename Real>
	Capsule3<Real> MergeCapsules (const Capsule3<Real>& capsule0,  const Capsule3<Real>& capsule1);
}

#endif // MATHEMATICS_CONTAINMENT_CONT_CAPSULE3_H
