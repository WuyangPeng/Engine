/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:49)

#ifndef CORE_TOOLS_DATA_TYPE_TABLE_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_TABLE_DETAIL_H

#include "Table.h"
#include "TupleDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)

template <int Rows, int Columns, typename Type>
CoreTools::Table<Rows, Columns, Type>::Table() noexcept
    : entry{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#include SYSTEM_WARNING_POP

template <int Rows, int Columns, typename Type>
CoreTools::Table<Rows, Columns, Type>::Table(ParamType member00, ParamType member01, ParamType member10, ParamType member11) noexcept(std::is_arithmetic_v<Type>) requires(Rows == 2 && Columns == 2)
    : entry{ member00, member01, member10, member11 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Rows, int Columns, typename Type>
CoreTools::Table<Rows, Columns, Type>::Table(ParamType member00,
                                             ParamType member01,
                                             ParamType member02,
                                             ParamType member10,
                                             ParamType member11,
                                             ParamType member12,
                                             ParamType member20,
                                             ParamType member21,
                                             ParamType member22) noexcept(std::is_arithmetic_v<Type>) requires(Rows == 3 && Columns == 3)
    : entry{ member00, member01, member02, member10, member11, member12, member20, member21, member22 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Rows, int Columns, typename Type>
CoreTools::Table<Rows, Columns, Type>::Table(ParamType member00,
                                             ParamType member01,
                                             ParamType member02,
                                             ParamType member03,
                                             ParamType member10,
                                             ParamType member11,
                                             ParamType member12,
                                             ParamType member13,
                                             ParamType member20,
                                             ParamType member21,
                                             ParamType member22,
                                             ParamType member23,
                                             ParamType member30,
                                             ParamType member31,
                                             ParamType member32,
                                             ParamType member33) noexcept(std::is_arithmetic_v<Type>) requires(Rows == 4 && Columns == 4)
    : entry{ member00,
             member01,
             member02,
             member03,
             member10,
             member11,
             member12,
             member13,
             member20,
             member21,
             member22,
             member23,
             member30,
             member31,
             member32,
             member33 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int Rows, int Columns, typename Type>
bool CoreTools::Table<Rows, Columns, Type>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int Rows, int Columns, typename Type>
const Type* CoreTools::Table<Rows, Columns, Type>::operator[](int row) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto index = Columns * row;

    return &entry.at(index);
}

template <int Rows, int Columns, typename Type>
Type* CoreTools::Table<Rows, Columns, Type>::operator[](int row)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS_TO_POINTER(Type, row);
}

template <int Rows, int Columns, typename Type>
const Type& CoreTools::Table<Rows, Columns, Type>::operator()(int row, int column) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto index = column + Columns * row;

    return entry.at(index);
}

template <int Rows, int Columns, typename Type>
Type& CoreTools::Table<Rows, Columns, Type>::operator()(int row, int column)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Type&>(static_cast<const ClassType&>(*this)(row, column));

#include SYSTEM_WARNING_POP
}

template <int Rows, int Columns, typename Type>
void CoreTools::Table<Rows, Columns, Type>::SetRow(int row, const ColumnTuple& tuple)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto index = Columns * row;
    for (auto column = 0; column < Columns; ++column)
    {
        entry.at(index) = tuple[column];

        ++index;
    }
}

template <int Rows, int Columns, typename Type>
typename CoreTools::Table<Rows, Columns, Type>::ColumnTuple CoreTools::Table<Rows, Columns, Type>::GetRow(int row) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    ColumnTuple result{};

    auto index = Columns * row;
    for (auto column = 0; column < Columns; ++column)
    {
        result[column] = entry.at(index);

        ++index;
    }

    return result;
}

template <int Rows, int Columns, typename Type>
void CoreTools::Table<Rows, Columns, Type>::SetColumn(int column, const RowTuple& tuple)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto index = column;
    for (auto row = 0; row < Rows; ++row)
    {
        entry.at(index) = tuple[row];

        index += Columns;
    }
}

template <int Rows, int Columns, typename Type>
typename CoreTools::Table<Rows, Columns, Type>::RowTuple CoreTools::Table<Rows, Columns, Type>::GetColumn(int column) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    RowTuple result{};

    auto index = column;
    for (auto row = 0; row < Rows; ++row)
    {
        result[row] = entry.at(index);

        index += Columns;
    }

    return result;
}

template <int Rows, int Columns, typename Type>
typename CoreTools::Table<Rows, Columns, Type>::ArrayTypeConstIter CoreTools::Table<Rows, Columns, Type>::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entry.begin();
}

template <int Rows, int Columns, typename Type>
typename CoreTools::Table<Rows, Columns, Type>::ArrayTypeConstIter CoreTools::Table<Rows, Columns, Type>::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entry.end();
}

template <int Rows, int Columns, typename Type>
typename CoreTools::Table<Rows, Columns, Type>::ArrayType CoreTools::Table<Rows, Columns, Type>::GetCoordinate() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entry;
}

template <int Rows, int Columns, typename Type>
bool CoreTools::operator==(const Table<Rows, Columns, Type>& lhs, const Table<Rows, Columns, Type>& rhs)
{
    return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <int Rows, int Columns, typename Type>
bool CoreTools::operator<(const Table<Rows, Columns, Type>& lhs, const Table<Rows, Columns, Type>& rhs)
{
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

#endif  // CORE_TOOLS_DATA_TYPE_TABLE_DETAIL_H