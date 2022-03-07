///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/22 22:26)

#include "Network/NetworkExport.h"

#include "BoostMainManager.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::BoostMainManager::BoostMainManager(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{}, executorWorkGuardContext{ disableNotThrow }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostMainManager)

void Network::BoostMainManager::Run()
{
    NETWORK_CLASS_IS_VALID_9;

    executorWorkGuardContext.Run();
}

Network::IOContextType& Network::BoostMainManager::GetIOContext() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return executorWorkGuardContext.GetIOContext();
}

void Network::BoostMainManager::StopContext()
{
    NETWORK_CLASS_IS_VALID_9;

    executorWorkGuardContext.PostStopContext();
}

bool Network::BoostMainManager::IsContextStop() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return executorWorkGuardContext.IsContextStop();
}

void Network::BoostMainManager::RestartContext()
{
    NETWORK_CLASS_IS_VALID_9;

    executorWorkGuardContext.RestartContext();
}

void Network::BoostMainManager::DispatchStopContext()
{
    executorWorkGuardContext.DispatchStopContext();
}
