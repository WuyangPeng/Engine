///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 15:16)

#ifndef MATHEMATICS_OBJECTS_2D_ARC2_ACHIEVE_H
#define MATHEMATICS_OBJECTS_2D_ARC2_ACHIEVE_H

#include "Arc2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Arc2<Real>::Arc2(const Vector2& center, Real radius, const Vector2& end0, const Vector2& end1, const Real epsilon) noexcept
    : center{ center }, radius{ radius }, end0{ end0 }, end1{ end1 }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Arc2<Real>::IsValid() const noexcept
{
    try
    {
        if (Math::Approximate(Vector2Tools::DistanceSquared(center, end0), radius * radius, epsilon) &&
            Math::Approximate(Vector2Tools::DistanceSquared(center, end1), radius * radius, epsilon))
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
bool Mathematics::Arc2<Real>::Contains(const Vector2& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_2(Math::Approximate(Vector2Tools::Distance(center, point), radius, epsilon), "point不在圆上。");

    // 断言：|P-C| = Real其中P为输入点，C为圆心，Real为圆弧半径。
    // 对于P是在圆弧A至B，它必须是在包含A的平面，法线N = Perp(B-A)
    // 这里Perp(u,v) = (v,-u)。

    const auto diffPointEnd0 = point - end0;
    const auto diffEnd1End0 = end1 - end0;
    const auto dotPerp = Vector2Tools::DotPerp(diffPointEnd0, diffEnd1End0);

    return -epsilon <= dotPerp;
}

template <typename Real>
typename Mathematics::Arc2<Real>::Vector2 Mathematics::Arc2<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
Real Mathematics::Arc2<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return radius;
}

template <typename Real>
typename Mathematics::Arc2<Real>::Vector2 Mathematics::Arc2<Real>::GetEnd0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return end0;
}

template <typename Real>
typename Mathematics::Arc2<Real>::Vector2 Mathematics::Arc2<Real>::GetEnd1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return end1;
}

#endif  // MATHEMATICS_OBJECTS_2D_ARC2_ACHIEVE_H
