// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/12 10:43)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Cylinder3.h"   
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorLine3Cylinder3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorLine3Cylinder3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Cylinder3 = Cylinder3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;  		
		
	public:
		StaticFindIntersectorLine3Cylinder3(const Line3& line,const Cylinder3& cylinder);
		
		// Object access.
		const Line3 GetLine () const;
		const Cylinder3 GetCylinder () const;
		
		// The intersection set.
		int GetQuantity() const;
		const Vector3D GetPoint(int i) const;

	private:
		// Static intersection query.
		void Find ();		
		
		// The objects to intersect.
		Line3 mLine;
		Cylinder3 mCylinder;
		
		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[2];

	public:
		// Shared by IntrRay3Cylinder3 and IntrSegment3Cylinder3.
		static int Find (const Vector3D& origin, const Vector3D& dir,const Cylinder3& cylinder, Real t[2]);
	};

	using StaticFindIntersectorLine3Cylinder3f = StaticFindIntersectorLine3Cylinder3<float>;
	using StaticFindIntersectorLine3Cylinder3d = StaticFindIntersectorLine3Cylinder3<double>;

}

#endif // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_H
