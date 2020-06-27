// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:35)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_BOX2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Box2.h" 
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorLine2Box2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorLine2Arc2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Line2 = Line2<Real>;
		using Box2 = Box2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorLine2Box2(const Line2& line, const Box2& box);

		// Object access.
		const Line2 GetLine() const;
		const Box2 GetBox() const;

		// The intersection set.
		int GetQuantity() const;
		const Vector2D& GetPoint(int i) const;

	private:
		// Static intersection queries.
		void Find();

		static bool Clip(Real denom, Real numer, Real& t0, Real& t1);

		// The objects to intersect.
		Line2 mLine;
		Box2 mBox;

		// Information about the intersection set.
		int mQuantity;
		Vector2D mPoint[2];

	public:
		// Shared by IntrRay2Box2 and IntrSegment2Box2.
		static bool DoClipping(Real t0, Real t1, const Vector2D& origin, const Vector2D& direction, const Box2& box,
							   bool solid, int& quantity, Vector2D point[2], int& intrType);
	};

	using StaticFindIntersectorLine2Box2f = StaticFindIntersectorLine2Box2<float>;
	using StaticFindIntersectorLine2Box2d = StaticFindIntersectorLine2Box2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_BOX2_H
