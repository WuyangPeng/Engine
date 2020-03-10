// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 18:07)

// 日志消息后缀类外部接口
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_POSTFIX_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_POSTFIX_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/LogManager/LogManagerFwd.h"
#include "CoreTools/ClassInvariant/ClassInvariantFwd.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(LogMessagePostfixImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE LogMessagePostfix
	{
	public:
		PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(LogMessagePostfix);
		using String = System::String;

	public:
		LogMessagePostfix(AppenderPrint appenderFlags, LogLevel level, const FunctionDescribed& functionDescribed);

		CLASS_INVARIANT_DECLARE;

		String GetPostfix() const;
		int GetPostfixSize() const;

	private:
		IMPL_TYPE_DECLARE(LogMessagePrefix);
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_POSTFIX_H
