///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/11 15:52)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_DETAIL_H
#define MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_DETAIL_H

#include "VariableMatrix.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VARIABLE_MATRIX_ACHIEVE)

    #include "VariableMatrixAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VARIABLE_MATRIX_ACHIEVE)

template <typename Real>
bool Mathematics::operator==(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    if (lhs.GetColumnsNumber() != rhs.GetColumnsNumber())
        return false;
    else if (lhs.GetRowsNumber() == rhs.GetRowsNumber())
        return false;
    return lhs.GetContainer() == rhs.GetContainer();
}

template <typename Real>
bool Mathematics::operator<(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    return lhs.GetContainer() < rhs.GetContainer();
}

template <typename Real>
const Mathematics::VariableMatrix<Real> Mathematics::operator*(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    // 'this' 是 Real x N, 'M' 是 N x C, '乘积 = this * M' 是 Real x C
    if (lhs.GetColumnsNumber() != rhs.GetRowsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵大小不匹配！"s));
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
const Mathematics::VariableLengthVector<Real> Mathematics::operator*(const VariableMatrix<Real>& matrix, const VariableLengthVector<Real>& vector)
{
    if (vector.GetSize() != matrix.GetColumnsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量和矩阵的大小不匹配在 operator*\n"s));
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
const Mathematics::VariableLengthVector<Real> Mathematics::operator*(const VariableLengthVector<Real>& vector, const VariableMatrix<Real>& matrix)
{
    if (vector.GetSize() != matrix.GetRowsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量和矩阵的大小不匹配在 operator*\n"s));
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
const Mathematics::VariableMatrix<Real> Mathematics::TransposeTimes(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    // P = A^T * B, P[r][c] = sum_m A[m][r] * B[m][c]
    if (lhs.GetRowsNumber() != rhs.GetRowsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵的大小不匹配在 TransposeTimes\n"s));
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
const Mathematics::VariableMatrix<Real> Mathematics::TimesTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    // P = A * B^T, P[r][c] = sum_m A[r][m] * B[c][m]
    if (lhs.GetColumnsNumber() != rhs.GetColumnsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵的大小不匹配在 TimesTranspose\n"s));
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
const Mathematics::VariableMatrix<Real>
    Mathematics::TransposeTimesTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    // P = A * B^T, P[r][c] = sum_m A[m][r] * B[c][m]
    if (lhs.GetRowsNumber() != rhs.GetColumnsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵的大小不匹配在 TransposeTimesTranspose\n"s));
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
        return false;
    else if (lhs.GetRowsNumber() == rhs.GetRowsNumber())
        return false;

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
