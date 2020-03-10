// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/12 13:56)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Lozenge3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorLozenge3Lozenge3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorLozenge3Lozenge3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Lozenge3 = Lozenge3<Real>;
		using Vector3DTools = Vector3DTools<Real>; 
		using Math = Math<Real>;		
		
	public:
		StaticTestIntersectorLozenge3Lozenge3 (const Lozenge3& lozenge0, const Lozenge3& lozenge1);

		// Object access.
		const Lozenge3 GetLozenge0 () const;
		const Lozenge3 GetLozenge1 () const;
		
		// Static intersection query.
		void Test ();
		
	private:
		// The objects to intersect.
		Lozenge3 mLozenge0;
		Lozenge3 mLozenge1;
	};
	
	using StaticTestIntersectorLozenge3Lozenge3f = StaticTestIntersectorLozenge3Lozenge3<float>;
	using StaticTestIntersectorLozenge3Lozenge3d = StaticTestIntersectorLozenge3Lozenge3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_H
