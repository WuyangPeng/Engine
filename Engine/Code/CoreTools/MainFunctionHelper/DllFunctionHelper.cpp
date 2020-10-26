//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 10:08)

#include "CoreTools/CoreToolsExport.h"

#include "DllFunctionHelper.h"
#include "System/SystemOutput/Flags/DialogBoxCommandFlags.h"
#include "System/SystemOutput/MessageBoxSelection.h"
#include "System/Window/WindowSystem.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Threading/DllMutex.h"

#include <stdexcept>

using std::runtime_error;
using std::string;
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
        JudgeUserSelectionWithTChar(error.GetError().c_str());
    }
    catch (const runtime_error& error)
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
        case System::DialogBoxCommand::IDYes:
        {
            // ���Զϵ㡣
            System::DebugBreak();

            break;
        }
        case System::DialogBoxCommand::IDNo:
        {
            // ����ִ�С�
            break;
        }
        case System::DialogBoxCommand::IDCancel:
        default:
        {
            // ��ִֹ�С�
            System::Exit();
            break;
        }
    }
}

void CoreTools::DllFunctionHelper::JudgeUserSelectionWithChar(const string& message) noexcept
{
    const auto type = System::MessageBoxSelectionWithChar(message.c_str(), "����");

    JudgeSelection(type);
}
