//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 17:42)

#include "Network/NetworkExport.h"

#include "BoostMainManager.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::BoostMainManager::BoostMainManager() noexcept
    : ParentType{}, m_ExecutorWorkGuardContext{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostMainManager)

void Network::BoostMainManager::Run()
{
    NETWORK_CLASS_IS_VALID_9;

    m_ExecutorWorkGuardContext.Run();
}

Network::IOContextType& Network::BoostMainManager::GetIOContext() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return m_ExecutorWorkGuardContext.GetIOContext();
}

void Network::BoostMainManager::StopContext()
{
    NETWORK_CLASS_IS_VALID_9;

    m_ExecutorWorkGuardContext.PostStopContext();
}

bool Network::BoostMainManager::IsContextStop() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_ExecutorWorkGuardContext.IsContextStop();
}

void Network::BoostMainManager::RestartContext()
{
    NETWORK_CLASS_IS_VALID_9;

    m_ExecutorWorkGuardContext.RestartContext();
}

void Network::BoostMainManager::DispatchStopContext()
{
    m_ExecutorWorkGuardContext.DispatchStopContext();
}
