// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 18:09)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Line2.h"   
#include "Mathematics/Objects2D/Triangle2.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorLine2Triangle2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorLine2Triangle2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Line2 = Line2<Real>;
		using Triangle2 = Triangle2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;		
		
	public:
		StaticTestIntersectorLine2Triangle2(const Line2& line, const Triangle2& triangle);
		
		// Object access.
		const Line2 GetLine () const;
		const Triangle2 GetTriangle () const;  		
		
	private:
		// Static intersection query.
		void Test();
	
		// The objects to intersect.
		Line2 mLine;
		Triangle2 mTriangle;	 
		
	public:
		// Shared by IntrRay2Triangle2 and IntrSegment2Triangle2.
		
		// Determine how the triangle and line intersect (if at all).
		static void TriangleLineRelations (const Vector2D& origin,const Vector2D& direction, const Triangle2& triangle,
                                           Real dist[3], int sign[3], int& positive, int& negative,int& zero);
		
		// Compute the parameter interval for the segment of intersection when
		// the triangle transversely intersects the line.
		static void GetInterval (const Vector2D& origin,const Vector2D& direction, const Triangle2& triangle,
								 const Real dist[3], const int sign[3], Real param[2]);
	};

	using StaticTestIntersectorLine2Triangle2f = StaticTestIntersectorLine2Triangle2<float>;
	using StaticTestIntersectorLine2Triangle2d = StaticTestIntersectorLine2Triangle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_TRIANGLE2_H
