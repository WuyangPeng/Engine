///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 14:44)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_ACHIEVE_H

#include "PolynomialFit2Powers.h"
#include "Detail/PolynomialFit2PowersImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::PolynomialFit2Powers<Real>::PolynomialFit2Powers(const Samples& xSamples, const Samples& wSamples, const Powers& powers)
    : m_Impl{ std::make_shared<ImplType>(xSamples, wSamples, powers) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialFit2Powers<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialFit2Powers<Real>::IsSolveSucceed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsSolveSucceed();
}

template <typename Real>
Real Mathematics::PolynomialFit2Powers<Real>::GetXMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetXMin();
}

template <typename Real>
Real Mathematics::PolynomialFit2Powers<Real>::GetXMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetXMax();
}

template <typename Real>
Real Mathematics::PolynomialFit2Powers<Real>::GetWMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetWMin();
}

template <typename Real>
Real Mathematics::PolynomialFit2Powers<Real>::GetWMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetWMax();
}

template <typename Real>
Real Mathematics::PolynomialFit2Powers<Real>::operator()(Real x) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (*m_Impl)(x);
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT2_POWERS_ACHIEVE_H
