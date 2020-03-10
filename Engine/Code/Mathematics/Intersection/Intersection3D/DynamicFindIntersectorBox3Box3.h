// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 09:12)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h" 
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicFindIntersectorBox3Box3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicFindIntersectorBox3Box3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>; 

	public:
		DynamicFindIntersectorBox3Box3(const Box3& box0, const Box3& box1,Real tmax,
									   const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::sm_ZeroTolerance);

		// Object access.
		const Box3 GetBox0() const;
		const Box3 GetBox1() const;

		// The intersection set for dynamic find-intersection.
		int GetQuantity() const;
		const Vector3D GetPoint(int i) const;

	private:
		// Dynamic find-intersection query.  The contact set is computed.
		void Find ();  

		// The objects to intersect.
		Box3 mBox0;
		Box3 mBox1;

		// The intersection set for dynamic find-intersection.  The worst case
		// is a polygon with 8 vertices.
		int mQuantity;
		Vector3D mPoint[8];
	};

	using DynamicFindIntersectorBox3Box3f = DynamicFindIntersectorBox3Box3<float>;
	using DynamicFindIntersectorBox3Box3d = DynamicFindIntersectorBox3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_H
