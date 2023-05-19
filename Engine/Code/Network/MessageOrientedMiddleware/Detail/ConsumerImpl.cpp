///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 17:01)

#include "Network/NetworkExport.h"

#include "ConsumerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::ConsumerImpl::ConsumerImpl(ConfigurationStrategy configurationStrategy)
    : configurationStrategy{ std::move(configurationStrategy) }, messageEventManager{ MessageEventManager::Create() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ConsumerImpl::~ConsumerImpl() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ConsumerImpl::ConsumerImpl(ConsumerImpl&& rhs) noexcept
    : configurationStrategy{ std::move(rhs.configurationStrategy) }, messageEventManager{ std::move(rhs.messageEventManager) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ConsumerImpl& Network::ConsumerImpl::operator=(ConsumerImpl&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    configurationStrategy = std::move(rhs.configurationStrategy);
    messageEventManager = std::move(rhs.messageEventManager);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConsumerImpl)

Network::ConfigurationStrategy Network::ConsumerImpl::GetConfigurationStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return configurationStrategy;
}

Network::MessageEventManager& Network::ConsumerImpl::GetMessageEventManager() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return messageEventManager;
}

void Network::ConsumerImpl::Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_9;

    messageEventManager.Insert(messageId, messageEvent);
}
