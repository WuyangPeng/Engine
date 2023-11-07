///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:16)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_DETAIL_H

#include "PolynomialFit3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Approximation/PolynomialSamplesPowerDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"

template <typename Real>
Mathematics::PolynomialFit3<Real>::PolynomialFit3(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, size_t xDegree, size_t yDegree)
    : coeff((xDegree + 1) * (yDegree + 1)), solveSucceed{ false }
{
    Calculate(xSamples, ySamples, wSamples, boost::numeric_cast<int>(xDegree), boost::numeric_cast<int>(yDegree));

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::PolynomialFit3<Real>::Calculate(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, int xDegree, int yDegree)
{
    MATHEMATICS_ASSERTION_2(xSamples.size() == ySamples.size(), "传入的样品大小不同！\n");
    MATHEMATICS_ASSERTION_2(xSamples.size() == wSamples.size(), "传入的样品大小不同！\n");

    const auto xBound = xDegree + 1;
    const auto yBound = yDegree + 1;
    const auto quantity = xBound * yBound;

    // x、y的幂。
    PolynomialSamplesPower<Real> xPower{ xSamples, xDegree };
    PolynomialSamplesPower<Real> yPower{ ySamples, yDegree };

    // Vandermonde矩阵和右手坐标系的线性系统。
    VariableMatrix<Real> matrix{ quantity, quantity };
    Samples inputVector(quantity);

    const auto numSamples = wSamples.size();

    for (auto yDegreeIndex = 0; yDegreeIndex <= yDegree; ++yDegreeIndex)
    {
        for (auto xDegreeIndex = 0; xDegreeIndex <= xDegree; ++xDegreeIndex)
        {
            const auto index = xDegreeIndex + xBound * yDegreeIndex;

            inputVector.at(index) = Math::GetValue(0);
            for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
            {
                inputVector.at(index) += wSamples.at(samplesIndex) * xPower(samplesIndex, xDegreeIndex) * yPower(samplesIndex, yDegreeIndex);
            }

            for (auto innerYDegreeIndex = 0; innerYDegreeIndex <= yDegree; ++innerYDegreeIndex)
            {
                for (auto innerXDegreeIndex = 0; innerXDegreeIndex <= xDegree; ++innerXDegreeIndex)
                {
                    const auto innerIndex = innerXDegreeIndex + xBound * innerYDegreeIndex;
                    matrix(index, innerIndex) = Math::GetValue(0);
                    for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
                    {
                        matrix(index, innerIndex) += xPower(samplesIndex, xDegreeIndex + innerXDegreeIndex) * yPower(samplesIndex, yDegreeIndex + innerYDegreeIndex);
                    }
                }
            }
        }
    }

    try
    {
        // 求解多项式系数。
        const LinearSystem<Real> linearSystem{};

        coeff = linearSystem.Solve(matrix, inputVector);

        solveSucceed = true;
    }
    catch (const CoreTools::Error& error)
    {
        solveSucceed = false;

        LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools, SYSTEM_TEXT("求解线性系统失败\n"), error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialFit3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::PolynomialFit3<Real>::Samples Mathematics::PolynomialFit3<Real>::GetCoeff() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return coeff;
}

template <typename Real>
bool Mathematics::PolynomialFit3<Real>::IsSolveSucceed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return solveSucceed;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_DETAIL_H
