///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/10 09:21)

#include "Network/NetworkExport.h"

#include "RouteServiceImpl.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/ConfigurationStrategy.h"

using namespace std::literals;

Network::RouteServiceImpl::RouteServiceImpl(ConfigurationStrategy configurationStrategy)
    : consumerNode{},
      address{ ComputeAddress(configurationStrategy) },
      consumer{ configurationStrategy, address },
      producer{ configurationStrategy },
      configurationStrategy{ std::move(configurationStrategy) }
{
    if (address.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("中间件地址为空。"))
    }

    NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Network::RouteServiceImpl::IsValid() const noexcept
{
    if (!address.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

System::String Network::RouteServiceImpl::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return address;
}

System::String Network::RouteServiceImpl::GetFirstConsumer(SocketType serverType) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    if (const auto iter = std::ranges::find_if(consumerNode, [serverType](const auto& value) noexcept {
            return value.GetServerType() == serverType;
        });
        iter != consumerNode.cend())
    {
        return iter->GetConsumer();
    }

    THROW_EXCEPTION(SYSTEM_TEXT("服务器类型不存在。"s))
}

void Network::RouteServiceImpl::AddConsumer(SocketType serverType, int serverId, const String& aAddress)
{
    NETWORK_CLASS_IS_VALID_1;

    consumerNode.emplace_back(serverType, serverId, aAddress);
}

void Network::RouteServiceImpl::RemoveConsumer(SocketType serverType, int serverId)
{
    NETWORK_CLASS_IS_VALID_1;

    const auto result = std::ranges::remove_if(consumerNode, [serverType, serverId](const auto& value) noexcept {
        return value.GetServerType() == serverType && value.GetServerId() == serverId;
    });

    consumerNode.erase(result.begin(), result.end());
}

void Network::RouteServiceImpl::BroadcastMessage(SocketType serverType, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    for (const auto& value : consumerNode)
    {
        if (value.GetServerType() == serverType)
        {
            SendServerMessage(value.GetConsumer(), message);
        }
    }
}

void Network::RouteServiceImpl::BroadcastMessage(const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    for (const auto& value : consumerNode)
    {
        SendServerMessage(value.GetConsumer(), message);
    }
}

void Network::RouteServiceImpl::SendServerMessage(const String& aAddress, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    producer.SendServerMessage(aAddress, message);
}

void Network::RouteServiceImpl::Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_1;

    consumer.Insert(messageId, messageEvent);
}

Network::RouteServiceImpl::String Network::RouteServiceImpl::ComputeAddress(const ConfigurationStrategy& configurationStrategy)
{
    const auto configurationParameter = configurationStrategy.GetConfigurationParameter();

    return configurationParameter.GetFirstParameter(SYSTEM_TEXT("SocketType")) +
           SYSTEM_TEXT("_") +
           configurationParameter.GetFirstParameter(SYSTEM_TEXT("ServerId")) +
           SYSTEM_TEXT("_") +
           configurationParameter.GetFirstParameter(SYSTEM_TEXT("IntranetIp")) +
           SYSTEM_TEXT("_") +
           configurationParameter.GetFirstParameter(SYSTEM_TEXT("IntranetPort"));
}
