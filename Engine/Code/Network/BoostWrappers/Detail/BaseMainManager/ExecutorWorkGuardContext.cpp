///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/22 22:31)

#include "Network/NetworkExport.h"

#include "ExecutorWorkGuardContext.h"
#include "System/Helper/PragmaWarning/AsioPost.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using boost::asio::post;
using boost::system::system_error;
using CoreTools::Error;
using std::bind;
using std::exception;

Network::ExecutorWorkGuardContext::ExecutorWorkGuardContext(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ioContext{}, work{ make_work_guard(ioContext) }
{
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
        catch (const Error& error)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                << error
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
        catch (const system_error& error)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                << error.what()
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
        catch (const exception& error)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                << error.what()
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
        catch (...)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                << "未知错误\n"
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
    }
}

Network::IOContextType& Network::ExecutorWorkGuardContext::GetIOContext() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return ioContext;
}

void Network::ExecutorWorkGuardContext::PostStopContext()
{
    NETWORK_CLASS_IS_VALID_9;

    post(ioContext, bind(&IOContextType::stop, &ioContext));
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
