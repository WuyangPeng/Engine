// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:20)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SPHERE3_H
#define MATHEMATICS_CONTAINMENT_CONT_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
	
	// Compute the smallest axis-aligned bounding box of the points, then
	// compute a sphere containing the box.
	template <typename Real>
	Sphere3<Real> ContSphereOfAABB(const std::vector<Vector3D<Real> >& points);
	
	// Compute the smallest sphere whose center is the average of the input
	// points.
	template <typename Real>
	Sphere3<Real> ContSphereAverage (int numPoints, const Vector3D<Real>* points);
	
	// Test for containment of a point inside a sphere.
	template <typename Real>
	bool InSphere (const Vector3D<Real>& point, const Sphere3<Real>& sphere);
	
	// Compute the smallest sphere that contains the input spheres.
	template <typename Real>
	Sphere3<Real> MergeSpheres (const Sphere3<Real>& sphere0,  const Sphere3<Real>& sphere1);
}

#endif // MATHEMATICS_CONTAINMENT_CONT_SPHERE3_H
