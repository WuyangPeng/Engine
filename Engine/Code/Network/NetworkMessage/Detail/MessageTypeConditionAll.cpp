///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 22:33)

#include "Network/NetworkExport.h"

#include "MessageTypeConditionAll.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/MessageManager.h"

Network::MessageTypeConditionAll::MessageTypeConditionAll() noexcept
    : ParentType{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageTypeConditionAll)

bool Network::MessageTypeConditionAll::IsVersionsConform(MAYBE_UNUSED int version) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return true;
}

int Network::MessageTypeConditionAll::GetMinVersion() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}

int Network::MessageTypeConditionAll::GetMaxVersion() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return MESSAGE_MANAGER_SINGLETON.GetFullVersion();
}
