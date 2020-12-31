//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 10:02)

#include "CoreTools/CoreToolsExport.h"

#include "CMainFunctionHelper.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Command/CommandHandle.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/MemoryTools/MemoryManager.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

using std::cerr;
using std::cout;
using std::exception;
using std::ofstream;
using std::ostream;
using namespace std::literals;

CoreTools::CMainFunctionHelper::CMainFunctionHelper(int argc, char** argv)
    : m_Argc{ argc }, m_Argv{ argv }, m_Stream{}, m_Schedule{ ScheduleType::Failure }
{
    try
    {
        InitSingleton();
    }
    catch (const Error& error)
    {
        CERR << error.GetError() << SYSTEM_TEXT('\n');
    }
    catch (const exception& error)
    {
        cerr << error.what() << '\n';
    }
    catch (...)
    {
        cerr << "未知错误\n";
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CMainFunctionHelper::CMainFunctionHelper(CMainFunctionHelper&& rhs) noexcept
    : m_Argc{ rhs.m_Argc }, m_Argv{ std::move(rhs.m_Argv) }, m_Stream{ std::move(rhs.m_Stream) }, m_Schedule{ rhs.m_Schedule }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CMainFunctionHelper& CoreTools::CMainFunctionHelper::operator=(CMainFunctionHelper&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_Argc = rhs.m_Argc;
    m_Argv = std::move(rhs.m_Argv);
    m_Stream = std::move(rhs.m_Stream);
    m_Schedule = rhs.m_Schedule;

    return *this;
}

CoreTools::CMainFunctionHelper::~CMainFunctionHelper() noexcept
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    DestroySingleton();
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::CMainFunctionHelper::IsValid() const noexcept
{
    if (m_Schedule < ScheduleType::Max)
        return true;
    else if (m_Argc < 1 || *m_Argv == nullptr)
        return false;
    else
        return true;
}
#endif  // OPEN_CLASS_INVARIANT

int CoreTools::CMainFunctionHelper::GetArgc() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Argc;
}

char** CoreTools::CMainFunctionHelper::GetArgv() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Argv;
}

int CoreTools::CMainFunctionHelper::Run() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    EXCEPTION_TRY
    {
        if (m_Schedule == ScheduleType::Max)
            return DoRun();
        else
            return -1;
    }
    EXCEPTION_ALL_CATCH(CoreTools)

    return -1;
}

// private
void CoreTools::CMainFunctionHelper::InitSingleton()
{
    InitUniqueIDManager();
    InitLog();
    InitMemory();
    GenerateStream();
    InitStreamLocale();
}

// private
void CoreTools::CMainFunctionHelper::InitUniqueIDManager()
{
    UniqueIDManager::Create(UniqueIDSelect::Max);

    m_Schedule = ScheduleType::UniqueIDManager;
}

// private
void CoreTools::CMainFunctionHelper::InitLog()
{
    Log::Create();
    LOG_SINGLETON.LoadConfiguration("Configuration/Log.json");

    m_Schedule = ScheduleType::Log;
}

// private
void CoreTools::CMainFunctionHelper::InitMemory() noexcept(g_MemoryNoexcept)
{
    MEMORY_CREATE;

    m_Schedule = ScheduleType::Memory;
}

// private
void CoreTools::CMainFunctionHelper::GenerateStream()
{
    if (m_Argc == 2)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        m_Stream = OStreamShared{ std::string{ m_Argv[1] } };
#include STSTEM_WARNING_POP
    }
    else if (2 < m_Argc)
    {
        CommandHandle command{ m_Argc, m_Argv };

        m_Stream = OStreamShared{ command.GetFileName() };
    }
    else
    {
        m_Stream = OStreamShared{};
    }

    m_Schedule = ScheduleType::Max;
}

// private
void CoreTools::CMainFunctionHelper::DestroySingleton() noexcept
{
    DestroyStream();
    DestroyMemory();
    DestroyLog();
    DestroyUniqueIDManager();
}

// private
void CoreTools::CMainFunctionHelper::DestroyStream() noexcept
{
}

// private
void CoreTools::CMainFunctionHelper::DestroyMemory() noexcept
{
    if (ScheduleType::Memory <= m_Schedule)
    {
        MEMORY_DESTROY;
    }
}

// private
void CoreTools::CMainFunctionHelper::DestroyLog() noexcept
{
    if (ScheduleType::Log <= m_Schedule)
    {
        Log::Destroy();
    }
}

// private
void CoreTools::CMainFunctionHelper::DestroyUniqueIDManager() noexcept
{
    if (ScheduleType::UniqueIDManager <= m_Schedule)
    {
        UniqueIDManager::Destroy();
    }
}

void CoreTools::CMainFunctionHelper::SystemPause() noexcept
{
    System::SystemPause();
}

void CoreTools::CMainFunctionHelper::InitStreamLocale()
{
    std::locale nullLocale{ ""s };

    COUT.imbue(nullLocale);
    CIN.imbue(nullLocale);
    CERR.imbue(nullLocale);
    CLOG.imbue(nullLocale);
}

CoreTools::OStreamShared CoreTools::CMainFunctionHelper::GetStreamShared() const noexcept
{
    return m_Stream;
}
