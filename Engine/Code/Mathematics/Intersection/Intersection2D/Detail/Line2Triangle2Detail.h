///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/22 10:53)

#ifndef MATHEMATICS_INTERSECTION_LINE2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_LINE2_TRIANGLE2_DETAIL_H

#include "Line2Triangle2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"

template <typename Real>
Mathematics::Line2Triangle2<Real>::Line2Triangle2(const Vector2D& origin, const Vector2D& direction, const Triangle2& triangle)
    : m_Distance{}, m_Sign{}, m_Positive{}, m_Negative{}, m_Zero{}, m_Origin{ origin }, m_Direction{ direction }, m_Triangle{ triangle }
{
    TriangleLineRelations();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Line2Triangle2<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Line2Triangle2<Real>::GetPositive() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Positive;
}

template <typename Real>
int Mathematics::Line2Triangle2<Real>::GetNegative() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Negative;
}

template <typename Real>
void Mathematics::Line2Triangle2<Real>::TriangleLineRelations()
{
    auto vertex = m_Triangle.GetVertex();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    for (int i = 0; i < sm_Size; ++i)
    {
        auto diff = vertex.at(i) - m_Origin;
        m_Distance[i] = Vector2DTools::DotPerp(diff, m_Direction);
        if (Math::GetZeroTolerance() < m_Distance[i])
        {
            m_Sign[i] = NumericalValueSymbol::Positive;
            ++m_Positive;
        }
        else if (m_Distance[i] < -Math::GetZeroTolerance())
        {
            m_Sign[i] = NumericalValueSymbol::Negative;
            ++m_Negative;
        }
        else
        {
            m_Distance[i] = Math::GetValue(0);
            m_Sign[i] = NumericalValueSymbol::Zero;
            ++m_Zero;
        }
    }

#include STSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Vector2D<Real> Mathematics::Line2Triangle2<Real>::GetInterval() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto vertex = m_Triangle.GetVertex();

    // 将三角形投影到线上。
    DistanceType proj{};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    for (auto i = 0; i < sm_Size; ++i)
    {
        auto diff = vertex[i] - m_Origin;
        proj[i] = Vector2DTools::DotProduct(m_Direction, diff);
    }

    // 用线计算三角形边缘的横向交点。

    auto quantity = 0;
    Vector2D param{};
    for (auto i0 = 2, i1 = 0; i1 < sm_Size; i0 = i1++)
    {
        if (m_Sign[i0] * System::EnumCastUnderlying(m_Sign[i1]) < 0)
        {
            MATHEMATICS_ASSERTION_0(quantity < 2, "交叉点太多\n");

            auto numer = m_Distance[i0] * proj[i1] - m_Distance[i1] * proj[i0];
            auto denom = m_Distance[i0] - m_Distance[i1];
            param[quantity++] = numer / denom;
        }
    }

    if (quantity < 2)
    {
        for (auto i0 = 1, i1 = 2, i2 = 0; i2 < sm_Size; i0 = i1, i1 = i2++)
        {
            if (m_Sign[i2] == NumericalValueSymbol::Zero)
            {
                MATHEMATICS_ASSERTION_0(quantity < 2, "交叉点太多\n");
                param[quantity++] = proj[i2];
            }
        }
    }

#include STSTEM_WARNING_POP

    // 排序
    MATHEMATICS_ASSERTION_0(1 <= quantity, "需要至少一个相交点\n");

    if (quantity == 2)
    {
        if (param[1] < param[0])
        {
            std::swap(param[0], param[1]);
        }
    }
    else
    {
        param[1] = param[0];
    }

    return param;
}

#endif  // MATHEMATICS_INTERSECTION_LINE2_TRIANGLE2_DETAIL_H
