// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:45)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ROOT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ROOT_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/RootType.h"

#include <type_traits>

// ���ַ��ⷽ�̵ĸ�
namespace Mathematics
{
	template <typename Real>
	class Bisect1Root
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Bisect1Root<Real>;

	public:
		// �����޽�
		Bisect1Root();
		// �����н�
		Bisect1Root(Real root, BisectRootType type);

		CLASS_INVARIANT_DECLARE;

		// ��m_Bisect1RootType == Bisect1RootTypeHaveSolutionʱ��
		// m_Root����Ч�ġ�
		// ��m_Bisect1RootType == Bisect1RootTypeUnknownʱ��
		// m_Root�ǽ���ֵ������֤�������ȷ�ġ�
		// ��m_Bisect1RootType == Bisect1RootTypeNoSolutionʱ��
		// GetRoot()�׳��쳣��
		Real GetRoot() const;
		BisectRootType GetBisect1RootType() const;

	private:
		Real m_Root;
		BisectRootType m_Bisect1RootType;
	};

	using Bisect1Rootf = Bisect1Root<float>;
	using Bisect1Rootd = Bisect1Root<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ROOT_H
