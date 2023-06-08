///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:36)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_DETAIL_H

#include "PolynomialFit2.h"
#include "PolynomialSamplesPowerDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"

template <typename Real>
Mathematics::PolynomialFit2<Real>::PolynomialFit2(const Samples& xSamples, const Samples& wSamples, int degree)
    : coeff{ degree }, solveSucceed{ false }
{
    Calculate(xSamples, wSamples);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::PolynomialFit2<Real>::Calculate(const Samples& xSamples, const Samples& wSamples)
{
    MATHEMATICS_ASSERTION_2(xSamples.size() == wSamples.size(), "�������Ʒ��С��ͬ��\n");

    const auto degree = coeff.GetDegree();
    const auto quantity = degree + 1;
    const auto numSamples = wSamples.size();

    // x���ݡ�
    PolynomialSamplesPower<Real> power{ xSamples, degree };

    // Vandermonde�������������ϵ������ϵͳ��
    VariableMatrix<Real> matrix{ quantity, quantity };
    typename LinearSystem<Real>::RealContainer inputVector(quantity);

    for (auto degreeIndex = 0; degreeIndex <= degree; ++degreeIndex)
    {
        inputVector.at(degreeIndex) = Math::GetValue(0);
        for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
        {
            inputVector.at(degreeIndex) += wSamples.at(samplesIndex) * power(samplesIndex, degreeIndex);
        }

        for (auto innerIndex = 0; innerIndex <= degree; ++innerIndex)
        {
            matrix(degreeIndex, innerIndex) = Math::GetValue(0);
            for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
            {
                matrix(degreeIndex, innerIndex) += power(samplesIndex, degreeIndex + innerIndex);
            }
        }
    }

    try
    {
        // ������ʽϵ����

        const LinearSystem<Real> linearSystem{};

        const auto outputVector = linearSystem.Solve(matrix, inputVector);

        coeff = Polynomial{ outputVector };
        solveSucceed = true;
    }
    catch (const CoreTools::Error& error)
    {
        solveSucceed = false;

        LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools, SYSTEM_TEXT("�������ϵͳʧ��\n"), error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialFit2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::PolynomialFit2<Real>::Polynomial Mathematics::PolynomialFit2<Real>::GetCoeff() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return coeff;
}

template <typename Real>
bool Mathematics::PolynomialFit2<Real>::IsSolveSucceed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return solveSucceed;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_DETAIL_H
