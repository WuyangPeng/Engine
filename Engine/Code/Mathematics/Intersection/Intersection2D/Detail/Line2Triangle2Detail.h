///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 19:18)

#ifndef MATHEMATICS_INTERSECTION_LINE2_TRIANGLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_LINE2_TRIANGLE2_DETAIL_H

#include "Line2Triangle2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

template <typename Real>
Mathematics::Line2Triangle2<Real>::Line2Triangle2(const Vector2& origin, const Vector2& direction, const Triangle2& triangle)
    : distance{}, sign{}, positive{}, negative{}, zero{}, origin{ origin }, direction{ direction }, triangle{ triangle }
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

    return positive;
}

template <typename Real>
int Mathematics::Line2Triangle2<Real>::GetNegative() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return negative;
}

template <typename Real>
void Mathematics::Line2Triangle2<Real>::TriangleLineRelations()
{
    auto vertex = triangle.GetVertex();

    for (int i = 0; i < size; ++i)
    {
        auto diff = vertex.at(i) - origin;
        distance.at(i) = Vector2Tools::DotPerp(diff, direction);
        if (Math::GetZeroTolerance() < distance.at(i))
        {
            sign.at(i) = NumericalValueSymbol::Positive;
            ++positive;
        }
        else if (distance.at(i) < -Math::GetZeroTolerance())
        {
            sign.at(i) = NumericalValueSymbol::Negative;
            ++negative;
        }
        else
        {
            distance.at(i) = Math::GetValue(0);
            sign.at(i) = NumericalValueSymbol::Zero;
            ++zero;
        }
    }
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Line2Triangle2<Real>::GetInterval() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto vertex = triangle.GetVertex();

    // 将三角形投影到线上。
    DistanceType proj{};

    for (auto i = 0; i < size; ++i)
    {
        auto diff = vertex.at(i) - origin;
        proj.at(i) = Vector2Tools::DotProduct(direction, diff);
    }

    using System::operator*;

    // 用线计算三角形边缘的横向交点。

    auto quantity = 0;
    Vector2 param{};
    for (auto i0 = 2, i1 = 0; i1 < size; i0 = i1++)
    {
        if (sign.at(i0) * System::EnumCastUnderlying(sign.at(i1)) < 0)
        {
            MATHEMATICS_ASSERTION_0(quantity < 2, "交叉点太多\n");

            auto numer = distance.at(i0) * proj.at(i1) - distance.at(i1) * proj.at(i0);
            auto denom = distance.at(i0) - distance.at(i1);
            param[quantity++] = numer / denom;
        }
    }

    if (quantity < 2)
    {
        for (auto i0 = 1, i1 = 2, i2 = 0; i2 < size; i0 = i1, i1 = i2++)
        {
            if (sign.at(i2) == NumericalValueSymbol::Zero)
            {
                MATHEMATICS_ASSERTION_0(quantity < 2, "交叉点太多\n");
                param[quantity++] = proj.at(i2);
            }
        }
    }

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
