// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/18 18:07)

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

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

const char* CoreTools::TriggerAssert
	::sm_DebugPrompt{ "�ڲ���������Ƿ�Ҫ���е��ԣ�" };
const size_t CoreTools::TriggerAssert
	::sm_DebugPromptLength{ System::Strlen(TriggerAssert::sm_DebugPrompt) };
const char* CoreTools::TriggerAssert
	::sm_MessagePrefix{ "\n%sʧ����%s(%s,%d):\n" };
const size_t CoreTools::TriggerAssert
	::sm_MaxPrefixBytes{ sm_MaxMessageBytes - sm_DebugPromptLength - 1 };
const char* CoreTools::TriggerAssert
	::sm_TriggerAssertCheckInvariant{ "����ʽ" };
const char* CoreTools::TriggerAssert
	::sm_TriggerAssertCheckAssertion{ "����" };

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX
const char* CoreTools::TriggerAssert
	::sm_MessageBoxTitle{ "����ʧ�ܣ�" };
#endif // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

#include STSTEM_WARNING_POP

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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26492)
	va_list arguments{};
	va_start(arguments, format);
#include STSTEM_WARNING_POP

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
	::GenerateMessagePrefix(const FunctionDescribed& functionDescribed, const char* triggerAssertCheck) noexcept
{
	// ��Ϣǰ׺��
	System::SNPrintf(m_Message.data(), sm_MaxPrefixBytes, sm_MaxPrefixBytes, sm_MessagePrefix,
					 triggerAssertCheck, functionDescribed.GetFileName(), functionDescribed.GetCurrentFunction(), functionDescribed.GetLine());
}

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
// private
void CoreTools::TriggerAssert
	::AppendUserArguments(const char* format, va_list arguments) noexcept
{
	// ���ָ���Ĳ�����
	auto length = System::Strlen(m_Message.data());
	System::VsnPrintf(m_Message.data() + length, sm_MaxPrefixBytes - length, format, arguments);
}
#include STSTEM_WARNING_POP

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW
// private
void CoreTools::TriggerAssert
	::WriteToOutputDebug() noexcept
{
	// ��Ϣ��������Դ��ڡ�
	System::OutputDebugStringWithChar(m_Message.data());
}
#endif // CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX
// private
void CoreTools::TriggerAssert
	::JudgeUserSelection()
{
	// ���û�һ��������Զϵ㣬����������ִֹ�С�
	System::Strcat(m_Message.data(), sm_MaxMessageBytes, sm_DebugPrompt);

	const auto type = System::MessageBoxSelectionWithChar(m_Message.data(), sm_MessageBoxTitle);

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
			// ���Զϵ㡣
			System::DebugBreak();

			break;
		}
		case DialogBoxCommand::IDNo:
		{
			// ����ִ�С�

			break;
		}
		case DialogBoxCommand::IDCancel:
		default:
		{
			if (m_TriggerAssertCheck == TriggerAssertCheck::Assertion)
			{
				// �����쳣��
				THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(m_Message.data()));
			}
			else
			{
				// �˳�����
				System::Exit();
			}

			break;
		}
	}
}
#endif // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX
