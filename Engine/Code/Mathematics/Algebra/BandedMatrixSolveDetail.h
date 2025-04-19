/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/02/18 13:34)

#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_DETAIL_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_DETAIL_H

#include "BandedMatrixDetail.h"
#include "BandedMatrixSolve.h"
#include "VariableLengthVectorDetail.h"
#include "VariableMatrixDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

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
    BandedMatrixType upperBandedMatrix{ cholesky };
    upperBandedMatrix.SetLowerBandZero();

    BandedMatrixType lowerBandedMatrix{ cholesky };
    lowerBandedMatrix.SetUpperBandZero();

    for (auto row = 0; row < input.GetSize(); ++row)
    {
        for (auto column = 0; column < input.GetSize(); ++column)
        {
            if (!MathType::Approximate(input(row, column), GetProduct(upperBandedMatrix, lowerBandedMatrix, row, column), epsilon))
            {
                return false;
            }
        }
    }

    return true;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::BandedMatrixSolve<Real>::GetProduct(const BandedMatrixType& upperBandedMatrix, const BandedMatrixType& lowerBandedMatrix, int row, int column) const
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
Real Mathematics::BandedMatrixSolve<Real>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return epsilon;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrixSolve<Real>::ResetSize(int size, int lowerBandsNumber, int upperBandsNumber, Real aEpsilon)
{
    MATHEMATICS_CLASS_IS_VALID_6;

    input.ResetSize(size, lowerBandsNumber, upperBandsNumber);
    cholesky.ResetSize(size, lowerBandsNumber, upperBandsNumber);
    solve = BandedMatrixSolveFlags::Unsolved;
    epsilon = aEpsilon;
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
typename Mathematics::BandedMatrixSolve<Real>::VariableMatrixType Mathematics::BandedMatrixSolve<Real>::ToInputVariableMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return input.ToVariableMatrix();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::BandedMatrixSolve<Real>::VariableMatrixType Mathematics::BandedMatrixSolve<Real>::ToCholeskyVariableMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_6;

    return cholesky.ToVariableMatrix();
}

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::BandedMatrixSolve<Real>::CholeskyFactor()
{
    MATHEMATICS_CLASS_IS_VALID_6;

    if (input.GetLowerBandsNumber() != input.GetUpperBandsNumber())
    {
        /// ��Ч�Ĵ�״������
        THROW_EXCEPTION(SYSTEM_TEXT("Bands ��������� CholeskyFactor\n"s))
    }

    if (solve == BandedMatrixSolveFlags::Unsolved)
    {
        cholesky = input;
        const auto size = GetSize();
        const auto sizeMinusOne = size - 1;
        const auto lowerBandsNumber = GetLowerBandsNumber();

        for (auto index = 0; index < size; ++index)
        {
            // ÿ�ο�ʼ��������С�����������ٴ�0��ʼ��
            const auto minColumn = std::max(0, index - lowerBandsNumber);

            // ����С����������������
            for (auto column = minColumn; column < index; ++column)
            {
                const auto maxColumn = std::min(column + lowerBandsNumber, sizeMinusOne);

                for (auto i = index; i <= maxColumn; ++i)
                {
                    cholesky(i, index) -= cholesky(index, column) * cholesky(i, column);
                }
            }

            // �����������������������Ϊ�ܴ�С��1��
            const auto maxColumn = std::min(index + lowerBandsNumber, sizeMinusOne);

            // �������Ǿ����ֵ���Ƶ������Ǿ���
            for (auto i = 0; i < index; ++i)
            {
                cholesky(i, index) = cholesky(index, i);
            }

            const auto diagonal = cholesky(index, index);
            if (diagonal <= MathType::GetValue(0))
            {
                solve = BandedMatrixSolveFlags::Failure;

                return false;
            }

            const auto invSqrt = MathType::InvSqrt(diagonal);
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
typename Mathematics::BandedMatrixSolve<Real>::VariableLengthVectorType Mathematics::BandedMatrixSolve<Real>::SolveSystem(const VariableLengthVectorType& vector)
{
    MATHEMATICS_CLASS_IS_VALID_6;
    MATHEMATICS_ASSERTION_0(vector.GetSize() == GetSize(), "�����������С�����");

    if (!CholeskyFactor())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ӷֽ�ʧ����SolveSystem��"s))
    }

    auto solveLowerVector = SolveLower(vector);

    return SolveUpper(solveLowerVector);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::BandedMatrixSolve<Real>::VariableLengthVectorType Mathematics::BandedMatrixSolve<Real>::SolveLower(const VariableLengthVectorType& vector) const
{
    VariableLengthVectorType result{ vector };

    const auto size = GetSize();

    for (auto row = 0; row < size; ++row)
    {
        const auto lowerRowRow = cholesky(row, row);
        if (MathType::FAbs(lowerRowRow) < epsilon)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("���ӷֽ�ʧ����SolveLower��"s));
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
typename Mathematics::BandedMatrixSolve<Real>::VariableLengthVectorType Mathematics::BandedMatrixSolve<Real>::SolveUpper(const VariableLengthVectorType& vector) const
{
    VariableLengthVectorType result{ vector };

    const auto size = GetSize();

    for (auto row = size - 1; 0 <= row; --row)
    {
        const auto upperRowRow = cholesky(row, row);
        if (MathType::FAbs(upperRowRow) < epsilon)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("���ӷֽ�ʧ����SolveUpper��"s));
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
template <bool RowMajor>
typename Mathematics::BandedMatrixSolve<Real>::VariableMatrixType Mathematics::BandedMatrixSolve<Real>::SolveSystem(const VariableMatrixType& matrix)
{
    MATHEMATICS_CLASS_IS_VALID_6;
    MATHEMATICS_ASSERTION_0(matrix.GetColumnsNumber() == GetSize() && matrix.GetRowsNumber() == GetSize(), "�����С�����");

    if (!CholeskyFactor())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ӷֽ�ʧ����SolveSystem��"s))
    }

    auto solveLowerMatrix = SolveLower<RowMajor>(matrix);

    return SolveUpper<RowMajor>(solveLowerMatrix);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
template <bool RowMajor>
typename Mathematics::BandedMatrixSolve<Real>::VariableMatrixType Mathematics::BandedMatrixSolve<Real>::SolveLower(const VariableMatrixType& matrix) const
{
    const auto size = GetSize();
    std::vector<Real> container{ matrix.GetContainer() };
    CoreTools::LexicoArray2<RowMajor, typename std::vector<Real>::iterator> data{ size, matrix.GetColumnsNumber(), container.begin(), container.end() };

    for (auto row = 0; row < size; ++row)
    {
        const auto lowerRowRow = cholesky(row, row);
        if (MathType::FAbs(lowerRowRow) < epsilon)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("���ӷֽ�ʧ����SolveLower��"s));
        }

        for (auto column = 0; column < row; ++column)
        {
            const auto lowerRowColumn = cholesky(row, column);
            for (auto resultColumn = 0; resultColumn < matrix.GetColumnsNumber(); ++resultColumn)
            {
                data(row, resultColumn) -= lowerRowColumn * data(column, resultColumn);
            }
        }

        const auto inverse = MathType::GetValue(1) / lowerRowRow;
        for (auto resultColumn = 0; resultColumn < matrix.GetColumnsNumber(); ++resultColumn)
        {
            data(row, resultColumn) *= inverse;
        }
    }

    return VariableMatrixType{ matrix.GetRowsNumber(), matrix.GetColumnsNumber(), data.template GetContainer<std::vector<Real>>() };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
template <bool RowMajor>
typename Mathematics::BandedMatrixSolve<Real>::VariableMatrixType Mathematics::BandedMatrixSolve<Real>::SolveUpper(const VariableMatrixType& matrix) const
{
    const auto size = GetSize();

    std::vector<Real> container{ matrix.GetContainer() };
    CoreTools::LexicoArray2<RowMajor, typename std::vector<Real>::iterator> data{ size, matrix.GetColumnsNumber(), container.begin(), container.end() };

    for (auto row = GetSize() - 1; 0 <= row; --row)
    {
        const auto upperRowRow = cholesky(row, row);
        if (MathType::FAbs(upperRowRow) < epsilon)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("���ӷֽ�ʧ����SolveUpper��"s));
        }

        for (auto column = row + 1; column < GetSize(); ++column)
        {
            const auto upperRowColumn = cholesky(row, column);
            for (auto resultColumn = 0; resultColumn < matrix.GetColumnsNumber(); ++resultColumn)
            {
                data(row, resultColumn) -= upperRowColumn * data(column, resultColumn);
            }
        }

        const auto inverse = MathType::GetValue(1) / upperRowRow;
        for (auto resultColumn = 0; resultColumn < matrix.GetColumnsNumber(); ++resultColumn)
        {
            data(row, resultColumn) *= inverse;
        }
    }

    return VariableMatrixType{ matrix.GetRowsNumber(), matrix.GetColumnsNumber(), data.template GetContainer<std::vector<Real>>() };
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_DETAIL_H
