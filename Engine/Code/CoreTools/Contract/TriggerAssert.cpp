///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/22 14:42)

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
    // ��Ϣǰ׺��
    Format format{ GetMessagePrefix() };

    format % triggerAssertCheckMessage % functionDescribed.GetFileName() % functionDescribed.GetCurrentFunction() % functionDescribed.GetLine();

    return format.str();
}

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

void CoreTools::TriggerAssert::WriteToOutputDebug(const std::string& message) noexcept
{
    // ��Ϣ��������Դ��ڡ�
    System::OutputDebugStringWithChar(message.c_str());
}

#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

void CoreTools::TriggerAssert::JudgeUserSelection(const std::string& message) const
{
    // ���û�һ��������Զϵ㣬����������ִֹ�С�
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
            if (triggerAssertCheck == TriggerAssertCheck::Assertion)
            {
                // �����쳣��
                THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(message))
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

std::string CoreTools::TriggerAssert::GetMessageBoxTitle()
{
    static const auto messageBoxTitle = "����ʧ�ܣ�"s;

    return messageBoxTitle;
}

#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

std::string CoreTools::TriggerAssert::GetDebugPrompt()
{
    static const auto debugPrompt = "�ڲ���������Ƿ�Ҫ���е��ԣ�"s;

    return debugPrompt;
}

std::string CoreTools::TriggerAssert::GetMessagePrefix()
{
    static const auto messagePrefix = "\n%sʧ����%s��%s��%d��:\n"s;

    return messagePrefix;
}

std::string CoreTools::TriggerAssert::GetTriggerAssertCheckInvariant()
{
    static const auto triggerAssertCheckInvariant = "����ʽ"s;

    return triggerAssertCheckInvariant;
}

std::string CoreTools::TriggerAssert::GetTriggerAssertCheckAssertion()
{
    static const auto triggerAssertCheckAssertion = "����"s;

    return triggerAssertCheckAssertion;
}
