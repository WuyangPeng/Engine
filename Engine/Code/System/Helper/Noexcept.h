// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/08 21:17)

#ifndef SYSTEM_HELPER_NOEXCEPT_H
#define SYSTEM_HELPER_NOEXCEPT_H 

#include "PragmaWarning/CallTraits.h"
#include "System/SystemOutput/OutputDebugString.h"

namespace System
{
	template <typename Function>
	void NoexceptNoReturn(Function function) noexcept
	{
		try
		{
		#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)

			function();

		#include STSTEM_WARNING_POP
		}
		catch (...)
		{
			OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn 抛出异常。"));
		}
	}

	template <typename T1,typename Function>
	void NoexceptNoReturn(Function function, typename boost::call_traits<T1>::param_type parameter1) noexcept
	{
		try
		{
		#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)

			function(parameter1);

		#include STSTEM_WARNING_POP
		}
		catch (...)
		{
			OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn 抛出异常。"));
		}
	}

	template <typename T1, typename T2, typename Function>
	void NoexceptNoReturn(Function function, typename boost::call_traits<T1>::param_type parameter1, 
						  typename boost::call_traits<T2>::param_type parameter2) noexcept
	{
		try
		{
		#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)

			function(parameter1, parameter2);

		#include STSTEM_WARNING_POP
		}
		catch (...)
		{
			OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn 抛出异常。"));
		}
	}

	template <typename T1, typename T2, typename T3, typename Function>
	void NoexceptNoReturn(Function function, typename boost::call_traits<T1>::param_type parameter1,
						  typename boost::call_traits<T2>::param_type parameter2,
						  typename boost::call_traits<T3>::param_type parameter3) noexcept
	{
		try
		{
		#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)

			function(parameter1, parameter2, parameter3);

		#include STSTEM_WARNING_POP
		}
		catch (...)
		{
			OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn 抛出异常。"));
		}
	}

	template <typename T1, typename T2, typename T3, typename T4, typename Function>
	void NoexceptNoReturn(Function function, typename boost::call_traits<T1>::param_type parameter1,
						  typename boost::call_traits<T2>::param_type parameter2,
						  typename boost::call_traits<T3>::param_type parameter3,
						  typename boost::call_traits<T4>::param_type parameter4) noexcept
	{
		try
		{
		#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)

			function(parameter1, parameter2, parameter3, parameter4);

		#include STSTEM_WARNING_POP
		}
		catch (...)
		{
			OutputDebugStringWithTChar(SYSTEM_TEXT("NoexceptNoReturn 抛出异常。"));
		}
	}

	template <typename Result, typename Function>
	typename boost::call_traits<Result>::value_type Noexcept(Function function, typename boost::call_traits<Result>::param_type defaultResult) noexcept
	{
		try
		{
		#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)

			return function();

		#include STSTEM_WARNING_POP
		}
		catch (...)
		{
			OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));

			return defaultResult;
		}
	}

	template <typename Result, typename T1, typename Function>
	typename boost::call_traits<Result>::value_type Noexcept(Function function, typename boost::call_traits<T1>::param_type parameter1, typename boost::call_traits<Result>::param_type defaultResult) noexcept
	{
		try
		{
		#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)

			return function(parameter1);

		#include STSTEM_WARNING_POP
		}
		catch (...)
		{
			OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));

			return defaultResult;
		}
	}

	template <typename Result,typename T1, typename T2, typename Function>
	typename boost::call_traits<Result>::value_type Noexcept(Function function, typename boost::call_traits<T1>::param_type parameter1,
															 typename boost::call_traits<T2>::param_type parameter2,
															 typename boost::call_traits<Result>::param_type defaultResult) noexcept
	{
		try
		{
		#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)

			return function(parameter1, parameter2);

		#include STSTEM_WARNING_POP
		}
		catch (...)
		{
			OutputDebugStringWithTChar(SYSTEM_TEXT("Noexcept 抛出异常。"));

			return defaultResult;
		}
	}
}

#endif // SYSTEM_HELPER_NOEXCEPT_H
