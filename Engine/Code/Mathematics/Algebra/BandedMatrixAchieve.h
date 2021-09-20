///	Copyright (c) 2010-2020
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
    : impl{ std::make_shared<ImplType>(size, lowerBandsNumber, upperBandsNumber) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::BandedMatrix<Real>::BandedMatrix(const BandedMatrix& rhs)
    : impl{ std::make_shared<ImplType>(*rhs.impl) }
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
    ;

    std::swap(impl, rhs.impl);
}

template <typename Real>
Mathematics::BandedMatrix<Real>::BandedMatrix(BandedMatrix&& rhs) noexcept
    : impl{ std::move(rhs.impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::BandedMatrix<Real>& Mathematics::BandedMatrix<Real>::operator=(BandedMatrix&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    impl = std::move(rhs.impl);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::BandedMatrix<Real>::IsValid() const noexcept
{
    if (impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::BandedMatrix<Real>::GetSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetSize();
}

template <typename Real>
int Mathematics::BandedMatrix<Real>::GetLowerBandsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetLowerBandsNumber();
}

template <typename Real>
int Mathematics::BandedMatrix<Real>::GetUpperBandsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetUpperBandsNumber();
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::ResetSize(int size, int lowerBandsNumber, int upperBandsNumber)
{
    ;

    return impl->ResetSize(size, lowerBandsNumber, upperBandsNumber);
}

template <typename Real>
int Mathematics::BandedMatrix<Real>::GetStreamSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetStreamSize();
}

template <typename Real>
typename Mathematics::BandedMatrix<Real>::ContainerType Mathematics::BandedMatrix<Real>::GetDiagonalBand() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetDiagonalBand();
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::SetDiagonalBand(const ContainerType& diagonalBand)
{
    ;

    return impl->SetDiagonalBand(diagonalBand);
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::SetLowerBand(int index, const ContainerType& lowerBand)
{
    ;

    return impl->SetLowerBand(index, lowerBand);
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::SetLowerBandZero()
{
    ;

    return impl->SetLowerBandZero();
}

template <typename Real>
int Mathematics::BandedMatrix<Real>::GetLowerBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetLowerBandMax(index);
}

template <typename Real>
typename Mathematics::BandedMatrix<Real>::ContainerType Mathematics::BandedMatrix<Real>::GetLowerBand(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetLowerBand(index);
}

template <typename Real>
int Mathematics::BandedMatrix<Real>::GetUpperBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetUpperBandMax(index);
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::SetUpperBand(int index, const ContainerType& upperBand)
{
    ;

    return impl->SetUpperBand(index, upperBand);
}

template <typename Real>
typename Mathematics::BandedMatrix<Real>::ContainerType Mathematics::BandedMatrix<Real>::GetUpperBand(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetUpperBand(index);
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::SetUpperBandZero()
{
    ;

    return impl->SetUpperBandZero();
}

template <typename Real>
Real& Mathematics::BandedMatrix<Real>::operator()(int row, int column)
{
    ;

    return (*impl)(row, column);
}

template <typename Real>
const Real& Mathematics::BandedMatrix<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (*impl)(row, column);
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::SetZero()
{
    ;

    return impl->SetZero();
}

template <typename Real>
void Mathematics::BandedMatrix<Real>::SetIdentity()
{
    ;

    return impl->SetIdentity();
}

template <typename Real>
typename const Mathematics::BandedMatrix<Real>::VariableMatrix Mathematics::BandedMatrix<Real>::ToVariableMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->ToVariableMatrix();
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_ACHIEVE_H
