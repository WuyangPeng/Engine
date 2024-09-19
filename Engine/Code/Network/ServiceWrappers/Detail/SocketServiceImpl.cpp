/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:56)

#include "Network/NetworkExport.h"

#include "SocketServiceImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::SocketServiceImpl::SocketServiceImpl(ConfigurationStrategy configurationStrategy)
    : serviceSession{ configurationStrategy }, consumer{ serviceSession, configurationStrategy }, producer{ serviceSession, configurationStrategy }, configurationStrategy{ std::move(configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SocketServiceImpl)

void Network::SocketServiceImpl::SendTextMessage(const std::string& message)
{
    NETWORK_CLASS_IS_VALID_9;

    producer.SendTextMessage(message);
}

void Network::SocketServiceImpl::Response(const std::function<void(const std::string&)>& processDataCallback)
{
    NETWORK_CLASS_IS_VALID_9;

    return consumer.Response(processDataCallback);
}

void Network::SocketServiceImpl::Close()
{
    NETWORK_CLASS_IS_VALID_9;

    serviceSession.Close();
}
