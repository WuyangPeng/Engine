///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/02 18:42)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_IMPL_DETAIL_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_IMPL_DETAIL_H

#include "EllipseFit2Impl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Containment/ContBox2Detail.h"
#include "Mathematics/Distance/Distance2D/DistancePoint2Ellipse2Detail.h"
#include "Mathematics/NumericalAnalysis/MinimizeNDetail.h"

template <typename Real>
Mathematics::EllipseFit2Impl<Real>::EllipseFit2Impl(const Points& points)
    : m_Points{ points }, m_Center{}, m_Rotate{}, m_Extent0{}, m_Extent1{}, m_Exactly{}
{
    Fit2();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::EllipseFit2Impl<Real>::Fit2()
{
    // 能量函数为 E : Real^5 -> Real 其中
    // V = (V0, V1, V2, V3, V4)
    //   = (D[0], D[1], U.x, U.y, atan2(Real[1][0],Real[1][1])).

    InitialGuess();

    auto angle = Math::ATan2(m_Rotate.GetValue<0, 1>(), m_Rotate.GetValue<0, 0>());
    auto extent0 = m_Extent0 * Math::FAbs(m_Rotate.GetValue<0, 0>()) +
                   m_Extent1 * Math::FAbs(m_Rotate.GetValue<1, 0>());
    auto extent1 = m_Extent0 * Math::FAbs(m_Rotate.GetValue<0, 1>()) +
                   m_Extent1 * Math::FAbs(m_Rotate.GetValue<1, 1>());

    Container begin{ Math::GetRational(1, 2) * m_Extent0,
                     Math::GetRational(1, 2) * m_Extent1,
                     m_Center.GetX() - extent0,
                     m_Center.GetY() - extent1,
                     -Math::GetPI() };

    Container end{ Math::GetValue(2) * m_Extent0,
                   Math::GetValue(2) * m_Extent1,
                   m_Center.GetX() + extent0,
                   m_Center.GetY() + extent1,
                   Math::GetPI() };

    Container initial{ m_Extent0,
                       m_Extent1,
                       m_Center.GetX(),
                       m_Center.GetY(),
                       angle };

    const MinimizeN<Real, ClassType> minimizer{ 5, Energy, 8, 8, 32, this };

    auto data = minimizer.GetMinimum(begin, end, initial);

    m_Exactly = data.GetMinValue();

    const auto& minLocation = data.GetMinLocation();

    m_Extent0 = minLocation.at(0);
    m_Extent1 = minLocation.at(1);
    m_Center.SetCoordinate(minLocation.at(2), minLocation.at(3));

    m_Rotate.MakeRotation(-minLocation.at(4));
}

// private
template <typename Real>
void Mathematics::EllipseFit2Impl<Real>::InitialGuess()
{
    auto box = ContBox2<Real>::ContOrientedBox(m_Points);

    m_Center = box.GetCenter();
    m_Rotate.SetValue<0, 0>(box.GetAxis0().GetX());
    m_Rotate.SetValue<0, 1>(box.GetAxis0().GetY());
    m_Rotate.SetValue<1, 0>(box.GetAxis1().GetX());
    m_Rotate.SetValue<1, 1>(box.GetAxis1().GetY());
    m_Extent0 = box.GetExtent0();
    m_Extent1 = box.GetExtent1();
}

// static
// private
template <typename Real>
Real Mathematics::EllipseFit2Impl<Real>::Energy(const Container& input, const EllipseFit2Impl* userData)
{
    if (userData == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("致命错误，传递空指针。"s));
    }

    const auto& self = *userData;

    // 构建旋转矩阵
    const Matrix2 rotate{ -input.at(4) };

    Ellipse2<Real> ellipse{ Vector2D::GetZero(), Vector2D::GetUnitX(),
                            Vector2D::GetUnitY(), input.at(0), input.at(1) };

    // 变换点到中心C和旋转Real的列的坐标系统
    auto energy = Math::GetValue(0);

    const auto numPoints = userData->GetNumPoint();

    for (auto i = 0; i < numPoints; ++i)
    {
        const auto& value = self.GetPoint(i);
        const Vector2D diff{ value.GetX() - input.at(2), value.GetY() - input.at(3) };

        const auto point = rotate * diff;

        DistancePoint2Ellipse2<Real> distancePoint2Ellipse2{ point, ellipse };
        auto distance = distancePoint2Ellipse2.Get();

        energy += distance.GetDistance();
    }

    return energy;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::EllipseFit2Impl<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= m_Exactly)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::EllipseFit2Impl<Real>::GetExactly() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Exactly;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::EllipseFit2Impl<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::EllipseFit2Impl<Real>::GetRotate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Rotate;
}

template <typename Real>
Real Mathematics::EllipseFit2Impl<Real>::GetExtent0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Extent0;
}

template <typename Real>
Real Mathematics::EllipseFit2Impl<Real>::GetExtent1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Extent1;
}

template <typename Real>
int Mathematics::EllipseFit2Impl<Real>::GetNumPoint() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(m_Points.size());
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::EllipseFit2Impl<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Points.at(index);
}

#endif  // MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_IMPL_DETAIL_H
