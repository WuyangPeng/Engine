// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:32)

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

		// ��̬�ཻ��ѯ���������䴦�ڵ�һ��/���һ�νӴ���ʱ�䡣
		Real GetFirstTime() const;
		Real GetLastTime() const;

		// �йؽ�������Ϣ��
		// �ཻ��Ϊ0�����䲻�ص�����
		// 1������߽��ཻ����2�������������ཻ����
		int GetNumIntersections() const;
		Real GetIntersection(int index) const;

	private:
		void Find(Real tMax, Real speedU, Real speedV);

	private:
		// �й��ཻ����Ϣ��
		Real m_FirstTime;
		Real m_LastTime;

		std::vector<Real> m_Intersections;
	};

	using DynamicFindIntersector1f = DynamicFindIntersector1<float>;
	using DynamicFindIntersector1d = DynamicFindIntersector1<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_H
