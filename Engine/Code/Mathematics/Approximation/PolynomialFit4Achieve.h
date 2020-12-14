///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 13:57)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_ACHIEVE_H

#include "PolynomialFit4.h"
#include "Detail/PolynomialFit4ImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::PolynomialFit4<Real>::PolynomialFit4(const Samples& xSamples, const Samples& ySamples, const Samples& zSamples,
                                                  const Samples& wSamples, size_t xDegree, size_t yDegree, size_t zDegree)
    : m_Impl{ std::make_shared<ImplType>(xSamples, ySamples, zSamples, wSamples, xDegree, yDegree, zDegree) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialFit4<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::PolynomialFit4<Real>::Samples Mathematics::PolynomialFit4<Real>::GetCoeff() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetCoeff();
}

template <typename Real>
bool Mathematics::PolynomialFit4<Real>::IsSolveSucceed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsSolveSucceed();
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT4_ACHIEVE_H
