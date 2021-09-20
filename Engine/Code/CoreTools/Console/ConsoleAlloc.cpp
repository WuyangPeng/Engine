///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/30 19:03)

#include "CoreTools/CoreToolsExport.h"

#include "ConsoleAlloc.h"
#include "System/Console/ConsoleCreate.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <string>

using std::string;
using namespace std::literals;

CoreTools::ConsoleAlloc::ConsoleAlloc(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : out{ nullptr }, in{ nullptr }, error{ nullptr }
{
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
    if (out != nullptr && in != nullptr && error != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void CoreTools::ConsoleAlloc::OpenConsole()
{
    const auto allocSuccess = System::AllocConsole();

    if (!allocSuccess)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����̨��������"s));
    }

    ReOpenConsole();
}

void CoreTools::ConsoleAlloc::ReOpenConsole()
{
    const auto outPath = "CONOUT$"s;
    const auto inPath = "CONOUT$"s;
    const auto outMode = "w+t"s;
    const auto inMode = "r+t"s;

    if (!(System::FReOpenConsole(out, outPath.c_str(), outMode.c_str(), stdout) &&
          System::FReOpenConsole(in, inPath.c_str(), inMode.c_str(), stdin) &&
          System::FReOpenConsole(error, outPath.c_str(), outMode.c_str(), stderr) &&
          System::RemoveConsoleCloseButton()))
    {
        CloseConsole();

        THROW_EXCEPTION(SYSTEM_TEXT("�ض�λ����̨����"s));
    }
}

void CoreTools::ConsoleAlloc::CloseConsole() noexcept
{
    CloseConsole(out);
    CloseConsole(in);
    CloseConsole(error);

    if (!System::FreeConsole())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("�رտ���̨����")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

void CoreTools::ConsoleAlloc::CloseConsole(FILE* file) noexcept
{
    if (file != nullptr)
    {
        if (!System::FCloseConsole(file))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
                << SYSTEM_TEXT("�ͷſ���̨�ļ�����������")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
    }
}
