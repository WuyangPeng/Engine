// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/12 10:50)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Torus3.h" 
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	template <typename Real>
	class  StaticFindIntersectorLine3Torus3 : public StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorLine3Torus3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Torus3 = Torus3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   		
		
	public:
		StaticFindIntersectorLine3Torus3(const Line3& line, const Torus3& torus);
		
		// Object access.
		const Line3 GetLine () const;
		const Torus3 GetTorus () const;		

		// The intersection set (quantity is at most 4).
		int GetQuantity() const;
		const Vector3D GetPoint(int i) const;

	private:
		// Static intersection query.
		void Find ();
		
		// The objects to intersect.
		Line3 mLine;
		Torus3 mTorus;
		
		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[4];
	};
	
	using StaticFindIntersectorLine3Torus3f = StaticFindIntersectorLine3Torus3<float>;
	using StaticFindIntersectorLine3Torus3d = StaticFindIntersectorLine3Torus3<double>;
}

#endif // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_H
