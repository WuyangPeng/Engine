/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:23)

#include "Network/NetworkExport.h"

#include "MessageManager.h"
#include "MessageSourceDetail.h"
#include "MessageTargetDetail.h"
#include "MessageTypeCondition.h"
#include "NullDoubleMessage.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

Network::NullDoubleMessage::NullDoubleMessage(MessageHeadStrategy messageHeadStrategy, int64_t messageId)
    : ParentType{ messageHeadStrategy, messageId }
{
    if (!IsUseSubId(messageHeadStrategy))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("NullDoubleMessage����ʹ������Ϣid������"))
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullDoubleMessage);

CORE_TOOLS_RTTI_DEFINE(Network, NullDoubleMessage);
NETWORK_DEFAULT_STREAM_DEFINE(Network, NullDoubleMessage);
NETWORK_FACTORY_DEFINE(Network, NullDoubleMessage);
