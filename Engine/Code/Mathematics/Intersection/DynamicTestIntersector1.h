// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:33)

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
		DynamicTestIntersector1(Real u0, Real u1, Real v0, Real v1, Real tMax, Real speedU, Real speedV, const Real epsilon = Math::GetZeroTolerance());
		virtual ~DynamicTestIntersector1();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		virtual bool IsIntersection() const override;

		// 动态相交查询的两个区间处于第一次/最后一次接触的时间。
		Real GetFirstTime() const;
		Real GetLastTime() const;

	private:
		void Test(Real tMax, Real speedU, Real speedV);

	private:
		// 有关相交的信息。
		Real m_FirstTime;
		Real m_LastTime;

		bool m_Intersection;
	};

	using DynamicTestIntersector1f = DynamicTestIntersector1<float>;
	using DynamicTestIntersector1d = DynamicTestIntersector1<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_H
