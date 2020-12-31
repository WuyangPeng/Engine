///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/27 16:13)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_ACHIEVE_H

#include "PolynomialRootsRational.h"
#include "Detail/PolynomialRootsRationalImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <memory>

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
template <typename Real>
Mathematics::PolynomialRootsRational<Real>::PolynomialRootsRational(Real epsilon)
    : m_Impl{ std::make_shared<ImplType>(epsilon) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

template <typename Real>
Mathematics::PolynomialRootsRational<Real>::PolynomialRootsRational(const PolynomialRootsRational& rhs)
    : m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::PolynomialRootsRational<Real>& Mathematics::PolynomialRootsRational<Real>::operator=(const PolynomialRootsRational& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    PolynomialRootsRational result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real>
void Mathematics::PolynomialRootsRational<Real>::Swap(PolynomialRootsRational& rhs) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    std::swap(m_Impl, rhs.m_Impl);
}

template <typename Real>
Mathematics::PolynomialRootsRational<Real>::PolynomialRootsRational(PolynomialRootsRational&& rhs) noexcept
    : m_Impl{ std::move(rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::PolynomialRootsRational<Real>& Mathematics::PolynomialRootsRational<Real>::operator=(PolynomialRootsRational&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    m_Impl = std::move(rhs.m_Impl);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::PolynomialRootsRational<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetQuantity();
}

template <typename Real>
Real Mathematics::PolynomialRootsRational<Real>::GetRoot(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetRoot(index);
}

template <typename Real>
int Mathematics::PolynomialRootsRational<Real>::GetMultiplicity(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMultiplicity(index);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Linear(Real constant, Real once)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Linear(constant, once);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Linear(const PolynomialRational& constant, const PolynomialRational& once)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Linear(constant, once);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Quadratic(Real constant, Real once, Real secondary)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Quadratic(constant, once, secondary);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Quadratic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Quadratic(constant, once, secondary);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Quadratic(const PolynomialRational& constant, const PolynomialRational& once)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Quadratic(constant, once);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Cubic(Real constant, Real once, Real secondary, Real thrice)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Cubic(constant, once, secondary, thrice);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Cubic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary, const PolynomialRational& thrice)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Cubic(constant, once, secondary, thrice);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Cubic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Cubic(constant, once, secondary);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Quartic(Real constant, Real once, Real secondary, Real thrice, Real quartic)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Quartic(constant, once, secondary, thrice, quartic);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Quartic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary, const PolynomialRational& thrice, const PolynomialRational& quartic)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Quartic(constant, once, secondary, thrice, quartic);
}

template <typename Real>
bool Mathematics::PolynomialRootsRational<Real>::Quartic(const PolynomialRational& constant, const PolynomialRational& once, const PolynomialRational& secondary, const PolynomialRational& thrice)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Quartic(constant, once, secondary, thrice);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_RATIONAL_ACHIEVE_H