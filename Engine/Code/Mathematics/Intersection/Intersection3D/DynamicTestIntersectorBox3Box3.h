// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:46)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h" 
#include "Mathematics/Objects3D/Box3.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicTestIntersectorBox3Box3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicTestIntersectorBox3Box3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		DynamicTestIntersectorBox3Box3(const Box3& box0, const Box3& box1, Real tmax,
									   const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

		// Object access.
		const Box3 GetBox0() const;
		const Box3 GetBox1() const;

	private:
		// Dynamic test-intersection query.  The first time of contact (if any)
		// is computed, but not any information about the contact set.
		void Test();

		// Support for dynamic queries.  The inputs are the projection intervals
		// for the boxes onto a potential separating axis, the relative speed of
		// the intervals, and the maximum time for the query.  The outputs are
		// the first time when separating fails and the last time when separation
		// begins again along that axis.  The outputs are *updates* in the sense
		// that this function is called repeatedly for the potential separating
		// axes.  The output first time is updated only if it is larger than
		// the input first time.  The output last time is updated only if it is
		// smaller than the input last time.
		//
		// NOTE:  The BoxBoxAxisTest function could be used, but the box-box
		// code optimizes the projections of the boxes onto the various axes.
		// This function is effectively BoxBoxAxisTest but without the dot product
		// of axis-direction and velocity to obtain speed.  The optimizations are
		// to compute the speed with fewer operations.
		bool IsSeparated(Real min0, Real max0, Real min1, Real max1, Real speed, Real tmax, Real& tlast);

		// The objects to intersect.
		Box3 mBox0;
		Box3 mBox1;
	};

	using DynamicTestIntersectorBox3Box3f = DynamicTestIntersectorBox3Box3<float>;
	using DynamicTestIntersectorBox3Box3d = DynamicTestIntersectorBox3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_H
