// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:47)

#ifndef MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_H
#define MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"  
#include "Mathematics/Objects3D/Triangle3.h"  
#include "Mathematics/Intersection/IntersectionFwd.h"

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE  FindContactSet
	{
	public:
		FindContactSet(const Vector3D<Real> segment[2], const Triangle3<Real>& triangle, int side, const IntersectorConfiguration<Real>& segCfg, const IntersectorConfiguration<Real>& triCfg,
					   const Vector3D<Real>& segVelocity, const Vector3D<Real>& triVelocity, Real tfirst, int& quantity, Vector3D<Real>* P);

		FindContactSet(const Vector3D<Real> segment[2], const Box3<Real>& box, int side, const IntersectorConfiguration<Real>& segCfg, const IntersectorConfiguration<Real>& boxCfg,
					   const Vector3D<Real>& segVelocity, const Vector3D<Real>& boxVelocity, Real tfirst, int& quantity, Vector3D<Real>* P);

		FindContactSet(const Triangle3<Real>& triangle, const Box3<Real>& box, int side, const IntersectorConfiguration<Real>& triCfg, const IntersectorConfiguration<Real>& boxCfg,
					   const Vector3D<Real>& triVelocity, const Vector3D<Real>& boxVelocity, Real tfirst, int& quantity, Vector3D<Real>* P);

		FindContactSet(const Box3<Real>& box0, const Box3<Real>& box1, int side, const IntersectorConfiguration<Real>& box0Cfg, const IntersectorConfiguration<Real>& box1Cfg,
					   const Vector3D<Real>& box0Velocity, const Vector3D<Real>& box1Velocity, Real tfirst, int& quantity, Vector3D<Real>* P);

	private:
		// These functions are called when it is known that the features are
		// intersecting.  Consequently, they are specialized versions of the
		// object-object intersection algorithms.

		static void ColinearSegments(const Vector3D<Real> segment0[2], const Vector3D<Real> segment1[2], int& quantity, Vector3D<Real>* P);

		static void SegmentThroughPlane(const Vector3D<Real> segment[2], const Vector3D<Real>& planeOrigin, const Vector3D<Real>& planeNormal, int& quantity, Vector3D<Real>* P);

		static void SegmentSegment(const Vector3D<Real> segment0[2], const Vector3D<Real> segment1[2], int& quantity, Vector3D<Real>* P);

		static void ColinearSegmentTriangle(const Vector3D<Real> segment[2], const Vector3D<Real> triangle[3], int& quantity, Vector3D<Real>* P);

		static void CoplanarSegmentRectangle(const Vector3D<Real> segment[2], const Vector3D<Real> rectangle[4], int& quantity, Vector3D<Real>* P);

		static void CoplanarTriangleRectangle(const Vector3D<Real> triangle[3], const Vector3D<Real> rectangle[4], int& quantity, Vector3D<Real>* P);

		static void CoplanarRectangleRectangle(const Vector3D<Real> rectangle0[4], const Vector3D<Real> rectangle1[4], int& quantity, Vector3D<Real>* P);
	};
}

#endif // MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_H
