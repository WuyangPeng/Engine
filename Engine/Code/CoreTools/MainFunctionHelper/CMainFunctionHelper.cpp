///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:40)

#include "CoreTools/CoreToolsExport.h"

#include "CMainFunctionHelper.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Command/CommandHandle.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <fstream>
#include <iostream>

using namespace std::literals;

CoreTools::CMainFunctionHelper::CMainFunctionHelper(int argc, char** argv)
    : argc{ argc }, argv{ argv }, stream{ true }, schedule{ ScheduleType::Failure }
{
    try
    {
        InitSingleton();
    }
    catch (const Error& error)
    {
        CERR << error.GetError() << SYSTEM_TEXT('\n');
    }
    catch (const std::exception& error)
    {
        std::cerr << error.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "未知错误\n";
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CMainFunctionHelper::CMainFunctionHelper(CMainFunctionHelper&& rhs) noexcept
    : argc{ rhs.argc }, argv{ rhs.argv }, stream{ std::move(rhs.stream) }, schedule{ rhs.schedule }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CMainFunctionHelper& CoreTools::CMainFunctionHelper::operator=(CMainFunctionHelper&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (this != &rhs)
    {
        argc = rhs.argc;
        argv = rhs.argv;
        stream = std::move(rhs.stream);
        schedule = rhs.schedule;
    }

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
    if (schedule < ScheduleType::Max)
        return true;
    else if (argc < 1 || *argv == nullptr)
        return false;
    else
        return true;
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::CMainFunctionHelper::GetArgc() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return argc;
}

char** CoreTools::CMainFunctionHelper::GetArgv() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return argv;
}

char* CoreTools::CMainFunctionHelper::GetArgv(int index) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return argv[index];

#include SYSTEM_WARNING_POP
}

int CoreTools::CMainFunctionHelper::Run() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    EXCEPTION_TRY
    {
        if (schedule == ScheduleType::Max)
            return DoRun();
        else
            return -1;
    }
    EXCEPTION_ALL_CATCH(CoreTools)

    return -1;
}

void CoreTools::CMainFunctionHelper::InitSingleton()
{
    InitUniqueIdManager();
    InitLog();
    GenerateStream();
    InitStreamLocale();
}

void CoreTools::CMainFunctionHelper::InitUniqueIdManager()
{
    UniqueIdManager::Create(UniqueIdSelect::Max);

    schedule = ScheduleType::UniqueIdManager;
}

void CoreTools::CMainFunctionHelper::InitLog()
{
    Log::Create();
    LOG_SINGLETON.LoadConfiguration("Configuration/Log.json");

    schedule = ScheduleType::Log;
}

void CoreTools::CMainFunctionHelper::GenerateStream()
{
    if (argc == 2)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        stream = OStreamShared{ std::string{ argv[1] } };

#include SYSTEM_WARNING_POP
    }
    else if (2 < argc)
    {
        const CommandHandle command{ argc, argv };

        stream = OStreamShared{ command.GetFileName() };
    }
    else
    {
        stream = OStreamShared{ true };
    }

    schedule = ScheduleType::Max;
}

void CoreTools::CMainFunctionHelper::DestroySingleton() noexcept
{
    DestroyStream();
    DestroyLog();
    DestroyUniqueIdManager();
}

void CoreTools::CMainFunctionHelper::DestroyStream() noexcept
{
}

void CoreTools::CMainFunctionHelper::DestroyLog() noexcept
{
    if (ScheduleType::Log <= schedule)
    {
        Log::Destroy();
    }
}

void CoreTools::CMainFunctionHelper::DestroyUniqueIdManager() noexcept
{
    if (ScheduleType::UniqueIdManager <= schedule)
    {
        UniqueIdManager::Destroy();
    }
}

void CoreTools::CMainFunctionHelper::SystemPause() noexcept
{
    System::SystemPause();
}

void CoreTools::CMainFunctionHelper::InitStreamLocale()
{
    const std::locale nullLocale{ ""s };

    COUT.imbue(nullLocale);
    CIN.imbue(nullLocale);
    CERR.imbue(nullLocale);
    CLOG.imbue(nullLocale);
}

CoreTools::OStreamShared CoreTools::CMainFunctionHelper::GetStreamShared() const noexcept
{
    return stream;
}
