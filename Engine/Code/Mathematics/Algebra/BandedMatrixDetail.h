/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/18 13:19)

#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_DETAIL_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_DETAIL_H

#include "BandedMatrix.h"
#include "VariableLengthVectorDetail.h"
#include "VariableMatrixDetail.h"
#include "Detail/BandedMatrixDataDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <gsl/util>

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::BandedMatrix<Real>::BandedMatrix(int size, int lowerBandsNumber, int upperBandsNumber)
    : diagonalBandContainer(size), lowerBandData{ size, lowerBandsNumber }, upperBandData{ size, upperBandsNumber }
{
    if (size <= 0 ||
        lowerBandsNumber < 0 ||
        size <= lowerBandsNumber ||
        upperBandsNumber < 0 ||
        size <= upperBandsNumber)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效参数。"))
    }

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

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include SYSTEM_WARNING_POP
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::BandedMatrix<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (row < 0 || GetSize() <= row || column < 0 || GetSize() <= column)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效 row 或 column 在 BandedMatrixImpl::operator\n"));
    }

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

template <typename Real>
requires std::is_arithmetic_v<Real>
template <bool RowMajor>
typename Mathematics::BandedMatrix<Real>::VariableMatrix Mathematics::BandedMatrix<Real>::ComputeInverse(Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto size = GetSize();

    LexicoArray2<RowMajor, Real> inverseLexicoArray{ size, size, LexicoArray2<RowMajor, Real>::Container(size * size) };

    for (auto row = 0; row < size; ++row)
    {
        for (auto column = 0; column < size; ++column)
        {
            if (row != column)
            {
                inverseLexicoArray(row, column) = Real{};
            }
            else
            {
                inverseLexicoArray(row, row) = Math::GetValue(1);
            }
        }
    }

    BandedMatrix result = *this;

    /// 正向消除。
    for (auto row = 0; row < size; ++row)
    {
        /// 枢轴必须为非零才能继续。
        const auto diagonal = result(row, row);
        if (Math::FAbs(diagonal) <= epsilon)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("不存在逆矩阵。"))
        }

        Real invDiagonal = Math::GetValue(1) / diagonal;
        result(row, row) = Math::GetValue(1);

        /// 将行相乘，使其与对角线项1一致。
        const auto columnMin = row + 1;
        auto columnMax = columnMin + GetUpperBandsNumber();
        if (size < columnMax)
        {
            columnMax = size;
        }

        for (auto c = columnMin; c < columnMax; ++c)
        {
            result(row, c) *= invDiagonal;
        }
        for (auto c = 0; c <= row; ++c)
        {
            inverseLexicoArray(row, c) *= invDiagonal;
        }

        /// 减少剩余的行数。
        const auto rowMin = row + 1;
        auto rowMax = rowMin + GetLowerBandsNumber();
        if (size < rowMax)
        {
            rowMax = size;
        }

        for (auto r = rowMin; r < rowMax; ++r)
        {
            const auto mult = result(r, row);
            result(r, row) = Real{};
            for (auto c = columnMin; c < columnMax; ++c)
            {
                result(r, c) -= mult * result(row, c);
            }
            for (auto c = 0; c <= row; ++c)
            {
                inverseLexicoArray(r, c) -= mult * inverseLexicoArray(row, c);
            }
        }
    }

    /// 后向消除
    for (auto row = size - 1; row >= 1; --row)
    {
        const auto rowMax = row - 1;
        auto rowMin = row - GetUpperBandsNumber();

        if (rowMin < 0)
        {
            rowMin = 0;
        }

        for (auto r = rowMax; r >= rowMin; --r)
        {
            const auto mult = result(r, row);
            result(r, row) = Real{};
            for (auto c = 0; c < size; ++c)
            {
                inverseLexicoArray(r, c) -= mult * inverseLexicoArray(row, c);
            }
        }
    }

    return VariableMatrix{ size, size, inverseLexicoArray.GetContainer() };
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_DETAIL_H
