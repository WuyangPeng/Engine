///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:55)

#include "Network/NetworkExport.h"

#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "MessageTypeCondition.h"
#include "NullMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

Network::NullMessage::NullMessage(MessageHeadStrategy messageHeadStrategy, int64_t messageId)
    : ParentType{ messageHeadStrategy, messageId }
{
    if (IsUseSubId(messageHeadStrategy) || IsUseDescribe(messageHeadStrategy))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("NullMessage 只能使用主消息id创建。"))
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullMessage);

CORE_TOOLS_RTTI_DEFINE(Network, NullMessage);
NETWORK_DEFAULT_STREAM_DEFINE(Network, NullMessage);
NETWORK_FACTORY_DEFINE(Network, NullMessage);
