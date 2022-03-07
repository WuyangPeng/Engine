// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ²âÊÔ°æ±¾£º0.0.2.4 (2020/03/12 13:06)

#include "NullSocketManager.h"

#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::make_shared;

Network::NullSocketManager ::NullSocketManager(int64_t messageID)
    : ParentType{ CoreTools::DisableNotThrow::Disable }, m_Event{ make_shared<TestNetworkMessageEvent>() }, m_MessageID{ messageID }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSocketManager);

void Network::NullSocketManager ::InitEvent(uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_1;

    InsertEvent(socketID, m_MessageID, m_Event);
}

bool Network::NullSocketManager ::EventFunction([[maybe_unused]] const CallbackParameters& callbackParameters) noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    return true;
}

int Network::NullSocketManager ::GetValue() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return m_Event->GetValue();
}
