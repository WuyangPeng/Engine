// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 15:57)

#ifndef CORE_TOOLS_DATA_TYPE_TABLE_H
#define CORE_TOOLS_DATA_TYPE_TABLE_H

// 类T可以是原生数据或数据类有下面的成员函数：
// T::T();
// T::T(const T&);
// T& T::operator= (const T&);

#include "CoreTools/CoreToolsDll.h"

#include "DataTypesFwd.h"
#include "CoreTools/TemplateTools/ParamType.h"

#include <boost/operators.hpp>
#include <array>

namespace CoreTools
{
	template <int Rows, int Columns, typename Type>
	class Table : private boost::totally_ordered<Table<Rows, Columns, Type>>
	{
	public:
		using ClassType = Table<Rows, Columns, Type>;
		using ColumnTuple = Tuple<Columns, Type>;
		using RowTuple = Tuple<Rows, Type>;
		using ParamType = typename ParamType<Type>::type;

	public:
		Table();
		~Table();

		Table(const Table& rhs);
		Table& operator= (const Table& rhs);

		Table(ParamType member00, ParamType member01, ParamType member10, ParamType member11);

		Table(ParamType member00, ParamType member01, ParamType member02,
			  ParamType member10, ParamType member11, ParamType member12,
			  ParamType member20, ParamType member21, ParamType member22);

		Table(ParamType member00, ParamType member01, ParamType member02, ParamType member03,
			  ParamType member10, ParamType member11, ParamType member12, ParamType member13,
			  ParamType member20, ParamType member21, ParamType member22, ParamType member23,
			  ParamType member30, ParamType member31, ParamType member32, ParamType member33);

		CLASS_INVARIANT_DECLARE;

		const Type* operator[](int row) const noexcept;
		Type* operator[](int row) noexcept;
		const Type& operator()(int row, int column) const noexcept;
		Type& operator()(int row, int column) noexcept;

		void SetRow(int row, const ColumnTuple& tuple);
		ColumnTuple GetRow(int row) const;
		void SetColumn(int column, const RowTuple& tuple);
		RowTuple GetColumn(int column) const;

	private:
		void Set(const Table& rhs);

	private:
		// 该数组存储为行主序。
		static constexpr int sm_EnteriesNumber{ Rows * Columns };

		std::array<Type, sm_EnteriesNumber> m_Entry;
	};

	template <int Rows, int Columns, typename Type>
	bool operator==(const Table<Rows, Columns, Type>& lhs, const Table<Rows, Columns, Type>& rhs);

	template <int Rows, int Columns, typename Type>
	bool operator< (const Table<Rows, Columns, Type>& lhs, const Table<Rows, Columns, Type>& rhs);
}

#endif // CORE_TOOLS_DATA_TYPE_TABLE_H
