// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/18 18:03)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SCOPE_EXIT_DETAIL_H
#define CORE_TOOLS_CLASS_INVARIANT_SCOPE_EXIT_DETAIL_H

#include "ScopeExit.h"  
#include "System/SystemOutput/OutputDebugString.h"

template<typename T>
CoreTools::ScopeExit<T>
	::ScopeExit(T function) noexcept
	: m_Function{ function }
{

}

template<typename T>
CoreTools::ScopeExit<T>
	::~ScopeExit() noexcept
{
	try
	{
		m_Function();
	}
	catch (...)
	{
		// 忽略所有异常
		System::OutputDebugStringWithTChar(SYSTEM_TEXT("ScopeExit 析构抛出异常"));
	}
}

#endif // CORE_TOOLS_CLASS_INVARIANT_SCOPE_EXIT_DETAIL_H
