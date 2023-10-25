///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 10:00)

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
#include "CoreTools/LogManager/Detail/AnalysisAppenderManager.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

SINGLETON_GET_PTR_DEFINE(CoreTools, Log);

CoreTools::Log::LogUniquePtr CoreTools::Log::log{};

void CoreTools::Log::Create()
{
    LogAsynchronous::Create();

    LOG_ASYNCHRONOUS_SINGLETON.Run();

    log = std::make_unique<Log>(LogCreate::Init);
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

CoreTools::Log::Log(LogCreate logCreate)
    : impl{ DisableNotThrow::Disable }
{
    System::UnusedFunction(logCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Log)

void CoreTools::Log::LoadConfiguration(const std::string& fileName)
{
    try
    {
        // 从文件读取数据的操作不需要加锁处理。
        const AnalysisAppenderManager analysis{ fileName };

        SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

        return impl->LoadConfiguration(analysis);
    }
    catch (const boost::property_tree::ptree_error& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

CoreTools::LogLevel CoreTools::Log::GetMinLogLevelType(LogFilter filter) const
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    return impl->GetMinLogLevelType(filter);
}

void CoreTools::Log::Write(const LogMessage& logMessage)
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    impl->Write(logMessage);
}