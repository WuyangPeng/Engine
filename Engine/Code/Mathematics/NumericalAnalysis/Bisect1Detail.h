// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 13:33)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_DETAIL_H

#include "Bisect1.h"
#include "Math.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect1<Real>
	::Bisect1(Function function, int maxLevel, Real tolerance)
	:m_Function{ function }, m_MaxLevel{ maxLevel }, m_Tolerance{ tolerance }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect1<Real>
	::IsValid() const noexcept
{
	if (m_Function != nullptr && 0 < m_MaxLevel && Math<Real>::sm_Zero <= m_Tolerance)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Bisect1<Real>::Bisect1Root Mathematics::Bisect1<Real>
	::Bisect(Real beginPoint, Real endPoint)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	// 测试两个端点。
	auto beginPointFunctionValue = m_Function(beginPoint);
	if (Math<Real>::FAbs(beginPointFunctionValue) <= m_Tolerance)
	{
		return Bisect1Root{ beginPoint,BisectRootType::HaveSolution };
	}

	auto endPointFunctionValue = m_Function(endPoint);
	if (Math<Real>::FAbs(endPointFunctionValue) <= m_Tolerance)
	{
		return Bisect1Root{ endPoint,BisectRootType::HaveSolution };
	}

	// 方程无解
	if (Math<Real>::sm_Zero < beginPointFunctionValue * endPointFunctionValue)
	{
		return Bisect1Root{};
	}

	auto middlePoints = static_cast<Real>(0.5) * (beginPoint + endPoint);

	for (auto level = 0; level < m_MaxLevel; ++level)
	{
		auto middlePointFunctionValue = m_Function(middlePoints);
		if (Math<Real>::FAbs(middlePointFunctionValue) <= m_Tolerance)
		{
			return Bisect1Root{ middlePoints,BisectRootType::HaveSolution };
		}

		if (beginPointFunctionValue * middlePointFunctionValue < Math<Real>::sm_Zero)
		{
			endPoint = middlePoints;
			endPointFunctionValue = middlePointFunctionValue;
		}
		else if (endPointFunctionValue * middlePointFunctionValue < Math<Real>::sm_Zero)
		{
			beginPoint = middlePoints;
			beginPointFunctionValue = middlePointFunctionValue;
		}

		middlePoints = static_cast<Real>(0.5) * (beginPoint + endPoint);
	}

	// 循环超出了次数，返回一个中间值。
	return Bisect1Root{ middlePoints,BisectRootType::Unknown };
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_DETAIL_H

