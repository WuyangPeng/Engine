///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 15:45)

#include "NullSocketManager.h"

#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::make_shared;

Network::NullSocketManager::NullSocketManager(int64_t messageID)
    : ParentType{ CoreTools::DisableNotThrow::Disable }, event{ make_shared<TestNetworkMessageEvent>() }, messageID{ messageID }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSocketManager);

void Network::NullSocketManager::InitEvent(uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_1;

    InsertEvent(socketID, messageID, event);
}

bool Network::NullSocketManager::EventFunction(MAYBE_UNUSED const CallbackParameters& callbackParameters) noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    return true;
}

int Network::NullSocketManager::GetValue() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return event->GetValue();
}
