///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 18:02)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H

#include "StaticTestIntersectorTriangle2Triangle2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>::StaticTestIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1, const Real dotThreshold)
    : ParentType{ dotThreshold }, triangle0{ triangle0 }, triangle1{ triangle1 }
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
Mathematics::Triangle2<Real> Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>::GetTriangle0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle0;
}

template <typename Real>
Mathematics::Triangle2<Real> Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>::GetTriangle1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>::Test()
{
    // ����������0�ı�Ե�Ƿ���롣
    for (auto i0 = 0, i1 = 2; i0 < 3; i1 = i0++)
    {
        auto vertex = triangle0.GetVertex();
        // ������ V0[i1] + t * perp(V0[i0]-V0[i1]), perp(x,y) = (y,-x).
        const Vector2 direction{ vertex.at(i0).GetY() - vertex.at(i1).GetY(),
                                 vertex.at(i1).GetX() - vertex.at(i0).GetX() };

        if (WhichSide(triangle1.GetVertex(), vertex.at(i1), direction) == NumericalValueSymbol::Positive)
        {
            // Triangle1��ȫ��triangle0�ߵ����ࡣ
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // ����������1�ı�Ե�Ƿ���롣
    for (auto i0 = 0, i1 = 2; i0 < 3; i1 = i0++)
    {
        auto vertex = triangle1.GetVertex();
        // ������ V1[i1] + t*perp(V1[i0]-V1[i1]), perp(x,y) = (y,-x).
        const Vector2 direction{ vertex.at(i0).GetY() - vertex.at(i1).GetY(),
                                 vertex.at(i1).GetX() - vertex.at(i0).GetX() };
        if (WhichSide(triangle0.GetVertex(), vertex.at(i1), direction) == NumericalValueSymbol::Positive)
        {
            // Triangle0��ȫ��triangle1�ߵ����ࡣ
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    this->SetIntersectionType(IntersectionType::Point);
}

template <typename Real>
Mathematics::NumericalValueSymbol Mathematics::StaticTestIntersectorTriangle2Triangle2<Real>::WhichSide(const Container& vertex, const Vector2& point, const Vector2& direction)
{
    /// ����ͶӰΪP + t * D��ʽ�� �������t> 0���򷵻�ֵΪ+1��
    /// �������t <0���򷵻�-1�������򷵻�0������������£����߽������ηֿ���

    auto positive = 0;
    auto negative = 0;
    auto zero = 0;
    for (const auto& value : vertex)
    {
        auto t = Vector2Tools::DotProduct(direction, (value - point));
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

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_DETAIL_H