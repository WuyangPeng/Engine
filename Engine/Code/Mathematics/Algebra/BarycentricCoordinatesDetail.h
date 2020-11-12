///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 16:49)

#ifndef MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_DETAIL_H
#define MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_DETAIL_H

#include "BarycentricCoordinates.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real, int WindowSize>
Mathematics::BarycentricCoordinates<Real, WindowSize>::BarycentricCoordinates() noexcept
    : m_IsValid{ false }, m_Tuple{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real, int WindowSize>
Mathematics::BarycentricCoordinates<Real, WindowSize>::BarycentricCoordinates(bool isValid, const Tuple& tuple) noexcept
    : m_IsValid{ isValid }, m_Tuple{ tuple }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, int WindowSize>
bool Mathematics::BarycentricCoordinates<Real, WindowSize>::IsValid() const noexcept
{
    if (!m_IsValid || Math::FAbs(Math::GetValue(1) - m_Tuple.GetSum()) <= Math::GetZeroTolerance())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, int WindowSize>
Real Mathematics::BarycentricCoordinates<Real, WindowSize>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;
    MATHEMATICS_ASSERTION_0(m_IsValid, "重心坐标是无效的！");

    return m_Tuple[index];
}

template <typename Real, int WindowSize>
bool Mathematics::BarycentricCoordinates<Real, WindowSize>::IsBarycentricCoordinatesValid() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return m_IsValid;
}

#endif  // MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_DETAIL_H
