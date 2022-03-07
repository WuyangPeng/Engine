///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/18 23:01)

#include "Network/NetworkExport.h"

#include "DoubleMessage.h"
#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "MessageTypeCondition.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Network::DoubleMessage::DoubleMessage(int64_t messageID) noexcept
    : ParentType{ messageID }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, DoubleMessage);

CORE_TOOLS_RTTI_DEFINE(Network, DoubleMessage);
NETWORK_ABSTRACT_FACTORY_DEFINE(Network, DoubleMessage);
NETWORK_DEFAULT_STREAM_DEFINE(Network, DoubleMessage);

int32_t Network::DoubleMessage::GetMessageID() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int32_t>(GetFullMessageID() >> sm_MessageBytes);
}

int32_t Network::DoubleMessage::GetSubMessageID() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int32_t>(GetFullMessageID() & sm_MaxMessageID);
}
