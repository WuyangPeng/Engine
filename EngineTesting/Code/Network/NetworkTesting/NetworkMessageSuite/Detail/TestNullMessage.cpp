///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/11 11:35)

#include "TestNullMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Helper/StreamMacro.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

Network::TestNullMessage::TestNullMessage(int64_t messageId) noexcept
    : ParentType{ MessageHeadStrategy::Default, messageId }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestNullMessage);

CORE_TOOLS_RTTI_DEFINE(Network, TestNullMessage);
NETWORK_DEFAULT_STREAM_DEFINE(Network, TestNullMessage);
NETWORK_FACTORY_DEFINE(Network, TestNullMessage);

int Network::TestNullMessage::GetValue() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return GetMessageId();
}