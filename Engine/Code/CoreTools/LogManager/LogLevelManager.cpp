// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 11:07)

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
			return SYSTEM_TEXT("禁用");
		case LogLevel::Trace:
			return SYSTEM_TEXT("跟踪");
		case LogLevel::Debug:
			return SYSTEM_TEXT("调试");
		case LogLevel::Info:
			return SYSTEM_TEXT("一般");
		case LogLevel::Warn:
			return SYSTEM_TEXT("警告");
		case LogLevel::Error:
			return SYSTEM_TEXT("错误");
		case LogLevel::Fatal:
			return SYSTEM_TEXT("致命错误");
		default:
			CORE_TOOLS_ASSERTION_2(false, "未找到日志等级的相关描述！");
			return SYSTEM_TEXT("");
	}
}
