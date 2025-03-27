/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/20 19:13)

#ifndef MATHEMATICS_OBJECTS_2D_ARC2_ACHIEVE_H
#define MATHEMATICS_OBJECTS_2D_ARC2_ACHIEVE_H

#include "Arc2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Arc2<Real>::Arc2() noexcept
    : center{ Vector2Type::GetZero() }, radius{ MathType::GetValue(1) }, end0{ Vector2Type::GetUnitX() }, end1{ Vector2Type::GetUnitY() }, epsilon{ MathType::GetZeroTolerance() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Arc2<Real>::Arc2(const Vector2Type& center, Real radius, const Vector2Type& end0, const Vector2Type& end1, Real epsilon) noexcept
    : center{ center }, radius{ radius }, end0{ end0 }, end1{ end1 }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Arc2<Real>::Arc2(const AlgebraVector2& center, Real radius, const AlgebraVector2& end0, const AlgebraVector2& end1, Real epsilon)
    : center{ center[0], center[1] }, radius{ radius }, end0{ end0[0], end0[1] }, end1{ end1[0], end1[1] }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Arc2<Real>::IsValid() const noexcept
{
    try
    {
        if (MathType::Approximate(Vector2ToolsType::Distance(center, end0), radius, epsilon) &&
            MathType::Approximate(Vector2ToolsType::Distance(center, end1), radius, epsilon))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Arc2<Real>::Contains(const Vector2Type& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    /// 如果epsilon为负，则公差的行为就像传递了epsilon的零值一样。

    const auto length = Vector2ToolsType::GetLength(point - center);
    if (MathType::FAbs(length - radius) <= epsilon)
    {
        const auto diffPointEnd0 = point - end0;
        const auto diffEnd1End0 = end1 - end0;
        const auto dotPerp = Vector2ToolsType::DotPerp(diffPointEnd0, diffEnd1End0);

        return Real{} <= dotPerp;
    }
    else
    {
        return false;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Arc2<Real>::Contains(const AlgebraVector2& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Contains(Vector2Type{ point[0], point[1] });
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Arc2<Real>::CircleContains(const Vector2Type& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto diffPointEnd0 = point - end0;
    const auto diffEnd1End0 = end1 - end0;
    const auto dotPerp = Vector2ToolsType::DotPerp(diffPointEnd0, diffEnd1End0);

    return Real{} <= dotPerp;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Arc2<Real>::CircleContains(const AlgebraVector2& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return CircleContains(Vector2Type{ point[0], point[1] });
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Arc2<Real>::Vector2Type Mathematics::Arc2<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::Arc2<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return radius;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Arc2<Real>::Vector2Type Mathematics::Arc2<Real>::GetEnd0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return end0;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::Arc2<Real>::Vector2Type Mathematics::Arc2<Real>::GetEnd1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return end1;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator==(const Arc2<Real>& lhs, const Arc2<Real>& rhs)
{
    return lhs.GetCenter() == rhs.GetCenter() && lhs.GetRadius() == rhs.GetRadius() && lhs.GetEnd0() == rhs.GetEnd0() && lhs.GetEnd1() == rhs.GetEnd1();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator!=(const Arc2<Real>& lhs, const Arc2<Real>& rhs)
{
    return !(lhs == rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator<(const Arc2<Real>& lhs, const Arc2<Real>& rhs)
{
    if (lhs.GetCenter() < rhs.GetCenter())
    {
        return true;
    }

    if (rhs.GetCenter() < lhs.GetCenter())
    {
        return false;
    }

    if (lhs.GetRadius() < rhs.GetRadius())
    {
        return true;
    }

    if (rhs.GetRadius() < lhs.GetCenter())
    {
        return false;
    }

    if (lhs.GetEnd0() < rhs.GetEnd0())
    {
        return true;
    }

    if (rhs.GetEnd0() < lhs.GetEnd0())
    {
        return false;
    }

    return lhs.GetEnd1() < rhs.GetEnd1();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator<=(const Arc2<Real>& lhs, const Arc2<Real>& rhs)
{
    return !(rhs < lhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator>(const Arc2<Real>& lhs, const Arc2<Real>& rhs)
{
    return !(lhs < rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator>=(const Arc2<Real>& lhs, const Arc2<Real>& rhs)
{
    return rhs < lhs;
}

#endif  // MATHEMATICS_OBJECTS_2D_ARC2_ACHIEVE_H
