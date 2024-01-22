/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:25)

#include "Network/NetworkExport.h"

#include "BoostMainManager.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::BoostMainManager::BoostMainManager(CoreTools::DisableNotThrow disableNotThrow)
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

Network::IoContextType& Network::BoostMainManager::GetContext() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return executorWorkGuardContext.GetContext();
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
