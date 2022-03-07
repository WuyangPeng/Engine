///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/18 15:08)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_DETAIL_H

#include "EllipseFit2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Containment/ContBox2Detail.h"
#include "Mathematics/Distance/Distance2D/DistancePoint2Ellipse2Detail.h"
#include "Mathematics/Distance/DistanceResultDetail.h"
#include "Mathematics/NumericalAnalysis/MinimizeNDetail.h"

template <typename Real>
Mathematics::EllipseFit2<Real>::EllipseFit2(const Points& points)
    : points{ points }, center{}, rotate{}, extent0{}, extent1{}, exactly{}
{
    Fit2();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::EllipseFit2<Real>::Fit2()
{
    // 能量函数为 E : Real^5 -> Real 其中
    // V = (V0, V1, V2, V3, V4)
    //   = (D[0], D[1], U.x, U.y, atan2(Real[1][0],Real[1][1])).

    InitialGuess();

    auto angle = Math::ATan2(rotate.GetValue<0, 1>(), rotate.GetValue<0, 0>());
    auto value0 = extent0 * Math::FAbs(rotate.GetValue<0, 0>()) +
                  extent1 * Math::FAbs(rotate.GetValue<1, 0>());
    auto value1 = extent0 * Math::FAbs(rotate.GetValue<0, 1>()) +
                  extent1 * Math::FAbs(rotate.GetValue<1, 1>());

    Container begin{ Math::GetRational(1, 2) * extent0,
                     Math::GetRational(1, 2) * extent1,
                     center.GetX() - value0,
                     center.GetY() - value1,
                     -Math::GetPI() };

    Container end{ Math::GetValue(2) * extent0,
                   Math::GetValue(2) * extent1,
                   center.GetX() + value0,
                   center.GetY() + value1,
                   Math::GetPI() };

    Container initial{ extent0,
                       extent1,
                       center.GetX(),
                       center.GetY(),
                       angle };

    const MinimizeN<Real, ClassType> minimizer{ 5, Energy, 8, 8, 32, this };

    auto data = minimizer.GetMinimum(begin, end, initial);

    exactly = data.GetMinValue();

    const auto& minLocation = data.GetMinLocation();

    extent0 = minLocation.at(0);
    extent1 = minLocation.at(1);
    center.SetCoordinate(minLocation.at(2), minLocation.at(3));

    rotate.MakeRotation(-minLocation.at(4));
}

// private
template <typename Real>
void Mathematics::EllipseFit2<Real>::InitialGuess()
{
    const auto box = ContBox2<Real>::ContOrientedBox(points);

    center = box.GetCenter();
    rotate.SetValue<0, 0>(box.GetAxis0().GetX());
    rotate.SetValue<0, 1>(box.GetAxis0().GetY());
    rotate.SetValue<1, 0>(box.GetAxis1().GetX());
    rotate.SetValue<1, 1>(box.GetAxis1().GetY());
    extent0 = box.GetExtent0();
    extent1 = box.GetExtent1();
}

// static
// private
template <typename Real>
Real Mathematics::EllipseFit2<Real>::Energy(const Container& input, const EllipseFit2* userData)
{
    if (userData == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("致命错误，传递空指针。"s));
    }

    const auto& self = *userData;

    // 构建旋转矩阵
    const Matrix2 rotate{ -input.at(4) };

    const Ellipse2<Real> ellipse{ Vector2::GetZero(), Vector2::GetUnitX(), Vector2::GetUnitY(), input.at(0), input.at(1) };

    // 变换点到中心C和旋转Real的列的坐标系统
    auto energy = Math::GetValue(0);

    const auto numPoints = userData->GetNumPoint();

    for (auto i = 0; i < numPoints; ++i)
    {
        const auto& value = self.GetPoint(i);
        const Vector2 diff{ value.GetX() - input.at(2), value.GetY() - input.at(3) };

        const auto point = rotate * diff;

        DistancePoint2Ellipse2<Real> distancePoint2Ellipse2{ point, ellipse };
        auto distance = distancePoint2Ellipse2.Get();

        energy += distance.GetDistance();
    }

    return energy;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::EllipseFit2<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= exactly)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::EllipseFit2<Real>::GetExactly() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return exactly;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::EllipseFit2<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::EllipseFit2<Real>::GetRotate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rotate;
}

template <typename Real>
Real Mathematics::EllipseFit2<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return extent0;
}

template <typename Real>
Real Mathematics::EllipseFit2<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return extent1;
}

template <typename Real>
int Mathematics::EllipseFit2<Real>::GetNumPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(points.size());
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::EllipseFit2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return points.at(index);
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_DETAIL_H
