// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:50)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CAPSULE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"  
#include "Mathematics/Objects3D/Capsule3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorRay3Capsule3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorRay3Capsule3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ray3 = Ray3<Real>;
		using Capsule3 = Capsule3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorRay3Capsule3(const Ray3& ray, const Capsule3& capsule);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Ray3 GetRay() const;
                [[nodiscard]] const Capsule3 GetCapsule() const;

		// The intersection set.
                [[nodiscard]] int GetQuantity() const;
                [[nodiscard]] const Vector3D GetPoint(int index) const;

	private:
		// Static intersection queries.
		void Find();

		// The objects to intersect.
		Ray3 mRay;
		Capsule3 mCapsule;

		// Information about the intersection set.
		int m_Quantity;
		Vector3D m_Point[2];
	};

	using FloatStaticFindIntersectorRay3Capsule3 = StaticFindIntersectorRay3Capsule3<float>;
	using DoubleStaticFindIntersectorRay3Capsule3 = StaticFindIntersectorRay3Capsule3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CAPSULE3_H
