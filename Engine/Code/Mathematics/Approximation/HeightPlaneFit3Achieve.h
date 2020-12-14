///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/03 15:35)

#ifndef MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_ACHIEVE_H

#include "HeightPlaneFit3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h"

template <typename Real>
Mathematics::HeightPlaneFit3<Real>::HeightPlaneFit3(const Points& points)
    : m_CoeffA{}, m_CoeffB{}, m_CoeffC{}, m_IsFit3Success{ false }
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

    return m_IsFit3Success;
}

template <typename Real>
Real Mathematics::HeightPlaneFit3<Real>::GetCoeffA() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_IsFit3Success)
    {
        return m_CoeffA;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ʧ�ܣ�"s));
    }
}

template <typename Real>
Real Mathematics::HeightPlaneFit3<Real>::GetCoeffB() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_IsFit3Success)
    {
        return m_CoeffB;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ʧ�ܣ�"s));
    }
}

template <typename Real>
Real Mathematics::HeightPlaneFit3<Real>::GetCoeffC() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_IsFit3Success)
    {
        return m_CoeffC;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ʧ�ܣ�"s));
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

    auto numPoints = static_cast<Real>(points.size());

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
        using Vector3 = typename LinearSystem<Real>::Vector3;
        using Matrix3 = typename LinearSystem<Real>::Matrix3;

        Matrix3 matrix{ Vector3{ sumXX, sumXY, sumX }, Vector3{ sumXY, sumYY, sumY }, Vector3{ sumX, sumY, numPoints } };

        const Vector3 input{ sumXZ, sumYZ, sumZ };

        auto output = LinearSystem<Real>{}.Solve3(matrix, input);

        m_CoeffA = output.at(0);
        m_CoeffB = output.at(1);
        m_CoeffC = output.at(2);

        m_IsFit3Success = true;
    }
    catch (CoreTools::Error&)
    {
        m_IsFit3Success = false;
    }
}

#endif  // MATHEMATICS_APPROXIMATION_HEIGHT_PLANE_FIT3_ACHIEVE_H
