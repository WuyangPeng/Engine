///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 11:09)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_DETAIL_H
#define MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_DETAIL_H

#include "Matrix2Detail.h"
#include "Matrix3Detail.h"
#include "VariableLengthVectorDetail.h"
#include "VariableMatrix.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(int rowsNumber, int columnsNumber)
    : container(rowsNumber, VariableLengthVector{ columnsNumber })
{
    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(int rowsNumber, int columnsNumber, const ContainerType& entry)
    : container{}
{
    SetContainer(rowsNumber, columnsNumber, entry);

    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(const VectorContainerType& matrix)
    : container{ matrix }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(const Matrix2& rhs)
    : container{}
{
    for (auto row = 0; row < Matrix2::vectorSize; ++row)
    {
        typename VariableLengthVector::ContainerType variableLengthVector{};

        for (int column = 0; column < Matrix2::vectorSize; ++column)
        {
            variableLengthVector.emplace_back(rhs(row, column));
        }

        container.emplace_back(variableLengthVector);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(const Matrix3& rhs)
    : container{}
{
    for (auto row = 0; row < Matrix3::vectorSize; ++row)
    {
        typename VariableLengthVector::ContainerType variableLengthVector{};

        for (int column = 0; column < Matrix3::vectorSize; ++column)
        {
            variableLengthVector.emplace_back(rhs(row, column));
        }

        container.emplace_back(variableLengthVector);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::VariableMatrix<Real>::IsValid() const noexcept
{
    try
    {
        auto size = -1;
        for (const auto& value : container)
        {
            if (size == -1)
            {
                size = value.GetSize();
            }

            if (value.GetSize() != size)
            {
                return false;
            }
        }

        return true;
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableMatrix<Real>::ResetSize(int rowsNumber, int columnsNumber)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    if (rowsNumber < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("rowsNumber为负数！"s))
    }

    if (columnsNumber < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("columnsNumber为负数！"s))
    }

    container.clear();
    container.resize(rowsNumber, VariableLengthVector{ columnsNumber });
    container.shrink_to_fit();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::VariableMatrix<Real>::GetRowsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return boost::numeric_cast<int>(container.size());
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::VariableMatrix<Real>::GetColumnsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    if (container.empty())
    {
        return 0;
    }
    else
    {
        return container.begin()->GetSize();
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::VariableMatrix<Real>::GetElementsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return GetRowsNumber() * GetColumnsNumber();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Mathematics::VariableLengthVector<Real>& Mathematics::VariableMatrix<Real>::operator[](int row) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return container.at(row);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableMatrix<Real>::operator[](int row)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    return OPERATOR_SQUARE_BRACKETS(VariableLengthVector, row);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::VariableMatrix<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return (*this)[row][column];
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::VariableMatrix<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_3;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include SYSTEM_WARNING_POP
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::VariableMatrix<Real>::ContainerType Mathematics::VariableMatrix<Real>::GetContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    ContainerType result{};

    for (const auto& vector : container)
    {
        result.insert(result.end(), vector.begin(), vector.end());
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableMatrix<Real>::SetContainer(int rowsNumber, int columnsNumber, const ContainerType& entry)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    const auto size = rowsNumber * columnsNumber;

    if (size != boost::numeric_cast<int>(entry.size()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("可变矩阵大小错误。"s))
    }

    for (auto row = 0; row < rowsNumber; ++row)
    {
        typename VariableLengthVector::ContainerType variableLengthVector{};

        for (int column = 0; column < columnsNumber; ++column)
        {
            const auto index = row * columnsNumber + column;
            variableLengthVector.emplace_back(entry.at(index));
        }

        container.emplace_back(variableLengthVector);
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableMatrix<Real>::SetIdentity()
{
    MATHEMATICS_CLASS_IS_VALID_3;

    const auto rowsNumber = GetRowsNumber();
    const auto columnsNumber = GetColumnsNumber();

    if (rowsNumber != columnsNumber)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("可变矩阵不是方阵！"s))
    }

    for (auto rows = 0; rows < rowsNumber; ++rows)
    {
        for (auto columns = 0; columns < columnsNumber; ++columns)
        {
            if (rows == columns)
            {
                (*this)(rows, columns) = Math::GetValue(1);
            }
            else
            {
                (*this)(rows, columns) = Math::GetValue(0);
            }
        }
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableMatrix<Real>::SetRow(int row, const VariableLengthVector& vector)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    if (vector.GetSize() == GetColumnsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量大小与矩阵列数不相等！"s))
    }

    (*this)[row] = vector;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::VariableMatrix<Real>::VariableLengthVector Mathematics::VariableMatrix<Real>::GetRow(int row) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return container.at(row);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableMatrix<Real>::SetColumn(int column, const VariableLengthVector& vector)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    const auto rowsNumber = GetRowsNumber();

    if (vector.GetSize() == rowsNumber)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量大小与矩阵行数不相等！"s))
    }

    for (auto rows = 0; rows < rowsNumber; ++rows)
    {
        (*this)(rows, column) = vector[rows];
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::VariableMatrix<Real>::VariableLengthVector Mathematics::VariableMatrix<Real>::GetColumn(int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    const auto rowsNumber = GetRowsNumber();

    typename VariableLengthVector::ContainerType variableLengthVector{};

    for (auto rows = 0; rows < rowsNumber; ++rows)
    {
        variableLengthVector.emplace_back((*this)(rows, column));
    }

    return VariableLengthVector{ variableLengthVector };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableMatrix<Real>::ResetMatrix(const VectorContainerType& matrix)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    container = matrix;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableMatrix<Real>::SwapRows(int lhsRow, int rhsRow)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    if (lhsRow != rhsRow)
    {
        std::swap((*this)[lhsRow], (*this)[rhsRow]);
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableMatrix<Real>::SwapColumns(int lhsColumns, int rhsColumns)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    if (lhsColumns != rhsColumns)
    {
        for (auto rows = 0; rows < GetRowsNumber(); ++rows)
        {
            std::swap((*this)(rows, lhsColumns), (*this)(rows, rhsColumns));
        }
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator*=(const VariableMatrix& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    if (GetColumnsNumber() != rhs.GetRowsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵大小不匹配！"s))
    }

    *this = *this * rhs;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::VariableMatrix<Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    const auto rowsNumber = GetRowsNumber();
    const auto columnsNumber = GetColumnsNumber();

    ContainerType result{};

    for (auto rows = 0; rows < rowsNumber; ++rows)
    {
        for (auto columns = 0; columns < columnsNumber; ++columns)
        {
            result.emplace_back(-(*this)(rows, columns));
        }
    }

    return VariableMatrix{ rowsNumber, columnsNumber, result };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator+=(const VariableMatrix& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    const auto rowsNumber = GetRowsNumber();
    const auto columnsNumber = GetColumnsNumber();

    if (columnsNumber != rhs.GetColumnsNumber() || rowsNumber != rhs.GetRowsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵大小不匹配！"s))
    }

    for (auto rows = 0; rows < rowsNumber; ++rows)
    {
        for (auto columns = 0; columns < columnsNumber; ++columns)
        {
            (*this)(rows, columns) += rhs[rows][columns];
        }
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator-=(const VariableMatrix& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    const auto rowsNumber = GetRowsNumber();
    const auto columnsNumber = GetColumnsNumber();

    if (columnsNumber != rhs.GetColumnsNumber() || rowsNumber != rhs.GetRowsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵大小不匹配！"s))
    }

    for (auto rows = 0; rows < rowsNumber; ++rows)
    {
        for (auto columns = 0; columns < columnsNumber; ++columns)
        {
            (*this)(rows, columns) -= rhs[rows][columns];
        }
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator*=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    for (auto rows = 0; rows < GetRowsNumber(); ++rows)
    {
        for (auto columns = 0; columns < GetColumnsNumber(); ++columns)
        {
            (*this)[rows][columns] *= scalar;
        }
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator/=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    const auto rowsNumber = GetRowsNumber();
    const auto columnsNumber = GetColumnsNumber();

    if (Math::GetZeroTolerance() < scalar)
    {
        for (auto rows = 0; rows < rowsNumber; ++rows)
        {
            for (auto columns = 0; columns < columnsNumber; ++columns)
            {
                (*this)[rows][columns] /= scalar;
            }
        }
    }
    else
    {
        for (auto rows = 0; rows < rowsNumber; ++rows)
        {
            for (auto columns = 0; columns < columnsNumber; ++columns)
            {
                (*this)[rows][columns] = Math::maxReal;
            }
        }
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::VariableMatrix<Real>::QuadraticForm(const VariableLengthVector& vector0, const VariableLengthVector& vector1) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    if (vector0.GetSize() != GetRowsNumber() || vector1.GetSize() != GetColumnsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("QuadraticForm中大小不匹配！\n"s))
    }

    return Dot(vector0, (*this) * vector1);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::VariableMatrix<Real>::Transpose() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    const auto rowsNumber = GetRowsNumber();
    const auto columnsNumber = GetColumnsNumber();

    VariableMatrix<Real> result{ columnsNumber, rowsNumber };

    for (auto rows = 0; rows < rowsNumber; ++rows)
    {
        for (auto columns = 0; columns < columnsNumber; ++columns)
        {
            result(columns, rows) = (*this)(rows, columns);
        }
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::VariableMatrix<Real>::Matrix3 Mathematics::VariableMatrix<Real>::GetMatrix3() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    if (GetRowsNumber() != GetColumnsNumber() && GetRowsNumber() != Matrix3::matrixSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵不是Matrix3\n"s))
    }

    return Matrix3{ (*this)(0, 0),
                    (*this)(0, 1),
                    (*this)(0, 2),
                    (*this)(1, 0),
                    (*this)(1, 1),
                    (*this)(1, 2),
                    (*this)(2, 0),
                    (*this)(2, 1),
                    (*this)(2, 2) };
}

template <typename Real>
bool Mathematics::operator==(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    if (lhs.GetColumnsNumber() != rhs.GetColumnsNumber())
        return false;
    else if (lhs.GetRowsNumber() != rhs.GetRowsNumber())
        return false;

    return lhs.GetContainer() == rhs.GetContainer();
}

template <typename Real>
bool Mathematics::operator<(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    return lhs.GetContainer() < rhs.GetContainer();
}

template <typename Real>
Mathematics::VariableMatrix<Real> Mathematics::operator*(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    // 'this' 是 Real x N, 'M' 是 N x C, '乘积 = this * M' 是 Real x C
    if (lhs.GetColumnsNumber() != rhs.GetRowsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵大小不匹配！"s))
    }

    VariableMatrix<Real> result{ lhs.GetRowsNumber(), rhs.GetColumnsNumber() };

    for (auto rows = 0; rows < result.GetRowsNumber(); ++rows)
    {
        for (auto columns = 0; columns < result.GetColumnsNumber(); ++columns)
        {
            for (auto index = 0; index < lhs.GetColumnsNumber(); ++index)
            {
                result(rows, columns) += lhs(rows, index) * rhs(index, columns);
            }
        }
    }

    return result;
}

template <typename Real>
Mathematics::VariableLengthVector<Real> Mathematics::operator*(const VariableMatrix<Real>& matrix, const VariableLengthVector<Real>& vector)
{
    if (vector.GetSize() != matrix.GetColumnsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量和矩阵的大小不匹配在 operator*\n"s))
    }

    VariableLengthVector<Real> product{ matrix.GetRowsNumber() };

    for (auto rows = 0; rows < matrix.GetRowsNumber(); ++rows)
    {
        for (auto columns = 0; columns < matrix.GetColumnsNumber(); ++columns)
        {
            product[rows] += matrix(rows, columns) * vector[columns];
        }
    }

    return product;
}

template <typename Real>
Mathematics::VariableLengthVector<Real> Mathematics::operator*(const VariableLengthVector<Real>& vector, const VariableMatrix<Real>& matrix)
{
    if (vector.GetSize() != matrix.GetRowsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量和矩阵的大小不匹配在 operator*\n"s))
    }

    VariableLengthVector<Real> product{ matrix.GetColumnsNumber() };

    for (auto columns = 0; columns < matrix.GetColumnsNumber(); ++columns)
    {
        for (auto rows = 0; rows < matrix.GetRowsNumber(); ++rows)
        {
            product[columns] += vector[rows] * matrix(rows, columns);
        }
    }

    return product;
}

template <typename Real>
Mathematics::VariableMatrix<Real> Mathematics::TransposeTimes(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    // P = A^T * B, P[r][c] = sum_m A[m][r] * B[m][c]
    if (lhs.GetRowsNumber() != rhs.GetRowsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵的大小不匹配在 TransposeTimes\n"s))
    }

    VariableMatrix<Real> result{ lhs.GetColumnsNumber(), rhs.GetColumnsNumber() };
    for (auto rows = 0; rows < result.GetRowsNumber(); ++rows)
    {
        for (auto columns = 0; columns < result.GetColumnsNumber(); ++columns)
        {
            for (auto index = 0; index < lhs.GetRowsNumber(); ++index)
            {
                result(rows, columns) += lhs(index, rows) * rhs(index, columns);
            }
        }
    }
    return result;
}

template <typename Real>
Mathematics::VariableMatrix<Real> Mathematics::TimesTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    // P = A * B^T, P[r][c] = sum_m A[r][m] * B[c][m]
    if (lhs.GetColumnsNumber() != rhs.GetColumnsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵的大小不匹配在 TimesTranspose\n"s))
    }

    VariableMatrix<Real> result{ lhs.GetRowsNumber(), rhs.GetRowsNumber() };
    for (auto rows = 0; rows < result.GetRowsNumber(); ++rows)
    {
        for (auto columns = 0; columns < result.GetColumnsNumber(); ++columns)
        {
            for (auto index = 0; index < lhs.GetColumnsNumber(); ++index)
            {
                result(rows, columns) += lhs(rows, index) * rhs(columns, index);
            }
        }
    }

    return result;
}

template <typename Real>
Mathematics::VariableMatrix<Real> Mathematics::TransposeTimesTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    // P = A * B^T, P[r][c] = sum_m A[m][r] * B[c][m]
    if (lhs.GetRowsNumber() != rhs.GetColumnsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵的大小不匹配在 TransposeTimesTranspose\n"s))
    }

    VariableMatrix<Real> result{ lhs.GetColumnsNumber(), rhs.GetRowsNumber() };
    for (auto rows = 0; rows < result.GetRowsNumber(); ++rows)
    {
        for (auto columns = 0; columns < result.GetColumnsNumber(); ++columns)
        {
            for (auto index = 0; index < lhs.GetRowsNumber(); ++index)
            {
                result(rows, columns) += lhs(index, rows) * rhs(columns, index);
            }
        }
    }

    return result;
}

template <typename Real>
bool Mathematics::Approximate(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs, const Real epsilon)
{
    if (lhs.GetColumnsNumber() != rhs.GetColumnsNumber())
    {
        return false;
    }
    else if (lhs.GetRowsNumber() != rhs.GetRowsNumber())
    {
        return false;
    }

    for (auto row = 0; row < lhs.GetRowsNumber(); ++row)
    {
        for (auto column = 0; column < lhs.GetColumnsNumber(); ++column)
        {
            if (epsilon < Math<Real>::FAbs(lhs(row, column) - rhs(row, column)))
            {
                return false;
            }
        }
    }

    return true;
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const VariableMatrix<Real>& matrix)
{
    for (auto row = 0; row < matrix.GetRowsNumber(); ++row)
    {
        for (auto column = 0; column < matrix.GetColumnsNumber(); ++column)
        {
            outFile << "(" << row << "," << column << ")=" << matrix(row, column) << "　";
        }
    }

    return outFile;
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_DETAIL_H
