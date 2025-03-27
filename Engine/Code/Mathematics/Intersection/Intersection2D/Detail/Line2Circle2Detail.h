///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:23)

#ifndef MATHEMATICS_INTERSECTION_LINE2_CIRCLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_LINE2_CIRCLE2_DETAIL_H

#include "Line2Circle2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

template <typename Real>
Mathematics::Line2Circle2<Real>::Line2Circle2(const Vector2& origin, const Vector2& direction, const Vector2& center, Real radius)
    : rootCount{}, parameter{}, intersects{}
{
    Find(origin, direction, center, radius);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Line2Circle2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Line2Circle2<Real>::GetRootCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return rootCount;
}

template <typename Real>
Real Mathematics::Line2Circle2<Real>::GetParameter(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return parameter.at(index);
}

template <typename Real>
void Mathematics::Line2Circle2<Real>::ClearParameter0() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    parameter[0] = parameter[1];

#include SYSTEM_WARNING_POP
}

template <typename Real>
bool Mathematics::Line2Circle2<Real>::IsIntersects() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return intersects;
}

template <typename Real>
void Mathematics::Line2Circle2<Real>::Find(const Vector2& origin, const Vector2& direction, const Vector2& center, Real radius)
{
    /// 直线P + t * D 与圆|X - C| = Real。 线方向是单位长度。 t值是二次方程式的根：
    ///   0 = |t * D + P - C|^2 - Real^2
    ///     = t^2 + 2 * Dot(D, P- C)*t + |P - C|^2 - Real^2
    ///     = t^2 + 2 * a1 * t + a0
    /// 如果返回两个根，则顺序为T [0] <T [1]。

    auto diff = origin - center;
    auto a0 = Vector2Tools::GetLengthSquared(diff) - radius * radius;
    auto a1 = Vector2Tools::DotProduct(direction, diff);
    auto discr = a1 * a1 - a0;
    if (discr > MathType::GetZeroTolerance())
    {
        rootCount = 2;
        discr = MathType::Sqrt(discr);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        parameter[0] = -a1 - discr;
        parameter[1] = -a1 + discr;

#include SYSTEM_WARNING_POP
    }
    else if (discr < -MathType::GetZeroTolerance())
    {
        rootCount = 0;
    }
    else  // discr == 0
    {
        rootCount = 1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        parameter[0] = -a1;

#include SYSTEM_WARNING_POP
    }

    intersects = (rootCount != 0);
}

#endif  // MATHEMATICS_INTERSECTION_LINE2_CIRCLE2_DETAIL_H
