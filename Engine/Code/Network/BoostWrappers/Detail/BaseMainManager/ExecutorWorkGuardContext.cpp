///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 14:25)

#include "Network/NetworkExport.h"

#include "ExecutorWorkGuardContext.h"
#include "System/Helper/PragmaWarning/AsioPost.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::ExecutorWorkGuardContext::ExecutorWorkGuardContext(CoreTools::DisableNotThrow disableNotThrow)
    : ioContext{}, work{ make_work_guard(ioContext) }
{
    System::UnusedFunction(disableNotThrow);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ExecutorWorkGuardContext)

void Network::ExecutorWorkGuardContext::Run()
{
    NETWORK_CLASS_IS_VALID_9;

    for (;;)
    {
        try
        {
            ioContext.run();
            break;
        }
        catch (const CoreTools::Error& error)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
        catch (const std::system_error& error)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
        catch (const std::exception& error)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
        catch (...)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, "未知错误\n", CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
}

Network::IoContextType& Network::ExecutorWorkGuardContext::GetContext() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return ioContext;
}

void Network::ExecutorWorkGuardContext::PostStopContext()
{
    NETWORK_CLASS_IS_VALID_9;

    post(ioContext, std::bind(&IoContextType::stop, &ioContext));
}

bool Network::ExecutorWorkGuardContext::IsContextStop() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ioContext.stopped();
}

void Network::ExecutorWorkGuardContext::RestartContext()
{
    NETWORK_CLASS_IS_VALID_9;

    ioContext.restart();
}

void Network::ExecutorWorkGuardContext::DispatchStopContext()
{
    ioContext.stop();
}
