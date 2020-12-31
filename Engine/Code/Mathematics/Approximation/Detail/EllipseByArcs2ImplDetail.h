///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/02 16:34)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_IMPL_DETAIL_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_IMPL_DETAIL_H

#include "EllipseByArcs2Impl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Containment/ScribeCircle2CircumscribeDetail.h"

template <typename Real>
Mathematics::EllipseByArcs2Impl<Real>::EllipseByArcs2Impl(Real begin, Real end, size_t numArcs)
    : m_Points(numArcs + 1), m_Circle(numArcs)
{
    MATHEMATICS_ASSERTION_2(2 <= m_Circle.size(), "必须至少指定两个圆弧\n");
    MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= begin, "begin必须大于或等于0\n");
    MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= end, " end必须大于或等于0\n");

    Calculate(begin, end);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::EllipseByArcs2Impl<Real>::Calculate(Real begin, Real end)
{
    // 中间椭圆数量
    auto beginSquare = begin * begin;
    auto endSquare = end * end;
    auto aMultipliedB = begin * end;
    auto inverseEndSquareMinusBeginSquare = Math::GetValue(1) / (endSquare - beginSquare);

    auto numArcs = boost::numeric_cast<int>(m_Circle.size());

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 在第一象限椭圆的终点。点按逆时针顺序产生。
    m_Points[0] = Vector2D{ begin, Math::GetValue(0) };
    m_Points[numArcs] = Vector2D{ Math::GetValue(0), end };

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
        m_Points[index].SetCoordinate(begin * Math::Sqrt(Math::FAbs((pow - beginSquare) * inverseEndSquareMinusBeginSquare)),
                                      end * Math::Sqrt(Math::FAbs((pow - endSquare) * inverseEndSquareMinusBeginSquare)));
    }

    // 计算圆弧在 (a,0).
    ScribeCircle2Circumscribe<Real> beginCircumscribe{ Vector2D{ m_Points[1].GetX(), -m_Points[1].GetY() }, m_Points[0], m_Points[1] };
    m_Circle[0] = beginCircumscribe.GetCircle2();

    // 计算圆弧在 (0,b).
    const auto last = numArcs - 1;
    ScribeCircle2Circumscribe<Real> endCircumscribe{ Vector2D{ -m_Points[last].GetX(), m_Points[last].GetY() }, m_Points[numArcs], m_Points[last] };
    m_Circle[last] = endCircumscribe.GetCircle2();

    // 在点(a,0) 和 (0,b)间计算圆弧
    for (auto index = 1; index < last; ++index)
    {
        const auto nextIndex = index + 1;
        const auto beforeIndex = index - 1;
        ScribeCircle2Circumscribe<Real> circumscribe{ m_Points[beforeIndex], m_Points[index], m_Points[nextIndex] };
        m_Circle[index] = circumscribe.GetCircle2();
    }

#include STSTEM_WARNING_POP
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::EllipseByArcs2Impl<Real>::IsValid() const noexcept
{
    if (2 <= m_Circle.size() && m_Points.size() == m_Circle.size() + 1)
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
typename const Mathematics::EllipseByArcs2Impl<Real>::PointsType Mathematics::EllipseByArcs2Impl<Real>::GetPoints() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Points;
}

template <typename Real>
typename const Mathematics::EllipseByArcs2Impl<Real>::Circle2Container Mathematics::EllipseByArcs2Impl<Real>::GetCircle2() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Circle;
}

template <typename Real>
int Mathematics::EllipseByArcs2Impl<Real>::getNumArcs() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(m_Circle.size());
}

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::EllipseByArcs2Impl<Real>::GetArc2(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto nextIndex = index + 1;
    Arc2 arc{ m_Circle.at(index).GetCenter(), m_Circle.at(index).GetRadius(), m_Points.at(index), m_Points.at(nextIndex) };

    return arc;
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSE_BY_ARCS2_IMPL_DETAIL_H
