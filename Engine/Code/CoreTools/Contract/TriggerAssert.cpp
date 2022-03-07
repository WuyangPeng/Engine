///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/10 18:27)

#include "CoreTools/CoreToolsExport.h"

#include "ScopeExitDetail.h"
#include "TriggerAssert.h"
#include "Flags/CheckInvariantFlags.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;
using namespace std::literals;

void CoreTools::TriggerAssert::Process(const FunctionDescribed& functionDescribed, const Format& format)
{
    const auto messagePrefix = GenerateMessagePrefix(functionDescribed);

    const auto message = messagePrefix + format.str();

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

    WriteToOutputDebug(message);

#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

#ifdef OPEN_IMPORTANT_EXCPTION_ASSERT

    if (triggerAssertCheck == TriggerAssertCheck::Assertion)
    {
        THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(message));
    }

#else  // !OPEN_IMPORTANT_EXCPTION_ASSERT

    #ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

    JudgeUserSelection(message);

    #endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

#endif  // OPEN_IMPORTANT_EXCPTION_ASSERT
}

// private
string CoreTools::TriggerAssert::GenerateMessagePrefix(const FunctionDescribed& functionDescribed)
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

// private
string CoreTools::TriggerAssert::GenerateMessagePrefix(const FunctionDescribed& functionDescribed, const string& triggerAssertCheckMessage)
{
    // ��Ϣǰ׺��
    Format format{ GetMessagePrefix() };

    format % triggerAssertCheckMessage % functionDescribed.GetFileName() % functionDescribed.GetCurrentFunction() % functionDescribed.GetLine();

    return format.str();
}

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

// private
void CoreTools::TriggerAssert::WriteToOutputDebug(const string& message) noexcept
{
    // ��Ϣ��������Դ��ڡ�
    System::OutputDebugStringWithChar(message.c_str());
}

#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

// private
void CoreTools::TriggerAssert::JudgeUserSelection(const string& message)
{
    // ���û�һ��������Զϵ㣬����������ִֹ�С�
    const auto debugMessage = message + GetDebugPrompt();

    const auto type = System::MessageBoxSelectionWithChar(debugMessage.c_str(), GetMessageBoxTitle().c_str());

    JudgeSelection(type, debugMessage);
}

// private
void CoreTools::TriggerAssert::JudgeSelection(DialogBoxCommand selection, const string& message)
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
                THROW_EXCEPTION(StringConversion::MultiByteConversionStandard(message));
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

string CoreTools::TriggerAssert::GetMessageBoxTitle()
{
    static const auto messageBoxTitle = "����ʧ�ܣ�"s;

    return messageBoxTitle;
}

#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

string CoreTools::TriggerAssert::GetDebugPrompt()
{
    static const auto debugPrompt = "�ڲ���������Ƿ�Ҫ���е��ԣ�"s;

    return debugPrompt;
}

string CoreTools::TriggerAssert::GetMessagePrefix()
{
    static const auto messagePrefix = "\n%sʧ����%s��%s��%d��:\n"s;

    return messagePrefix;
}

string CoreTools::TriggerAssert::GetTriggerAssertCheckInvariant()
{
    static const auto triggerAssertCheckInvariant = "����ʽ"s;

    return triggerAssertCheckInvariant;
}

string CoreTools::TriggerAssert::GetTriggerAssertCheckAssertion()
{
    static const auto triggerAssertCheckAssertion = "����"s;

    return triggerAssertCheckAssertion;
}
