//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 15:22)

#include "CoreTools/CoreToolsExport.h"

#include "ConsoleAlloc.h"
#include "System/Console/ConsoleCreate.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <string>

using std::string;

CoreTools::ConsoleAlloc::ConsoleAlloc([[maybe_unused]] DisableNotThrow disableNotThrow)
    : m_Out{ nullptr }, m_In{ nullptr }, m_Error{ nullptr }
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
    if (m_Out != nullptr && m_In != nullptr && m_Error != nullptr)
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

    const string outPath{ "CONOUT$" };
    const string inPath{ "CONOUT$" };
    const string outMode{ "w+t" };
    const string inMode{ "r+t" };

    if (!(System::FReOpenConsole(m_Out, outPath.c_str(), outMode.c_str(), stdout) &&
          System::FReOpenConsole(m_In, inPath.c_str(), inMode.c_str(), stdin) &&
          System::FReOpenConsole(m_Error, outPath.c_str(), outMode.c_str(), stderr) &&
          System::RemoveConsoleCloseButton()))
    {
        CloseConsole();

        THROW_EXCEPTION(SYSTEM_TEXT("�ض�λ����̨����"s));
    }
}

void CoreTools::ConsoleAlloc::CloseConsole() noexcept
{
    if (!(m_Out != nullptr && System::FCloseConsole(m_Out) &&
          m_In != nullptr && System::FCloseConsole(m_In) &&
          m_Error != nullptr && System::FCloseConsole(m_Error)))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("�ͷſ���̨�ļ�����������")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }

    if (!System::FreeConsole())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
            << SYSTEM_TEXT("�رտ���̨����")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}
