//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 17:53)

#include "Network/NetworkExport.h"

#include "ExecutorWorkGuardContextThread.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::make_unique;

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

Network::IOContextType& Network::ExecutorWorkGuardContextThread::GetIOContext() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return executorWorkGuardContext.GetIOContext();
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

// private
void Network::ExecutorWorkGuardContextThread::InitThread()
{
    thread = make_unique<ThreadType>(&ExecutorWorkGuardContext::Run, &executorWorkGuardContext);
}

// private
void Network::ExecutorWorkGuardContextThread::JoinThreads()
{
    if (thread != nullptr)
    {
        thread->join();

        thread.reset();
    }
}
