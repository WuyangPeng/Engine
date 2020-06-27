// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/18 18:03)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SCOPE_EXIT_DETAIL_H
#define CORE_TOOLS_CLASS_INVARIANT_SCOPE_EXIT_DETAIL_H

#include "ScopeExit.h"  
#include "System/Helper/Noexcept.h"
#include "System/SystemOutput/OutputDebugString.h"

template<typename T>
CoreTools::ScopeExit<T>
	::ScopeExit(T function) noexcept
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
	: m_Function{ function }
#include STSTEM_WARNING_POP
{

}

template<typename T>
CoreTools::ScopeExit<T>
	::~ScopeExit() noexcept
{
	try
	{
	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(26447)

		m_Function();

	#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		// ���������쳣
		System::OutputDebugStringWithTChar(SYSTEM_TEXT("ScopeExit �����׳��쳣"));
	}
}

#endif // CORE_TOOLS_CLASS_INVARIANT_SCOPE_EXIT_DETAIL_H
