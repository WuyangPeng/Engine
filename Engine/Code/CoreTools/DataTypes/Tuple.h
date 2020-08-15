// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 15:57)

#ifndef CORE_TOOLS_DATA_TYPE_TUPLE_H
#define CORE_TOOLS_DATA_TYPE_TUPLE_H

// ��T������ԭ�����ݻ�������������ĳ�Ա������
// T::T();
// T::T(const T&);
// T& T::operator= (const T&);

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TemplateTools/ParamType.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <array>
#include <iosfwd>

namespace CoreTools
{
	template <int Dimension, typename Type>
	class Tuple : private boost::totally_ordered<Tuple<Dimension, Type> >
	{
	public:
		using ClassType = Tuple<Dimension, Type>;
		using ParamType = typename ParamType<Type>::type;

	public:
		Tuple() noexcept;

		explicit Tuple(ParamType firstParam) noexcept;
		Tuple(ParamType firstParam, ParamType secondParam) noexcept;
		Tuple(ParamType firstParam, ParamType secondParam, ParamType thirdParam) noexcept;
		Tuple(ParamType firstParam, ParamType secondParam, ParamType thirdParam, ParamType fourthParam) noexcept;

		CLASS_INVARIANT_DECLARE;

		const Type& operator[] (int index) const;
		Type& operator[] (int index);

	private:
		void Set(const Tuple& rhs) noexcept;

	private:
		std::array<Type, Dimension> m_Tuple;
	};

	// ��T������ԭ�����ݻ�������������ĳ�Ա������
	// bool operator== (const T&,const T&);
	// bool operator< (const T&,const T&);

	template <int32_t Dimension, typename Type>
	bool operator==(const Tuple<Dimension, Type>& lhs, const Tuple<Dimension, Type>& rhs);

	template <int32_t Dimension, typename Type>
	bool operator< (const Tuple<Dimension, Type>& lhs, const Tuple<Dimension, Type>& rhs);

	template <int32_t Dimension, typename Type>
	std::ostream& operator <<(std::ostream& os, const Tuple<Dimension, Type>& tuple);
}

#endif // CORE_TOOLS_DATA_TYPE_TUPLE_H