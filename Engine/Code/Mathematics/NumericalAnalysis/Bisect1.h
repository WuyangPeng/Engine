// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:45)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_H

#include "Mathematics/MathematicsDll.h"

#include "Bisect1Root.h"
#include "Mathematics/Base/Math.h"

// ���ַ��ⷽ��
namespace Mathematics
{
	template <typename Real>
	class Bisect1
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Bisect1<Real>;
		using Function = Real(*)(Real);
		using Bisect1Root = Bisect1Root<Real>;

	public:
		Bisect1(Function function, int maxLevel, Real tolerance = Math<Real>::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		// ͨ�������������˵����ⷽ��
		const Bisect1Root Bisect(Real beginPoint, Real endPoint);

	private:
		// �������ݺͺ�����
		Function m_Function;
		int m_MaxLevel;
		Real m_Tolerance;
	};

	using Bisect1f = Bisect1<float>;
	using Bisect1d = Bisect1<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_H
