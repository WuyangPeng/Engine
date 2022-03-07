// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:17)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_BOX2_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Box2.h"   
#include "Mathematics/Query/QueryBase.h"

namespace Mathematics
{
	// Compute a minimum-area oriented box containing the specified points.  The
	// algorithm uses the rotating calipers method.  If the input points represent
	// a counterclockwise-ordered polygon, set 'isConvexPolygon' to 'true';
	// otherwise, set 'isConvexPolygon' to 'false'.
	//
	// This is a function class.  Use it as follows:
	//   Box2<Real> minBox = MinBox2(numPoints, points, epsilon, queryType,
	//       isConvexPolygon);
	
	template <typename Real>
	class MinBox2
	{
	public:
		MinBox2 (const std::vector<Vector2<Real> >& points, Real epsilon, QueryType queryType, bool isConvexPolygon);
		
		operator Box2<Real> () const;
		
	private:
		// Flags for the rotating calipers algorithm.
		enum { F_NONE, F_LEFT, F_RIGHT, F_BOTTOM, F_TOP };
		
		void UpdateBox (const Vector2<Real>& LPoint, const Vector2<Real>& RPoint, const Vector2<Real>& BPoint,
                        const Vector2<Real>& TPoint, const Vector2<Real>& U, const Vector2<Real>& V, Real& minAreaDiv4);
		
		Box2<Real> mMinBox;
	};
}

#endif // MATHEMATICS_CONTAINMENT_CONT_MIN_BOX2_H
