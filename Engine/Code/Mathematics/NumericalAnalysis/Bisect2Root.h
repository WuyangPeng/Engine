// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 12:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ROOT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ROOT_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/RootType.h"

#include <type_traits>

// 二分法解方程的根
namespace Mathematics
{
	template <typename Real>
	class Bisect2Root
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Bisect2Root<Real>;

	public:
		// 方程无解
		Bisect2Root();
		// 方程有解
		Bisect2Root(Real xRoot, Real yRoot, BisectRootType type);

		CLASS_INVARIANT_DECLARE;

		// 当m_BisectRootType == BisectRootType::HaveSolution时，
		// m_XRoot、m_YRoot是有效的。
		// 当m_BisectRootType == BisectRootType::Unknown时，
		// m_XRoot、m_YRoot是近似值，不保证结果是正确的。
		// 当m_BisectRootType == BisectRootType::NoSolution时，
		// GetXRoot()、GetYRoot()抛出异常。
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
