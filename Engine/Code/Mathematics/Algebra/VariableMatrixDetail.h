/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/05 14:17)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_DETAIL_H
#define MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_DETAIL_H

#include "Matrix2Detail.h"
#include "Matrix3Detail.h"
#include "VariableLengthVectorDetail.h"
#include "VariableMatrix.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/GaussianEliminationDetail.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(int rowsNumber, int columnsNumber)

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    : container(rowsNumber, VariableLengthVector{ columnsNumber })

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    : container(columnsNumber, VariableLengthVector{ rowsNumber })

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
{
    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(int rowsNumber, int columnsNumber, int row, int column)
    : VariableMatrix{ rowsNumber, columnsNumber }
{
    MakeUnit(row, column);

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
Mathematics::VariableMatrix<Real>::VariableMatrix(VectorContainerType matrix) noexcept
    : container{ std::move(matrix) }
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

        for (auto column = 0; column < Matrix2::vectorSize; ++column)
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

        for (auto column = 0; column < Matrix3::vectorSize; ++column)
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
        for (const auto& element : container)
        {
            if (size == -1)
            {
                size = element.GetSize();
            }

            if (element.GetSize() != size)
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
void Mathematics::VariableMatrix<Real>::SetSize(int rowsNumber, int columnsNumber)
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

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    container.resize(rowsNumber, VariableLengthVector{ columnsNumber });

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    container.resize(columnsNumber, VariableLengthVector{ rowsNumber });

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    container.shrink_to_fit();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::VariableMatrix<Real>::GetRowsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return boost::numeric_cast<int>(container.size());

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    if (container.empty())
    {
        return 0;
    }
    else
    {
        return container.begin()->GetSize();
    }

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::VariableMatrix<Real>::GetColumnsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    if (container.empty())
    {
        return 0;
    }
    else
    {
        return container.begin()->GetSize();
    }

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return boost::numeric_cast<int>(container.size());

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
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
const Real& Mathematics::VariableMatrix<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return container.at(index / GetColumnsNumber())[index % GetColumnsNumber()];

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return container.at(index / GetRowsNumber())[index % GetRowsNumber()];

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::VariableMatrix<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::VariableMatrix<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return container.at(row)[column];

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return container.at(column)[row];

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
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

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    for (auto row = 0; row < rowsNumber; ++row)
    {
        typename VariableLengthVector::ContainerType variableLengthVector{};

        for (auto column = 0; column < columnsNumber; ++column)
        {
            const auto index = row * columnsNumber + column;
            variableLengthVector.emplace_back(entry.at(index));
        }

        container.emplace_back(variableLengthVector);
    }

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    for (int column = 0; column < columnsNumber; ++column)
    {
        typename VariableLengthVector::ContainerType variableLengthVector{};

        for (auto row = 0; row < rowsNumber; ++row)
        {
            const auto index = column * rowsNumber + row;
            variableLengthVector.emplace_back(entry.at(index));
        }

        container.emplace_back(variableLengthVector);
    }

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableMatrix<Real>::SetRow(int row, const VariableLengthVector& vector)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    const auto columnsNumber = GetColumnsNumber();

    if (vector.GetSize() != columnsNumber)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量大小与矩阵列数不相等！"s))
    }

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    container.at(row) = vector;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    for (auto column = 0; column < columnsNumber; ++column)
    {
        (*this)(column, row) = vector[column];
    }

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::VariableMatrix<Real>::VariableLengthVector Mathematics::VariableMatrix<Real>::GetRow(int row) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return container.at(row);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    const auto columnsNumber = GetColumnsNumber()();

    typename VariableLengthVector::ContainerType variableLengthVector{};

    for (auto column = 0; column < GetColumnsNumber(); ++column)
    {
        variableLengthVector.emplace_back((*this)(column, row));
    }

    return VariableLengthVector{ variableLengthVector };

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableMatrix<Real>::SetColumn(int column, const VariableLengthVector& vector)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    const auto rowsNumber = GetRowsNumber();

    if (vector.GetSize() != rowsNumber)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量大小与矩阵行数不相等！"s))
    }

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    for (auto rows = 0; rows < rowsNumber; ++rows)
    {
        (*this)(rows, column) = vector[rows];
    }

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    container.at(column) = vector;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::VariableMatrix<Real>::VariableLengthVector Mathematics::VariableMatrix<Real>::GetColumn(int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    const auto rowsNumber = GetRowsNumber();

    typename VariableLengthVector::ContainerType variableLengthVector{};

    for (auto rows = 0; rows < rowsNumber; ++rows)
    {
        variableLengthVector.emplace_back((*this)(rows, column));
    }

    return VariableLengthVector{ variableLengthVector };

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return container.at(column);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
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
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

        std::swap(container.at(lhsRow), container.at(rhsRow));

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

        for (auto columns = 0; columns < GetColumnsNumber(); ++columns)
        {
            std::swap((*this)(lhsRow, columns), (*this)(rhsRow, columns));
        }

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableMatrix<Real>::SwapColumns(int lhsColumns, int rhsColumns)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    if (lhsColumns != rhsColumns)
    {
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

        for (auto rows = 0; rows < GetRowsNumber(); ++rows)
        {
            std::swap((*this)(rows, lhsColumns), (*this)(rows, rhsColumns));
        }

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

        std::swap(container.at(lhsColumns), container.at(rhsColumns));

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::VariableMatrix<Real>::Equal(const VariableMatrix& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    if (GetColumnsNumber() != rhs.GetColumnsNumber())
        return false;
    else if (GetRowsNumber() != rhs.GetRowsNumber())
        return false;

    auto index = 0;
    for (const auto& element : container)
    {
        if (element != rhs.container.at(index))
        {
            return false;
        }
        ++index;
    }

    return true;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::VariableMatrix<Real>::Less(const VariableMatrix& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    if (GetElementsNumber() < rhs.GetElementsNumber())
        return true;
    else if (rhs.GetElementsNumber() < GetElementsNumber())
        return false;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    else if (GetRowsNumber() < rhs.GetRowsNumber())
        return true;
    else if (rhs.GetRowsNumber() < GetRowsNumber())
        return false;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    else if (GetColumnsNumber() < rhs.GetColumnsNumber())
        return true;
    else if (rhs.GetColumnsNumber() < GetColumnsNumber())
        return false;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    auto index = 0;
    for (const auto& element : container)
    {
        if (element < rhs.container.at(index))
        {
            return true;
        }
        else if (rhs.container.at(index) < element)
        {
            return false;
        }
        ++index;
    }

    return false;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator*=(const VariableMatrix& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    *this = *this * rhs;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::VariableMatrix<Real>::operator+() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::VariableMatrix<Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    const auto rowsNumber = GetRowsNumber();
    const auto columnsNumber = GetColumnsNumber();

    VariableMatrix result{ rowsNumber, columnsNumber };

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    auto index = 0;
    for (const auto& element : container)
    {
        result.SetRow(index, -element);

        ++index;
    }

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    auto index = 0;
    for (const auto& element : container)
    {
        result.SetColumn(index, -element);

        ++index;
    }

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    return result;
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

    for (auto index = 0; index < GetElementsNumber(); ++index)
    {
        (*this)[index] += rhs[index];
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

    for (auto index = 0; index < GetElementsNumber(); ++index)
    {
        (*this)[index] -= rhs[index];
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator*=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    for (auto index = 0; index < GetElementsNumber(); ++index)
    {
        (*this)[index] *= scalar;
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator/=(Real scalar)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    if (Math::GetZeroTolerance() < scalar)
    {
        for (auto index = 0; index < GetElementsNumber(); ++index)
        {
            (*this)[index] /= scalar;
        }
    }
    else
    {
        MakeZero();
    }

    return *this;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::VariableMatrix<Real>::L1Norm() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    Real sum{};

    for (auto i = 0; i < GetElementsNumber(); ++i)
    {
        sum += Math::FAbs((*this)[i]);
    }

    return sum;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::VariableMatrix<Real>::L2Norm() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    Real sum{};

    for (auto i = 0; i < GetElementsNumber(); ++i)
    {
        sum += (*this)[i] * (*this)[i];
    }

    return Math::Sqrt(sum);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::VariableMatrix<Real>::LInfinityNorm() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    Real maxComponent{};

    for (auto i = 0; i < GetElementsNumber(); ++i)
    {
        const auto component = Math::FAbs((*this)[i]);
        if (maxComponent < component)
        {
            maxComponent = component;
        }
    }

    return maxComponent;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::VariableMatrix<Real>::Inverse(bool* reportInvertibility) const
{
    if (GetRowsNumber() != GetColumnsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵必须是正方形。"))
    }

    VariableMatrix inverse{ GetRowsNumber(), GetColumnsNumber() };

    GaussianElimination<Real> gaussianElimination{ GetRowsNumber(), GetContainer(), true };

    if (reportInvertibility)
    {
        *reportInvertibility = gaussianElimination.IsInverse();
    }

    inverse.SetContainer(GetRowsNumber(), GetColumnsNumber(), gaussianElimination.GetInverse());

    return inverse;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::VariableMatrix<Real>::Determinant() const
{
    if (GetRowsNumber() != GetColumnsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵必须是正方形。"))
    }

    GaussianElimination<Real> gaussianElimination{ GetRowsNumber(), GetContainer(), false };

    return gaussianElimination.GetDeterminant();
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

    VariableMatrix result{ columnsNumber, rowsNumber };

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
requires std::is_arithmetic_v<Real>
void Mathematics::VariableMatrix<Real>::MakeZero()
{
    MATHEMATICS_CLASS_IS_VALID_3;

    for (auto& element : container)
    {
        element.MakeZero();
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableMatrix<Real>::MakeUnit(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    MakeZero();

    if (0 <= row && row < GetRowsNumber() && 0 <= column && column < GetColumnsNumber())
    {
        operator()(row, column) = Math::GetValue(1);
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::VariableMatrix<Real>::MakeIdentity()
{
    MATHEMATICS_CLASS_IS_VALID_3;

    MakeZero();

    const auto numDiagonal = (GetRowsNumber() <= GetColumnsNumber() ? GetRowsNumber() : GetColumnsNumber());
    for (auto i = 0; i < numDiagonal; ++i)
    {
        operator()(i, i) = Math::GetValue(1);
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::VariableMatrix<Real>::Zero(int rowsNumber, int columnsNumber)
{
    return VariableMatrix{ rowsNumber, columnsNumber };
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::VariableMatrix<Real>::Unit(int rowsNumber, int columnsNumber, int row, int column)
{
    VariableMatrix result{ rowsNumber, columnsNumber };

    result.MakeUnit(row, column);

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::VariableMatrix<Real>::Identity(int rowsNumber, int columnsNumber)
{
    VariableMatrix result{ rowsNumber, columnsNumber };

    result.MakeIdentity();

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator==(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    return lhs.Equal(rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::operator<(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    return lhs.Less(rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::operator*(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    return Multiply(lhs, rhs);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::Multiply(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    /// 'this' 是 Real x N, 'M' 是 N x C, '乘积 = this * M' 是 Real x C
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
requires std::is_arithmetic_v<Real>
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
requires std::is_arithmetic_v<Real>
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
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::TransposeMultiply(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    /// P = A^T * B, P[r][c] = sum_m A[m][r] * B[m][c]
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
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::MultiplyTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    /// P = A * B^T, P[r][c] = sum_m A[r][m] * B[c][m]
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
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::TransposeMultiplyTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    /// P = A * B^T, P[r][c] = sum_m A[m][r] * B[c][m]
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
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::Multiply(const VariableMatrix<Real>& matrix, const VariableLengthVector<Real>& diagonal)
{
    if (diagonal.GetSize() != matrix.GetColumnsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量和矩阵的大小不匹配！"s))
    }

    VariableMatrix<Real> result{ matrix.GetRowsNumber(), matrix.GetColumnsNumber() };

    for (auto rows = 0; rows < result.GetRowsNumber(); ++rows)
    {
        for (auto columns = 0; columns < result.GetColumnsNumber(); ++columns)
        {
            result(rows, columns) += matrix(rows, columns) * diagonal[columns];
        }
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::Multiply(const VariableLengthVector<Real>& diagonal, const VariableMatrix<Real>& matrix)
{
    if (diagonal.GetSize() != matrix.GetRowsNumber())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("向量和矩阵的大小不匹配！"s))
    }

    VariableMatrix<Real> result{ matrix.GetRowsNumber(), matrix.GetColumnsNumber() };

    for (auto rows = 0; rows < result.GetRowsNumber(); ++rows)
    {
        for (auto columns = 0; columns < result.GetColumnsNumber(); ++columns)
        {
            result(rows, columns) += diagonal[columns] * matrix(rows, columns);
        }
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::OuterProduct(const VariableLengthVector<Real>& u, const VariableLengthVector<Real>& v)
{
    VariableMatrix<Real> result{ u.GetSize(), v.GetSize() };

    for (auto rows = 0; rows < result.GetRowsNumber(); ++rows)
    {
        for (auto columns = 0; columns < result.GetColumnsNumber(); ++columns)
        {
            result(rows, columns) = u[rows] * v[columns];
        }
    }

    return result;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::VariableMatrix<Real> Mathematics::MakeDiagonal(int rowsNumber, int columnsNumber, const VariableLengthVector<Real>& diagonal)
{
    VariableMatrix<Real> matrix{ rowsNumber, columnsNumber };
    const auto numDiagonal = (rowsNumber <= columnsNumber ? rowsNumber : columnsNumber);

    for (auto i = 0; i < numDiagonal; ++i)
    {
        matrix(i, i) = diagonal[i];
    }

    return matrix;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
bool Mathematics::Approximate(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs, Real epsilon)
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
requires std::is_arithmetic_v<Real>
std::ostream& Mathematics::operator<<(std::ostream& stream, const VariableMatrix<Real>& matrix)
{
    for (auto row = 0; row < matrix.GetRowsNumber(); ++row)
    {
        for (auto column = 0; column < matrix.GetColumnsNumber(); ++column)
        {
            stream << "(" << row << "," << column << ")=" << matrix(row, column) << "　";
        }
    }

    return stream;
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_DETAIL_H
