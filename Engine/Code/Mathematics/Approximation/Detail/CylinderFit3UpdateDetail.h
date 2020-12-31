///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/02 16:17)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DETAIL_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DETAIL_H

#include "CylinderFit3Update.h"
#include "CylinderFit3UpdateDataDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/PolynomialDetail.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/PolynomialRootsDetail.h"
#include "Mathematics/Objects2D/Line2Detail.h"

#include <algorithm>

template <typename Real>
Mathematics::CylinderFit3Update<Real>::CylinderFit3Update(const Points& points, const Vector3D& guessCenter, const Vector3D& guessAxis, const Real epsilon)
    : m_Points{ points },
      m_InverseRadiusSqrare{ Math::GetValue(1) },
      m_Axis{ guessAxis },
      m_Center{ guessCenter },
      m_Exactly{ Math::sm_MaxReal },
      m_Epsilon{ epsilon },
      m_UpdateData{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::CylinderFit3Update<Real>::Update(int maxLoopTime)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_2(0 < maxLoopTime, "循环次数为负数\n");

    for (auto i = 0; i < maxLoopTime; ++i)
    {
        // 先存储每一个循环需要的值，避免重复计算
        CalculateUpdateData();

        UpdateInverseRadiusSqrare();
        UpdateDirection();
        UpdateCenter();
    }
}

template <typename Real>
void Mathematics::CylinderFit3Update<Real>::CalculateUpdateData()
{
    m_UpdateData.clear();

    for (const auto& point : m_Points)
    {
        m_UpdateData.emplace_back(point, m_Center, m_Axis);
    }
}

// private
template <typename Real>
void Mathematics::CylinderFit3Update<Real>::UpdateInverseRadiusSqrare() noexcept(g_Assert < 2 || g_MathematicsAssert < 2)
{
    auto deltaCrossAxisLengthSquaredSum = Math::GetValue(0);
    auto deltaCrossAxisLengthQuarticSum = Math::GetValue(0);

    for (const auto& data : m_UpdateData)
    {
        auto deltaCrossAxisLengthQuartic = data.GetDeltaCrossAxisLengthQuartic();
        deltaCrossAxisLengthSquaredSum += deltaCrossAxisLengthQuartic;
        deltaCrossAxisLengthQuarticSum += deltaCrossAxisLengthQuartic * deltaCrossAxisLengthQuartic;
    }

    m_InverseRadiusSqrare = deltaCrossAxisLengthSquaredSum / deltaCrossAxisLengthQuarticSum;
    m_Exactly = Math::GetValue(1) - m_InverseRadiusSqrare * deltaCrossAxisLengthSquaredSum / static_cast<Real>(m_UpdateData.size());

    MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= m_Exactly && m_Exactly <= Math::GetValue(1), "误差值错误！");
}

// private
template <typename Real>
void Mathematics::CylinderFit3Update<Real>::UpdateDirection()
{
    // 计算的最快下降的方向。
    Vector3D descentDirection{};
    auto aMean = Math::GetValue(0);
    auto aaMean = Math::GetValue(0);

    for (const auto& data : m_UpdateData)
    {
        const auto delta = data.GetDelta();
        auto a = m_InverseRadiusSqrare * data.GetDeltaCrossAxisLengthQuartic() - Math::GetValue(1);
        aMean += a;
        aaMean += a * a;
        descentDirection += a * data.GetDescentDirection();
    }

    auto inverseNumPoints = Math::GetValue(1) / static_cast<Real>(m_Points.size());

    aMean *= inverseNumPoints;
    aaMean *= inverseNumPoints;
    if (descentDirection.IsZero(m_Epsilon))
    {
        m_Exactly = aaMean;
        MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= m_Exactly && m_Exactly <= Math::GetValue(1), "误差值错误！");

        return;
    }

    // 计算用于最快下降的线的四次多项式。
    auto abMean = Math::GetValue(0);
    auto acMean = Math::GetValue(0);
    auto bbMean = Math::GetValue(0);
    auto bcMean = Math::GetValue(0);
    auto ccMean = Math::GetValue(0);
    for (const auto& data : m_UpdateData)
    {
        const auto delta = data.GetDelta();
        const auto deltaCrossAxis = data.GetDeltaCrossAxis();
        const auto deltaCrossDescentDirection = Vector3DTools<Real>::CrossProduct(delta, descentDirection);
        auto a = m_InverseRadiusSqrare * data.GetDeltaCrossAxisLengthQuartic() - Math::GetValue(1);
        auto b = m_InverseRadiusSqrare * Vector3DTools<Real>::DotProduct(deltaCrossAxis, deltaCrossDescentDirection);
        auto c = m_InverseRadiusSqrare * Vector3DTools<Real>::VectorMagnitudeSquared(deltaCrossDescentDirection);
        abMean += a * b;
        acMean += a * c;
        bbMean += b * b;
        bcMean += b * c;
        ccMean += c * c;
    }

    abMean *= inverseNumPoints;
    acMean *= inverseNumPoints;
    bbMean *= inverseNumPoints;
    bcMean *= inverseNumPoints;
    ccMean *= inverseNumPoints;

    std::vector<Real> tuple{ aaMean,
                             Math::GetValue(-4) * abMean,
                             (Math::GetValue(2) * acMean + Math::GetValue(4) * bbMean),
                             Math::GetValue(-4) * bcMean,
                             ccMean };

    Polynomial<Real> polynomial{ tuple };

    auto derivativePolynomial = polynomial.GetDerivative();

    PolynomialRoots<Real> polynomialRoots{ m_Epsilon };
    if (!polynomialRoots.FindAlgebraic(derivativePolynomial[0], derivativePolynomial[1], derivativePolynomial[2], derivativePolynomial[3]))
    {
        return;
    }

    const auto count = polynomialRoots.GetCount();

    auto min = polynomial(Math::GetValue(0));
    auto minIndex = -1;
    for (auto i = 0; i < count; ++i)
    {
        auto value = polynomial(polynomialRoots.GetRoot(i));
        if (value < min)
        {
            min = value;
            minIndex = i;
        }
    }

    m_Exactly = min;
    MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= m_Exactly && m_Exactly <= Math::GetValue(1), "误差值错误！");

    if (0 <= minIndex)
    {
        m_Axis -= polynomialRoots.GetRoot(minIndex) * descentDirection;
        auto length = Vector3DTools<Real>::VectorMagnitude(m_Axis);
        m_Axis.Normalize();
        m_InverseRadiusSqrare *= length * length;
    }
}

// private
template <typename Real>
void Mathematics::CylinderFit3Update<Real>::UpdateCenter()
{
    auto inverseNumPoints = Math::GetValue(1) / static_cast<Real>(m_UpdateData.size());

    // 计算的最快下降的方向。
    Vector3D descentDirection{};
    auto aMean = Math::GetValue(0);
    auto aaMean = Math::GetValue(0);

    for (const auto& data : m_UpdateData)
    {
        auto delta = data.GetPoint() - m_Center;
        const auto deltaCrossAxis = Vector3DTools<Real>::CrossProduct(delta, m_Axis);
        auto a = m_InverseRadiusSqrare * Vector3DTools<Real>::VectorMagnitude(deltaCrossAxis) - Math::GetValue(1);

        aMean += a;
        aaMean += a * a;

        // 确保|m_Axis| = 1
        descentDirection += (delta - m_Axis * Vector3DTools<Real>::DotProduct(m_Axis, delta)) * a;
    }

    aMean *= inverseNumPoints;
    aaMean *= inverseNumPoints;

    if (descentDirection.IsZero(m_Epsilon))
    {
        m_Exactly = aaMean;
        MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= m_Exactly && m_Exactly <= Math::GetValue(1), "误差值错误！");

        return;
    }

    // 计算用于最快下降的线的四次多项式。
    const auto descentDirectionCrossAxis = Vector3DTools<Real>::CrossProduct(descentDirection, m_Axis);
    auto c = Vector3DTools<Real>::VectorMagnitude(descentDirectionCrossAxis) * inverseNumPoints * m_InverseRadiusSqrare;
    auto bMean = Math::GetValue(0);
    auto abMean = Math::GetValue(0);
    auto bbMean = Math::GetValue(0);

    for (const auto& data : m_UpdateData)
    {
        const auto deltaCrossAxis = data.GetDeltaCrossAxis();
        auto a = m_InverseRadiusSqrare * data.GetDeltaCrossAxisLengthQuartic() - Math::GetValue(1);
        auto b = m_InverseRadiusSqrare * (Vector3DTools<Real>::DotProduct(deltaCrossAxis, descentDirectionCrossAxis));
        bMean += b;
        abMean += a * b;
        bbMean += b * b;
    }
    bMean *= inverseNumPoints;
    abMean *= inverseNumPoints;
    bbMean *= inverseNumPoints;

    std::vector<Real> tuple{ aaMean,
                             Math::GetValue(4) * abMean,
                             Math::GetValue(2) * c * aMean + Math::GetValue(4) * bbMean,
                             Math::GetValue(4) * c * bMean,
                             c * c };

    Polynomial<Real> polynomial{ tuple };

    auto derivativePolynomial = polynomial.GetDerivative();

    PolynomialRoots<Real> polynomialRoots{ m_Epsilon };
    if (!polynomialRoots.FindAlgebraic(derivativePolynomial[0], derivativePolynomial[1], derivativePolynomial[2], derivativePolynomial[3]))
    {
        return;
    }
    const auto count = polynomialRoots.GetCount();

    auto min = polynomial(Math::GetValue(0));
    auto minIndex = -1;
    for (auto i = 0; i < count; ++i)
    {
        auto value = polynomial(polynomialRoots.GetRoot(i));
        if (value < min)
        {
            min = value;
            minIndex = i;
        }
    }

    m_Exactly = min;
    MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= m_Exactly && m_Exactly <= Math::GetValue(1), "误差值错误！");

    if (0 <= minIndex)
    {
        m_Center -= polynomialRoots.GetRoot(minIndex) * descentDirection;
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::CylinderFit3Update<Real>::IsValid() const noexcept
{
    try
    {
        if (Math::GetValue(0) <= m_InverseRadiusSqrare && Math::GetValue(0) <= m_Exactly && Math::GetValue(0) <= m_Epsilon && m_Axis.IsNormalize(m_Epsilon))
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
Real Mathematics::CylinderFit3Update<Real>::GetExactly() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Exactly;
}

template <typename Real>
typename const Mathematics::CylinderFit3Update<Real>::Vector3D Mathematics::CylinderFit3Update<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
typename const Mathematics::CylinderFit3Update<Real>::Vector3D Mathematics::CylinderFit3Update<Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Axis;
}

template <typename Real>
Real Mathematics::CylinderFit3Update<Real>::GetInverseRadiusSqrare() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_InverseRadiusSqrare;
}

#endif  // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DETAIL_H
