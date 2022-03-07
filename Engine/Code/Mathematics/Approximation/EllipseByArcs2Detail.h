///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/17 18:23)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_DETAIL_H

#include "EllipseByArcs2.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Containment/ScribeCircle2CircumscribeDetail.h"

template <typename Real>
Mathematics::EllipseByArcs2<Real>::EllipseByArcs2(Real begin, Real end, size_t numArcs)
    : points(numArcs + 1), circle(numArcs)
{
    MATHEMATICS_ASSERTION_2(2 <= circle.size(), "必须至少指定两个圆弧\n");
    MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= begin, "begin必须大于或等于0\n");
    MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= end, " end必须大于或等于0\n");

    Calculate(begin, end);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::EllipseByArcs2<Real>::Calculate(Real begin, Real end)
{
    // 中间椭圆数量
    const auto beginSquare = begin * begin;
    const auto endSquare = end * end;
    const auto aMultipliedB = begin * end;
    const auto inverseEndSquareMinusBeginSquare = Math::GetValue(1) / (endSquare - beginSquare);

    const auto numArcs = boost::numeric_cast<int>(circle.size());

    // 在第一象限椭圆的终点。点按逆时针顺序产生。
    points.at(0) = Vector2{ begin, Math::GetValue(0) };
    points.at(numArcs) = Vector2{ Math::GetValue(0), end };

    // 终点的曲率，对于计算圆弧存储曲率。
    auto beginCurvature = begin / endSquare;
    auto endCurvature = end / beginSquare;

    // 选择基于曲率特性的椭圆点。
    for (auto index = 1; index < numArcs; ++index)
    {
        // 新点曲率为两端曲率加权平均值。
        auto weight1 = static_cast<Real>(index) / static_cast<Real>(numArcs);
        auto weight0 = Math::GetValue(1) - weight1;
        auto curvature = weight0 * beginCurvature + weight1 * endCurvature;

        // 使用曲率计算点。
        auto pow = Math::Pow(aMultipliedB / curvature, Math::GetValue(2) / Math::GetValue(3));
        points.at(index).SetCoordinate(begin * Math::Sqrt(Math::FAbs((pow - beginSquare) * inverseEndSquareMinusBeginSquare)),
                                       end * Math::Sqrt(Math::FAbs((pow - endSquare) * inverseEndSquareMinusBeginSquare)));
    }

    // 计算圆弧在 (a,0).
    ScribeCircle2Circumscribe<Real> beginCircumscribe{ Vector2{ points.at(1).GetX(), -points.at(1).GetY() }, points.at(0), points.at(1) };
    circle.at(0) = beginCircumscribe.GetCircle2();

    // 计算圆弧在 (0,b).
    const auto last = numArcs - 1;
    ScribeCircle2Circumscribe<Real> endCircumscribe{ Vector2{ -points.at(last).GetX(), points.at(last).GetY() }, points.at(numArcs), points.at(last) };
    circle.at(last) = endCircumscribe.GetCircle2();

    // 在点(a,0) 和 (0,b)间计算圆弧
    for (auto index = 1; index < last; ++index)
    {
        const auto nextIndex = index + 1;
        const auto beforeIndex = index - 1;
        ScribeCircle2Circumscribe<Real> circumscribe{ points.at(beforeIndex), points.at(index), points.at(nextIndex) };
        circle.at(index) = circumscribe.GetCircle2();
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::EllipseByArcs2<Real>::IsValid() const noexcept
{
    if (2 <= circle.size() && points.size() == circle.size() + 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::EllipseByArcs2<Real>::PointsType Mathematics::EllipseByArcs2<Real>::GetPoints() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return points;
}

template <typename Real>
typename Mathematics::EllipseByArcs2<Real>::Circle2Container Mathematics::EllipseByArcs2<Real>::GetCircle2() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

template <typename Real>
int Mathematics::EllipseByArcs2<Real>::getNumArcs() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(circle.size());
}

template <typename Real>
Mathematics::Arc2<Real> Mathematics::EllipseByArcs2<Real>::GetArc2(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto nextIndex = index + 1;
    Arc2 arc{ circle.at(index).GetCenter(), circle.at(index).GetRadius(), points.at(index), points.at(nextIndex) };

    return arc;
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_DETAIL_H
