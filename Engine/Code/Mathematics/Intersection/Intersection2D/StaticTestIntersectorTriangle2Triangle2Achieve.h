///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/23 22:07)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_ACHIEVE_H

#include "StaticTestIntersectorTriangle2Triangle2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>::StaticTestIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1, const Real dotThreshold)
    : ParentType{ dotThreshold }, m_Triangle0{ triangle0 }, m_Triangle1{ triangle1 }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>::GetTriangle0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle0;
}

template <typename Real>
const Mathematics::Triangle2<Real> Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>::GetTriangle1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>::Test()
{
    // 测试三角形0的边缘是否分离。
    for (auto i0 = 0, i1 = 2; i0 < 3; i1 = i0++)
    {
        auto vertex = m_Triangle0.GetVertex();
        // 测试轴 V0[i1] + t * perp(V0[i0]-V0[i1]), perp(x,y) = (y,-x).
        const Vector2D direction{ vertex.at(i0).GetY() - vertex.at(i1).GetY(),
                                  vertex.at(i1).GetX() - vertex.at(i0).GetX() };

        if (WhichSide(m_Triangle1.GetVertex(), vertex.at(i1), direction) == NumericalValueSymbol::Positive)
        {
            // Triangle1完全在triangle0边的正侧。
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // 测试三角形1的边缘是否分离。
    for (auto i0 = 0, i1 = 2; i0 < 3; i1 = i0++)
    {
        auto vertex = m_Triangle1.GetVertex();
        // 测试轴 V1[i1] + t*perp(V1[i0]-V1[i1]), perp(x,y) = (y,-x).
        const Vector2D direction{ vertex.at(i0).GetY() - vertex.at(i1).GetY(),
                                  vertex.at(i1).GetX() - vertex.at(i0).GetX() };
        if (WhichSide(m_Triangle0.GetVertex(), vertex.at(i1), direction) == NumericalValueSymbol::Positive)
        {
            // Triangle0完全在triangle1边的正侧。
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    this->SetIntersectionType(IntersectionType::Point);
}

template <typename Real>
Mathematics::NumericalValueSymbol Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>::WhichSide(const Container& vertex, const Vector2D& point, const Vector2D& direction)
{
    /// 顶点投影为P + t * D形式。 如果所有t> 0，则返回值为+1；
    /// 如果所有t <0，则返回-1；否则，则返回0，在这种情况下，该线将三角形分开。

    auto positive = 0;
    auto negative = 0;
    auto zero = 0;
    for (const auto& value : vertex)
    {
        auto t = Vector2DTools::DotProduct(direction, (value - point));
        if (Math::GetValue(0) < t)
        {
            ++positive;
        }
        else if (t < Math::GetValue(0))
        {
            ++negative;
        }
        else
        {
            ++zero;
        }

        if (0 < positive && 0 < negative)
        {
            return NumericalValueSymbol::Zero;
        }
    }
    return (zero == 0 ? (0 < positive ? NumericalValueSymbol::Positive : NumericalValueSymbol::Negative) : NumericalValueSymbol::Zero);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_ACHIEVE_H