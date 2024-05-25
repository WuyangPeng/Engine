/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:44)

#ifndef CORE_TOOLS_DATA_TYPE_TABLE_H
#define CORE_TOOLS_DATA_TYPE_TABLE_H

/// 类T可以是原生数据或数据类有下面的成员函数：
/// T::T();
/// T::T(const T&);
/// T& T::operator= (const T&);

#include "CoreTools/CoreToolsDll.h"

#include "DataTypesFwd.h"
#include "System/Helper/PragmaWarning/CallTraits.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <array>

namespace CoreTools
{
    template <int Rows, int Columns, typename Type>
    class Table final : private boost::totally_ordered<Table<Rows, Columns, Type>>
    {
    public:
        using ClassType = Table<Rows, Columns, Type>;

        using ColumnTuple = Tuple<Columns, Type>;
        using RowTuple = Tuple<Rows, Type>;
        using ParamType = typename boost::call_traits<Type>::param_type;

        /// 该数组存储为行主序。
        static constexpr auto rowsNumber = Rows;
        static constexpr auto columnsNumber = Columns;
        static constexpr auto elementNumber = rowsNumber * columnsNumber;

        using ArrayType = std::array<Type, elementNumber>;
        using ArrayTypeConstIter = typename ArrayType::const_iterator;

    public:
        Table() noexcept;

        Table(ParamType member00,
              ParamType member01,
              ParamType member10,
              ParamType member11) noexcept(std::is_arithmetic_v<Type>) requires(Rows == 2 && Columns == 2);

        Table(ParamType member00,
              ParamType member01,
              ParamType member02,
              ParamType member10,
              ParamType member11,
              ParamType member12,
              ParamType member20,
              ParamType member21,
              ParamType member22) noexcept(std::is_arithmetic_v<Type>) requires(Rows == 3 && Columns == 3);

        Table(ParamType member00,
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
              ParamType member33) noexcept(std::is_arithmetic_v<Type>) requires(Rows == 4 && Columns == 4);

        CLASS_INVARIANT_DECLARE;

        NODISCARD const Type* operator[](int row) const;
        NODISCARD Type* operator[](int row);
        NODISCARD const Type& operator()(int row, int column) const;
        NODISCARD Type& operator()(int row, int column);

        NODISCARD ArrayTypeConstIter begin() const noexcept;
        NODISCARD ArrayTypeConstIter end() const noexcept;

        void SetRow(int row, const ColumnTuple& tuple);
        NODISCARD ColumnTuple GetRow(int row) const;
        void SetColumn(int column, const RowTuple& tuple);
        NODISCARD RowTuple GetColumn(int column) const;

        NODISCARD ArrayType GetCoordinate() const noexcept;

    private:
        ArrayType entry;
    };

    template <int Rows, int Columns, typename Type>
    NODISCARD bool operator==(const Table<Rows, Columns, Type>& lhs, const Table<Rows, Columns, Type>& rhs);

    template <int Rows, int Columns, typename Type>
    NODISCARD bool operator<(const Table<Rows, Columns, Type>& lhs, const Table<Rows, Columns, Type>& rhs);
}

#endif  // CORE_TOOLS_DATA_TYPE_TABLE_H
