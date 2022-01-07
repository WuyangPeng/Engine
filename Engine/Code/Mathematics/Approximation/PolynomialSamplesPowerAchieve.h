///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 10:05)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_ACHIEVE_H

#include "PolynomialSamplesPower.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h" 

template <typename Real>
Mathematics::PolynomialSamplesPower<Real>::PolynomialSamplesPower(const Samples& samples, int degree)
    : m_NumDegree{ 2 * degree + 1 }, m_NumSamples{ boost::numeric_cast<int>(samples.size()) }, m_Power{ m_NumDegree, m_NumSamples }
{
    Calculate(samples);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::PolynomialSamplesPower<Real>::Calculate(const Samples& samples)
{
    for (auto samplesIndex = 0; samplesIndex < m_NumSamples; ++samplesIndex)
    {
        m_Power(samplesIndex, 0) = Math::GetValue(1);
        for (auto degreeIndex = 1; degreeIndex < m_NumDegree; ++degreeIndex)
        {
            m_Power(samplesIndex, degreeIndex) = samples.at(samplesIndex) * m_Power(samplesIndex, degreeIndex - 1);
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialSamplesPower<Real>::IsValid() const noexcept
{
    if (0 < m_NumDegree && 0 < m_NumSamples)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::PolynomialSamplesPower<Real>::operator()(int samplesIndex, int degreeIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= samplesIndex && samplesIndex < GetNumSamples(), "索引越界！\n");
    MATHEMATICS_ASSERTION_0(0 <= degreeIndex && degreeIndex < GetNumDegree(), "索引越界！\n");

    return m_Power(samplesIndex, degreeIndex);
}

template <typename Real>
int Mathematics::PolynomialSamplesPower<Real>::GetNumSamples() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_NumSamples;
}

template <typename Real>
int Mathematics::PolynomialSamplesPower<Real>::GetNumDegree() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_NumDegree;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_ACHIEVE_H