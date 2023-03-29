///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/22 14:42)

#include "CoreTools/CoreToolsExport.h"

#include "ScopeExitDetail.h"
#include "TriggerAssert.h"
#include "Flags/CheckInvariantFlags.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

void CoreTools::TriggerAssert::Process(const FunctionDescribed& functionDescribed, const Format& format)
{
    const auto messagePrefix = GenerateMessagePrefix(functionDescribed);

    const auto message = messagePrefix + format.str();

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

    WriteToOutputDebug(message);

#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

#ifdef OPEN_IMPORTANT_EXCEPTION_ASSERT

    if (triggerAssertCheck == TriggerAssertCheck::Assertion)
    {
        THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(message));
    }

#else  // !OPEN_IMPORTANT_EXCEPTION_ASSERT

    #ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

    JudgeUserSelection(message);

    #endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT
}

std::string CoreTools::TriggerAssert::GenerateMessagePrefix(const FunctionDescribed& functionDescribed) const
{
    if (triggerAssertCheck == TriggerAssertCheck::Invariant)
    {
        return GenerateMessagePrefix(functionDescribed, GetTriggerAssertCheckInvariant());
    }
    else
    {
        return GenerateMessagePrefix(functionDescribed, GetTriggerAssertCheckAssertion());
    }
}

std::string CoreTools::TriggerAssert::GenerateMessagePrefix(const FunctionDescribed& functionDescribed, const std::string& triggerAssertCheckMessage)
{
    // 消息前缀。
    Format format{ GetMessagePrefix() };

    format % triggerAssertCheckMessage % functionDescribed.GetFileName() % functionDescribed.GetCurrentFunction() % functionDescribed.GetLine();

    return format.str();
}

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

void CoreTools::TriggerAssert::WriteToOutputDebug(const std::string& message) noexcept
{
    // 消息输出到调试窗口。
    System::OutputDebugStringWithChar(message.c_str());
}

#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

void CoreTools::TriggerAssert::JudgeUserSelection(const std::string& message) const
{
    // 给用户一个机会调试断点，继续，或终止执行。
    const auto debugMessage = message + GetDebugPrompt();

    const auto type = System::MessageBoxSelectionWithChar(debugMessage.c_str(), GetMessageBoxTitle().c_str());

    JudgeSelection(type, debugMessage);
}

void CoreTools::TriggerAssert::JudgeSelection(DialogBoxCommand selection, const std::string& message) const
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
            if (triggerAssertCheck == TriggerAssertCheck::Assertion)
            {
                // 拋出异常。
                THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(message))
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

std::string CoreTools::TriggerAssert::GetMessageBoxTitle()
{
    static const auto messageBoxTitle = "断言失败！"s;

    return messageBoxTitle;
}

#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

std::string CoreTools::TriggerAssert::GetDebugPrompt()
{
    static const auto debugPrompt = "内部程序错误，是否要进行调试？"s;

    return debugPrompt;
}

std::string CoreTools::TriggerAssert::GetMessagePrefix()
{
    static const auto messagePrefix = "\n%s失败在%s（%s，%d）:\n"s;

    return messagePrefix;
}

std::string CoreTools::TriggerAssert::GetTriggerAssertCheckInvariant()
{
    static const auto triggerAssertCheckInvariant = "不变式"s;

    return triggerAssertCheckInvariant;
}

std::string CoreTools::TriggerAssert::GetTriggerAssertCheckAssertion()
{
    static const auto triggerAssertCheckAssertion = "断言"s;

    return triggerAssertCheckAssertion;
}
