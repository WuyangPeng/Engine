// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.1.0.0 (2020/04/02 15:11)

#ifndef CORE_TOOLS_HELPER_NOEXCEPT_DETAIL_H
#define CORE_TOOLS_HELPER_NOEXCEPT_DETAIL_H 

#include "Noexcept.h"
#include "System/Helper/PragmaWarning.h"

template <typename T, typename Function>
void CoreTools
	::NoexceptNoReturn(const T& master, Function function) noexcept
{
	try
	{
	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26447)

		(master.*function)();

	#include STSTEM_WARNING_POP
	}
	catch (...)
	{

	}
}

template <typename T, typename Function, typename T1>
void  CoreTools
	::NoexceptNoReturn(const T& master, Function function, const T1& parameter1) noexcept
{
	try
	{
	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26447)

		(master.*function)(parameter1);

	#include STSTEM_WARNING_POP
	}
	catch (...)
	{

	}
}

template <typename T, typename Result, typename Function>
Result CoreTools
	::Noexcept(const T& master, Function function, const Result& defaultResult) noexcept
{
	try
	{
	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26447)

		return (master.*function)();

	#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		return defaultResult;
	}
}

template <typename T, typename Result, typename Function, typename T1>
Result  CoreTools
	::Noexcept(const T& master, Function function, const T1& parameter1, const Result& defaultResult) noexcept
{
	try
	{
	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26447)

		return (master.*function)(parameter1);

	#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		return defaultResult;
	}
}

template <typename T, typename Function>
void CoreTools
	::NoexceptNoReturn(T& master, Function function) noexcept
{
	try
	{
	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26447)

		(master.*function)();

	#include STSTEM_WARNING_POP
	}
	catch (...)
	{

	}
}

template <typename T, typename Function, typename T1>
void  CoreTools
	::NoexceptNoReturn(T& master, Function function, const T1& parameter1) noexcept
{
	try
	{
	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26447)

		(master.*function)(parameter1);

	#include STSTEM_WARNING_POP
	}
	catch (...)
	{

	}
}

template <typename T, typename Result, typename Function>
Result CoreTools
	::Noexcept(T& master, Function function, const Result& defaultResult) noexcept
{
	try
	{
	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26447)

		return (master.*function)();

	#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		return defaultResult;
	}
}

template <typename T, typename Result, typename Function, typename T1>
Result  CoreTools
	::Noexcept(T& master, Function function, const T1& parameter1, const Result& defaultResult) noexcept
{
	try
	{
	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26447)

		return (master.*function)(parameter1);

	#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		return defaultResult;
	}
}

#endif // CORE_TOOLS_HELPER_NOEXCEPT_DETAIL_H
