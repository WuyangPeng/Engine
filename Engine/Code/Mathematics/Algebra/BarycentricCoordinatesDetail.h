// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 13:02)

#ifndef MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_DETAIL_H
#define MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_DETAIL_H

#include "BarycentricCoordinates.h"
#include "AlgebraTraits.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, int WindowSize>
Mathematics::BarycentricCoordinates <Real, WindowSize>
	::BarycentricCoordinates()
	:m_IsValid{ false }, m_Tuple{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real, int WindowSize>
Mathematics::BarycentricCoordinates <Real, WindowSize>
	::BarycentricCoordinates(bool isValid, const Tuple& tuple)
	:m_IsValid{ isValid }, m_Tuple{ tuple }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, int WindowSize>
bool Mathematics::BarycentricCoordinates <Real, WindowSize>
	::IsValid() const noexcept
{
	if (!m_IsValid)
		return true;

	auto coordinatesSum = Math::sm_Zero;
	for (auto i = 0; i < WindowSize; ++i)
	{
		coordinatesSum += m_Tuple[i];
	}

	if (Math::FAbs(Math::sm_One - coordinatesSum) <= Math::sm_ZeroTolerance)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real, int WindowSize>
const Real& Mathematics::BarycentricCoordinates <Real, WindowSize>
	::operator[] (int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;
	MATHEMATICS_ASSERTION_0(0 <= index && index < WindowSize, "索引错误！");
	MATHEMATICS_ASSERTION_0(m_IsValid, "重心坐标是无效的！");

	return m_Tuple[index];
}

template <typename Real, int WindowSize>
bool Mathematics::BarycentricCoordinates <Real, WindowSize>
	::IsBarycentricCoordinatesValid() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_3;

	return m_IsValid;
}

#endif // MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_DETAIL_H
