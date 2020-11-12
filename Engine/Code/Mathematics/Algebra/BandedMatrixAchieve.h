///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 14:31)

#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_ACHIEVE_H

#include "BandedMatrix.h"
#include "VariableMatrix.h"
#include "Detail/BandedMatrixImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::BandedMatrix<Real>::BandedMatrix(int size, int lowerBandsNumber, int upperBandsNumber)
    : m_Impl{ std::make_shared<ImplType>(size, lowerBandsNumber, upperBandsNumber) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::BandedMatrix<Real>::BandedMatrix(const BandedMatrix& rhs)
    : m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::BandedMatrix<Real>& Mathematics::BandedMatrix<Real>::operator=(const BandedMatrix& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    BandedMatrix temp{ rhs };

    Swap(temp);

    return *this;
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::Swap(BandedMatrix& rhs) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    std::swap(m_Impl, rhs.m_Impl);
}

template <typename Real>
Mathematics::BandedMatrix<Real>::BandedMatrix(BandedMatrix&& rhs) noexcept
    : m_Impl{ std::move(rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::BandedMatrix<Real>& Mathematics::BandedMatrix<Real>::operator=(BandedMatrix&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    m_Impl = std::move(rhs.m_Impl);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::BandedMatrix<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::BandedMatrix<Real>::GetSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetSize();
}

template <typename Real>
int Mathematics::BandedMatrix<Real>::GetLowerBandsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetLowerBandsNumber();
}

template <typename Real>
int Mathematics::BandedMatrix<Real>::GetUpperBandsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetUpperBandsNumber();
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::ResetSize(int size, int lowerBandsNumber, int upperBandsNumber)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->ResetSize(size, lowerBandsNumber, upperBandsNumber);
}

template <typename Real>
int Mathematics::BandedMatrix<Real>::GetStreamSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetStreamSize();
}

template <typename Real>
typename Mathematics::BandedMatrix<Real>::ContainerType Mathematics::BandedMatrix<Real>::GetDiagonalBand() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetDiagonalBand();
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::SetDiagonalBand(const ContainerType& diagonalBand)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetDiagonalBand(diagonalBand);
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::SetLowerBand(int index, const ContainerType& lowerBand)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetLowerBand(index, lowerBand);
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::SetLowerBandZero()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetLowerBandZero();
}

template <typename Real>
int Mathematics::BandedMatrix<Real>::GetLowerBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetLowerBandMax(index);
}

template <typename Real>
typename Mathematics::BandedMatrix<Real>::ContainerType Mathematics::BandedMatrix<Real>::GetLowerBand(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetLowerBand(index);
}

template <typename Real>
int Mathematics::BandedMatrix<Real>::GetUpperBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetUpperBandMax(index);
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::SetUpperBand(int index, const ContainerType& upperBand)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetUpperBand(index, upperBand);
}

template <typename Real>
typename Mathematics::BandedMatrix<Real>::ContainerType Mathematics::BandedMatrix<Real>::GetUpperBand(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetUpperBand(index);
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::SetUpperBandZero()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetUpperBandZero();
}

template <typename Real>
Real& Mathematics::BandedMatrix<Real>::operator()(int row, int column)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return (*m_Impl)(row, column);
}

template <typename Real>
const Real& Mathematics::BandedMatrix<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (*m_Impl)(row, column);
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::SetZero()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetZero();
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::SetIdentity()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetIdentity();
}

template <typename Real>
typename const Mathematics::BandedMatrix<Real>::VariableMatrix Mathematics::BandedMatrix<Real>::ToVariableMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->ToVariableMatrix();
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_ACHIEVE_H
