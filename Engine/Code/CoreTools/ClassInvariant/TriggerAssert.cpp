// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/18 18:07)

#include "CoreTools/CoreToolsExport.h"

#include "TriggerAssert.h"
#include "ScopeExitDetail.h"
#include "Flags/CheckInvariantFlags.h" 
#include "System/Window/WindowSystem.h"
#include "System/SystemOutput/SystemOutput.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/CharacterString/StringConversion.h"

#include <cstdio>
#include <cstdarg> 

const char* CoreTools::TriggerAssert
	::sm_DebugPrompt{ "内部程序错误，是否要进行调试？" };
const size_t CoreTools::TriggerAssert
	::sm_DebugPromptLength{ System::Strlen(TriggerAssert::sm_DebugPrompt) };
const char* CoreTools::TriggerAssert
	::sm_MessagePrefix{ "\n%s失败在%s(%s,%d):\n" };
const size_t CoreTools::TriggerAssert
	::sm_MaxPrefixBytes{ sm_MaxMessageBytes - sm_DebugPromptLength - 1 };
const char* CoreTools::TriggerAssert
	::sm_TriggerAssertCheckInvariant{ "不变式" };
const char* CoreTools::TriggerAssert
	::sm_TriggerAssertCheckAssertion{ "断言" };

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX
const char* CoreTools::TriggerAssert
	::sm_MessageBoxTitle{ "断言失败！" };
#endif // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

CoreTools::TriggerAssert
	::TriggerAssert(TriggerAssertCheck triggerAssertCheck, const FunctionDescribed& functionDescribed, const char* format, va_list arguments)
	:m_TriggerAssertCheck{ triggerAssertCheck }, m_Message{ }
{
	Process(functionDescribed, format, arguments);
}

CoreTools::TriggerAssert
	::TriggerAssert(TriggerAssertCheck triggerAssertCheck, const FunctionDescribed& functionDescribed, const char* format, ...)
	:m_TriggerAssertCheck{ triggerAssertCheck }, m_Message{ }
{
	va_list arguments{};
	va_start(arguments, format);

	ScopeExit<> onExit{ [&arguments]()
	{
		va_end(arguments);
	} };

	Process(functionDescribed, format, arguments);
}

void CoreTools::TriggerAssert
	::Process(const FunctionDescribed& functionDescribed, const char* format, va_list arguments)
{
	if (m_TriggerAssertCheck == TriggerAssertCheck::Invariant)
	{
		GenerateMessagePrefix(functionDescribed, sm_TriggerAssertCheckInvariant);
	}
	else
	{
		GenerateMessagePrefix(functionDescribed, sm_TriggerAssertCheckAssertion);
	}

	AppendUserArguments(format, arguments);

	if (m_TriggerAssertCheck == TriggerAssertCheck::Assertion)
	{
		// 断言失败，写入日志。类不变式不处理，以避免递归调用。
		WriteToLog();
	}

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW
	WriteToOutputDebug();
#endif // CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

#ifdef OPEN_IMPORTANT_EXCPTION_ASSERT

	if (m_TriggerAssertCheck == TriggerAssertCheck::Assertion)
	{
		THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(m_Message.data()));
	}

#else // !OPEN_IMPORTANT_EXCPTION_ASSERT

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX
	JudgeUserSelection();
#endif // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX 

#endif // OPEN_IMPORTANT_EXCPTION_ASSERT 
}

// private
void CoreTools::TriggerAssert
	::GenerateMessagePrefix(const FunctionDescribed& functionDescribed, const char* triggerAssertCheck)
{
	// 消息前缀。
	System::SNPrintf(m_Message.data(), sm_MaxPrefixBytes, sm_MaxPrefixBytes, sm_MessagePrefix,
					 triggerAssertCheck, functionDescribed.GetFileName(), functionDescribed.GetCurrentFunction(), functionDescribed.GetLine());
}

// private
void CoreTools::TriggerAssert
	::AppendUserArguments(const char* format, va_list arguments)
{
	// 添加指定的参数。
	auto length = System::Strlen(m_Message.data());
	System::VsnPrintf(m_Message.data() + length, sm_MaxPrefixBytes - length, format, arguments);
}

// private
void CoreTools::TriggerAssert
	::WriteToLog()
{
	LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("Assert"))
		<< m_Message.data()
		<< LogAppenderIOManageSign::Refresh;
}

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW
// private
void CoreTools::TriggerAssert
	::WriteToOutputDebug()
{
	// 消息输出到调试窗口。
	System::OutputDebugStringWithChar(m_Message.data());
}
#endif // CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX
// private
void CoreTools::TriggerAssert
	::JudgeUserSelection()
{
	// 给用户一个机会调试断点，继续，或终止执行。
	System::Strcat(m_Message.data(), sm_MaxMessageBytes, sm_DebugPrompt);

	auto type = System::MessageBoxSelectionWithChar(m_Message.data(), sm_MessageBoxTitle);

	JudgeSelection(type);
}

// private
void CoreTools::TriggerAssert
	::JudgeSelection(DialogBoxCommand selection)
{
	switch (selection)
	{
		case DialogBoxCommand::IDYes:
		{
			// 调试断点。
			System::DebugBreak();

			break;
		}
		case DialogBoxCommand::IDNo:
		{
			// 继续执行。

			break;
		}
		case DialogBoxCommand::IDCancel:
		default:
		{
			if (m_TriggerAssertCheck == TriggerAssertCheck::Assertion)
			{
				// 拋出异常。
				THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(m_Message.data()));
			}
			else
			{
				// 退出程序。
				System::Exit();
			}

			break;
		}
	}
}
#endif // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX
