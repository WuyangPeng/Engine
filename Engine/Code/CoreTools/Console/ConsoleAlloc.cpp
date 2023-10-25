///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 10:01)

#include "CoreTools/CoreToolsExport.h"

#include "ConsoleAlloc.h"
#include "System/Console/ConsoleCreate.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/LogManager/LogAsynchronous.h"

#include <string>

using namespace std::literals;

CoreTools::ConsoleAlloc CoreTools::ConsoleAlloc::Create()
{
    return ConsoleAlloc{ DisableNotThrow::Disable };
}

CoreTools::ConsoleAlloc::ConsoleAlloc(DisableNotThrow disableNotThrow)
    : out{ nullptr }, in{ nullptr }, error{ nullptr }
{
    System::UnusedFunction(disableNotThrow);

    OpenConsole();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::ConsoleAlloc::~ConsoleAlloc() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    CloseConsole();
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::ConsoleAlloc::IsValid() const noexcept
{
    return out != nullptr && in != nullptr && error != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::ConsoleAlloc::OpenConsole()
{
    if (const auto allocSuccess = System::AllocConsole(); !allocSuccess)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����̨��������"s))
    }

    ReOpenConsole();
}

void CoreTools::ConsoleAlloc::ReOpenConsole()
{
    const auto outPath = "CONOUT$"s;
    const auto inPath = "CONOUT$"s;
    const auto outMode = "w+t"s;
    const auto inMode = "r+t"s;

    if (!(System::ReOpenConsole(out, outPath.c_str(), outMode.c_str(), stdout) &&
          System::ReOpenConsole(in, inPath.c_str(), inMode.c_str(), stdin) &&
          System::ReOpenConsole(error, outPath.c_str(), outMode.c_str(), stderr) &&
          System::RemoveConsoleCloseButton()))
    {
        CloseConsole();

        THROW_EXCEPTION(SYSTEM_TEXT("�ض�λ����̨����"s))
    }
}

void CoreTools::ConsoleAlloc::CloseConsole() const noexcept
{
    try
    {
        LOG_ASYNCHRONOUS_SINGLETON.Wait();
    }
    catch (...)
    {
    }

    CloseConsole(out);
    CloseConsole(in);
    CloseConsole(error);

    if (!System::FreeConsole())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("�رտ���̨����"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

void CoreTools::ConsoleAlloc::CloseConsole(FILE* file) noexcept
{
    if (file != nullptr && !System::CloseConsole(file))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("�ͷſ���̨�ļ�����������"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}
