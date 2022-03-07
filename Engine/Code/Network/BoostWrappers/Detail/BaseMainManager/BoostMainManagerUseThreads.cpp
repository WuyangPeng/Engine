///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/22 22:30)

#include "Network/NetworkExport.h"

#include "BoostMainManagerUseThreads.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/Configuration/ConfigurationSubStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"

using std::make_unique;

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
    for (auto& value : threads)
    {
        value.join();
    }

    threads.clear();
}

// private
void Network::BoostMainManagerUseThreads::DoInitThread()
{
    for (auto i = 0; i < threadNumber; ++i)
    {
        auto thread = make_unique<ThreadType>(&ClassType::ThreadsRun, this);
        threads.push_back(std::move(thread));
    }

    if (threads.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("boost �߳�����Ϊ�㣡"s));
    }
}
