///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/11 16:09)

#include "ConsoleHelper.h"
#include "System/Console/ConsoleCreate.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"

#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

ConsoleSystemTesting::ConsoleHelper::ConsoleHelper() noexcept
    : out{ nullptr }, in{ nullptr }, error{ nullptr }, isSuccess{ false }
{
    AllocConsole();

    SYSTEM_SELF_CLASS_IS_VALID_1;
}

// private
void ConsoleSystemTesting::ConsoleHelper::AllocConsole() noexcept
{
    if (System::AllocConsole() &&
        System::FReOpenConsole(out, "CONOUT$", "w+t", stdout) &&
        System::FReOpenConsole(in, "CONIN$", "r+t", stdin) &&
        System::FReOpenConsole(error, "CONOUT$", "w+t", stderr) &&
        System::RemoveConsoleCloseButton())
    {
        isSuccess = true;
    }
    else
    {
        isSuccess = false;

        LOG_SINGLETON_APPENDER(Error, User)
            << SYSTEM_TEXT("��������̨ʧ�ܣ�")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

ConsoleSystemTesting::ConsoleHelper::~ConsoleHelper() noexcept
{
    SYSTEM_SELF_CLASS_IS_VALID_1;

    FreeConsole();
}

// private
void ConsoleSystemTesting::ConsoleHelper::FreeConsole() noexcept
{
    if (!(System::FCloseConsole(out) &&
          System::FCloseConsole(in) &&
          System::FCloseConsole(error) &&
          System::FreeConsole()))
    {
        LOG_SINGLETON_APPENDER(Error, User)
            << SYSTEM_TEXT("���ٿ���̨ʧ�ܣ�")
            << LOG_SINGLETON_TRIGGER_ASSERT;
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
    cout << "һ����������Ϣ��ʾ�ڿ���̨��" << endl;
    cerr << "����̨û�йرհ�ť��" << endl;
}
