/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:26)

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
