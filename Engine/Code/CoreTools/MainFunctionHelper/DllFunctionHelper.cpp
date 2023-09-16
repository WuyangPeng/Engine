///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 16:44)

#include "CoreTools/CoreToolsExport.h"

#include "DllFunctionHelper.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/SystemOutput/MessageBoxSelection.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Threading/DllMutex.h"

#include <stdexcept>

using namespace std::literals;

void CoreTools::DllFunctionHelper::InitializeMutex(DllMutex* mutex)
{
    CORE_TOOLS_ASSERTION_0(mutex != nullptr, "DllMutexָ��Ϊ�գ�");

    try
    {
        mutex->Initialize();
    }
    catch (const Error& error)
    {
        JudgeUserSelectionWithTChar(error.GetError());
    }
    catch (const std::runtime_error& error)
    {
        JudgeUserSelectionWithChar(error.what());
    }
    catch (...)
    {
        JudgeUserSelectionWithTChar(SYSTEM_TEXT("δ֪����"s));
    }
}

void CoreTools::DllFunctionHelper::DeleteMutex(DllMutex* mutex)
{
    CORE_TOOLS_ASSERTION_0(mutex != nullptr, "DllMutexָ��Ϊ�գ�");

    mutex->Delete();
}

void CoreTools::DllFunctionHelper::JudgeUserSelectionWithTChar(const System::String& message) noexcept
{
    const System::DialogBoxCommand type = System::MessageBoxSelectionWithTChar(message.c_str(), SYSTEM_TEXT("����"));

    JudgeSelection(type);
}

void CoreTools::DllFunctionHelper::JudgeSelection(System::DialogBoxCommand selection) noexcept
{
    switch (selection)
    {
        case System::DialogBoxCommand::IdYes:
        {
            // ���Զϵ㡣
            System::DebugBreak();

            break;
        }
        case System::DialogBoxCommand::IdNo:
        {
            // ����ִ�С�
            break;
        }
        case System::DialogBoxCommand::IdCancel:
        default:
        {
            // ��ִֹ�С�
            System::Exit();
            break;
        }
    }
}

void CoreTools::DllFunctionHelper::JudgeUserSelectionWithChar(const std::string& message) noexcept
{
    const auto type = System::MessageBoxSelectionWithChar(message.c_str(), "����");

    JudgeSelection(type);
}
