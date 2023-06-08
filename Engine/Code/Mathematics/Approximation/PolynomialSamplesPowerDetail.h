///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 17:36)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_DETAIL_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_DETAIL_H

#include "PolynomialSamplesPower.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::PolynomialSamplesPower<Real>::PolynomialSamplesPower(const Samples& samples, int degree)
    : numDegree{ 2 * degree + 1 }, numSamples{ boost::numeric_cast<int>(samples.size()) }, power{ numSamples, numDegree }
{
    Calculate(samples);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::PolynomialSamplesPower<Real>::Calculate(const Samples& samples)
{
    for (auto samplesIndex = 0; samplesIndex < numSamples; ++samplesIndex)
    {
        power(samplesIndex, 0) = Math::GetValue(1);
        for (auto degreeIndex = 1; degreeIndex < numDegree; ++degreeIndex)
        {
            power(samplesIndex, degreeIndex) = samples.at(samplesIndex) * power(samplesIndex, degreeIndex - 1);
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialSamplesPower<Real>::IsValid() const noexcept
{
    if (0 < numDegree && 0 < numSamples)
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

    return power(samplesIndex, degreeIndex);
}

template <typename Real>
int Mathematics::PolynomialSamplesPower<Real>::GetNumSamples() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return numSamples;
}

template <typename Real>
int Mathematics::PolynomialSamplesPower<Real>::GetNumDegree() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return numDegree;
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_SAMPLES_POWER_DETAIL_H