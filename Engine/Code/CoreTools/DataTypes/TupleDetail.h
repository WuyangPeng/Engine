// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:15)

#ifndef CORE_TOOLS_DATA_TYPE_TUPLE_DETAIL_H
#define CORE_TOOLS_DATA_TYPE_TUPLE_DETAIL_H

#include "Tuple.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h" 
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <int Dimension, typename Type>
CoreTools::Tuple<Dimension, Type>
	::Tuple() noexcept
	:m_Tuple{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

 

template <int Dimension, typename Type>
CoreTools::Tuple<Dimension, Type>
	::Tuple(ParamType firstParam) noexcept
	:m_Tuple{ firstParam }
{
	static_assert(Dimension == 1, "Dimension == 1");

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Dimension, typename Type>
CoreTools::Tuple<Dimension, Type>
	::Tuple(ParamType firstParam, ParamType secondParam) noexcept
	:m_Tuple{ firstParam,secondParam }
{
	static_assert(Dimension == 2, "Dimension == 2");

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Dimension, typename Type>
CoreTools::Tuple<Dimension, Type>
	::Tuple(ParamType firstParam, ParamType secondParam, ParamType thirdParam) noexcept
	:m_Tuple{ firstParam,secondParam,thirdParam }
{
	static_assert(Dimension == 3, "Dimension == 3");

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <int Dimension, typename Type>
CoreTools::Tuple<Dimension, Type>
	::Tuple(ParamType firstParam, ParamType secondParam, ParamType thirdParam, ParamType fourthParam) noexcept
	:m_Tuple{ firstParam,secondParam,thirdParam,fourthParam }
{
	static_assert(Dimension == 4, "Dimension == 4");

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

// private
template <int Dimension, typename Type>
void CoreTools::Tuple<Dimension, Type>
	::Set(const Tuple& rhs) noexcept
{
	m_Tuple = rhs.m_Tuple;
}

#ifdef OPEN_CLASS_INVARIANT
template <int Dimension, typename Type>
bool CoreTools::Tuple<Dimension, Type>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <int Dimension, typename Type>
const Type& CoreTools::Tuple<Dimension, Type>
	::operator[] (int index) const  
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return m_Tuple.at(index);	
}

template <int Dimension, typename Type>
Type& CoreTools::Tuple<Dimension, Type>
	::operator[] (int index)  
{
	CORE_TOOLS_CLASS_IS_VALID_9; 

	return OPERATOR_SQUARE_BRACKETS(Type, index);
}

// 非成员函数
template <int Dimension, typename Type>
bool CoreTools
	::operator== (const Tuple<Dimension, Type>& lhs, const Tuple<Dimension, Type>& rhs)
{
	for (auto i = 0; i < Dimension; ++i)
	{
		if (!(lhs[i] == rhs[i]))
			return false;
	}

	return true;
}

template <int Dimension, typename Type>
bool CoreTools
	::operator< (const Tuple<Dimension, Type>& lhs, const Tuple<Dimension, Type>& rhs)
{
	for (auto i = 0; i < Dimension; ++i)
	{
		if (lhs[i] < rhs[i])
			return true;
		else if (rhs[i] < lhs[i])
			return false;
	}

	return false;
}

template <int Dimension, typename Type>
std::ostream& CoreTools
	::operator<<(std::ostream& os, const Tuple<Dimension, Type>& tuple)
{
	for (auto i = 0; i < Dimension; ++i)
	{
		os << tuple[i] << " ";
	}

	return os;
}

#endif // CORE_TOOLS_DATA_TYPE_TUPLE_DETAIL_H