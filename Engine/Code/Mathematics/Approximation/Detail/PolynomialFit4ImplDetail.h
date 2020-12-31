///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 13:49)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_IMPL_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_IMPL_DETAIL_H

#include "PolynomialFit4Impl.h"
#include "PolynomialSamplesPowerDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"

template <typename Real>
Mathematics::PolynomialFit4Impl<Real>::PolynomialFit4Impl(const Samples& xSamples, const Samples& ySamples, const Samples& zSamples,
                                                          const Samples& wSamples, size_t xDegree, size_t yDegree, size_t zDegree)
    : m_Coeff((xDegree + 1) * (yDegree + 1) * (zDegree + 1)), m_SolveSucceed{ false }
{
    Calculate(xSamples, ySamples, zSamples, wSamples, boost::numeric_cast<int>(xDegree), boost::numeric_cast<int>(yDegree), boost::numeric_cast<int>(zDegree));

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::PolynomialFit4Impl<Real>::Calculate(const Samples& xSamples, const Samples& ySamples, const Samples& zSamples,
                                                      const Samples& wSamples, int xDegree, int yDegree, int zDegree)
{
    const auto xBound = xDegree + 1;
    const auto yBound = yDegree + 1;
    const auto zBound = zDegree + 1;
    const auto quantity = xBound * yBound * zBound;

    // x、y、z的幂。
    PolynomialSamplesPower<Real> xPower{ xSamples, xDegree };
    PolynomialSamplesPower<Real> yPower{ ySamples, yDegree };
    PolynomialSamplesPower<Real> zPower{ zSamples, zDegree };

    // Vandermonde矩阵和右手坐标系的线性系统。
    VariableMatrix<Real> matrix{ quantity, quantity };
    Samples inputVector(quantity);

    const auto numSamples = wSamples.size();

    for (auto zDegreeIndex = 0; zDegreeIndex <= zDegree; ++zDegreeIndex)
    {
        for (auto yDegreeIndex = 0; yDegreeIndex <= yDegree; ++yDegreeIndex)
        {
            for (auto xDegreeIndex = 0; xDegreeIndex <= xDegree; ++xDegreeIndex)
            {
                const auto index = xDegreeIndex + xBound * (yDegreeIndex + yBound * zDegreeIndex);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

                inputVector[index] = Math::GetValue(0);
                for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
                {
                    inputVector[index] += wSamples[samplesIndex] * xPower(samplesIndex, xDegreeIndex) * yPower(samplesIndex, yDegreeIndex) * zPower(samplesIndex, zDegreeIndex);
                }

#include STSTEM_WARNING_POP

                for (auto innerZDegreeIndex = 0; innerZDegreeIndex <= zDegree; ++innerZDegreeIndex)
                {
                    for (auto innerYDegreeIndex = 0; innerYDegreeIndex <= yDegree; ++innerYDegreeIndex)
                    {
                        for (auto innerXDegreeIndex = 0; innerXDegreeIndex <= xDegree; ++innerXDegreeIndex)
                        {
                            const auto innerIndex = innerXDegreeIndex + xBound * (innerYDegreeIndex + yBound * innerZDegreeIndex);
                            auto sum = Math::GetValue(0);
                            for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
                            {
                                sum += xPower(samplesIndex, xDegreeIndex + innerXDegreeIndex) *
                                       yPower(samplesIndex, yDegreeIndex + innerYDegreeIndex) *
                                       zPower(samplesIndex, zDegreeIndex + innerZDegreeIndex);
                            }

                            matrix(index, innerIndex) = sum;
                        }
                    }
                }
            }
        }
    }

    try
    {
        // 求解多项式系数。
        const LinearSystem<Real> linearSystem{};

        m_Coeff = linearSystem.Solve(matrix, inputVector);

        m_SolveSucceed = true;
    }
    catch (const CoreTools::Error& error)
    {
        m_SolveSucceed = false;

        LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools)
            << SYSTEM_TEXT("求解线性系统失败\n")
            << error
            << CoreTools::LogAppenderIOManageSign::Refresh;
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialFit4Impl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::PolynomialFit4Impl<Real>::Samples Mathematics::PolynomialFit4Impl<Real>::GetCoeff() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Coeff;
}

template <typename Real>
bool Mathematics::PolynomialFit4Impl<Real>::IsSolveSucceed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_SolveSucceed;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_IMPL_DETAIL_H
