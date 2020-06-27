// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:37)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Ray2.h"
#include "Mathematics/Objects2D/Circle2.h"   
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorRay2Circle2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorRay2Circle2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Ray2 = Ray2<Real>;
		using Circle2 = Circle2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorRay2Circle2(const Ray2& ray, const Circle2& circle);

		// Object access.
		const Ray2 GetRay() const;
		const Circle2 GetCircle() const;

		// The intersection set.
		int GetQuantity() const;
		const Vector2D& GetPoint(int i) const;

	private:
		// Static intersection query.
		void Find();

		// The objects to intersect.
		Ray2 mRay;
		Circle2 mCircle;

		// Information about the intersection set.
		int mQuantity;
		Vector2D mPoint[2];
	};

	using StaticFindIntersectorRay2Circle2f = StaticFindIntersectorRay2Circle2<float>;
	using StaticFindIntersectorRay2Circle2d = StaticFindIntersectorRay2Circle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_CIRCLE2_H
