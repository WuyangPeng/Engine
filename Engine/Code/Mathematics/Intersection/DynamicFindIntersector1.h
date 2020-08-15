// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:32)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_H

#include "Intersector1.h"

#include <vector>

namespace Mathematics
{
	template <typename Real>
	class DynamicFindIntersector1 : public Intersector1<Real>
	{
	public:
		using ClassType = DynamicFindIntersector1<Real>;
		using ParentType = Intersector1<Real>;
		using Math = Math<Real>;

	public:
		DynamicFindIntersector1(Real u0, Real u1, Real v0, Real v1, Real tMax, Real speedU, Real speedV, const Real epsilon = Math::sm_ZeroTolerance);
		virtual ~DynamicFindIntersector1();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		 bool IsIntersection() const override;

		// 动态相交查询的两个区间处于第一次/最后一次接触的时间。
		Real GetFirstTime() const;
		Real GetLastTime() const;

		// 有关交集的信息。
		// 相交数为0（区间不重叠），
		// 1（区间边界相交）或2（区间与区间相交）。
		int GetNumIntersections() const;
		Real GetIntersection(int index) const;

	private:
		void Find(Real tMax, Real speedU, Real speedV);

	private:
		// 有关相交的信息。
		Real m_FirstTime;
		Real m_LastTime;

		std::vector<Real> m_Intersections;
	};

	using DynamicFindIntersector1f = DynamicFindIntersector1<float>;
	using DynamicFindIntersector1d = DynamicFindIntersector1<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_H
