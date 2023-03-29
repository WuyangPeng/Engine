///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 11:18)

#ifndef CORE_TOOLS_DATA_TYPE_TABLE_H
#define CORE_TOOLS_DATA_TYPE_TABLE_H

// 类T可以是原生数据或数据类有下面的成员函数：
// T::T();
// T::T(const T&);
// T& T::operator= (const T&);

#include "CoreTools/CoreToolsDll.h"

#include "DataTypesFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/TemplateTools/ParamType.h"

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
        using ParamType = typename ParamType<Type>::type;

        // 该数组存储为行主序。
        static constexpr auto elementNumber = Rows * Columns;

        using ArrayType = std::array<Type, elementNumber>;
        using ArrayTypeConstIter = typename ArrayType::const_iterator;

    public:
        Table() noexcept;

        Table(ParamType member00, ParamType member01, ParamType member10, ParamType member11) noexcept;

        Table(ParamType member00,
              ParamType member01,
              ParamType member02,
              ParamType member10,
              ParamType member11,
              ParamType member12,
              ParamType member20,
              ParamType member21,
              ParamType member22) noexcept;

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
              ParamType member33) noexcept;

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
