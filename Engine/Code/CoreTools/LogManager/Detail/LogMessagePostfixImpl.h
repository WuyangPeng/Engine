// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 18:06)

// 日志消息后缀类内部接口
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_POSTFIX_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_POSTFIX_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/LogManager/LogManagerFwd.h"
#include "CoreTools/Contract/FunctionDescribed.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE LogMessagePostfixImpl
	{
	public:
		using ClassType = LogMessagePostfixImpl;
		using String = System::String;

	public:
		LogMessagePostfixImpl(AppenderPrint appenderFlags, LogLevel level, const FunctionDescribed& functionDescribed);

		CLASS_INVARIANT_DECLARE;

		String GetPostfix() const;
		int GetPostfixSize() const;

	private:
		void GeneratePostfix();
		void GenerateFunctionDescribedPostfix();

	private:
		String m_Postfix;
		AppenderPrint m_AppenderFlags;
		LogLevel m_Level;
		FunctionDescribed m_FunctionDescribed;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_POSTFIX_IMPL_H
