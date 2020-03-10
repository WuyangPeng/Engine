// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 18:00)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_IMPL_DETAIL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_IMPL_DETAIL_H 

#include "LogAppenderIOManagerImpl.h"
#include "System/SystemOutput/OutputDebugString.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template<typename T>
CoreTools::LogAppenderIOManagerImpl& CoreTools::LogAppenderIOManagerImpl
	::operator<<(T value) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	try
	{
		m_Message += System::ToString(value);
	}
	catch (...)
	{
		// ���������쳣
		System::OutputDebugStringWithTChar(SYSTEM_TEXT("LogAppenderIOManagerImpl operator<< �׳��쳣��"));
	}

	return *this;
}

#endif // CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_IMPL_DETAIL_H
