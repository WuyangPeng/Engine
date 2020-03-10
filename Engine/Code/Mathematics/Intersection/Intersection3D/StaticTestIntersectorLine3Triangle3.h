// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/12 13:55)

#ifndef MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_LINE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_LINE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Triangle3.h"
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	// �����ཻ��ѯ��
	template <typename Real>
	class StaticTestIntersectorLine3Triangle3 : public StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorLine3Triangle3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;
		
	public:
		StaticTestIntersectorLine3Triangle3(const Line3& line,const Triangle3& triangle,const Real epsilon = Math::sm_ZeroTolerance);

		virtual ~StaticTestIntersectorLine3Triangle3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		const Line3 GetLine () const;
		const Triangle3 GetTriangle () const;

	private:
		void Test();
		
	private: 
		// �ཻ����
		Line3 m_Line;
		Triangle3 m_Triangle;		
	};

	using StaticTestIntersectorLine3Triangle3f = StaticTestIntersectorLine3Triangle3<float>;
	using StaticTestIntersectorLine3Triangle3d = StaticTestIntersectorLine3Triangle3<double>;
}

#endif // MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_LINE3_TRIANGLE3_H
