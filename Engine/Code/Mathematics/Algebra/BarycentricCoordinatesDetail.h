///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 10:25)

#ifndef MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_DETAIL_H
#define MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_DETAIL_H

#include "BarycentricCoordinates.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real, int WindowSize>
requires std::is_arithmetic_v<Real> && (WindowSize == 3 || WindowSize == 4)
Mathematics::BarycentricCoordinates<Real, WindowSize>::BarycentricCoordinates() noexcept
    : isValid{ false }, tuple{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real, int WindowSize>
requires std::is_arithmetic_v<Real> && (WindowSize == 3 || WindowSize == 4)
Mathematics::BarycentricCoordinates<Real, WindowSize>::BarycentricCoordinates(bool isValid, const TupleType& tuple) noexcept
    : isValid{ isValid }, tuple{ tuple }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, int WindowSize>
requires std::is_arithmetic_v<Real> && (WindowSize == 3 || WindowSize == 4) bool Mathematics::BarycentricCoordinates<Real, WindowSize>::IsValid() const noexcept
{
    if (!isValid || Math::FAbs(Math::GetValue(1) - tuple.GetSum()) <= Math::GetZeroTolerance())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, int WindowSize>
requires std::is_arithmetic_v<Real> && (WindowSize == 3 || WindowSize == 4)
Real Mathematics::BarycentricCoordinates<Real, WindowSize>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;
    MATHEMATICS_ASSERTION_0(isValid, "重心坐标是无效的！");

    return tuple[index];
}

template <typename Real, int WindowSize>
requires std::is_arithmetic_v<Real> && (WindowSize == 3 || WindowSize == 4) bool Mathematics::BarycentricCoordinates<Real, WindowSize>::IsBarycentricCoordinatesValid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return isValid;
}

#endif  // MATHEMATICS_ALGEBRA_BARYCENTRIC_COORDINATES_DETAIL_H
