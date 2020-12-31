// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:51)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CYLINDER3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"  
#include "Mathematics/Objects3D/Cylinder3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorRay3Cylinder3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorRay3Cylinder3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ray3 = Ray3<Real>;
		typedef Cylinder3<Real> Cylinder3;
		typedef Vector3DTools<Real> Vector3DTools;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorRay3Cylinder3(const Ray3& ray, const Cylinder3& cylinder);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Ray3 GetRay() const;
                [[nodiscard]] const Cylinder3 GetCylinder() const;

		// The intersection set.
                [[nodiscard]] int GetQuantity() const;
                [[nodiscard]] const Vector3D GetPoint(int index) const;

		// Static intersection query.
		void Find();

	private:
		// The objects to intersect.
		Ray3 mRay;
		Cylinder3 mCylinder;

		// Information about the intersection set.
		int m_Quantity;
		Vector3D m_Point[2];
	};

	using FloatStaticFindIntersectorRay3Cylinder3 = StaticFindIntersectorRay3Cylinder3<float>;
	using DoubleStaticFindIntersectorRay3Cylinder3 = StaticFindIntersectorRay3Cylinder3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CYLINDER3_H
