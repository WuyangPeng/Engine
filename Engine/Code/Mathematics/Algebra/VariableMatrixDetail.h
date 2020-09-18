// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.5 (2020/03/19 15:34)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_DETAIL_H
#define MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_DETAIL_H

#include "VariableMatrix.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VARIABLE_MATRIX_DETAIL)

    #include "Matrix2Detail.h"
    #include "Matrix3Detail.h"
    #include "VariableLengthVector.h"
    #include "CoreTools/Helper/MemberFunctionMacro.h"
    #include "CoreTools/Helper/MemoryMacro.h"
    #include "Mathematics/Base/MathDetail.h"

    #include "System/Helper/PragmaWarning.h"
    #include "System/Helper/PragmaWarning/NumericCast.h"
    #include "CoreTools/Helper/ExceptionMacro.h"

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)
    #include SYSTEM_WARNING_DISABLE(26455)
    #include SYSTEM_WARNING_DISABLE(26489)
    #include SYSTEM_WARNING_DISABLE(26487)
    #include SYSTEM_WARNING_DISABLE(26481)
    #include SYSTEM_WARNING_DISABLE(26488)
 #include SYSTEM_WARNING_DISABLE(26409)
 #include SYSTEM_WARNING_DISABLE(26492)
 
    #include SYSTEM_WARNING_DISABLE(26456)
template <typename Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(int rowsNumber, int columnsNumber)
    : m_RowsNumber{ rowsNumber }, m_ColumnsNumber{ columnsNumber }, m_ElementsNumber{ m_RowsNumber * m_ColumnsNumber },
      m_Entry{ 0 < m_ElementsNumber ? NEW2<Real>(m_ColumnsNumber, m_RowsNumber) : nullptr }
{
    if (0 < m_ElementsNumber)
    {
        memset(m_Entry[0], 0, m_ElementsNumber * sizeof(Real));
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(int rowsNumber, int columnsNumber, const std::vector<Real>& entry)
    : m_RowsNumber{ rowsNumber }, m_ColumnsNumber{ columnsNumber },
      m_ElementsNumber{ m_RowsNumber * m_ColumnsNumber }, m_Entry{ 0 < m_ElementsNumber ? NEW2<Real>(m_ColumnsNumber, m_RowsNumber) : nullptr }
{
    MATHEMATICS_ASSERTION_0(entry.size() == boost::numeric_cast<size_t>(m_ElementsNumber), "传入的数据大小不符合！");

    if (0 < m_ElementsNumber)
    {
        memcpy(m_Entry[0], &entry[0], m_ElementsNumber * sizeof(Real));
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(int rowsNumber, int columnsNumber, const std::vector<std::vector<Real>>& matrix)
    : m_RowsNumber{ rowsNumber }, m_ColumnsNumber{ columnsNumber },
      m_ElementsNumber{ m_RowsNumber * m_ColumnsNumber }, m_Entry{ 0 < m_ElementsNumber ? NEW2<Real>(m_ColumnsNumber, m_RowsNumber) : nullptr }
{
    MATHEMATICS_ASSERTION_0(matrix.size() == boost::numeric_cast<size_t>(m_RowsNumber), "传入的数据行数不符合！");

    if (0 < m_ElementsNumber)
    {
        for (auto row = 0u; row < matrix.size(); ++row)
        {
            MATHEMATICS_ASSERTION_0(matrix[row].size() == boost::numeric_cast<size_t>(m_ColumnsNumber), "传入的数据列数不符合！");

            memcpy(m_Entry[row], &matrix[row][0], matrix[row].size() * sizeof(Real));
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(const VariableMatrix& rhs)
    : m_RowsNumber{ rhs.m_RowsNumber }, m_ColumnsNumber{ rhs.m_ColumnsNumber },
      m_ElementsNumber{ m_RowsNumber * m_ColumnsNumber }, m_Entry{ 0 < m_ElementsNumber ? NEW2<Real>(m_ColumnsNumber, m_RowsNumber) : nullptr }
{
    if (0 < m_ElementsNumber)
    {
        memcpy(m_Entry[0], rhs.m_Entry[0], m_ElementsNumber * sizeof(Real));
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(const Matrix3& rhs)
    : m_RowsNumber{ 3 }, m_ColumnsNumber{ 3 },
      m_ElementsNumber{ m_RowsNumber * m_ColumnsNumber }, m_Entry{ 0 < m_ElementsNumber ? NEW2<Real>(m_ColumnsNumber, m_RowsNumber) : nullptr }
{
    if (0 < m_ElementsNumber)
    {
        memcpy(m_Entry[0], rhs[0], m_ElementsNumber * sizeof(Real));
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::VariableMatrix<Real>::VariableMatrix(const Matrix2& rhs)
    : m_RowsNumber{ 2 }, m_ColumnsNumber{ 2 },
      m_ElementsNumber{ m_RowsNumber * m_ColumnsNumber }, m_Entry{ 0 < m_ElementsNumber ? NEW2<Real>(m_ColumnsNumber, m_RowsNumber) : nullptr }
{
    if (0 < m_ElementsNumber)
    {
        memcpy(m_Entry[0], rhs[0], m_ElementsNumber * sizeof(Real));
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator=(const VariableMatrix& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    VariableMatrix<Real> result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real>
void Mathematics::VariableMatrix<Real>::Swap(VariableMatrix& rhs) noexcept
{
    std::swap(m_ColumnsNumber, rhs.m_ColumnsNumber);
    std::swap(m_RowsNumber, rhs.m_RowsNumber);

    m_ElementsNumber = m_RowsNumber * m_ColumnsNumber;
    rhs.m_ElementsNumber = rhs.m_RowsNumber * rhs.m_ColumnsNumber;

    std::swap(m_Entry, rhs.m_Entry);
}

template <typename Real>
Mathematics::VariableMatrix<Real>::~VariableMatrix()
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;

    EXCEPTION_TRY
    {
        #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26447)
        DELETE2<Real>(m_Entry);
        #include STSTEM_WARNING_POP
    }
    EXCEPTION_ALL_CATCH(Mathematics)
}

    #ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::VariableMatrix<Real>::IsValid() const noexcept
{
    if (m_ColumnsNumber < 0 || m_RowsNumber < 0 || m_ElementsNumber < 0 || m_ColumnsNumber * m_RowsNumber != m_ElementsNumber)
        return false;
    else if (0 < m_ElementsNumber && m_Entry != nullptr)
        return true;
    else if (m_ElementsNumber == 0 && m_Entry == nullptr)
        return true;
    else
        return false;
}
    #endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::VariableMatrix<Real>::SetIdentity()
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(m_RowsNumber == m_ColumnsNumber, "可变矩阵不是方阵！");

    CoreTools::DoNothing();

    for (auto i = 0; i < m_RowsNumber; ++i)
    {
        m_Entry[i][i] = Math::GetValue(1);
    }
}

template <typename Real>
void Mathematics::VariableMatrix<Real>::ResetSize(int rowsNumber, int columnsNumber)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    VariableMatrix<Real> result{ rowsNumber, columnsNumber };

    Swap(result);
}

template <typename Real>
int Mathematics::VariableMatrix<Real>::GetRowsNumber() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RowsNumber;
}

template <typename Real>
int Mathematics::VariableMatrix<Real>::GetColumnsNumber() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_ColumnsNumber;
}

template <typename Real>
int Mathematics::VariableMatrix<Real>::GetElementsNumber() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_ElementsNumber;
}

template <typename Real>
std::vector<Real> Mathematics::VariableMatrix<Real>::GetValue() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    std::vector<Real> result;

     for (auto rows = 0; rows < m_RowsNumber; ++rows)
    {
        for (auto columns = 0; columns < m_ColumnsNumber; ++columns)
        {
            result.emplace_back(m_Entry[rows][columns]);
        }
    }

    return result;
}

template <typename Real>
const Real* Mathematics::VariableMatrix<Real>::GetElements() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (m_Entry != nullptr)
    {
        return m_Entry[0];
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵大小为零！"s));
    }
}

template <typename Real>
Real* Mathematics::VariableMatrix<Real>::GetElements()
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(m_Entry != nullptr, "矩阵大小为零！");

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(Real*, GetElements);
}

template <typename Real>
const Real* Mathematics::VariableMatrix<Real>::operator[](int row) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    #ifdef MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE
    MATHEMATICS_ASSERTION_0(0 <= row && row < m_RowsNumber, "索引错误！");
    #endif  // MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE

    return m_Entry[row];
}

template <typename Real>
Real* Mathematics::VariableMatrix<Real>::operator[](int row)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    #ifdef MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE
    MATHEMATICS_ASSERTION_0(0 <= row && row < m_RowsNumber, "索引错误！");
    #endif  // MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE

    return OPERATOR_SQUARE_BRACKETS_TO_POINTER(Real, row);
}

template <typename Real>
const Real& Mathematics::VariableMatrix<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    #ifdef MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE
    MATHEMATICS_ASSERTION_0(0 <= row && row < m_RowsNumber && 0 <= column && column < m_ColumnsNumber, "索引错误！");
    #endif  // MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE

    return m_Entry[row][column];
}

template <typename Real>
Real& Mathematics::VariableMatrix<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    #ifdef MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE
    MATHEMATICS_ASSERTION_0(0 <= row && row < m_RowsNumber && 0 <= column && column < m_ColumnsNumber, "索引错误！");
    #endif  // MATHEMATICS_ASSERT_VARIABLE_MATRIX_OUT_OF_RANGE

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));
}

template <typename Real>
void Mathematics::VariableMatrix<Real>::SetRow(int row, const VariableLengthVector& vector)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_0(0 <= row && row < m_RowsNumber, "索引错误！");
    MATHEMATICS_ASSERTION_0(vector.GetSize() == m_ColumnsNumber, "向量大小与矩阵列数不相等！");

    for (auto columns = 0; columns < m_ColumnsNumber; ++columns)
    {
        m_Entry[row][columns] = vector[columns];
    }
}

template <typename Real>
typename const Mathematics::VariableMatrix<Real>::VariableLengthVector
    Mathematics::VariableMatrix<Real>::GetRow(int row) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= row && row < m_RowsNumber, "索引错误！");

    VariableLengthVector vector{ m_ColumnsNumber };

    for (auto columns = 0; columns < m_ColumnsNumber; ++columns)
    {
        vector[columns] = m_Entry[row][columns];
    }

    return vector;
}

template <typename Real>
void Mathematics::VariableMatrix<Real>::SetColumn(int column, const VariableLengthVector& vector)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_0(0 <= column && column < m_ColumnsNumber, "索引错误！");
    MATHEMATICS_ASSERTION_1(vector.GetSize() == m_RowsNumber, "向量大小与矩阵行数不相等！");

    for (auto rows = 0; rows < m_RowsNumber; ++rows)
    {
        m_Entry[rows][column] = vector[rows];
    }
}

template <typename Real>
typename const Mathematics::VariableMatrix<Real>::VariableLengthVector
    Mathematics::VariableMatrix<Real>::GetColumn(int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= column && column < m_ColumnsNumber, "索引错误！");

    VariableLengthVector vector{ m_RowsNumber };

    for (auto rows = 0; rows < m_RowsNumber; ++rows)
    {
        vector[rows] = m_Entry[rows][column];
    }

    return vector;
}

template <typename Real>
void Mathematics::VariableMatrix<Real>::ResetMatrix(int rowsNumber, int columnsNumber, const std::vector<Real>& entry)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    VariableMatrix<Real> result{ rowsNumber, columnsNumber, entry };

    Swap(result);
}

template <typename Real>
void Mathematics::VariableMatrix<Real>::ResetMatrix(int rowsNumber, int columnsNumber, const std::vector<std::vector<Real>>& matrix)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    VariableMatrix<Real> result{ rowsNumber, columnsNumber, matrix };

    Swap(result);
}

template <typename Real>
void Mathematics::VariableMatrix<Real>::SwapRows(int firstRow, int secondRow)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_0(0 <= firstRow && firstRow < m_RowsNumber && 0 <= secondRow && secondRow < m_RowsNumber, "索引错误！");

    if (firstRow != secondRow)
    {
        for (auto columns = 0; columns < m_ColumnsNumber; ++columns)
        {
            std::swap(m_Entry[firstRow][columns], m_Entry[secondRow][columns]);
        }
    }
}

template <typename Real>
void Mathematics::VariableMatrix<Real>::SwapColumns(int firstColumns, int secondColumns)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_0(0 <= firstColumns && firstColumns < m_ColumnsNumber && 0 <= secondColumns && secondColumns < m_ColumnsNumber, "索引错误！");

    if (firstColumns != secondColumns)
    {
        for (auto rows = 0; rows < m_RowsNumber; ++rows)
        {
            std::swap(m_Entry[rows][firstColumns], m_Entry[rows][secondColumns]);
        }
    }
}

template <typename Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator*=(const VariableMatrix& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_1(m_ColumnsNumber == rhs.m_RowsNumber, "矩阵大小不匹配！\n");

    *this = *this * rhs;

    return *this;
}

template <typename Real>
const Mathematics::VariableMatrix<Real> Mathematics::VariableMatrix<Real>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    VariableMatrix<Real> result{ m_RowsNumber, m_ColumnsNumber };

    for (auto rows = 0; rows < m_RowsNumber; ++rows)
    {
        for (auto columns = 0; columns < m_ColumnsNumber; ++columns)
        {
            result.m_Entry[rows][columns] = -m_Entry[rows][columns];
        }
    }

    return result;
}

template <typename Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator+=(const VariableMatrix& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_0(m_ColumnsNumber == rhs.m_ColumnsNumber && m_RowsNumber == rhs.m_RowsNumber, "矩阵大小不匹配！\n");

    for (auto rows = 0; rows < m_RowsNumber; ++rows)
    {
        for (auto columns = 0; columns < m_ColumnsNumber; ++columns)
        {
            m_Entry[rows][columns] += rhs.m_Entry[rows][columns];
        }
    }

    return *this;
}

template <typename Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator-=(const VariableMatrix& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_0(m_ColumnsNumber == rhs.m_ColumnsNumber && m_RowsNumber == rhs.m_RowsNumber, "矩阵大小不匹配！\n");

    for (auto rows = 0; rows < m_RowsNumber; ++rows)
    {
        for (auto columns = 0; columns < m_ColumnsNumber; ++columns)
        {
            m_Entry[rows][columns] -= rhs.m_Entry[rows][columns];
        }
    }

    return *this;
}

template <typename Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator*=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto rows = 0; rows < m_RowsNumber; ++rows)
    {
        for (auto columns = 0; columns < m_ColumnsNumber; ++columns)
        {
            m_Entry[rows][columns] *= scalar;
        }
    }

    return *this;
}

template <typename Real>
Mathematics::VariableMatrix<Real>& Mathematics::VariableMatrix<Real>::operator/=(Real scalar) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::GetZeroTolerance() < scalar)
    {
        for (auto rows = 0; rows < m_RowsNumber; ++rows)
        {
            for (auto columns = 0; columns < m_ColumnsNumber; ++columns)
            {
                m_Entry[rows][columns] /= scalar;
            }
        }
    }
    else
    {
        for (auto rows = 0; rows < m_RowsNumber; ++rows)
        {
            for (auto columns = 0; columns < m_ColumnsNumber; ++columns)
            {
                m_Entry[rows][columns] = Math::sm_MaxReal;
            }
        }
    }

    return *this;
}

template <typename Real>
Real Mathematics::VariableMatrix<Real>::QuadraticForm(const VariableLengthVector& firstVector, const VariableLengthVector& secondVector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(firstVector.GetSize() == m_RowsNumber && secondVector.GetSize() == m_ColumnsNumber, "QuadraticForm中大小不匹配！\n");

    return Dot(firstVector, (*this) * secondVector);
}

template <typename Real>
const Mathematics::VariableMatrix<Real> Mathematics::VariableMatrix<Real>::Transpose() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    VariableMatrix<Real> result{ m_ColumnsNumber, m_RowsNumber };

    for (auto rows = 0; rows < m_RowsNumber; ++rows)
    {
        for (auto columns = 0; columns < m_ColumnsNumber; ++columns)
        {
            result.m_Entry[columns][rows] = m_Entry[rows][columns];
        }
    }

    return result;
}

template <typename Real>
typename const Mathematics::VariableMatrix<Real>::Matrix3 Mathematics::VariableMatrix<Real>::GetMatrix3() const
{
    MATHEMATICS_ASSERTION_1(GetRowsNumber() == GetColumnsNumber() && GetRowsNumber() == 3, "矩阵不是Matrix3\n");

    CoreTools::DoNothing();

    return Matrix3{ m_Entry[0][0], m_Entry[0][1], m_Entry[0][2],
                    m_Entry[1][0], m_Entry[1][1], m_Entry[1][2],
                    m_Entry[2][0], m_Entry[2][1], m_Entry[2][2] };
}

    #include STSTEM_WARNING_POP

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VARIABLE_MATRIX_DETAIL)

template <typename Real>
bool Mathematics ::operator==(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    MATHEMATICS_ASSERTION_1(lhs.GetColumnsNumber() == rhs.GetColumnsNumber() && lhs.GetRowsNumber() == rhs.GetRowsNumber(), "矩阵大小不同！");

    return memcmp(lhs[0], rhs[0], sizeof(Real) * lhs.GetElementsNumber()) == 0;
}

template <typename Real>
bool Mathematics ::operator<(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    MATHEMATICS_ASSERTION_1(lhs.GetColumnsNumber() == rhs.GetColumnsNumber() && lhs.GetRowsNumber() == rhs.GetRowsNumber(), "矩阵大小不同！");

    return memcmp(lhs[0], rhs[0], sizeof(Real) * lhs.GetElementsNumber()) < 0;
}

template <typename Real>
const Mathematics::VariableMatrix<Real> Mathematics ::operator*(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    // 'this' 是 Real x N, 'M' 是 N x C, '乘积 = this * M' 是 Real x C
    MATHEMATICS_ASSERTION_1(lhs.GetColumnsNumber() == rhs.GetRowsNumber(), "矩阵大小不匹配！\n");

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
const Mathematics::VariableLengthVector<Real> Mathematics ::operator*(const VariableMatrix<Real>& matrix, const VariableLengthVector<Real>& vector)
{
    MATHEMATICS_ASSERTION_1(vector.GetSize() == matrix.GetColumnsNumber(), "向量和矩阵的大小不匹配在 operator*\n");
 #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26481)
    VariableLengthVector<Real> product{ matrix.GetRowsNumber() };

    for (auto rows = 0; rows < matrix.GetRowsNumber(); ++rows)
    {
        for (auto columns = 0; columns < matrix.GetColumnsNumber(); ++columns)
        {
            product[rows] += matrix[rows][columns] * vector[columns];
        }
    }
 #include STSTEM_WARNING_POP
    return product;
}

template <typename Real>
const Mathematics::VariableLengthVector<Real> Mathematics ::operator*(const VariableLengthVector<Real>& vector, const VariableMatrix<Real>& matrix)
{
    MATHEMATICS_ASSERTION_1(vector.GetSize() == matrix.GetRowsNumber(), "向量和矩阵的大小不匹配在 operator*\n");

    VariableLengthVector<Real> product{ matrix.GetColumnsNumber() };

    for (auto columns = 0; columns < matrix.GetColumnsNumber(); ++columns)
    {
        for (auto rows = 0; rows < matrix.GetRowsNumber(); ++rows)
        {
            product[columns] += vector[rows] * matrix[rows][columns];
        }
    }

    return product;
}

template <typename Real>
const Mathematics::VariableMatrix<Real> Mathematics ::TransposeTimes(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    // P = A^T * B, P[r][c] = sum_m A[m][r] * B[m][c]
    MATHEMATICS_ASSERTION_1(lhs.GetRowsNumber() == rhs.GetRowsNumber(), "矩阵的大小不匹配在 TransposeTimes\n");

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
const Mathematics::VariableMatrix<Real> Mathematics ::TimesTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    // P = A * B^T, P[r][c] = sum_m A[r][m] * B[c][m]
    MATHEMATICS_ASSERTION_1(lhs.GetColumnsNumber() == rhs.GetColumnsNumber(), "矩阵的大小不匹配在 TimesTranspose\n");

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
    Mathematics ::TransposeTimesTranspose(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    // P = A * B^T, P[r][c] = sum_m A[m][r] * B[c][m]
    MATHEMATICS_ASSERTION_1(lhs.GetRowsNumber() == rhs.GetColumnsNumber(), "矩阵的大小不匹配在 TransposeTimesTranspose\n");

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
bool Mathematics ::Approximate(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs, const Real epsilon)
{
    MATHEMATICS_ASSERTION_1(lhs.GetRowsNumber() == rhs.GetRowsNumber(), "矩阵row不同。");
    MATHEMATICS_ASSERTION_1(lhs.GetColumnsNumber() == rhs.GetColumnsNumber(), "矩阵column不同。");

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
bool Mathematics ::Approximate(const VariableMatrix<Real>& lhs, const VariableMatrix<Real>& rhs)
{
    return Approximate(lhs, rhs, Math<Real>::GetZeroTolerance());
}

template <typename Real>
std::ostream& Mathematics ::operator<<(std::ostream& outFile, const VariableMatrix<Real>& matrix)
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
