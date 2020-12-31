//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 17:50)

#include "Network/NetworkExport.h"

#include "BoostMainManagerUseThreads.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/Configuration/ConfigurationSubStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::make_unique;
using std::move;

Network::BoostMainManagerUseThreads::BoostMainManagerUseThreads(const ConfigurationSubStrategy& subStrategy)
    : ParentType{}, m_Thread{}, m_ThreadNumber{ subStrategy.GetValue(WrappersSubStrategy::Threads) }
{
    DoInitThread();

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostMainManagerUseThreads::~BoostMainManagerUseThreads() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    CoreTools::NoexceptNoReturn(*this, &ClassType::JoinThreads);
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostMainManagerUseThreads)

// private
void Network::BoostMainManagerUseThreads::InitThread()
{
    DoJoinThreads();
    DoInitThread();
}

// private
void Network::BoostMainManagerUseThreads::JoinThreads()
{
    DispatchStopContext();
    DoJoinThreads();
}

void Network::BoostMainManagerUseThreads::StopContext()
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    JoinThreads();
}

void Network::BoostMainManagerUseThreads::RestartContext()
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    ParentType::RestartContext();

    InitThread();
}

void Network::BoostMainManagerUseThreads::Run() noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

// private
void Network::BoostMainManagerUseThreads::ThreadsRun()
{
    ParentType::Run();
}

// private
void Network::BoostMainManagerUseThreads::DoJoinThreads()
{
    for (auto& value : m_Thread)
    {
        value.join();
    }

    m_Thread.clear();
}

// private
void Network::BoostMainManagerUseThreads::DoInitThread()
{
    for (auto i = 0; i < m_ThreadNumber; ++i)
    {
        auto thread = make_unique<ThreadType>(&ClassType::ThreadsRun, this);
        m_Thread.push_back(move(thread));
    }

    if (m_Thread.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("boost 线程数量为零！"s));
    }
}
