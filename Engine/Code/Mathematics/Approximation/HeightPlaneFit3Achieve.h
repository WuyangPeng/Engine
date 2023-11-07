///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:13)

#ifndef MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_ACHIEVE_H

#include "HeightPlaneFit3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h"

template <typename Real>
Mathematics::HeightPlaneFit3<Real>::HeightPlaneFit3(const Points& points)
    : coeffA{}, coeffB{}, coeffC{}, isFit3Success{ false }
{
    Calculate(points);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::HeightPlaneFit3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::HeightPlaneFit3<Real>::IsFit3Success() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return isFit3Success;
}

template <typename Real>
Real Mathematics::HeightPlaneFit3<Real>::GetCoeffA() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (isFit3Success)
    {
        return coeffA;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ʧ�ܣ�"s))
    }
}

template <typename Real>
Real Mathematics::HeightPlaneFit3<Real>::GetCoeffB() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (isFit3Success)
    {
        return coeffB;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ʧ�ܣ�"s))
    }
}

template <typename Real>
Real Mathematics::HeightPlaneFit3<Real>::GetCoeffC() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (isFit3Success)
    {
        return coeffC;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ʧ�ܣ�"s))
    }
}

template <typename Real>
void Mathematics::HeightPlaneFit3<Real>::Calculate(const Points& points)
{
    // ��������Ҫ��������ȷ����ƽ�档
    // ��ʹ���������������һ����ֱƽ�棬û����С���η���ϵġ��߶ȡ��ĸо���
    // �⽫������ϵ�����������ʽ��

    // ��������ϵͳ���ܺ͡�

    auto sumX = Math::GetValue(0);
    auto sumY = Math::GetValue(0);
    auto sumZ = Math::GetValue(0);
    auto sumXX = Math::GetValue(0);
    auto sumXY = Math::GetValue(0);
    auto sumXZ = Math::GetValue(0);
    auto sumYY = Math::GetValue(0);
    auto sumYZ = Math::GetValue(0);

    const auto numPoints = static_cast<Real>(points.size());

    for (const auto& point : points)
    {
        sumX += point.GetX();
        sumY += point.GetY();
        sumZ += point.GetZ();
        sumXX += point.GetX() * point.GetX();
        sumXY += point.GetX() * point.GetY();
        sumXZ += point.GetX() * point.GetZ();
        sumYY += point.GetY() * point.GetY();
        sumYZ += point.GetY() * point.GetZ();
    }

    try
    {
        using Vector = typename LinearSystem<Real>::Vector3;
        using Matrix3 = typename LinearSystem<Real>::Matrix3;

        const Matrix3 matrix{ Vector{ sumXX, sumXY, sumX }, Vector{ sumXY, sumYY, sumY }, Vector{ sumX, sumY, numPoints } };

        const Vector input{ sumXZ, sumYZ, sumZ };

        const auto output = LinearSystem<Real>{}.Solve3(matrix, input);

        coeffA = output.at(0);
        coeffB = output.at(1);
        coeffC = output.at(2);

        isFit3Success = true;
    }
    catch (CoreTools::Error&)
    {
        isFit3Success = false;
    }
}

#endif  // MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_ACHIEVE_H
