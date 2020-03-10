// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/20 11:07)

#include "CoreTools/CoreToolsExport.h"

#include "LogLevelManager.h"
#include "Flags/LogManagerFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

System::String CoreTools::LogLevelManager
	::GetLogLevelDescribe(LogLevel logLevelType)
{
	switch (logLevelType)
	{
		case LogLevel::Disabled:
			return SYSTEM_TEXT("����");
		case LogLevel::Trace:
			return SYSTEM_TEXT("����");
		case LogLevel::Debug:
			return SYSTEM_TEXT("����");
		case LogLevel::Info:
			return SYSTEM_TEXT("һ��");
		case LogLevel::Warn:
			return SYSTEM_TEXT("����");
		case LogLevel::Error:
			return SYSTEM_TEXT("����");
		case LogLevel::Fatal:
			return SYSTEM_TEXT("��������");
		default:
			CORE_TOOLS_ASSERTION_2(false, "δ�ҵ���־�ȼ������������");
			return SYSTEM_TEXT("");
	}
}
