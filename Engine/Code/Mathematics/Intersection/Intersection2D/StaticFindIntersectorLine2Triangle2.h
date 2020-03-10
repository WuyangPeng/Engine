// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 17:27)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Triangle2.h"   
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorLine2Triangle2 : public StaticIntersector<Real,Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorLine2Triangle2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Line2 = Line2<Real>;
		using Triangle2 = Triangle2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>; 
		
	public:
		StaticFindIntersectorLine2Triangle2 (const Line2& line,const Triangle2& triangle);
		
		// Object access.
		const Line2 GetLine () const;
		const Triangle2 GetTriangle () const;

		// The intersection set.  If the line and triangle do not intersect,
		// GetQuantity() returns 0, in which case the intersection type is
		// IT_EMPTY.  If the line and triangle intersect in a single point,
		// GetQuantity() returns 1, in which case the intersection type is
		// IT_POINT and GetPoint() returns the intersection point.  If the line
		// and triangle intersect in a segment, GetQuantity() returns 2, in which
		// case the intersection type is IT_SEGMENT and GetPoint() returns the
		// segment endpoints.
		int GetQuantity () const;
		const Vector2D& GetPoint (int i) const;

	private:
		void Find ();
		
		// The objects to intersect.
		Line2 mLine;
		Triangle2 mTriangle;
		
		// Information about the intersection set.
		int mQuantity;
		Vector2D mPoint[2];
		
	public:
		// Shared by IntrRay2Triangle2 and IntrSegment2Triangle2.
		
		// Determine how the triangle and line intersect (if at all).
		static void TriangleLineRelations (const Vector2D& origin,const Vector2D& direction,const Triangle2& triangle,Real dist[3], 
										   int sign[3],int& positive, int& negative,int& zero);
		
		// Compute the parameter interval for the segment of intersection when
		// the triangle transversely intersects the line.
		static void GetInterval (const Vector2D& origin, const Vector2D& direction,  const Triangle2& triangle,
								 const Real dist[3], const int sign[3], Real param[2]);
	};
	
	using StaticFindIntersectorLine2Triangle2f = StaticFindIntersectorLine2Triangle2<float>;
	using StaticFindIntersectorLine2Triangle2d = StaticFindIntersectorLine2Triangle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_TRIANGLE2_H
