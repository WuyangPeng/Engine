///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/26 10:17)

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
        using Math = Math<Real>;
        using ConstIter = SparseMatrixConstIterator<Real>;

    public:
        SparseMatrix(int rowsNumber, int columnsNumber);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetRowsNumber() const noexcept;
        [[nodiscard]] int GetColumnsNumber() const noexcept;

        [[nodiscard]] const Real& operator()(int row, int column) const;
        [[nodiscard]] Real& operator()(int row, int column);

        [[nodiscard]] const ConstIter GetBegin() const noexcept;
        [[nodiscard]] const ConstIter GetEnd() const noexcept;

    private:
        using SparseMatrixEntry = std::map<SparseMatrixIndex, Real>;

    private:
        int m_RowsNumber;
        int m_ColumnsNumber;
        SparseMatrixEntry m_SparseMatrixEntry;
    };

    // M * v (numColumns(matrix) = size(vector) 是必须的)
    template <typename Real>
    [[nodiscard]] const VariableLengthVector<Real> operator*(const SparseMatrix<Real>& matrix, const VariableLengthVector<Real>& vector);

    using FloatSparseMatrix = SparseMatrix<float>;
    using DoubleSparseMatrix = SparseMatrix<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SPARSE_MATRIX_H
