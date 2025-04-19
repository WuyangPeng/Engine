/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/31 10:25)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_DETAIL_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_DETAIL_H

#include "Matrix.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Detail/Matrix/MatrixTableDetail.h"
#include "Mathematics/Algebra/Vector/VectorDetail.h"
#include "Mathematics/NumericalAnalysis/GaussianElimination.h"

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::Matrix() noexcept
    : table{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::Matrix(const Container& values)
    : table{}
{
    auto index = 0;
    for (auto row = 0; row < NumRows; ++row)
    {
        for (auto column = 0; column < NumColumns; ++column)
        {
            table(row, column) = values.at(index);

            ++index;
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::Matrix(const BaseContainer& values)
    : table{}
{
    auto index = 0;
    for (auto row = 0; row < NumRows; ++row)
    {
        for (auto column = 0; column < NumColumns; ++column)
        {
            table(row, column) = values.at(index);

            ++index;
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::Matrix(Real m00, Real m01, Real m10, Real m11) noexcept requires(NumRows == 2 && NumColumns == 2)
    : table{ m00, m01, m10, m11 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::Matrix(Real m00, Real m01, Real m02, Real m10, Real m11, Real m12, Real m20, Real m21, Real m22) noexcept requires(NumRows == 3 && NumColumns == 3)
    : table{ m00, m01, m02, m10, m11, m12, m20, m21, m22 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::Matrix(Real m00, Real m01, Real m02, Real m03, Real m10, Real m11, Real m12, Real m13, Real m20, Real m21, Real m22, Real m23, Real m30, Real m31, Real m32, Real m33) noexcept requires(NumRows == 4 && NumColumns == 4)
    : table{ m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::Matrix(int row, int column)
    : table{}
{
    MakeUnit(row, column);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::BaseContainer Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::GetBaseContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    BaseContainer result{};

    for (auto i = 0; i < numElements; ++i)
    {
        result.emplace_back(table[i]);
    }

    return result;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
const Real& Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return table(row, column);
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Real& Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include SYSTEM_WARNING_POP
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::SetRow(int row, const Vector<NumColumns, Real>& vector)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto column = 0; column < NumColumns; ++column)
    {
        table(row, column) = vector[column];
    }
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::SetColumn(int column, const Vector<NumRows, Real>& vector)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto row = 0; row < NumRows; ++row)
    {
        table(row, column) = vector[row];
    }
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<NumColumns, Real> Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::GetRow(int row) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector<NumColumns, Real> result{};

    for (auto column = 0; column < NumColumns; ++column)
    {
        result[column] = table(row, column);
    }

    return result;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<NumRows, Real> Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::GetColumn(int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector<NumRows, Real> result{};

    for (auto row = 0; row < NumRows; ++row)
    {
        result[row] = table(row, column);
    }

    return result;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
const Real& Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return table[index];
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Real& Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator==(const Matrix& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return table == rhs.table;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator!=(const Matrix& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return !(*this == rhs);
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator<(const Matrix& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return table < rhs.table;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator<=(const Matrix& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return !(rhs < *this);
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator>(const Matrix& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return rhs < *this;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator>=(const Matrix& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return !(*this < rhs);
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::MakeZero()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i = 0; i < numElements; ++i)
    {
        table[i] = Real{};
    }
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::MakeUnit(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    MakeZero();
    if (0 <= row && row < NumRows && 0 <= column && column < NumColumns)
    {
        table(row, column) = MathType::GetValue(1);
    }
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
void Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::MakeIdentity()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    MakeZero();
    constexpr auto numDiagonal = (NumRows <= NumColumns ? NumRows : NumColumns);
    for (auto index = 0; index < numDiagonal; ++index)
    {
        table(index, index) = Real{};
    }
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::Zero() noexcept
{
    return Matrix{};
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::Unit(int row, int column)
{
    Matrix matrix{};

    matrix.MakeUnit(row, column);

    return matrix;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::Identity()
{
    Matrix matrix{};

    matrix.MakeIdentity();

    return matrix;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator+() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *this;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Matrix result{};

    for (auto i = 0; i < numElements; ++i)
    {
        result[i] = -table[i];
    }

    return result;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>& Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator+=(const Matrix& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i = 0; i < numElements; ++i)
    {
        table[i] += rhs[i];
    }

    return *this;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>& Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator-=(const Matrix& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i = 0; i < numElements; ++i)
    {
        table[i] -= rhs[i];
    }

    return *this;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>& Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator*=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto i = 0; i < numElements; ++i)
    {
        table[i] *= scalar;
    }

    return *this;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>& Mathematics::Algebra::Matrix<NumRows, NumColumns, Real>::operator/=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (MathType::GetZeroTolerance() < scalar)
    {
        for (auto i = 0; i < numElements; ++i)
        {
            table[i] /= scalar;
        }
    }
    else
    {
        MakeZero();
    }

    return *this;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::operator+(const Matrix<NumRows, NumColumns, Real>& lhs, const Matrix<NumRows, NumColumns, Real>& rhs)
{
    Matrix<NumRows, NumColumns, Real> result{ lhs };

    result += rhs;

    return result;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::operator-(const Matrix<NumRows, NumColumns, Real>& lhs, const Matrix<NumRows, NumColumns, Real>& rhs)
{
    Matrix<NumRows, NumColumns, Real> result{ lhs };

    result -= rhs;

    return result;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::operator*(const Matrix<NumRows, NumColumns, Real>& lhs, Real scalar)
{
    Matrix<NumRows, NumColumns, Real> result{ lhs };

    result *= scalar;

    return result;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::operator*(Real scalar, const Matrix<NumRows, NumColumns, Real>& rhs)
{
    Matrix<NumRows, NumColumns, Real> result{ rhs };

    result *= scalar;

    return result;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::operator/(const Matrix<NumRows, NumColumns, Real>& lhs, Real scalar)
{
    Matrix<NumRows, NumColumns, Real> result{ lhs };

    result /= scalar;

    return result;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::L1Norm(const Matrix<NumRows, NumColumns, Real>& matrix)
{
    auto sum = Math<Real>::FAbs(matrix[0]);

    for (auto i = 1; i < Matrix<NumRows, NumColumns, Real>::numElements; ++i)
    {
        sum += Math<Real>::FAbs(matrix[i]);
    }

    return sum;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::L2Norm(const Matrix<NumRows, NumColumns, Real>& matrix)
{
    auto sum = matrix[0] * matrix[0];

    for (auto i = 1; i < Matrix<NumRows, NumColumns, Real>::numElements; ++i)
    {
        sum += matrix[i] * matrix[i];
    }

    return sum;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::LInfinityNorm(const Matrix<NumRows, NumColumns, Real>& matrix)
{
    auto maxElement = Math<Real>::FAbs(matrix[0]);
    for (auto i = 1; i < Matrix<NumRows, NumColumns, Real>::numElements; ++i)
    {
        auto element = Math<Real>::FAbs(matrix[i]);
        if (maxElement < element)
        {
            maxElement = element;
        }
    }
    return maxElement;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<N, N, Real> Mathematics::Algebra::Inverse(const Matrix<N, N, Real>& matrix, bool* reportInvertibility)
{
    GaussianElimination<Real> gaussianElimination{ N, matrix.GetBaseContainer(), true };

    if (reportInvertibility)
    {
        *reportInvertibility = gaussianElimination.IsInverse();
    }

    return Matrix<N, N, Real>{ gaussianElimination.GetInverse() };
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::Determinant(const Matrix<N, N, Real>& matrix)
{
    GaussianElimination<Real> gaussianElimination{ N, matrix.GetBaseContainer(), false };

    return gaussianElimination.GetDeterminant();
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumColumns, NumRows, Real> Mathematics::Algebra::Transpose(const Matrix<NumRows, NumColumns, Real>& matrix)
{
    Matrix<NumColumns, NumRows, Real> result{};

    for (auto row = 0; row < NumRows; ++row)
    {
        for (auto column = 0; column < NumColumns; ++column)
        {
            result(column, row) = matrix(row, column);
        }
    }

    return result;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<NumRows, Real> Mathematics::Algebra::operator*(const Matrix<NumRows, NumColumns, Real>& matrix, const Vector<NumColumns, Real>& vector)
{
    Vector<NumRows, Real> result{};

    for (auto row = 0; row < NumRows; ++row)
    {
        for (auto column = 0; column < NumColumns; ++column)
        {
            result[row] += matrix(row, column) * vector[column];
        }
    }

    return result;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Vector<NumColumns, Real> Mathematics::Algebra::operator*(const Vector<NumRows, Real>& vector, const Matrix<NumRows, NumColumns, Real>& matrix)
{
    Vector<NumColumns, Real> result{};

    for (auto column = 0; column < NumColumns; ++column)
    {
        for (auto row = 0; row < NumRows; ++row)
        {
            result[column] += vector[row] * matrix(row, column);
        }
    }

    return result;
}

template <int NumRows, int NumColumns, int NumCommon, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::operator*(const Matrix<NumRows, NumCommon, Real>& lhs, const Matrix<NumCommon, NumColumns, Real>& rhs)
{
    return Multiply(lhs, rhs);
}

template <int NumRows, int NumColumns, int NumCommon, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::Multiply(const Matrix<NumRows, NumCommon, Real>& lhs, const Matrix<NumCommon, NumColumns, Real>& rhs)
{
    Matrix<NumRows, NumColumns, Real> result{};

    for (auto row = 0; row < NumRows; ++row)
    {
        for (auto column = 0; column < NumColumns; ++column)
        {
            for (auto index = 0; index < NumCommon; ++index)
            {
                result(row, column) += lhs(row, index) * rhs(index, column);
            }
        }
    }

    return result;
}

template <int NumRows, int NumColumns, int NumCommon, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::MultiplyTransposition(const Matrix<NumRows, NumCommon, Real>& lhs, const Matrix<NumCommon, NumColumns, Real>& rhs)
{
    Matrix<NumRows, NumColumns, Real> result{};

    for (auto row = 0; row < NumRows; ++row)
    {
        for (auto column = 0; column < NumColumns; ++column)
        {
            for (auto index = 0; index < NumCommon; ++index)
            {
                result(row, column) += lhs(row, index) * rhs(column, index);
            }
        }
    }

    return result;
}

template <int NumRows, int NumColumns, int NumCommon, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::TranspositionMultiply(const Matrix<NumRows, NumCommon, Real>& lhs, const Matrix<NumCommon, NumColumns, Real>& rhs)
{
    Matrix<NumRows, NumCommon, Real> result{};

    for (auto row = 0; row < NumRows; ++row)
    {
        for (auto column = 0; column < NumCommon; ++column)
        {
            for (auto index = 0; index < NumCommon; ++index)
            {
                result(row, column) += lhs(index, row) * rhs(index, column);
            }
        }
    }

    return result;
}

template <int NumRows, int NumColumns, int NumCommon, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::TranspositionMultiplyTransposition(const Matrix<NumRows, NumCommon, Real>& lhs, const Matrix<NumCommon, NumColumns, Real>& rhs)
{
    Matrix<NumRows, NumCommon, Real> result{};

    for (auto row = 0; row < NumRows; ++row)
    {
        for (auto column = 0; column < NumCommon; ++column)
        {
            for (auto index = 0; index < NumCommon; ++index)
            {
                result(row, column) += lhs(index, row) * rhs(column, index);
            }
        }
    }

    return result;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::Multiply(const Matrix<NumRows, NumColumns, Real>& matrix, const Vector<NumColumns, Real>& diagonal)
{
    Matrix<NumRows, NumColumns, Real> result{};

    for (auto row = 0; row < NumRows; ++row)
    {
        for (auto column = 0; column < NumColumns; ++column)
        {
            result(row, column) = matrix(row, column) * diagonal[column];
        }
    }

    return result;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::Multiply(const Vector<NumRows, Real>& diagonal, const Matrix<NumRows, NumColumns, Real>& matrix)
{
    Matrix<NumRows, NumColumns, Real> result{};

    for (auto row = 0; row < NumRows; ++row)
    {
        for (auto column = 0; column < NumColumns; ++column)
        {
            result(row, column) = diagonal[row] * matrix(row, column);
        }
    }

    return result;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<NumRows, NumColumns, Real> Mathematics::Algebra::OuterProduct(const Vector<NumRows, Real>& u, const Vector<NumColumns, Real>& v)
{
    Matrix<NumRows, NumColumns, Real> result{};

    for (auto row = 0; row < NumRows; ++row)
    {
        for (auto column = 0; column < NumColumns; ++column)
        {
            result(row, column) = u[row] * v[column];
        }
    }

    return result;
}

template <int N, typename Real>
requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<N, N, Real> Mathematics::Algebra::MakeDiagonal(const Vector<N, Real>& diagonal)
{
    Matrix<N, N, Real> matrix{};

    for (auto i = 0; i < N; ++i)
    {
        matrix(i, i) = diagonal[i];
    }

    return matrix;
}

template <int N, typename Real>
requires(1 <= N && N <= 3 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<N + 1, N + 1, Real> Mathematics::Algebra::HomogeneousLift(const Matrix<N, N, Real>& matrix)
{
    Matrix<N + 1, N + 1, Real> result{};
    result.MakeIdentity();

    for (auto row = 0; row < N; ++row)
    {
        for (auto column = 0; column < N; ++column)
        {
            result(row, column) = matrix(row, column);
        }
    }

    return result;
}

template <int N, typename Real>
requires(2 <= N && N <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::Matrix<N - 1, N - 1, Real> Mathematics::Algebra::HomogeneousProject(const Matrix<N, N, Real>& matrix)
{
    Matrix<N - 1, N - 1, Real> result{};

    for (auto row = 0; row < N - 1; ++row)
    {
        for (auto column = 0; column < N - 1; ++column)
        {
            result(row, column) = matrix(row, column);
        }
    }

    return result;
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_DETAIL_H
