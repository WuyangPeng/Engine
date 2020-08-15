// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.1 (2020/01/20 16:14)

#ifndef CORE_TOOLS_DATA_TYPE_TABLE_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_TABLE_DETAIL_H

#include "Table.h"
#include "TupleDetail.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26492)
template <int Rows, int Columns, typename Type>
CoreTools::Table<Rows, Columns, Type>::Table() noexcept
    : m_Entry{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Rows, int Columns, typename Type>
CoreTools::Table<Rows, Columns, Type>::Table(ParamType member00, ParamType member01, ParamType member10, ParamType member11) noexcept
    : m_Entry{ member00, member01, member10, member11 }
{
    static_assert(Rows == 2, "Rows == 2");
    static_assert(Columns == 2, "Columns == 2");

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Rows, int Columns, typename Type>
CoreTools::Table<Rows, Columns, Type>::Table(ParamType member00, ParamType member01, ParamType member02,
                                             ParamType member10, ParamType member11, ParamType member12,
                                             ParamType member20, ParamType member21, ParamType member22) noexcept
    : m_Entry{ member00, member01, member02, member10, member11, member12, member20, member21, member22 }
{
    static_assert(Rows == 3, "Rows == 3");
    static_assert(Columns == 3, "Columns == 3");

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Rows, int Columns, typename Type>
CoreTools::Table<Rows, Columns, Type>::Table(ParamType member00, ParamType member01, ParamType member02, ParamType member03,
                                             ParamType member10, ParamType member11, ParamType member12, ParamType member13,
                                             ParamType member20, ParamType member21, ParamType member22, ParamType member23,
                                             ParamType member30, ParamType member31, ParamType member32, ParamType member33) noexcept
    : m_Entry{ member00, member01, member02, member03, member10, member11, member12, member13,
               member20, member21, member22, member23, member30, member31, member32, member33 }
{
    static_assert(Rows == 4, "Rows == 4");
    static_assert(Columns == 4, "Columns == 4");

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Rows, int Columns, typename Type>
CoreTools::Table<Rows, Columns, Type>::~Table()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Rows, int Columns, typename Type>
CoreTools::Table<Rows, Columns, Type>::Table(const Table& rhs)
    : m_Entry{ rhs.m_Entry }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Rows, int Columns, typename Type>
CoreTools::Table<Rows, Columns, Type>& CoreTools::Table<Rows, Columns, Type>::operator=(const Table& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    Set(rhs);

    return *this;
}

// private
template <int Rows, int Columns, typename Type>
void CoreTools::Table<Rows, Columns, Type>::Set(const Table& rhs) noexcept
{
    m_Entry = rhs.m_Entry;
}

#ifdef OPEN_CLASS_INVARIANT
template <int Rows, int Columns, typename Type>
bool CoreTools::Table<Rows, Columns, Type>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <int Rows, int Columns, typename Type>
const Type* CoreTools::Table<Rows, Columns, Type>::operator[](int row) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    EXCEPTION_TRY
    {
        CORE_TOOLS_ASSERTION_0(0 <= Columns * row && Columns * row < sm_EnteriesNumber, "索引无效！");
    }
    EXCEPTION_ALL_CATCH(CoreTools)

    const auto index = Columns * row;

    return &m_Entry[index];
}

template <int Rows, int Columns, typename Type>
Type* CoreTools::Table<Rows, Columns, Type>::operator[](int row) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        CORE_TOOLS_ASSERTION_0(0 <= Columns * row && Columns * row < sm_EnteriesNumber, "索引无效！");
    }
    EXCEPTION_ALL_CATCH(CoreTools)

    return OPERATOR_SQUARE_BRACKETS_TO_POINTER(Type, row);
}

template <int Rows, int Columns, typename Type>
const Type& CoreTools::Table<Rows, Columns, Type>::operator()(int row, int column) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    EXCEPTION_TRY
    {
        CORE_TOOLS_ASSERTION_0(0 <= column + Columns * row && column + Columns * row < sm_EnteriesNumber, "索引无效！");
    }
    EXCEPTION_ALL_CATCH(CoreTools)

    const auto index = column + Columns * row;

    return m_Entry[index];
}

template <int Rows, int Columns, typename Type>
Type& CoreTools::Table<Rows, Columns, Type>::operator()(int row, int column) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        CORE_TOOLS_ASSERTION_0(0 <= column + Columns * row && column + Columns * row < sm_EnteriesNumber, "索引无效！");
    }
    EXCEPTION_ALL_CATCH(CoreTools)

    return const_cast<Type&>(static_cast<const ClassType&>(*this)(row, column));
}

template <int Rows, int Columns, typename Type>
void CoreTools::Table<Rows, Columns, Type>::SetRow(int row, const ColumnTuple& tuple)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto column = 0, index = Columns * row; column < Columns; ++column, ++index)
    {
        m_Entry[index] = tuple[column];
    }
}

template <int Rows, int Columns, typename Type>
typename CoreTools::Table<Rows, Columns, Type>::ColumnTuple CoreTools::Table<Rows, Columns, Type>::GetRow(int row) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    Tuple<Columns, Type> result{};

    for (auto column = 0, index = Columns * row; column < Columns; ++column, ++index)
    {
        result[column] = m_Entry[index];
    }

    return result;
}

template <int Rows, int Columns, typename Type>
void CoreTools::Table<Rows, Columns, Type>::SetColumn(int column, const RowTuple& tuple)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto row = 0, index = column; row < Rows; ++row, index += Columns)
    {
        m_Entry[index] = tuple[row];
    }
}

template <int Rows, int Columns, typename Type>
typename CoreTools::Table<Rows, Columns, Type>::RowTuple CoreTools::Table<Rows, Columns, Type>::GetColumn(int column) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    Tuple<Rows, Type> result{};

    for (auto row = 0, index = column; row < Rows; ++row, index += Columns)
    {
        result[row] = m_Entry[index];
    }
    return result;
}

// 非成员函数
template <int Rows, int Columns, typename Type>
bool CoreTools ::operator==(const Table<Rows, Columns, Type>& lhs, const Table<Rows, Columns, Type>& rhs)
{
    for (auto column = 0; column < Columns; ++column)
    {
        for (auto row = 0; row < Rows; ++row)
        {
            if (lhs(row, column) != rhs(row, column))
            {
                return false;
            }
        }
    }

    return true;
}

template <int Rows, int Columns, typename Type>
bool CoreTools ::operator<(const Table<Rows, Columns, Type>& lhs, const Table<Rows, Columns, Type>& rhs)
{
    for (auto column = 0; column < Columns; ++column)
    {
        for (auto row = 0; row < Rows; ++row)
        {
            if (lhs(row, column) < rhs(row, column))
                return true;
            else if (rhs(row, column) < lhs(row, column))
                return false;
        }
    }

    return false;
}
#include STSTEM_WARNING_POP
#endif  // CORE_TOOLS_DATA_TYPE_TABLE_DETAIL_H