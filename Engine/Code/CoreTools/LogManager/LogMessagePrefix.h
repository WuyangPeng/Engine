// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 18:07)

// 日志消息前缀类外部接口
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(LogMessagePrefixImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE LogMessagePrefix
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(LogMessagePrefix);
		using String = System::String;

	public:
		LogMessagePrefix(AppenderPrint appenderFlags, LogLevel level, LogFilter filter);

		CLASS_INVARIANT_DECLARE;

		String GetPrefix() const;
		int GetPrefixSize() const;

	private:
		IMPL_TYPE_DECLARE(LogMessagePrefix);
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_PREFIX_H
