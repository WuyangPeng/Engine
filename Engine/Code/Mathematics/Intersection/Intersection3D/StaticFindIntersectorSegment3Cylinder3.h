// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 11:44)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CYLINDER3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Segment3.h"  
#include "Mathematics/Objects3D/Cylinder3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorSegment3Cylinder3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorSegment3Cylinder3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Cylinder3 = Cylinder3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;  	
 
	public:
		StaticFindIntersectorSegment3Cylinder3 (const Segment3& segment,const Cylinder3& cylinder);
		
		// Object access.
		const Segment3 GetSegment () const;
		const Cylinder3 GetCylinder () const;

		// The intersection set.
		int GetQuantity () const;
		const Vector3D GetPoint (int i) const;		
		
	private:
		// Static intersection query.
		void Find ();
		
		// The objects to intersect.
		Segment3 mSegment;
		Cylinder3 mCylinder;
		
		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[2];
	};
	
	using StaticFindIntersectorSegment3Cylinder3f = StaticFindIntersectorSegment3Cylinder3<float>;
	using StaticFindIntersectorSegment3Cylinder3d = StaticFindIntersectorSegment3Cylinder3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CYLINDER3_H
