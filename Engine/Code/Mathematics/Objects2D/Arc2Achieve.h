///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 11:23)

#ifndef MATHEMATICS_OBJECTS2D_ARC2_ACHIEVE_H
#define MATHEMATICS_OBJECTS2D_ARC2_ACHIEVE_H

#include "Arc2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Arc2<Real>::Arc2(const Vector2D& center, Real radius, const Vector2D& end0, const Vector2D& end1, const Real epsilon) noexcept
    : m_Center{ center }, m_Radius{ radius }, m_End0{ end0 }, m_End1{ end1 }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Arc2<Real>::IsValid() const noexcept
{
    try
    {
        if (Math::Approximate(Vector2DTools::DistanceSquared(m_Center, m_End0), m_Radius * m_Radius, m_Epsilon) &&
            Math::Approximate(Vector2DTools::DistanceSquared(m_Center, m_End1), m_Radius * m_Radius, m_Epsilon))
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
bool Mathematics::Arc2<Real>::Contains(const Vector2D& point) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_2(Math::Approximate(Vector2DTools::Distance(m_Center, point), m_Radius, m_Epsilon), "point不在圆上。");

    // 断言：|P-C| = Real其中P为输入点，C为圆心，Real为圆弧半径。
    // 对于P是在圆弧A至B，它必须是在包含A的平面，法线N = Perp(B-A)
    // 这里Perp(u,v) = (v,-u)。

    auto diffPointEnd0 = point - m_End0;
    auto diffEnd1End0 = m_End1 - m_End0;
    auto dotPerp = Vector2DTools::DotPerp(diffPointEnd0, diffEnd1End0);

    return -m_Epsilon <= dotPerp;
}

template <typename Real>
typename const Mathematics::Arc2<Real>::Vector2D Mathematics::Arc2<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
Real Mathematics::Arc2<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Radius;
}

template <typename Real>
typename const Mathematics::Arc2<Real>::Vector2D Mathematics::Arc2<Real>::GetEnd0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_End0;
}

template <typename Real>
typename const Mathematics::Arc2<Real>::Vector2D Mathematics::Arc2<Real>::GetEnd1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_End1;
}

#endif  // MATHEMATICS_OBJECTS2D_ARC2_ACHIEVE_H
