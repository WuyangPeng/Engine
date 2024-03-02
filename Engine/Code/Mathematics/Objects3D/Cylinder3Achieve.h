/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/23 15:25)

#ifndef MATHEMATICS_OBJECTS_3D_CYLINDER3_ACHIEVE_H
#define MATHEMATICS_OBJECTS_3D_CYLINDER3_ACHIEVE_H

#include "Cylinder3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Cylinder3<Real>::Cylinder3() noexcept
    : axis{ Vector3::GetZero(), Vector3::GetUnitX() }, radius{ Math::GetValue(1) }, height{ Math::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Cylinder3<Real>::Cylinder3(const Line3& axis, Real radius, Real height) noexcept
    : axis{ axis }, radius{ radius }, height{ height }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Cylinder3<Real>::Cylinder3(const AlgebraLine3& axis, Real radius, Real height)
    : axis{ axis }, radius{ radius }, height{ height }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Cylinder3<Real>::IsValid() const noexcept
{
    try
    {
        if (Math::GetValue(0) <= radius && (Math::GetValue(0) <= height || Math::Approximate(height, Math::GetValue(-1))))
            return true;
        else
            return false;
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Line3<Real> Mathematics::Cylinder3<Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return axis;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Cylinder3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return radius;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Cylinder3<Real>::GetHeight() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return height;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Cylinder3<Real>::AlgebraLine3 Mathematics::Cylinder3<Real>::GetAlgebraAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return AlgebraLine3{ axis.GetOrigin().GetVector(), axis.GetDirection().GetVector() };
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Cylinder3<Real>::MakeInfiniteCylinder() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    height = Math::GetValue(-1);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Cylinder3<Real>::MakeFiniteCylinder(Real aHeight) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Real{} <= aHeight)
    {
        height = aHeight;
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Cylinder3<Real>::IsFinite() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Real{} <= height;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Cylinder3<Real>::IsInfinite() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return height < Real{};
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::operator==(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs)
{
    return lhs.GetAxis() == rhs.GetAxis() && lhs.GetRadius() == rhs.GetRadius() && lhs.GetHeight() == rhs.GetHeight();
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::operator!=(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs)
{
    return !(lhs == rhs);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::operator<(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs)
{
    if (lhs.GetAxis() < rhs.GetAxis())
    {
        return true;
    }

    if (rhs.GetAxis() < lhs.GetAxis())
    {
        return false;
    }

    if (lhs.GetRadius() < rhs.GetRadius())
    {
        return true;
    }

    if (rhs.GetRadius() < lhs.GetRadius())
    {
        return false;
    }

    return lhs.GetHeight() < rhs.GetHeight();
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::operator<=(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs)
{
    return !(rhs < lhs);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::operator>(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs)
{
    return rhs < lhs;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::operator>=(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_OBJECTS_3D_CYLINDER3_ACHIEVE_H
