// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 18:07)

// 日志等级管理类
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_LEVEL_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_LOG_LEVEL_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE LogLevelManager
	{
	public:
		using ClassType = LogLevelManager;
		using String = System::String;

	public:
		static String GetLogLevelDescribe(LogLevel logLevelType);
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOG_LEVEL_MANAGER_H
