//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 14:14)

#include "Network/NetworkExport.h"

#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "MessageTypeCondition.h"
#include "NullDoubleMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Network::NullDoubleMessage::NullDoubleMessage(int64_t messageID) noexcept
    : ParentType{ messageID }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullDoubleMessage);

CORE_TOOLS_RTTI_DEFINE(Network, NullDoubleMessage);
NETWORK_DEFAULT_STREAM_DEFINE(Network, NullDoubleMessage);
NETWORK_FACTORY_DEFINE(Network, NullDoubleMessage);
