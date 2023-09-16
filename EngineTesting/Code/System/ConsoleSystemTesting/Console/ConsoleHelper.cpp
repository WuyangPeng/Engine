///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 13:37)

#include "ConsoleHelper.h"
#include "System/Console/ConsoleCreate.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"

#include <iostream>

ConsoleSystemTesting::ConsoleHelper::ConsoleHelper() noexcept
    : out{ nullptr }, in{ nullptr }, error{ nullptr }, isSuccess{ false }
{
    AllocConsole();

    SYSTEM_SELF_CLASS_IS_VALID_1;
}

void ConsoleSystemTesting::ConsoleHelper::AllocConsole() noexcept
{
    if (DoAllocConsole())
    {
        isSuccess = true;
    }
    else
    {
        isSuccess = false;

        LOG_SINGLETON_APPENDER(Error, User, SYSTEM_TEXT("创建控制台失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

ConsoleSystemTesting::ConsoleHelper::~ConsoleHelper() noexcept
{
    SYSTEM_SELF_CLASS_IS_VALID_1;

    FreeConsole();
}

void ConsoleSystemTesting::ConsoleHelper::FreeConsole() noexcept
{
    if (!DoFreeConsole())
    {
        LOG_SINGLETON_APPENDER(Error, User, SYSTEM_TEXT("销毁控制台失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool ConsoleSystemTesting::ConsoleHelper::IsValid() const noexcept
{
    if (isSuccess)
    {
        if (in != nullptr && out != nullptr && error != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}

#endif  // OPEN_CLASS_INVARIANT

bool ConsoleSystemTesting::ConsoleHelper::IsSuccess() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return isSuccess;
}

void ConsoleSystemTesting::ConsoleHelper::PrintConsoleInfo()
{
    std::cout << "一共有两行消息显示在控制台。" << std::endl;
    std::cerr << "控制台没有关闭按钮。" << std::endl;
}

bool ConsoleSystemTesting::ConsoleHelper::DoAllocConsole() noexcept
{
    return System::AllocConsole() &&
           System::ReOpenConsole(out, "CONOUT$", "w+t", stdout) &&
           System::ReOpenConsole(in, "CONIN$", "r+t", stdin) &&
           System::ReOpenConsole(error, "CONOUT$", "w+t", stderr) &&
           System::RemoveConsoleCloseButton();
}

bool ConsoleSystemTesting::ConsoleHelper::DoFreeConsole() noexcept
{
    return System::CloseConsole(error) &&
           System::CloseConsole(in) &&
           System::CloseConsole(out) &&
           System::FreeConsole();
}
