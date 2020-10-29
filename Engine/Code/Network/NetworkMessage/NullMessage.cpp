//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 14:14)

#include "Network/NetworkExport.h"

#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "MessageTypeCondition.h"
#include "NullMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Network::NullMessage::NullMessage(int64_t messageID) noexcept
    : ParentType{ messageID }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullMessage);

CORE_TOOLS_RTTI_DEFINE(Network, NullMessage);
NETWORK_DEFAULT_STREAM_DEFINE(Network, NullMessage);
NETWORK_FACTORY_DEFINE(Network, NullMessage);
