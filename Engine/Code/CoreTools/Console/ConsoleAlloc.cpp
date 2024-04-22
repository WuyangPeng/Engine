/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 14:51)

#include "CoreTools/CoreToolsExport.h"

#include "ConsoleAlloc.h"
#include "System/Console/ConsoleCreate.h"
#include "System/Console/Using/ConsoleCreateUsing.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/LogManager/LogAsynchronous.h"

#include <string>

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
    if (const auto allocSuccess = System::AllocConsole();
        !allocSuccess)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����̨��������"s))
    }

    ReOpenConsole();
}

void CoreTools::ConsoleAlloc::ReOpenConsole()
{
    if (!(System::ReOpenConsole(out, System::stdOutPath, System::stdOutMode, stdout) &&
          System::ReOpenConsole(in, System::stdInPath, System::stdInMode, stdin) &&
          System::ReOpenConsole(error, System::stdOutPath, System::stdOutMode, stderr) &&
          System::RemoveConsoleCloseButton()))
    {
        CloseConsole();

        THROW_EXCEPTION(SYSTEM_TEXT("�ض�λ����̨����"s))
    }
}

void CoreTools::ConsoleAlloc::LogWait()
{
    LOG_ASYNCHRONOUS_SINGLETON.Wait();
}

void CoreTools::ConsoleAlloc::CloseConsole() const noexcept
{
    System::NoexceptNoReturn(&ClassType::LogWait);

    CloseConsole(out);
    CloseConsole(in);
    CloseConsole(error);

    if (!System::FreeConsole())
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("�رտ���̨����"));
    }
}

void CoreTools::ConsoleAlloc::CloseConsole(FILE* file) noexcept
{
    if (file != nullptr && !System::CloseConsole(file))
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("�ͷſ���̨�ļ�����������"));
    }
}
