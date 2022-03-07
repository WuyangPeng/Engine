///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 22:43)

#include "CoreTools/CoreToolsExport.h"

#include "Appender.h"
#include "Log.h"
#include "LogAsynchronous.h"
#include "Detail/LogImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::make_unique;
using std::string;

SINGLETON_GET_PTR_DEFINE(CoreTools, Log);

CoreTools::Log::LogUniquePtr CoreTools::Log::log{};

void CoreTools::Log::Create()
{
    LogAsynchronous::Create();

    LOG_ASYNCHRONOUS_SINGLETON.Run();

    log = make_unique<CoreTools::Log>(LogCreate::Init);
}

void CoreTools::Log::Destroy() noexcept
{
    log.reset();

    EXCEPTION_TRY
    {
        LOG_ASYNCHRONOUS_SINGLETON.Stop();
    }
    EXCEPTION_ALL_CATCH(CoreTools)

    LogAsynchronous::Destroy();
}

CoreTools::Log::Log(MAYBE_UNUSED LogCreate logCreate)
    : impl{ DisableNotThrow::Disable }, errorLogAppenderIOManager{ LogAppenderIOManager::Create() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Log)

void CoreTools::Log::InsertAppender(const String& name, const Appender& appenderPtr)
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    return impl->InsertAppender(name, appenderPtr);
}

void CoreTools::Log::RemoveAppender(const String& name)
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    return impl->RemoveAppender(name);
}

void CoreTools::Log::LoadConfiguration(const string& fileName)
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    return impl->LoadConfiguration(fileName);
}

CoreTools::LogAppenderIOManager& CoreTools::Log::OutTrace() noexcept
{
    try
    {
        SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

        return impl->OutTrace();
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("OutTrace抛出异常"));
    }

    return errorLogAppenderIOManager;
}

CoreTools::LogAppenderIOManager& CoreTools::Log::OutDebug() noexcept
{
    try
    {
        SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

        return impl->OutDebug();
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("OutDebug抛出异常"));
    }

    return errorLogAppenderIOManager;
}

CoreTools::LogAppenderIOManager& CoreTools::Log::OutInfo() noexcept
{
    try
    {
        SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

        return impl->OutInfo();
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("OutInfo抛出异常"));
    }

    return errorLogAppenderIOManager;
}

CoreTools::LogAppenderIOManager& CoreTools::Log::OutWarn() noexcept
{
    try
    {
        SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

        return impl->OutWarn();
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("OutWarn抛出异常"));
    }

    return errorLogAppenderIOManager;
}

CoreTools::LogAppenderIOManager& CoreTools::Log::OutError() noexcept
{
    try
    {
        SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

        return impl->OutError();
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("OutError抛出异常"));
    }

    return errorLogAppenderIOManager;
}

CoreTools::LogAppenderIOManager& CoreTools::Log::OutFatal() noexcept
{
    try
    {
        SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

        return impl->OutFatal();
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("OutFatal抛出异常"));
    }

    return errorLogAppenderIOManager;
}

void CoreTools::Log::ReloadAppenderFile()
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    return impl->ReloadAppenderFile();
}
