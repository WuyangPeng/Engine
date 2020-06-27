// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ROOT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ROOT_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/RootType.h"

#include <type_traits>

// ���ַ��ⷽ�̵ĸ�
namespace Mathematics
{
	template <typename Real>
	class Bisect2Root
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Bisect2Root<Real>;

	public:
		// �����޽�
		Bisect2Root();
		// �����н�
		Bisect2Root(Real xRoot, Real yRoot, BisectRootType type);

		CLASS_INVARIANT_DECLARE;

		// ��m_BisectRootType == BisectRootType::HaveSolutionʱ��
		// m_XRoot��m_YRoot����Ч�ġ�
		// ��m_BisectRootType == BisectRootType::Unknownʱ��
		// m_XRoot��m_YRoot�ǽ���ֵ������֤�������ȷ�ġ�
		// ��m_BisectRootType == BisectRootType::NoSolutionʱ��
		// GetXRoot()��GetYRoot()�׳��쳣��
		Real GetXRoot() const;
		Real GetYRoot() const;
		BisectRootType GetBisectRootType() const;

	private:
		Real m_XRoot;
		Real m_YRoot;
		BisectRootType m_BisectRootType;
	};

	using Bisect2Rootf = Bisect2Root<float>;
	using Bisect2Rootd = Bisect2Root<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ROOT_H
