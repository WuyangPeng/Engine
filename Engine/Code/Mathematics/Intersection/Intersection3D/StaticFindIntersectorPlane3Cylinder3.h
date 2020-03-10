// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 10:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h" 
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Ellipse3.h"  
#include "Mathematics/Objects3D/Cylinder3.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorPlane3Cylinder3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorPlane3Cylinder3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Cylinder3 = Cylinder3<Real>;
		using Line3 = Line3<Real>;
		using Circle3 = Circle3<Real>;
		using Ellipse3 = Ellipse3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;		
		
	public:
		StaticFindIntersectorPlane3Cylinder3 (const Plane3& plane,const Cylinder3& cylinder);
		
		// Object access.
		const Plane3 GetPlane () const;
		const Cylinder3 GetCylinder () const;

		// Culling support.  The view frustum is assumed to be on the positive
		// side of the plane.  The cylinder is culled if it is on the negative
		// side of the plane.
		bool CylinderIsCulled () const;

		// The intersection set for an *infinite* cylinder and the plane.
		enum
		{
			PC_EMPTY_SET,
			PC_ONE_LINE,
			PC_TWO_LINES,
			PC_CIRCLE,
			PC_ELLIPSE
		};

		int GetType () const;

		// Valid when GetType() returns PC_ONE_LINE.
		void GetOneLine (Line3& line) const;

		// Valid when GetType() returns PC_TWO_LINES.
		void GetTwoLines (Line3& line0, Line3& line1) const;

		// Valid when GetType() returns PC_CIRCLE.
		void GetCircle (Circle3& circle) const;

		// Valid when GetType() returns PC_ELLIPSE.
		void GetEllipse (Ellipse3& ellipse) const;

	private:
		// Static intersection query for an *infinite* cylinder.
		void Find ();
		
		// The objects to intersect.
		Plane3 mPlane;
		Cylinder3 mCylinder;
		
		// The intersection set when the cylinder is infinite.
		int mType;
		Line3 mLine0, mLine1;
		Circle3 mCircle;
		Ellipse3 mEllipse;		
	};
	
	using StaticFindIntersectorPlane3Cylinder3f = StaticFindIntersectorPlane3Cylinder3<float>;
	using StaticFindIntersectorPlane3Cylinder3d = StaticFindIntersectorPlane3Cylinder3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_H
