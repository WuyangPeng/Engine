// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 10:41)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_H

#include "Mathematics/MathematicsDll.h"
 
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Cone3.h"  
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorLine3Cone3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorLine3Cone3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Cone3 = Cone3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>; 		
		
	public:
		StaticFindIntersectorLine3Cone3(const Line3& line, const Cone3& cone);
		
		// Object access.
		const Line3 GetLine () const;
		const Cone3 GetCone () const;

		// The intersection set.  The possible intersection types are
		//   IT_EMTPY:   no intersection
		//   IT_POINT:   point[0] is the intersection point
		//   IT_SEGMENT: <point[0],point[1]> is the intersection segment
		//   IT_RAY:     point[0]+t*point[1] is the intersection ray
		int GetQuantity() const;
		const Vector3D GetPoint(int i) const;

	private:
		// Static intersection query.
		void Find();
		
		// The objects to intersect.
		Line3 mLine;
		Cone3 mCone;
		
		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[2];
	};
	
	using StaticFindIntersectorLine3Cone3f = StaticFindIntersectorLine3Cone3<float>;
	using StaticFindIntersectorLine3Cone3d = StaticFindIntersectorLine3Cone3<double>;
}

#endif // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_H
