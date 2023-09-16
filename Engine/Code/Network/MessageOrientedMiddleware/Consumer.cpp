///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 17:33)

#include "Network/NetworkExport.h"

#include "Consumer.h"
#include "Detail/ConsumerFactory.h"
#include "Detail/ConsumerImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::Consumer::Consumer(const ConfigurationStrategy& configurationStrategy, const String& address)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy, address }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, Consumer)

Network::MessageEventManager& Network::Consumer::GetMessageEventManager() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->GetMessageEventManager();
}

void Network::Consumer::Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->Insert(messageId, messageEvent);
}
