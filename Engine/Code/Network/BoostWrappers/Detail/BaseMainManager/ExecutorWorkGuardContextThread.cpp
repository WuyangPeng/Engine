/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:25)

#include "Network/NetworkExport.h"

#include "ExecutorWorkGuardContextThread.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::ExecutorWorkGuardContextThread::ExecutorWorkGuardContextThread(CoreTools::DisableNotThrow disableNotThrow)
    : executorWorkGuardContext{ disableNotThrow }, thread{}
{
    InitThread();

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ExecutorWorkGuardContextThread::~ExecutorWorkGuardContextThread() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    CoreTools::NoexceptNoReturn(*this, &ClassType::JoinThreads);
}

CLASS_INVARIANT_STUB_DEFINE(Network, ExecutorWorkGuardContextThread)

Network::IoContextType& Network::ExecutorWorkGuardContextThread::GetContext() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return executorWorkGuardContext.GetContext();
}

void Network::ExecutorWorkGuardContextThread::StopContext()
{
    NETWORK_CLASS_IS_VALID_9;

    executorWorkGuardContext.PostStopContext();

    JoinThreads();
}

bool Network::ExecutorWorkGuardContextThread::IsContextStop() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return executorWorkGuardContext.IsContextStop();
}

void Network::ExecutorWorkGuardContextThread::RestartContext()
{
    NETWORK_CLASS_IS_VALID_9;

    JoinThreads();

    executorWorkGuardContext.RestartContext();

    InitThread();
}

void Network::ExecutorWorkGuardContextThread::InitThread()
{
    thread = std::make_unique<ThreadType>(&ExecutorWorkGuardContext::Run, &executorWorkGuardContext);
}

void Network::ExecutorWorkGuardContextThread::JoinThreads()
{
    if (thread != nullptr)
    {
        thread->join();

        thread.reset();
    }
}
