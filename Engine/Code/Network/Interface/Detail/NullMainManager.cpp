///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/08 17:27)

#include "Network/NetworkExport.h"

#include "NullMainManager.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::NullMainManager::NullMainManager() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullMainManager)

void Network::NullMainManager::Run() noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

void Network::NullMainManager::StopContext() noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

bool Network::NullMainManager::IsContextStop() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return false;
}

void Network::NullMainManager::RestartContext() noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}
