// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:33)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR1_H

#include "Mathematics/Base/MathDetail.h"

#include <array>
#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Intersector1
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Intersector1<Real>;
		using Math = Math<Real>;

	public:
		// ���[u0,u1]��[v0,v1]�������ࡣ
		// �յ��������u0 <= u1��v0 <= v1�� 
		// ����sm_MaxReal��-sm_MaxReal��ֵ��
		// �����˻������u0 = u1��v0 = v1��
		Intersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon = Math::GetZeroTolerance());
		virtual ~Intersector1();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		Real GetU(int index) const;
		Real GetV(int index) const;

		virtual bool IsIntersection() const = 0;

		Real GetEpsilon() const;

	private:
		static constexpr auto sm_Size = 2;

		// �ཻ�ļ����
		std::array<Real, sm_Size> m_U;
		std::array<Real, sm_Size> m_V;

		Real m_Epsilon;
	};

	using Intersector1f = Intersector1<float>;
	using Intersector1d = Intersector1<double>;
}

#endif // MATHEMATICS_INTERSECTION_INTERSECTOR1_H
