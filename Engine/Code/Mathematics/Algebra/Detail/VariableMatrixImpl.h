///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/11 11:10)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_IMPL_H
#define MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/AlgebraFwd.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE VariableMatrixImpl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = VariableMatrixImpl<Real>;
        using Math = Math<Real>;
        using Matrix2 = Matrix2<Real>;
        using Matrix3 = Matrix3<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;
        using ContainerType = std::vector<Real>;
        using VectorContainerType = std::vector<VariableLengthVector>;

    public:
        VariableMatrixImpl() noexcept;
        explicit VariableMatrixImpl(int rowsNumber, int columnsNumber);
        VariableMatrixImpl(int rowsNumber, int columnsNumber, const ContainerType& entry);
        explicit VariableMatrixImpl(const VectorContainerType& matrix);
        explicit VariableMatrixImpl(const Matrix3& rhs);
        explicit VariableMatrixImpl(const Matrix2& rhs);

        CLASS_INVARIANT_DECLARE;

        // 坐标访问
        int GetRowsNumber() const;
        int GetColumnsNumber() const;

        const VariableLengthVector& operator[](int row) const;
        VariableLengthVector& operator[](int row);
        const Real& operator()(int row, int column) const;
        Real& operator()(int row, int column);

        // 重新设置大小会清空原有数据。
        void ResetSize(int rowsNumber, int columnsNumber);

        const ContainerType GetContainer() const;
        void SetContainer(int rowsNumber, int columnsNumber, const ContainerType& container);

    private:
        VectorContainerType m_Container;
    };
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_IMPL_H
