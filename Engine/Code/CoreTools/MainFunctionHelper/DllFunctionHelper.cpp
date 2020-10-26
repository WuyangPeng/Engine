//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 10:08)

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
    CORE_TOOLS_ASSERTION_0(mutex != nullptr, "DllMutex指针为空！");

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
        JudgeUserSelectionWithTChar(SYSTEM_TEXT("未知错误！"s));
    }
}

void CoreTools::DllFunctionHelper::DeleteMutex(DllMutex* mutex)
{
    CORE_TOOLS_ASSERTION_0(mutex != nullptr, "DllMutex指针为空！");

    mutex->Delete();
}

void CoreTools::DllFunctionHelper::JudgeUserSelectionWithTChar(const System::String& message) noexcept
{
    const System::DialogBoxCommand type = System::MessageBoxSelectionWithTChar(message.c_str(), SYSTEM_TEXT("错误"));

    JudgeSelection(type);
}

void CoreTools::DllFunctionHelper::JudgeSelection(System::DialogBoxCommand selection) noexcept
{
    switch (selection)
    {
        case System::DialogBoxCommand::IDYes:
        {
            // 调试断点。
            System::DebugBreak();

            break;
        }
        case System::DialogBoxCommand::IDNo:
        {
            // 继续执行。
            break;
        }
        case System::DialogBoxCommand::IDCancel:
        default:
        {
            // 终止执行。
            System::Exit();
            break;
        }
    }
}

void CoreTools::DllFunctionHelper::JudgeUserSelectionWithChar(const string& message) noexcept
{
    const auto type = System::MessageBoxSelectionWithChar(message.c_str(), "错误");

    JudgeSelection(type);
}
