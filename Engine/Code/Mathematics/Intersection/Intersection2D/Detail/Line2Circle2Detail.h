///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/18 16:42)

#ifndef MATHEMATICS_INTERSECTION_LINE2_CIRCLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_LINE2_CIRCLE2_DETAIL_H

#include "Line2Circle2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"

template <typename Real>
Mathematics::Line2Circle2<Real>::Line2Circle2(const Vector2D& origin, const Vector2D& direction, const Vector2D& center, Real radius)
    : m_RootCount{}, m_Parameter{}, m_Intersects{}
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

    return m_RootCount;
}

template <typename Real>
Real Mathematics::Line2Circle2<Real>::GetParameter(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Parameter.at(index);
}

template <typename Real>
void Mathematics::Line2Circle2<Real>::ClearParameter0() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    m_Parameter[0] = m_Parameter[1];

#include STSTEM_WARNING_POP
}

template <typename Real>
bool Mathematics::Line2Circle2<Real>::IsIntersects() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Intersects;
}

template <typename Real>
void Mathematics::Line2Circle2<Real>::Find(const Vector2D& origin, const Vector2D& direction, const Vector2D& center, Real radius)
{
    /// 直线P + t * D 与圆|X - C| = Real。 线方向是单位长度。 t值是二次方程式的根：
    ///   0 = |t * D + P - C|^2 - Real^2
    ///     = t^2 + 2 * Dot(D, P- C)*t + |P - C|^2 - Real^2
    ///     = t^2 + 2 * a1 * t + a0
    /// 如果返回两个根，则顺序为T [0] <T [1]。

    auto diff = origin - center;
    auto a0 = Vector2DTools::VectorMagnitudeSquared(diff) - radius * radius;
    auto a1 = Vector2DTools::DotProduct(direction, diff);
    auto discr = a1 * a1 - a0;
    if (discr > Math::GetZeroTolerance())
    {
        m_RootCount = 2;
        discr = Math::Sqrt(discr);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        m_Parameter[0] = -a1 - discr;
        m_Parameter[1] = -a1 + discr;

#include STSTEM_WARNING_POP
    }
    else if (discr < -Math::GetZeroTolerance())
    {
        m_RootCount = 0;
    }
    else  // discr == 0
    {
        m_RootCount = 1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        m_Parameter[0] = -a1;

#include STSTEM_WARNING_POP
    }

    m_Intersects = (m_RootCount != 0);
}

#endif  // MATHEMATICS_INTERSECTION_LINE2_CIRCLE2_DETAIL_H
