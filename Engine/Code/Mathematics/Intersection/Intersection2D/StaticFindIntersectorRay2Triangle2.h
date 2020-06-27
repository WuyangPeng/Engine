// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:37)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Ray2.h"
#include "Mathematics/Objects2D/Triangle2.h"    
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorRay2Triangle2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorRay2Triangle2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Ray2 = Ray2<Real>;
		using Triangle2 = Triangle2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorRay2Triangle2(const Ray2& ray, const Triangle2& triangle);

		// Object access.
		const Ray2 GetRay() const;
		const Triangle2 GetTriangle() const;

		// The intersection set.  If the ray and triangle do not intersect,
		// GetQuantity() returns 0, in which case the intersection type is
		// IT_EMPTY.  If the ray and triangle intersect in a single point,
		// GetQuantity() returns 1, in which case the intersection type is
		// IT_POINT and GetPoint() returns the intersection point.  If the ray
		// and triangle intersect in a segment, GetQuantity() returns 2, in which
		// case the intersection type is IT_SEGMENT and GetPoint() returns the
		// segment endpoints.
		int GetQuantity() const;
		const Vector2D GetPoint(int i) const;

	private:
		// Static intersection query.
		void Find();

		// The objects to intersect.
		Ray2 mRay;
		Triangle2 mTriangle;

		// Information about the intersection set.
		int mQuantity;
		Vector2D mPoint[2];
	};

	using StaticFindIntersectorRay2Triangle2f = StaticFindIntersectorRay2Triangle2<float>;
	using StaticFindIntersectorRay2Triangle2d = StaticFindIntersectorRay2Triangle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY2_TRIANGLE2_H
