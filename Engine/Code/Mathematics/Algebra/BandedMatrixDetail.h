///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 15:25)

#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_DETAIL_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_DETAIL_H

#include "BandedMatrix.h"
#include "VariableLengthVectorDetail.h"
#include "VariableMatrix.h"
#include "Detail/BandedMatrixDataDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/StreamMacro.h"

#include <gsl/util>

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::BandedMatrix<Real>::BandedMatrix(int size, int lowerBandsNumber, int upperBandsNumber)
    : diagonalBandContainer(size), lowerBandData{ size, lowerBandsNumber }, upperBandData{ size, upperBandsNumber }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::BandedMatrix<Real>::IsValid() const noexcept
{
    if (!diagonalBandContainer.empty() &&
        gsl::narrow_cast<int>(diagonalBandContainer.size()) == lowerBandData.GetSize() &&
        gsl::narrow_cast<int>(diagonalBandContainer.size()) == upperBandData.GetSize())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrix<Real>::GetSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(diagonalBandContainer.size());
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrix<Real>::GetLowerBandsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lowerBandData.GetBandsNumber();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrix<Real>::GetUpperBandsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return upperBandData.GetBandsNumber();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrix<Real>::ResetSize(int size, int lowerBandsNumber, int upperBandsNumber)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    diagonalBandContainer.resize(size, Math::GetValue(0));
    lowerBandData.ResetSize(size, lowerBandsNumber);
    upperBandData.ResetSize(size, upperBandsNumber);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrix<Real>::GetStreamSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return CoreTools::GetStreamSize(diagonalBandContainer) + lowerBandData.GetStreamSize() + upperBandData.GetStreamSize();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::BandedMatrix<Real>::ContainerType Mathematics::BandedMatrix<Real>::GetDiagonalBand() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return diagonalBandContainer;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrix<Real>::SetDiagonalBand(const ContainerType& diagonalBand)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (diagonalBand.size() != diagonalBandContainer.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("对角线元素大小不相等。"s))
    }

    diagonalBandContainer = diagonalBand;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrix<Real>::SetLowerBand(int index, const ContainerType& lowerBand)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    lowerBandData.SetBand(index, lowerBand);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrix<Real>::SetLowerBandZero()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    lowerBandData.SetZero();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrix<Real>::GetLowerBandMax(int index) const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lowerBandData.GetBandMax(index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::BandedMatrix<Real>::ContainerType Mathematics::BandedMatrix<Real>::GetLowerBand(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lowerBandData.GetBand(index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrix<Real>::GetUpperBandMax(int index) const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return upperBandData.GetBandMax(index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrix<Real>::SetUpperBand(int index, const ContainerType& upperBand)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    upperBandData.SetBand(index, upperBand);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::BandedMatrix<Real>::ContainerType Mathematics::BandedMatrix<Real>::GetUpperBand(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return upperBandData.GetBand(index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrix<Real>::SetUpperBandZero()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    upperBandData.SetZero();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::BandedMatrix<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include STSTEM_WARNING_POP
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::BandedMatrix<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= row && row < GetSize() && 0 <= column && column < GetSize(), "无效 row 或 column 在 BandedMatrixImpl::operator\n");

    if (column == row)
    {
        return diagonalBandContainer.at(row);
    }
    else if (row < column)
    {
        return upperBandData(row, column);
    }
    else
    {
        return lowerBandData(row, column);
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrix<Real>::SetZero()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    fill(diagonalBandContainer.begin(), diagonalBandContainer.end(), Math::GetValue(0));
    upperBandData.SetZero();
    lowerBandData.SetZero();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrix<Real>::SetIdentity()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    fill(diagonalBandContainer.begin(), diagonalBandContainer.end(), Math::GetValue(1));
    upperBandData.SetZero();
    lowerBandData.SetZero();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::BandedMatrix<Real>::VariableMatrix Mathematics::BandedMatrix<Real>::ToVariableMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto size = GetSize();
    VariableMatrix variableMatrix{ size, size };

    for (auto row = 0; row < size; ++row)
    {
        for (auto column = 0; column < size; ++column)
        {
            variableMatrix(row, column) = (*this)(row, column);
        }
    }

    return variableMatrix;
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_DETAIL_H
