///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:08)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_ACHIEVE_H

#include "CylinderFit3.h"
#include "OrthogonalLineFit3Detail.h"
#include "Detail/CylinderFit3UpdateDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Objects2D/Line2Detail.h"

#include <algorithm>

template <typename Real>
Mathematics::CylinderFit3<Real>::CylinderFit3(const Points& points, const Real epsilon)
    : center{}, axis{}, radius{}, height{}, exactly{ MathType::maxReal }, inputsAreInitialGuess{ false }, epsilon{ epsilon }
{
    Fit3(points);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::CylinderFit3<Real>::CylinderFit3(const Points& points, const Vector3Type& guessCenter, const Vector3Type& guessAxis, const Real epsilon)
    : center{ guessCenter }, axis{ guessAxis }, radius{}, height{}, exactly{ MathType::maxReal }, inputsAreInitialGuess{ true }, epsilon{ epsilon }
{
    Fit3(points);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::CylinderFit3<Real>::Fit3(const Points& points)
{
    InitialGuess(points);
    Update(points);
    auto average = ComputeHeight(points);
    ComputeCenter(average);
}

template <typename Real>
void Mathematics::CylinderFit3<Real>::InitialGuess(const Points& points)
{
    if (!inputsAreInitialGuess)
    {
        // 找到适合该数据的最小二乘线，并用它作为圆柱体轴的初始猜测。
        const OrthogonalLineFit3<Real> orthogonalLineFit3{ points };

        const auto line = orthogonalLineFit3.GetLine3();
        center = line.GetOrigin();
        axis = line.GetDirection();
    }
}

template <typename Real>
void Mathematics::CylinderFit3<Real>::Update(const Points& points)
{
    constexpr auto maxLoopTime = 8;

    CylinderFit3Update<Real> update{ points, center, axis, epsilon };
    update.Update(maxLoopTime);

    radius = MathType::InvSqrt(update.GetInverseRadiusSquare());
    center = update.GetCenter();
    axis = update.GetAxis();

    exactly = update.GetExactly();
}

template <typename Real>
Real Mathematics::CylinderFit3<Real>::ComputeHeight(const Points& points)
{
    // 项目点拟合到轴确定圆柱体沿轴的幅度。
    std::vector<Real> dotCollection{};
    for (const auto& point : points)
    {
        auto dot = Vector3Tools<Real>::DotProduct(axis, point - center);
        dotCollection.emplace_back(dot);
    }

    const auto boundary = std::minmax_element(dotCollection.begin(), dotCollection.end());

    // 计算高度。调整中心点到项目幅度中点
    height = *boundary.second - *boundary.first;

    return *boundary.first + *boundary.second;
}

template <typename Real>
void Mathematics::CylinderFit3<Real>::ComputeCenter(Real average)
{
    center += MathType::GetRational(1, 2) * average * axis;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::CylinderFit3<Real>::IsValid() const noexcept
{
    try
    {
        if (MathType::GetValue(0) <= radius && MathType::GetValue(0) <= height && MathType::GetValue(0) <= exactly && MathType::GetValue(0) <= epsilon && axis.IsNormalize(epsilon))
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

    return exactly;
}

template <typename Real>
typename Mathematics::CylinderFit3<Real>::Vector3Type Mathematics::CylinderFit3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
typename Mathematics::CylinderFit3<Real>::Vector3Type Mathematics::CylinderFit3<Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return axis;
}

template <typename Real>
Real Mathematics::CylinderFit3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return radius;
}

template <typename Real>
Real Mathematics::CylinderFit3<Real>::GetHeight() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return height;
}

#endif  // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_ACHIEVE_H
