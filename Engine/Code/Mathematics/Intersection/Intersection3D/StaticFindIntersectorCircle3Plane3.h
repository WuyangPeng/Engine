// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 10:33)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE3_PLANE3_H

#include "Mathematics/MathematicsDll.h"
  
#include "Mathematics/Objects3D/Plane3.h" 
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorCircle3Plane3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorCircle3Plane3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Circle3 = Circle3<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   
	 
	public:
		StaticFindIntersectorCircle3Plane3 (const Circle3& circle, const Plane3& plane);
		
		// Object access.
		const Circle3 GetCircle () const;
		const Plane3 GetPlane () const;

		// Information about the intersection set.  Only get the specific object
		// of intersection corresponding to the intersection type.  If the type
		// is IT_POINT, use GetPoint(i).  If the type is IT_OTHER, the set is a
		// circle, so use GetIntersectionCircle(), which returns the circle
		// object.
		int GetQuantity () const;
		const Vector3D GetPoint(int i) const;
		const Circle3 GetIntersectionCircle() const;

	private:
		// Static intersection queries.		
		void Find ();		
		
		// The objects to intersect.
		Circle3 mCircle;
		Plane3 mPlane;
		
		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[2];
	};
	
	using StaticFindIntersectorCircle3Plane3f = StaticFindIntersectorCircle3Plane3<float>;
	using StaticFindIntersectorCircle3Plane3d = StaticFindIntersectorCircle3Plane3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE3_PLANE3_H
