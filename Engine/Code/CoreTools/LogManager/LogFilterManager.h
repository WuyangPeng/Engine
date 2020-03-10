// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 18:07)

// ��־������������
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_FILTER_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_LOG_FILTER_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE LogFilterManager
	{
	public:
		using ClassType = LogFilterManager;
		using String = System::String;

	public:
		static String GetLogFilterDescribe(LogFilter logFilterType);
		static LogFilter GetLogFilterType(const String& describe);
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOG_FILTER_MANAGER_H
