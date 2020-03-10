// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.3 (2020/03/01 02:29)

#ifndef SYSTEM_HELPER_NOEXCEPT_H
#define SYSTEM_HELPER_NOEXCEPT_H 

namespace System
{
	template <typename Function>
	void Disable26447NoReturn(Function function) noexcept
	{
		try
		{
#include "PragmaWarning/Push.h"
#include "PragmaWarning/Disable26447.h"

			function();

#include "PragmaWarning/Pop.h"
		}
		catch (...)
		{
			 
		}
	}
	 

	template <typename Function,typename T1>
	void Disable26447NoReturn(Function function,const T1& parameter1) noexcept
	{
		try
		{
#include "PragmaWarning/Push.h"
#include "PragmaWarning/Disable26447.h" 

			function(parameter1);

#include "PragmaWarning/Pop.h"
		}
		catch (...)
		{
			 
		}
	}
	 

	template <typename Result, typename Function>
	Result Disable26447(Function function,const Result& defaultResult) noexcept
	{
		try
		{
#include "PragmaWarning/Push.h"
#include "PragmaWarning/Disable26447.h"  

			return function();

#include "PragmaWarning/Pop.h"
		}
		catch (...)
		{
			return defaultResult;
		}
	}
	 

	template <typename Result, typename Function, typename T1>
	Result Disable26447(Function function, const T1& parameter1, const Result& defaultResult) noexcept
	{
		try
		{
#include "PragmaWarning/Push.h"
#include "PragmaWarning/Disable26447.h"   

			return function(parameter1);

#include "PragmaWarning/Pop.h"
		}
		catch (...)
		{
			return defaultResult;
		}
	} 
}

#endif // SYSTEM_HELPER_NOEXCEPT_H
