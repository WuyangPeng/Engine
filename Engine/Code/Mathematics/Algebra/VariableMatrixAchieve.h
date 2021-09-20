///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/11 15:57)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_ACHIEVE_H

#include "Matrix2Detail.h"
#include "Matrix3Detail.h"
#include "VariableLengthVector.h"
#include "VariableMatrix.h"
#include "Detail/VariableMatrixImplDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
template <typename Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(int rowsNumber, int columnsNumber)
    : impl{ std::make_shared<ImplType>(rowsNumber, columnsNumber) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

template <typename Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(int rowsNumber, int columnsNumber, const ContainerType& entry)
    : impl{ std::make_shared<ImplType>(rowsNumber, columnsNumber, entry) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(const VectorContainerType& matrix)
    : impl{ std::make_shared<ImplType>(matrix) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(const Matrix2& rhs)
    : impl{ std::make_shared<ImplType>(rhs) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(const Matrix3& rhs)
    : impl{ std::make_shared<ImplType>(rhs) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(const VariableMatrix& rhs)
    : impl{ std::make_shared<ImplType>(*rhs.impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
template <typename Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator=(const VariableMatrix& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    VariableMatrix result{ rhs };

    Swap(result);

    return *this;
}
#include STSTEM_WARNING_POP

template <typename Real>
void Mathematics::VariableMatrix<Real>::Swap(VariableMatrix& rhs) noexcept
{
    ;

    std::swap(impl, rhs.impl);
}

template <typename Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(VariableMatrix&& rhs) noexcept
    : impl{ std::move(rhs.impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
template <typename Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator=(VariableMatrix&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    impl = std::move(rhs.impl);

    return *this;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::VariableMatrix<Real>::IsValid() const noexcept
{
    if (impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::VariableMatrix<Real>::ResetSize(int rowsNumber, int columnsNumber)
{
    ;

    return impl->ResetSize(rowsNumber, columnsNumber);
}

template <typename Real>
int Mathematics::VariableMatrix<Real>::GetRowsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetRowsNumber();
}

template <typename Real>
int Mathematics::VariableMatrix<Real>::GetColumnsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetColumnsNumber();
}

template <typename Real>
int Mathematics::VariableMatrix<Real>::GetElementsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return GetRowsNumber() * GetColumnsNumber();
}

template <typename Real>
const Mathematics::VariableLengthVector<Real>& Mathematics::VariableMatrix<Real>::operator[](int row) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#ifdef MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE
    MATHEMATICS_ASSERTION_0(0 <= row && row < GetRowsNumber(), "索引错误！");
#endif  // MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE

    return (*impl)[row];
}

template <typename Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableMatrix<Real>::operator[](int row)
{
    ;

#ifdef MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE
    MATHEMATICS_ASSERTION_0(0 <= row && row < GetRowsNumber(), "索引错误！");
#endif  // MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE

    return OPERATOR_SQUARE_BRACKETS(VariableLengthVector, row);
}

template <typename Real>
const Real& Mathematics::VariableMatrix<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#ifdef MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE
    MATHEMATICS_ASSERTION_0(0 <= row && row < GetRowsNumber() && 0 <= column && column < GetColumnsNumber(), "索引错误！");
#endif  // MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE

    return (*impl)(row, column);
}

template <typename Real>
Real& Mathematics::VariableMatrix<Real>::operator()(int row, int column)
{
    ;

#ifdef MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE
    MATHEMATICS_ASSERTION_0(0 <= row && row < GetRowsNumber() && 0 <= column && column < GetColumnsNumber(), "索引错误！");
#endif  // MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)
    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));
#include STSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::VariableMatrix<Real>::ContainerType Mathematics::VariableMatrix<Real>::GetContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return impl->GetContainer();
}

template <typename Real>
void Mathematics::VariableMatrix<Real>::SetContainer(int rowsNumber, int columnsNumber, const ContainerType& entry)
{
    ;

    return impl->SetContainer(rowsNumber, columnsNumber, entry);
}

template <typename Real>
void Mathematics::VariableMatrix<Real>::SetIdentity()
{
    ;

    const auto rowsNumber = GetRowsNumber();
    const auto columnsNumber = GetColumnsNumber();

    if (rowsNumber != columnsNumber)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("可变矩阵不是方阵！"s));
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
void Mathematics::VariableMatrix<Real>::SetRow(int row, const VariableLengthVector& vector)
{
    ;

    if (vector.GetSize() == GetColumnsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量大小与矩阵列数不相等！"s));
    }

    (*impl)[row] = vector;
}

template <typename Real>
typename const Mathematics::VariableMatrix<Real>::VariableLengthVector Mathematics::VariableMatrix<Real>::GetRow(int row) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (*impl)[row];
}

template <typename Real>
void Mathematics::VariableMatrix<Real>::SetColumn(int column, const VariableLengthVector& vector)
{
    ;

    const auto rowsNumber = GetRowsNumber();

    if (vector.GetSize() == rowsNumber)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量大小与矩阵行数不相等！"s));
    }

    for (auto rows = 0; rows < rowsNumber; ++rows)
    {
        (*impl)(rows, column) = vector[rows];
    }
}

template <typename Real>
typename const Mathematics::VariableMatrix<Real>::VariableLengthVector Mathematics::VariableMatrix<Real>::GetColumn(int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto rowsNumber = GetRowsNumber();

    VariableLengthVector vector{ rowsNumber };

    for (auto rows = 0; rows < rowsNumber; ++rows)
    {
        vector[rows] = (*impl)(rows, column);
    }

    return vector;
}

template <typename Real>
void Mathematics::VariableMatrix<Real>::ResetMatrix(const VectorContainerType& matrix)
{
    ;

    VariableMatrix<Real> result{ matrix };

    Swap(result);
}

template <typename Real>
void Mathematics::VariableMatrix<Real>::SwapRows(int lhsRow, int rhsRow)
{
    ;

    if (lhsRow != rhsRow)
    {
        std::swap((*impl)[lhsRow], (*impl)[rhsRow]);
    }
}

template <typename Real>
void Mathematics::VariableMatrix<Real>::SwapColumns(int lhsColumns, int rhsColumns)
{
    ;

    if (lhsColumns != rhsColumns)
    {
        for (auto rows = 0; rows < GetRowsNumber(); ++rows)
        {
            std::swap((*impl)(rows, lhsColumns), (*impl)(rows, rhsColumns));
        }
    }
}

template <typename Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator*=(const VariableMatrix& rhs)
{
    ;

    if (GetColumnsNumber() != rhs.GetRowsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵大小不匹配！"s));
    }

    *this = *this * rhs;

    return *this;
}

template <typename Real>
const Mathematics::VariableMatrix<Real> Mathematics::VariableMatrix<Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto rowsNumber = GetRowsNumber();
    const auto columnsNumber = GetColumnsNumber();

    VariableMatrix<Real> result{ rowsNumber, columnsNumber };

    for (auto rows = 0; rows < rowsNumber; ++rows)
    {
        for (auto columns = 0; columns < columnsNumber; ++columns)
        {
            result(rows, columns) = -(*this)(rows, columns);
        }
    }

    return result;
}

template <typename Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator+=(const VariableMatrix& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    const auto rowsNumber = GetRowsNumber();
    const auto columnsNumber = GetColumnsNumber();

    if (columnsNumber != rhs.GetColumnsNumber() || rowsNumber != rhs.GetRowsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵大小不匹配！"s));
    }

    for (auto rows = 0; rows < rowsNumber; ++rows)
    {
        for (auto columns = 0; columns < columnsNumber; ++columns)
        {
            (*impl)(rows, columns) += rhs[rows][columns];
        }
    }

    return *this;
}

template <typename Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator-=(const VariableMatrix& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    const auto rowsNumber = GetRowsNumber();
    const auto columnsNumber = GetColumnsNumber();

    if (columnsNumber != rhs.GetColumnsNumber() || rowsNumber != rhs.GetRowsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵大小不匹配！"s));
    }

    for (auto rows = 0; rows < rowsNumber; ++rows)
    {
        for (auto columns = 0; columns < columnsNumber; ++columns)
        {
            (*impl)(rows, columns) -= rhs[rows][columns];
        }
    }

    return *this;
}

template <typename Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator*=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

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
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator/=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

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
                (*this)[rows][columns] = Math::sm_MaxReal;
            }
        }
    }

    return *this;
}

template <typename Real>
Real Mathematics::VariableMatrix<Real>::QuadraticForm(const VariableLengthVector& vector0, const VariableLengthVector& vector1) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (vector0.GetSize() != GetRowsNumber() || vector1.GetSize() != GetColumnsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("QuadraticForm中大小不匹配！\n"s));
    }

    return Dot(vector0, (*this) * vector1);
}

template <typename Real>
const Mathematics::VariableMatrix<Real> Mathematics::VariableMatrix<Real>::Transpose() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto rowsNumber = GetRowsNumber();
    const auto columnsNumber = GetColumnsNumber();

    VariableMatrix<Real> result{ columnsNumber, rowsNumber };

    for (auto rows = 0; rows < rowsNumber; ++rows)
    {
        for (auto columns = 0; columns < columnsNumber; ++columns)
        {
            result(columns, rows) = (*impl)(rows, columns);
        }
    }

    return result;
}

template <typename Real>
typename const Mathematics::VariableMatrix<Real>::Matrix3 Mathematics::VariableMatrix<Real>::GetMatrix3() const
{
    if (GetRowsNumber() != GetColumnsNumber() && GetRowsNumber() != Matrix3::sm_MatrixSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵不是Matrix3\n"s));
    }

    return Matrix3{ (*this)(0, 0), (*this)(0, 1), (*this)(0, 2),
                    (*this)(1, 0), (*this)(1, 1), (*this)(1, 2),
                    (*this)(2, 0), (*this)(2, 1), (*this)(2, 2) };
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_ACHIEVE_H
