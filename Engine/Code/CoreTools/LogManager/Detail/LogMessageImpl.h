// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 18:06)

// 日志消息类内部接口
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/LogManagerFwd.h"
#include "CoreTools/ClassInvariant/FunctionDescribed.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE LogMessageImpl
	{
	public:
		using ClassType = LogMessageImpl;
		using String = System::String;

	public:
		LogMessageImpl(LogLevel level, LogFilter filter, const String& message, const FunctionDescribed& functionDescribed);

		CLASS_INVARIANT_DECLARE;

		String GetMessageDescribe() const;
		LogLevel GetLogLevel() const noexcept;
		LogFilter GetLogFilterType() const noexcept;
		int GetMessageSize() const;
		FunctionDescribed GetFunctionDescribed() const;

	private:
		LogLevel m_Level;
		LogFilter m_Filter;
		String m_Message;
		FunctionDescribed m_FunctionDescribed;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_IMPL_H
