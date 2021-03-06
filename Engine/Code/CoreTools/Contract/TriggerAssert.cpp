//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/10 15:15)

#include "CoreTools/CoreToolsExport.h"

#include "ScopeExitDetail.h"
#include "TriggerAssert.h"
#include "Flags/CheckInvariantFlags.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "System/Helper/PragmaWarning.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/Window/WindowSystem.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <cstdarg>
#include <cstdio>

const char* CoreTools::TriggerAssert::sm_DebugPrompt{ "内部程序错误，是否要进行调试？" };
const char* CoreTools::TriggerAssert::sm_MessagePrefix{ "\n%s失败在%s(%s,%d):\n" };
const char* CoreTools::TriggerAssert::sm_TriggerAssertCheckInvariant{ "不变式" };
const char* CoreTools::TriggerAssert::sm_TriggerAssertCheckAssertion{ "断言" };

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX
const char* CoreTools::TriggerAssert::sm_MessageBoxTitle{ "断言失败！" };
#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

CoreTools::TriggerAssert::TriggerAssert(TriggerAssertCheck triggerAssertCheck, const FunctionDescribed& functionDescribed, const char* format, va_list arguments)
    : m_TriggerAssertCheck{ triggerAssertCheck }, m_Message{}
{
    Process(functionDescribed, format, arguments);
}

CoreTools::TriggerAssert::TriggerAssert(TriggerAssertCheck triggerAssertCheck, const FunctionDescribed& functionDescribed, const char* format, ...)
    : m_TriggerAssertCheck{ triggerAssertCheck }, m_Message{}
{
    va_list arguments{};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26492)
    va_start(arguments, format);
#include STSTEM_WARNING_POP

    ScopeExit<> onExit{ [&arguments]() noexcept {
        va_end(arguments);
    } };

    Process(functionDescribed, format, arguments);
}

void CoreTools::TriggerAssert::Process(const FunctionDescribed& functionDescribed, const char* format, va_list arguments)
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
#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

#ifdef OPEN_IMPORTANT_EXCPTION_ASSERT

    if (m_TriggerAssertCheck == TriggerAssertCheck::Assertion)
    {
        THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(m_Message.data()));
    }

#else  // !OPEN_IMPORTANT_EXCPTION_ASSERT

    #ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

    JudgeUserSelection();

    #endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT
}

// private
void CoreTools::TriggerAssert::GenerateMessagePrefix(const FunctionDescribed& functionDescribed, const char* triggerAssertCheck) noexcept
{
    const auto maxPrefixBytes = GetMaxPrefixBytes();

    // 消息前缀。
    System::SNPrintf(m_Message.data(), maxPrefixBytes, maxPrefixBytes, sm_MessagePrefix,
                     triggerAssertCheck, functionDescribed.GetFileName(), functionDescribed.GetCurrentFunction(), functionDescribed.GetLine());
}

// private
void CoreTools::TriggerAssert::AppendUserArguments(const char* format, va_list arguments) noexcept
{
    // 添加指定的参数。
    auto length = System::Strlen(m_Message.data());

    const auto maxPrefixBytes = GetMaxPrefixBytes();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    if (length < maxPrefixBytes)
    {
        [[maybe_unused]] const auto result = System::VsnPrintf(m_Message.data() + length, maxPrefixBytes - length, format, arguments);
    }

#include STSTEM_WARNING_POP
}

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW
// private
void CoreTools::TriggerAssert::WriteToOutputDebug() noexcept
{
    // 消息输出到调试窗口。
    System::OutputDebugStringWithChar(m_Message.data());
}
#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX
// private
void CoreTools::TriggerAssert::JudgeUserSelection()
{
    // 给用户一个机会调试断点，继续，或终止执行。
    [[maybe_unused]] const auto result = System::Strcat(m_Message.data(), sm_MaxMessageBytes, sm_DebugPrompt);

    const auto type = System::MessageBoxSelectionWithChar(m_Message.data(), sm_MessageBoxTitle);

    JudgeSelection(type);
}

// private
void CoreTools::TriggerAssert::JudgeSelection(DialogBoxCommand selection)
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

size_t CoreTools::TriggerAssert::GetDebugPromptLength() noexcept
{
    static const auto debugPromptLength = System::Strlen(TriggerAssert::sm_DebugPrompt);

    return debugPromptLength;
}

size_t CoreTools::TriggerAssert::GetMaxPrefixBytes() noexcept
{
    static const auto maxPrefixBytes = sm_MaxMessageBytes - GetDebugPromptLength() - 1;

    return maxPrefixBytes;
}

#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX
