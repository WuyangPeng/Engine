//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 17:53)

#include "Network/NetworkExport.h"

#include "ExecutorWorkGuardContextThread.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::make_unique;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Network::ExecutorWorkGuardContextThread::ExecutorWorkGuardContextThread()
    : m_ExecutorWorkGuardContext{}, m_Thread{}
{
    InitThread();

    NETWORK_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP

Network::ExecutorWorkGuardContextThread::~ExecutorWorkGuardContextThread() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    CoreTools::NoexceptNoReturn(*this, &ClassType::JoinThreads);
}

CLASS_INVARIANT_STUB_DEFINE(Network, ExecutorWorkGuardContextThread)

Network::IOContextType& Network::ExecutorWorkGuardContextThread::GetIOContext() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return m_ExecutorWorkGuardContext.GetIOContext();
}

void Network::ExecutorWorkGuardContextThread::StopContext()
{
    NETWORK_CLASS_IS_VALID_9;

    m_ExecutorWorkGuardContext.PostStopContext();

    JoinThreads();
}

bool Network::ExecutorWorkGuardContextThread::IsContextStop() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_ExecutorWorkGuardContext.IsContextStop();
}

void Network::ExecutorWorkGuardContextThread::RestartContext()
{
    NETWORK_CLASS_IS_VALID_9;

    JoinThreads();

    m_ExecutorWorkGuardContext.RestartContext();

    InitThread();
}

// private
void Network::ExecutorWorkGuardContextThread::InitThread()
{
    m_Thread = make_unique<ThreadType>(&ExecutorWorkGuardContext::Run, &m_ExecutorWorkGuardContext);
}

// private
void Network::ExecutorWorkGuardContextThread::JoinThreads()
{
    if (m_Thread != nullptr)
    {
        m_Thread->join();

        m_Thread.reset();
    }
}
