/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/26 15:32)

#ifndef MATHEMATICS_OBJECTS_3D_LOZENGE3_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_LOZENGE3_DETAIL_H

#include "Lozenge3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Lozenge3<Real>::Lozenge3() noexcept
    : rectangle{}, radius{ Math::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Lozenge3<Real>::Lozenge3(const Rectangle3& rectangle, Real radius) noexcept
    : rectangle{ rectangle }, radius{ radius }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Lozenge3<Real>::Lozenge3(const AlgebraRectangle3& rectangle, Real radius)
    : rectangle{ rectangle }, radius{ radius }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Lozenge3<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) < radius)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Rectangle3<Real> Mathematics::Lozenge3<Real>::GetRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rectangle;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Lozenge3<Real>::AlgebraRectangle3 Mathematics::Lozenge3<Real>::GetAlgebraRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rectangle.GetAlgebraRectangle3();
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Lozenge3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return radius;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator==(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs)
{
    return lhs.GetRectangle() == rhs.GetRectangle() && lhs.GetRadius() == rhs.GetRadius();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator!=(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs)
{
    return !(lhs == rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator<(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs)
{
    if (lhs.GetRectangle() < rhs.GetRectangle())
    {
        return true;
    }

    if (rhs.GetRectangle() < lhs.GetRectangle())
    {
        return false;
    }

    return lhs.GetRadius() < rhs.GetRadius();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator<=(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs)
{
    return !(rhs < lhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator>(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs)
{
    return rhs < lhs;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator>=(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_OBJECTS_3D_LOZENGE3_DETAIL_H
