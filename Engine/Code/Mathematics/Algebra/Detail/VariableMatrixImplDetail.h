///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/11 11:12)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_IMPL_DETAIL_H
#define MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_IMPL_DETAIL_H

#include "VariableMatrixImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::VariableMatrixImpl<Real>::VariableMatrixImpl() noexcept
    : m_Container{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real>
Mathematics::VariableMatrixImpl<Real>::VariableMatrixImpl(int rowsNumber, int columnsNumber)
    : m_Container{ rowsNumber, VariableLengthVector{ columnsNumber } }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real>
Mathematics::VariableMatrixImpl<Real>::VariableMatrixImpl(int rowsNumber, int columnsNumber, const ContainerType& entry)
    : m_Container{}
{
    const auto size = rowsNumber * columnsNumber;

    if (size != boost::numeric_cast<int>(entry.size()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("可变矩阵大小错误。"s));
    }

    auto index = 0;
    for (auto i = 0; i < rowsNumber; ++i)
    {
        VariableLengthVector vector{ columnsNumber };

        for (auto& value : vector)
        {
            if (index == boost::numeric_cast<int>(entry.size()))
            {
                THROW_EXCEPTION(SYSTEM_TEXT("可变矩阵大小错误。"s));
            }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            value = entry[index];
#include STSTEM_WARNING_POP

            ++index;
        }

        m_Container.emplace_back(vector);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real>
Mathematics::VariableMatrixImpl<Real>::VariableMatrixImpl(const VectorContainerType& matrix)
    : m_Container{ matrix }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real>
Mathematics::VariableMatrixImpl<Real>::VariableMatrixImpl(const Matrix3& rhs)
    : m_Container{}
{
    for (auto row = 0; row < Matrix3::sm_MatrixSize; ++row)
    {
        VariableLengthVector vector{ Matrix3::sm_VectorSize };

        auto column = 0;
        for (auto& value : vector)
        {
            value = rhs(row, column);

            ++column;
        }

        m_Container.emplace_back(vector);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real>
Mathematics::VariableMatrixImpl<Real>::VariableMatrixImpl(const Matrix2& rhs)
    : m_Container{}
{
    for (auto row = 0; row < Matrix2::sm_MatrixSize; ++row)
    {
        VariableLengthVector vector{ Matrix2::sm_VectorSize };

        auto column = 0;
        for (auto& value : vector)
        {
            value = rhs(row, column);

            ++column;
        }

        m_Container.emplace_back(vector);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::VariableMatrixImpl<Real>::IsValid() const noexcept
{
    try
    {
        auto size = 0;
        for (const auto& value : m_Container)
        {
            if (size == 0)
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
int Mathematics::VariableMatrixImpl<Real>::GetRowsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return boost::numeric_cast<int>(m_Container.size());
}

template <typename Real>
int Mathematics::VariableMatrixImpl<Real>::GetColumnsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    if (m_Container.empty())
    {
        return 0;
    }
    else
    {
        return m_Container.begin()->GetSize();
    }
}

template <typename Real>
Mathematics::VariableLengthVector<Real>& Mathematics::VariableMatrixImpl<Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    return OPERATOR_SQUARE_BRACKETS(VariableLengthVector, index);
}

template <typename Real>
const Mathematics::VariableLengthVector<Real>& Mathematics::VariableMatrixImpl<Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return m_Container.at(index);
}

template <typename Real>
const Real& Mathematics::VariableMatrixImpl<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)
    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));
#include STSTEM_WARNING_POP
}

template <typename Real>
Real& Mathematics::VariableMatrixImpl<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    return m_Container.at(row)[column];
}

template <typename Real>
void Mathematics::VariableMatrixImpl<Real>::ResetSize(int rowsNumber, int columnsNumber)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    if (rowsNumber < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("rowsNumber为负数！"s));
    }

    if (columnsNumber < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("columnsNumber为负数！"s));
    }

    m_Container.clear();
    m_Container.resize(rowsNumber, VariableLengthVector{ columnsNumber });
    m_Container.shrink_to_fit();
}

template <typename Real>
const typename Mathematics::VariableMatrixImpl<Real>::ContainerType Mathematics::VariableMatrixImpl<Real>::GetContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    ContainerType result{};

    for (const auto& vector : m_Container)
    {
        result.insert(result.end(), vector.begin(), vector.end());
    }

    return result;
}

template <typename Real>
void Mathematics::VariableMatrixImpl<Real>::SetContainer(int rowsNumber, int columnsNumber, const ContainerType& container)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    *this = VariableMatrixImpl{ rowsNumber, columnsNumber, container };
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_MATRIX_IMPL_DETAIL_H
