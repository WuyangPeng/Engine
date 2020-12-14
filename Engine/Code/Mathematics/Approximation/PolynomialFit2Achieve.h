///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/03 17:37)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_ACHIEVE_H

#include "PolynomialFit2.h"
#include "PolynomialSamplesPowerDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystemDetail.h"

template <typename Real>
Mathematics::PolynomialFit2<Real>::PolynomialFit2(const Samples& xSamples, const Samples& wSamples, int degree)
    : m_Coeff{ degree }, m_SolveSucceed{ false }
{
    Calculate(xSamples, wSamples);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::PolynomialFit2<Real>::Calculate(const Samples& xSamples, const Samples& wSamples)
{
    MATHEMATICS_ASSERTION_2(xSamples.size() == wSamples.size(), "�������Ʒ��С��ͬ��\n");

    const auto degree = m_Coeff.GetDegree();
    const auto quantity = degree + 1;
    const auto numSamples = wSamples.size();

    // x���ݡ�
    PolynomialSamplesPower<Real> power{ xSamples, degree };

    // Vandermonde�������������ϵ������ϵͳ��
    VariableMatrix<Real> matrix{ quantity, quantity };
    typename LinearSystem<Real>::RealContainer inputVector(quantity);

    for (auto degreeIndex = 0; degreeIndex <= degree; ++degreeIndex)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        inputVector[degreeIndex] = Math::GetValue(0);
        for (auto samplesIndex = 0u; samplesIndex < numSamples; ++samplesIndex)
        {
            inputVector[degreeIndex] += wSamples[samplesIndex] * power(samplesIndex, degreeIndex);
        }

#include STSTEM_WARNING_POP

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

        auto outputVector = linearSystem.Solve(matrix, inputVector);

        m_Coeff = Polynomial{ outputVector };
        m_SolveSucceed = true;
    }
    catch (const CoreTools::Error& error)
    {
        m_SolveSucceed = false;

        LOG_SINGLETON_ENGINE_APPENDER(Info, CoreTools)
            << SYSTEM_TEXT("�������ϵͳʧ��\n")
            << error
            << LOG_SINGLETON_TRIGGER_ASSERT;
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
typename const Mathematics::PolynomialFit2<Real>::Polynomial Mathematics::PolynomialFit2<Real>::GetCoeff() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Coeff;
}

template <typename Real>
bool Mathematics::PolynomialFit2<Real>::IsSolveSucceed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_SolveSucceed;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_ACHIEVE_H
