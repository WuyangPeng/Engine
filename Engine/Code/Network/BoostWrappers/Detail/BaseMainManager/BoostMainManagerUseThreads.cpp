///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:22)

#include "Network/NetworkExport.h"

#include "BoostMainManagerUseThreads.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/Configuration/ConfigurationSubStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

Network::BoostMainManagerUseThreads::BoostMainManagerUseThreads(const ConfigurationSubStrategy& subStrategy)
    : ParentType{ CoreTools::DisableNotThrow::Disable }, threads{}, threadNumber{ subStrategy.GetValue(WrappersSubStrategy::Threads) }
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

void Network::BoostMainManagerUseThreads::InitThread()
{
    DoJoinThreads();
    DoInitThread();
}

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

void Network::BoostMainManagerUseThreads::ThreadsRun()
{
    ParentType::Run();
}

void Network::BoostMainManagerUseThreads::DoJoinThreads()
{
    for (auto& value : threads)
    {
        value.join();
    }

    threads.clear();
}

void Network::BoostMainManagerUseThreads::DoInitThread()
{
    for (auto i = 0; i < threadNumber; ++i)
    {
        auto thread = std::make_unique<ThreadType>(&ClassType::ThreadsRun, this);
        threads.push_back(std::move(thread));
    }

    if (threads.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("boost 线程数量为零！"s));
    }
}
