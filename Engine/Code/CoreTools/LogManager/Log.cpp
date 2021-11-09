//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.2 (2020/10/15 18:49)

#include "CoreTools/CoreToolsExport.h"

#include "Appender.h"
#include "Log.h"
#include "Detail/LogImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::make_unique;
using std::string;

SINGLETON_GET_PTR_DEFINE(CoreTools, Log);

CoreTools::Log::LogUniquePtr CoreTools::Log::sm_Log{};

void CoreTools::Log::Create()
{
    sm_Log = make_unique<CoreTools::Log>(LogCreate::Init);
}

void CoreTools::Log::Destroy() noexcept
{
    sm_Log.reset();
}

CoreTools::Log::Log([[maybe_unused]] LogCreate logCreate)
    : impl{ DisableNotThrow::Disable }
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
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("OutTrace�׳��쳣"));
    }

    return impl->OutTrace();
}

CoreTools::LogAppenderIOManager& CoreTools::Log::OutDebug() noexcept
{
    try
    {
        SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("OutDebug�׳��쳣"));
    }

    return impl->OutDebug();
}

CoreTools::LogAppenderIOManager& CoreTools::Log::OutInfo() noexcept
{
    try
    {
        SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("OutInfo�׳��쳣"));
    }

    return impl->OutInfo();
}

CoreTools::LogAppenderIOManager& CoreTools::Log::OutWarn() noexcept
{
    try
    {
        SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("OutWarn�׳��쳣"));
    }

    return impl->OutWarn();
}

CoreTools::LogAppenderIOManager& CoreTools::Log::OutError() noexcept
{
    try
    {
        SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("OutError�׳��쳣"));
    }

    return impl->OutError();
}

CoreTools::LogAppenderIOManager& CoreTools::Log::OutFatal() noexcept
{
    try
    {
        SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;
    }
    catch (...)
    {
        System::OutputDebugStringWithTChar(SYSTEM_TEXT("OutFatal�׳��쳣"));
    }

    return impl->OutFatal();
}

void CoreTools::Log::ReloadAppenderFile()
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    return impl->ReloadAppenderFile();
}
