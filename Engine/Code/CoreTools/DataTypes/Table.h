//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/16 14:04)

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
        static constexpr auto sm_EnteriesNumber = Rows * Columns;

        using ArrayType = std::array<Type, sm_EnteriesNumber>;
        using ArrayTypeConstIter = typename ArrayType::const_iterator;

    public:
        Table() noexcept;

        Table(ParamType member00, ParamType member01, ParamType member10, ParamType member11) noexcept;

        Table(ParamType member00, ParamType member01, ParamType member02,
              ParamType member10, ParamType member11, ParamType member12,
              ParamType member20, ParamType member21, ParamType member22) noexcept;

        Table(ParamType member00, ParamType member01, ParamType member02, ParamType member03,
              ParamType member10, ParamType member11, ParamType member12, ParamType member13,
              ParamType member20, ParamType member21, ParamType member22, ParamType member23,
              ParamType member30, ParamType member31, ParamType member32, ParamType member33) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Type* operator[](int row) const;
        [[nodiscard]] Type* operator[](int row);
        [[nodiscard]] const Type& operator()(int row, int column) const;
        [[nodiscard]] Type& operator()(int row, int column);

        [[nodiscard]] ArrayTypeConstIter begin() const noexcept;
        [[nodiscard]] ArrayTypeConstIter end() const noexcept;

        void SetRow(int row, const ColumnTuple& tuple);
        [[nodiscard]] ColumnTuple GetRow(int row) const;
        void SetColumn(int column, const RowTuple& tuple);
        [[nodiscard]] RowTuple GetColumn(int column) const;

        [[nodiscard]] ArrayType GetCoordinate() const noexcept;

    private:
        ArrayType m_Entry;
    };

    template <int Rows, int Columns, typename Type>
    bool operator==(const Table<Rows, Columns, Type>& lhs, const Table<Rows, Columns, Type>& rhs);

    template <int Rows, int Columns, typename Type>
    bool operator<(const Table<Rows, Columns, Type>& lhs, const Table<Rows, Columns, Type>& rhs);
}

#endif  // CORE_TOOLS_DATA_TYPE_TABLE_H
