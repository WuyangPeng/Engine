///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/27 11:47)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_ACHIEVE_H

#include "PolynomialRoots.h"
#include "Detail/PolynomialRootsImplDetail.h" 
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::PolynomialRoots<Real>::PolynomialRoots(Real epsilon)
    : m_Impl{ std::make_shared<ImplType>(epsilon) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::PolynomialRoots<Real>::PolynomialRoots(const PolynomialRoots& rhs)
    : m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::PolynomialRoots<Real>& Mathematics::PolynomialRoots<Real>::operator=(const PolynomialRoots& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    PolynomialRoots result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real>
void Mathematics::PolynomialRoots<Real>::Swap(PolynomialRoots& rhs) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    std::swap(m_Impl, rhs.m_Impl);
}

template <typename Real>
Mathematics::PolynomialRoots<Real>::PolynomialRoots(PolynomialRoots&& rhs) noexcept
    : m_Impl{ std::move(rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::PolynomialRoots<Real>& Mathematics::PolynomialRoots<Real>::operator=(PolynomialRoots&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    m_Impl = std::move(rhs.m_Impl);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialRoots<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::PolynomialRoots<Real>::SetMaxIterations(int maxIterations) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetMaxIterations(maxIterations);
}

template <typename Real>
int Mathematics::PolynomialRoots<Real>::GetCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetCount();
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::GetRoot(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetRoot(index);
}

template <typename Real>
typename const Mathematics::PolynomialRoots<Real>::ContainerConstIter Mathematics::PolynomialRoots<Real>::GetBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetBegin();
}

template <typename Real>
typename const Mathematics::PolynomialRoots<Real>::ContainerConstIter Mathematics::PolynomialRoots<Real>::GetEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetEnd();
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindAlgebraic(Real constant, Real once)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->FindAlgebraic(constant, once);
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::GetBound(Real constant, Real once)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->GetBound(constant, once);
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindAlgebraic(Real constant, Real once, Real secondary)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->FindAlgebraic(constant, once, secondary);
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::GetBound(Real constant, Real once, Real secondary)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->GetBound(constant, once, secondary);
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindAlgebraic(Real constant, Real once, Real secondary, Real thrice)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->FindAlgebraic(constant, once, secondary, thrice);
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindEigenvalues(Real constant, Real once, Real secondary, Real thrice, bool doBalancing, Real tolerance, bool isUseCompanion)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->FindEigenvalues(constant, once, secondary, thrice, doBalancing, tolerance, isUseCompanion);
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::GetBound(Real constant, Real once, Real secondary, Real thrice)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->GetBound(constant, once, secondary, thrice);
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::SpecialCubic(Real thrice, Real once, Real constant) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SpecialCubic(thrice, once, constant);
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindAlgebraic(Real constant, Real once, Real secondary, Real thrice, Real quartic)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->FindAlgebraic(constant, once, secondary, thrice, quartic);
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindEigenvalues(Real constant, Real once, Real secondary, Real thrice, Real quartic, bool doBalancing, Real tolerance)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->FindEigenvalues(constant, once, secondary, thrice, quartic, doBalancing, tolerance);
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::GetBound(Real constant, Real once, Real secondary, Real thrice, Real quartic)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->GetBound(constant, once, secondary, thrice, quartic);
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindBisection(const Polynomial& polynomial, int digits)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->FindBisection(polynomial, digits);
}

template <typename Real>
Real Mathematics::PolynomialRoots<Real>::GetBound(const Polynomial& polynomial)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->GetBound(polynomial);
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::FindBisection(const Polynomial& polynomial, Real xMin, Real xMax, int digits)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->FindBisection(polynomial, xMin, xMax, digits);
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::AllRealPartsNegative(const Polynomial& polynomial )
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->AllRealPartsNegative(polynomial );
}

template <typename Real>
bool Mathematics::PolynomialRoots<Real>::AllRealPartsPositive(const Polynomial& polynomial )
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->AllRealPartsNegative(polynomial );
}

template <typename Real>
int Mathematics::PolynomialRoots<Real>::GetRootCount(const Polynomial& polynomial, Real begin, Real end)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->GetRootCount(polynomial, begin, end);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_ACHIEVE_H
