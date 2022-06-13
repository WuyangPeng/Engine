///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/15 11:20)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_DETAIL_H

#include "SparseMatrix.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::SparseMatrix<Real>::SparseMatrix(int rowsNumber, int columnsNumber)
    : rowsNumber{ rowsNumber }, columnsNumber{ columnsNumber }, sparseMatrixEntry{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::SparseMatrix<Real>::IsValid() const noexcept
{
    if (0 < rowsNumber && 0 < columnsNumber)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::SparseMatrix<Real>::GetRowsNumber() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rowsNumber;
}

template <typename Real>
int Mathematics::SparseMatrix<Real>::GetColumnsNumber() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return columnsNumber;
}

template <typename Real>
const Real& Mathematics::SparseMatrix<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= row && row < rowsNumber, "row索引错误！");
    MATHEMATICS_ASSERTION_0(0 <= column && column < columnsNumber, "column索引错误！");

    const auto iter = sparseMatrixEntry.find(SparseMatrixIndex{ row, column });

    if (iter != sparseMatrixEntry.cend())
    {
        return iter->second;
    }
    else
    {
        static constexpr auto zero = Math::GetValue(0);

        MATHEMATICS_ASSERTION_0(Math::Approximate(zero, Math::GetValue(0), Math::GetZeroTolerance()), "静态const变量被修改！");

        return zero;
    }
}

template <typename Real>
Real& Mathematics::SparseMatrix<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_0(0 <= row && row < rowsNumber, "row索引错误！");
    MATHEMATICS_ASSERTION_0(0 <= column && column < columnsNumber, "column索引错误！");

    return sparseMatrixEntry[SparseMatrixIndex{ row, column }];
}

template <typename Real>
typename Mathematics::SparseMatrix<Real>::ConstIter Mathematics::SparseMatrix<Real>::GetBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ConstIter{ sparseMatrixEntry.begin() };
}

template <typename Real>
typename Mathematics::SparseMatrix<Real>::ConstIter Mathematics::SparseMatrix<Real>::GetEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ConstIter{ sparseMatrixEntry.end() };
}

template <typename Real>
const Mathematics::VariableLengthVector<Real> Mathematics::operator*(const SparseMatrix<Real>& matrix, const VariableLengthVector<Real>& vector)
{
    VariableLengthVector<Real> result{ vector.GetSize() };

    for (auto iter = matrix.GetBegin(); iter != matrix.GetEnd(); ++iter)
    {
        const auto row = iter.GetKey().GetRow();
        const auto column = iter.GetKey().GetColumn();
        const auto value = iter.GetMapped();
        result[row] += value * vector[column];
        if (row != column)
        {
            result[column] += value * vector[row];
        }
    }

    return result;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_DETAIL_H
