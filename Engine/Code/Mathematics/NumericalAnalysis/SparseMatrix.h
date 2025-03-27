/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 13:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "SparseMatrixConstIteratorDetail.h"
#include "SparseMatrixIndex.h"
#include "Mathematics/Algebra/VariableLengthVector.h"

#include <map>

namespace Mathematics
{
    template <typename Real>
    class SparseMatrix final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = SparseMatrix<Real>;
        using MathType = Math<Real>;
        using ConstIter = SparseMatrixConstIterator<Real>;

    public:
        SparseMatrix(int rowsNumber, int columnsNumber);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetRowsNumber() const noexcept;
        NODISCARD int GetColumnsNumber() const noexcept;

        NODISCARD const Real& operator()(int row, int column) const;
        NODISCARD Real& operator()(int row, int column);

        NODISCARD ConstIter GetBegin() const noexcept;
        NODISCARD ConstIter GetEnd() const noexcept;

    private:
        using SparseMatrixEntry = std::map<SparseMatrixIndex, Real>;

    private:
        int rowsNumber;
        int columnsNumber;
        SparseMatrixEntry sparseMatrixEntry;
    };

    // M * v (numColumns(matrix) = size(vector) 是必须的)
    template <typename Real>
    NODISCARD VariableLengthVector<Real> operator*(const SparseMatrix<Real>& matrix, const VariableLengthVector<Real>& vector);

    using SparseMatrixF = SparseMatrix<float>;
    using SparseMatrixD = SparseMatrix<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_H
