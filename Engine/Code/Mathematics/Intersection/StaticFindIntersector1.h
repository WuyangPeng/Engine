// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/11 14:41)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_H

#include "Intersector1.h"

#include <vector>

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersector1 : public Intersector1<Real>
	{
	public:	
		using ClassType = StaticFindIntersector1<Real>;
		using ParentType = Intersector1<Real>;
		using Math = Math<Real>;
	public:		 
		StaticFindIntersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon = Math::sm_ZeroTolerance);
		virtual ~StaticFindIntersector1();
		
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual bool IsIntersection() const override; 	

		// 有关交集的信息。
		// 相交数为0（区间不重叠），
		// 1（区间边界相交）或2（区间与区间相交）。
		int GetNumIntersections() const;
		Real GetIntersection(int index) const;

	private:
		void Find();

	private:
		std::vector<Real> m_Intersections;
	};

	using StaticFindIntersector1f = StaticFindIntersector1<float>;
	using StaticFindIntersector1d = StaticFindIntersector1<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_H
