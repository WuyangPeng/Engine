// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 17:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Triangle2.h" 
#include "Mathematics/Intersection/Intersector1.h"
#include "Mathematics/Intersection/StaticIntersector.h"   

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorTriangle2Triangle2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorTriangle2Triangle2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Triangle2 = Triangle2<Real>;
		using Vector2DTools = Vector2DTools<Real>; 
		using Math = Math<Real>;
		
	public:
		StaticFindIntersectorTriangle2Triangle2(const Triangle2& triangle0,const Triangle2& triangle1);
		
		// Object access.
		const Triangle2 GetTriangle0 () const;
		const Triangle2 GetTriangle1 () const;
		
		// Information about the intersection set.
		int GetQuantity () const;
		const Vector2D GetPoint (int i) const;
		
	private:
		// Dynamic queries.		 
		void Find();

	private:
		static int WhichSide (const Vector2D V[3], const Vector2D& P,const Vector2D& D);
		
		static void ClipConvexPolygonAgainstLine (const Vector2D& N,Real c, int& quantity, Vector2D V[6]);		
		 
		// The objects to intersect.
		Triangle2 mTriangle0;
		Triangle2 mTriangle1;
		
		// Information about the intersection set.
		int mQuantity;
		Vector2D mPoint[6];		
	};
	
	using StaticFindIntersectorTriangle2Triangle2f = StaticFindIntersectorTriangle2Triangle2<float>;
	using StaticFindIntersectorTriangle2Triangle2d = StaticFindIntersectorTriangle2Triangle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
