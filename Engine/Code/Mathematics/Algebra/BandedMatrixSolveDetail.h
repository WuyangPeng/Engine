///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 15:28)

#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_DETAIL_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_DETAIL_H

#include "BandedMatrixDetail.h"
#include "BandedMatrixSolve.h"
#include "VariableLengthVectorDetail.h"
#include "VariableMatrixDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/StreamMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::BandedMatrixSolve<Real>::BandedMatrixSolve(int size, int lowerBandsNumber, int upperBandsNumber, Real epsilon)
    : input{ size, lowerBandsNumber, upperBandsNumber },
      cholesky{ size, lowerBandsNumber, upperBandsNumber },
      solve{ BandedMatrixSolveFlags::Unsolved },
      epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_6;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::BandedMatrixSolve<Real>::IsValid() const noexcept
{
    try
    {
        if (input.GetSize() != cholesky.GetSize())
            return false;
        else if (input.GetUpperBandsNumber() != cholesky.GetUpperBandsNumber())
            return false;
        else if (input.GetLowerBandsNumber() != cholesky.GetLowerBandsNumber())
            return false;
        else if (solve != BandedMatrixSolveFlags::Succeed)
            return true;
        else
            return IsSolveValid();
    }
    catch (...)
    {
        return false;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::BandedMatrixSolve<Real>::IsSolveValid() const
{
    BandedMatrix upperBandedMatrix{ cholesky };
    upperBandedMatrix.SetLowerBandZero();

    BandedMatrix lowerBandedMatrix{ cholesky };
    lowerBandedMatrix.SetUpperBandZero();

    for (auto row = 0; row < input.GetSize(); ++row)
    {
        for (auto column = 0; column < input.GetSize(); ++column)
        {
            if (!Math::Approximate(input(row, column), GetProduct(upperBandedMatrix, lowerBandedMatrix, row, column), epsilon))
            {
                return false;
            }
        }
    }

    return true;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::BandedMatrixSolve<Real>::GetProduct(const BandedMatrix& upperBandedMatrix, const BandedMatrix& lowerBandedMatrix, int row, int column) const
{
    Real sum{};
    for (auto index = 0; index < upperBandedMatrix.GetSize(); ++index)
    {
        sum += lowerBandedMatrix(row, index) * upperBandedMatrix(index, column);
    }

    return sum;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrixSolve<Real>::GetSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return input.GetSize();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrixSolve<Real>::GetLowerBandsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return input.GetLowerBandsNumber();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrixSolve<Real>::GetUpperBandsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return input.GetUpperBandsNumber();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::BandedMatrixSolveFlags Mathematics::BandedMatrixSolve<Real>::GetSolve() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return solve;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrixSolve<Real>::GetStreamSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    auto size = input.GetStreamSize();
    size += CoreTools::GetStreamSize(epsilon);

    return size;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrixSolve<Real>::SetEpsilon(Real newEpsilon) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_6;

    epsilon = newEpsilon;
    solve = BandedMatrixSolveFlags::Unsolved;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::BandedMatrixSolve<Real>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return epsilon;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrixSolve<Real>::ResetSize(int size, int lowerBandsNumber, int upperBandsNumber, const Real newEpsilon)
{
    MATHEMATICS_CLASS_IS_VALID_6;

    input.ResetSize(size, lowerBandsNumber, upperBandsNumber);
    cholesky.ResetSize(size, lowerBandsNumber, upperBandsNumber);
    solve = BandedMatrixSolveFlags::Unsolved;
    epsilon = newEpsilon;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrixSolve<Real>::GetLowerBandMax(int index) const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return input.GetLowerBandMax(index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
std::vector<Real> Mathematics::BandedMatrixSolve<Real>::GetDiagonalBand() const
{
    MATHEMATICS_CLASS_IS_VALID_6;

    return input.GetDiagonalBand();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrixSolve<Real>::SetDiagonalBand(const ContainerType& diagonalBand)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return input.SetDiagonalBand(diagonalBand);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
std::vector<Real> Mathematics::BandedMatrixSolve<Real>::GetLowerBand(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return input.GetLowerBand(index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrixSolve<Real>::SetLowerBand(int index, const ContainerType& lowerBand)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return input.SetLowerBand(index, lowerBand);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrixSolve<Real>::GetUpperBandMax(int index) const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return input.GetUpperBandMax(index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrixSolve<Real>::SetUpperBand(int index, const ContainerType& upperBand)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return input.SetUpperBand(index, upperBand);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
std::vector<Real> Mathematics::BandedMatrixSolve<Real>::GetUpperBand(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return input.GetUpperBand(index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::BandedMatrixSolve<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_6;

    solve = BandedMatrixSolveFlags::Unsolved;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include SYSTEM_WARNING_POP
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::BandedMatrixSolve<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return input(row, column);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrixSolve<Real>::SetZero()
{
    MATHEMATICS_CLASS_IS_VALID_6;

    solve = BandedMatrixSolveFlags::Unsolved;

    input.SetZero();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrixSolve<Real>::SetIdentity()
{
    MATHEMATICS_CLASS_IS_VALID_6;

    solve = BandedMatrixSolveFlags::Unsolved;

    input.SetIdentity();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::BandedMatrixSolve<Real>::VariableMatrix Mathematics::BandedMatrixSolve<Real>::ToInputVariableMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_6;

    return input.ToVariableMatrix();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::BandedMatrixSolve<Real>::VariableMatrix Mathematics::BandedMatrixSolve<Real>::ToCholeskyVariableMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_6;

    return cholesky.ToVariableMatrix();
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::BandedMatrixSolve<Real>::CholeskyFactor()
{
    MATHEMATICS_CLASS_IS_VALID_6;

    if (input.GetLowerBandsNumber() != input.GetUpperBandsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Bands 必须相等在 CholeskyFactor\n"s))
    }

    if (solve == BandedMatrixSolveFlags::Unsolved)
    {
        cholesky = input;
        const auto size = GetSize();
        const auto sizeMinusOne = size - 1;
        const auto lowerBandsNumber = GetLowerBandsNumber();

        for (auto index = 0; index < size; ++index)
        {
            // 每次开始遍历的最小列数。（至少从0开始）
            const auto minColumn = std::max(0, index - lowerBandsNumber);

            // 从最小列数遍历到索引数
            for (auto column = minColumn; column < index; ++column)
            {
                const auto maxColumn = std::min(column + lowerBandsNumber, sizeMinusOne);

                for (auto i = index; i <= maxColumn; ++i)
                {
                    cholesky(i, index) -= cholesky(index, column) * cholesky(i, column);
                }
            }

            // 遍历到的最大列数，（至多为总大小减1）
            const auto maxColumn = std::min(index + lowerBandsNumber, sizeMinusOne);

            // 将下三角矩阵的值复制到上三角矩阵
            for (auto i = 0; i < index; ++i)
            {
                cholesky(i, index) = cholesky(index, i);
            }

            const auto diagonal = cholesky(index, index);
            if (diagonal <= Math::GetValue(0))
            {
                solve = BandedMatrixSolveFlags::Failure;

                return false;
            }

            const auto invSqrt = Math::InvSqrt(diagonal);
            for (auto i = index; i <= maxColumn; ++i)
            {
                cholesky(i, index) *= invSqrt;
            }
        }

        solve = BandedMatrixSolveFlags::Succeed;
    }

    return true;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::BandedMatrixSolve<Real>::VariableLengthVector Mathematics::BandedMatrixSolve<Real>::SolveSystem(const VariableLengthVector& vector)
{
    MATHEMATICS_CLASS_IS_VALID_6;
    MATHEMATICS_ASSERTION_1(vector.GetSize() == GetSize(), "矩阵和向量大小不相等");

    if (!CholeskyFactor())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("因子分解失败在SolveSystem！"s))
    }

    auto solveLowerVector = SolveLower(vector);

    return SolveUpper(solveLowerVector);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::BandedMatrixSolve<Real>::VariableLengthVector Mathematics::BandedMatrixSolve<Real>::SolveLower(const VariableLengthVector& vector) const
{
    VariableLengthVector result{ vector };

    const auto size = GetSize();

    for (auto row = 0; row < size; ++row)
    {
        const auto lowerRowRow = cholesky(row, row);
        if (Math::FAbs(lowerRowRow) < epsilon)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("因子分解失败在SolveLower！"s));
        }

        for (auto column = 0; column < row; ++column)
        {
            const auto lowerRowColumn = cholesky(row, column);
            result[row] -= lowerRowColumn * result[column];
        }

        result[row] /= lowerRowRow;
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::BandedMatrixSolve<Real>::VariableLengthVector Mathematics::BandedMatrixSolve<Real>::SolveUpper(const VariableLengthVector& vector) const
{
    VariableLengthVector result{ vector };

    const auto size = GetSize();

    for (auto row = size - 1; 0 <= row; --row)
    {
        const auto upperRowRow = cholesky(row, row);
        if (Math::FAbs(upperRowRow) < epsilon)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("因子分解失败在SolveUpper！"s));
        }

        for (auto column = row + 1; column < size; ++column)
        {
            const auto upperRowColumn = cholesky(row, column);
            result[row] -= upperRowColumn * result[column];
        }

        result[row] /= upperRowRow;
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::BandedMatrixSolve<Real>::VariableMatrix Mathematics::BandedMatrixSolve<Real>::SolveSystem(const VariableMatrix& matrix)
{
    MATHEMATICS_CLASS_IS_VALID_6;
    MATHEMATICS_ASSERTION_1(matrix.GetColumnsNumber() == GetSize() && matrix.GetRowsNumber() == GetSize(), "矩阵大小不相等");

    if (!CholeskyFactor())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("因子分解失败在SolveSystem！"s))
    }

    auto solveLowerMatrix = SolveLower(matrix);

    return SolveUpper(solveLowerMatrix);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::BandedMatrixSolve<Real>::VariableMatrix Mathematics::BandedMatrixSolve<Real>::SolveLower(const VariableMatrix& matrix) const
{
    VariableMatrix result{ matrix };

    const auto size = GetSize();

    for (auto row = 0; row < size; ++row)
    {
        const auto lowerRowRow = cholesky(row, row);
        if (Math::FAbs(lowerRowRow) < epsilon)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("因子分解失败在SolveLower！"s));
        }

        for (auto column = 0; column < row; ++column)
        {
            const auto lowerRowColumn = cholesky(row, column);
            for (auto resultColumn = 0; resultColumn < result.GetColumnsNumber(); ++resultColumn)
            {
                result(row, resultColumn) -= lowerRowColumn * result(column, resultColumn);
            }
        }

        const auto inverse = Math::GetValue(1) / lowerRowRow;
        for (auto resultColumn = 0; resultColumn < result.GetColumnsNumber(); ++resultColumn)
        {
            result(row, resultColumn) *= inverse;
        }
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::BandedMatrixSolve<Real>::VariableMatrix Mathematics::BandedMatrixSolve<Real>::SolveUpper(const VariableMatrix& matrix) const
{
    VariableMatrix result{ matrix };

    for (auto row = GetSize() - 1; 0 <= row; --row)
    {
        const auto upperRowRow = cholesky(row, row);
        if (Math::FAbs(upperRowRow) < epsilon)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("因子分解失败在SolveUpper！"s));
        }

        for (auto column = row + 1; column < GetSize(); ++column)
        {
            const auto upperRowColumn = cholesky(row, column);
            for (auto resultColumn = 0; resultColumn < result.GetColumnsNumber(); ++resultColumn)
            {
                result(row, resultColumn) -= upperRowColumn * result(column, resultColumn);
            }
        }

        const auto inverse = Math::GetValue(1) / upperRowRow;
        for (auto resultColumn = 0; resultColumn < result.GetColumnsNumber(); ++resultColumn)
        {
            result(row, resultColumn) *= inverse;
        }
    }

    return result;
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_DETAIL_H
