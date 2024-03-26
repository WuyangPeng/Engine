/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 17:26)

#include "ConsoleHelper.h"
#include "System/Console/ConsoleCreate.h"
#include "System/Console/Using/ConsoleCreateUsing.h"
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

        LOG_SINGLETON_APPENDER(Error, System, SYSTEM_TEXT("创建控制台失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

ConsoleSystemTesting::ConsoleHelper::~ConsoleHelper() noexcept
{
    SYSTEM_SELF_CLASS_IS_VALID_1;

    FreeConsole();
}

void ConsoleSystemTesting::ConsoleHelper::FreeConsole() const noexcept
{
    if (!DoFreeConsole())
    {
        LOG_SINGLETON_APPENDER(Error, System, SYSTEM_TEXT("销毁控制台失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool ConsoleSystemTesting::ConsoleHelper::IsValid() const noexcept
{
    return !isSuccess || (in != nullptr && out != nullptr && error != nullptr);
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
           System::ReOpenConsole(out, System::stdOutPath, System::stdOutMode, stdout) &&
           System::ReOpenConsole(in, System::stdInPath, System::stdInMode, stdin) &&
           System::ReOpenConsole(error, System::stdOutPath, System::stdOutMode, stderr) &&
           System::RemoveConsoleCloseButton();
}

bool ConsoleSystemTesting::ConsoleHelper::DoFreeConsole() const noexcept
{
    return System::CloseConsole(error) &&
           System::CloseConsole(in) &&
           System::CloseConsole(out) &&
           System::FreeConsole();
}
