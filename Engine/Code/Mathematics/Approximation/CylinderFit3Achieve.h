///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/02 14:59)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_ACHIEVE_H

#include "CylinderFit3.h"
#include "Detail/CylinderFit3UpdateDetail.h"
#include "OrthogonalLineFit3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Objects2D/Line2Detail.h"

#include <algorithm>

template <typename Real>
Mathematics::CylinderFit3<Real>::CylinderFit3(const Points& points, const Real epsilon)
    : m_Center{}, m_Axis{}, m_Radius{}, m_Height{}, m_Exactly{ Math::sm_MaxReal }, m_InputsAreInitialGuess{ false }, m_Epsilon{ epsilon }
{
    Fit3(points);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::CylinderFit3<Real>::CylinderFit3(const Points& points, const Vector3D& guessCenter, const Vector3D& guessAxis, const Real epsilon)
    : m_Center{ guessCenter }, m_Axis{ guessAxis }, m_Radius{}, m_Height{}, m_Exactly{ Math::sm_MaxReal }, m_InputsAreInitialGuess{ true }, m_Epsilon{ epsilon }
{
    Fit3(points);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::CylinderFit3<Real>::Fit3(const Points& points)
{
    InitialGuess(points);
    Update(points);
    auto average = ComputeHeight(points);
    ComputeCenter(average);
}

// private
template <typename Real>
void Mathematics::CylinderFit3<Real>::InitialGuess(const Points& points)
{
    if (!m_InputsAreInitialGuess)
    {
        // 找到适合该数据的最小二乘线，并用它作为圆柱体轴的初始猜测。
        const OrthogonalLineFit3<Real> orthogonalLineFit3{ points };

        const auto line = orthogonalLineFit3.GetLine3();
        m_Center = line.GetOrigin();
        m_Axis = line.GetDirection();
    }
}

// private
template <typename Real>
void Mathematics::CylinderFit3<Real>::Update(const Points& points)
{
    constexpr auto maxLoopTime = 8;

    CylinderFit3Update<Real> update{ points, m_Center, m_Axis, m_Epsilon };
    update.Update(maxLoopTime);

    m_Radius = Math::InvSqrt(update.GetInverseRadiusSqrare());
    m_Center = update.GetCenter();
    m_Axis = update.GetAxis();

    m_Exactly = update.GetExactly();
}

// private
template <typename Real>
Real Mathematics::CylinderFit3<Real>::ComputeHeight(const Points& points)
{
    // 项目点拟合到轴确定圆柱体沿轴的幅度。
    std::vector<Real> dotCollection{};
    for (const auto& point : points)
    {
        auto dot = Vector3DTools<Real>::DotProduct(m_Axis, point - m_Center);
        dotCollection.emplace_back(dot);
    }

    const auto boundary = std::minmax_element(dotCollection.begin(), dotCollection.end());

    // 计算高度。调整中心点到项目幅度中点
    m_Height = *boundary.second - *boundary.first;

    return *boundary.first + *boundary.second;
}

// private
template <typename Real>
void Mathematics::CylinderFit3<Real>::ComputeCenter(Real average)
{
    m_Center += Math::GetRational(1, 2) * average * m_Axis;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::CylinderFit3<Real>::IsValid() const noexcept
{
    try
    {
        if (Math::GetValue(0) <= m_Radius && Math::GetValue(0) <= m_Height && Math::GetValue(0) <= m_Exactly && Math::GetValue(0) <= m_Epsilon && m_Axis.IsNormalize(m_Epsilon))
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
Real Mathematics::CylinderFit3<Real>::GetExactly() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Exactly;
}

template <typename Real>
typename const Mathematics::CylinderFit3<Real>::Vector3D Mathematics::CylinderFit3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
typename const Mathematics::CylinderFit3<Real>::Vector3D Mathematics::CylinderFit3<Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Axis;
}

template <typename Real>
Real Mathematics::CylinderFit3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Radius;
}

template <typename Real>
Real Mathematics::CylinderFit3<Real>::GetHeight() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Height;
}

#endif  // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_ACHIEVE_H
