///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 13:38)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_ACHIEVE_H

#include "PolynomialFit3.h"
#include "Detail/PolynomialFit3ImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::PolynomialFit3<Real>::PolynomialFit3(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, size_t xDegree, size_t yDegree)
    : m_Impl{ std::make_shared<ImplType>(xSamples, ySamples, wSamples, xDegree, yDegree) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialFit3<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::PolynomialFit3<Real>::Samples Mathematics::PolynomialFit3<Real>::GetCoeff() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetCoeff();
}

template <typename Real>
bool Mathematics::PolynomialFit3<Real>::IsSolveSucceed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsSolveSucceed();
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_ACHIEVE_H
