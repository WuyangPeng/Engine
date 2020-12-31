///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/04 15:20)

#ifndef MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_ACHIEVE_H

#include "PolynomialFit3Powers.h"
#include "Detail/PolynomialFit3PowersImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::PolynomialFit3Powers<Real>::PolynomialFit3Powers(const Samples& xSamples, const Samples& ySamples, const Samples& wSamples, const Powers& powers, bool isRepackage)
    : m_Impl{ std::make_shared<ImplType>(xSamples, ySamples, wSamples, powers, isRepackage) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialFit3Powers<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::PolynomialFit3Powers<Real>::IsSolveSucceed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsSolveSucceed();
}

template <typename Real>
Real Mathematics::PolynomialFit3Powers<Real>::GetXMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetXMin();
}

template <typename Real>
Real Mathematics::PolynomialFit3Powers<Real>::GetXMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetXMax();
}

template <typename Real>
Real Mathematics::PolynomialFit3Powers<Real>::GetYMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetYMin();
}

template <typename Real>
Real Mathematics::PolynomialFit3Powers<Real>::GetYMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetYMax();
}

template <typename Real>
Real Mathematics::PolynomialFit3Powers<Real>::GetWMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetWMin();
}

template <typename Real>
Real Mathematics::PolynomialFit3Powers<Real>::GetWMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetWMax();
}

template <typename Real>
Real Mathematics::PolynomialFit3Powers<Real>::operator()(Real x, Real y) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (*m_Impl)(x, y);
}

#endif  // MATHEMATICS_APPROXIMATION_POLYNOMIAL_FIT3_POWERS_ACHIEVE_H
