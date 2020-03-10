// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/11 14:31)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_H

#include "Intersector1.h"

namespace Mathematics
{
	template <typename Real>
	class DynamicTestIntersector1 : public Intersector1<Real>
	{
	public:
		using ClassType = DynamicTestIntersector1<Real>;
		using ParentType = Intersector1<Real>;
		using Math = Math<Real>;

	public:
		DynamicTestIntersector1(Real u0, Real u1, Real v0, Real v1,Real tMax, Real speedU, Real speedV,const Real epsilon = Math::sm_ZeroTolerance);
		virtual ~DynamicTestIntersector1();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual bool IsIntersection() const override;

		// ��̬�ཻ��ѯ���������䴦�ڵ�һ��/���һ�νӴ���ʱ�䡣
		Real GetFirstTime() const;
		Real GetLastTime() const;

	private:
		void Test(Real tMax, Real speedU, Real speedV);

	private:
		// �й��ཻ����Ϣ��
		Real m_FirstTime;
		Real m_LastTime;

		bool m_Intersection;
	};

	using DynamicTestIntersector1f = DynamicTestIntersector1<float>;
	using DynamicTestIntersector1d = DynamicTestIntersector1<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_H
