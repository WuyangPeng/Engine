//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 11:55)

#include "Network/NetworkExport.h"

#include "OnlySendingClient.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkMessage/BufferReceiveStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"

#include <vector>

using std::make_shared;
using std::string;
using std::vector;

Network::OnlySendingClient::OnlySendingClient(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager)
    : ParentType{ configurationStrategy, socketManager },
      sockConnector{ configurationStrategy },
      sockStream{ make_shared<SockStream>(configurationStrategy) },
      bufferSendStream{ configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy(), configurationStrategy.GetEncryptedCompressionStrategy() },
      buffer(make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy()))
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, OnlySendingClient)

uint64_t Network::OnlySendingClient::Connect()
{
    NETWORK_CLASS_IS_VALID_9;

    const auto strategy = GetConfigurationStrategy();

    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(strategy.GetIP(), strategy.GetPort(), strategy) };

    if (sockConnector.Connect(sockStream, sockAddress))
    {
        return UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(CoreTools::UniqueIdSelect::Network);
    }
    else
    {
        return 0;
    }
}

void Network::OnlySendingClient::AsyncConnect()
{
    NETWORK_CLASS_IS_VALID_9;

    const auto strategy = GetConfigurationStrategy();

    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(strategy.GetIP(), strategy.GetPort(), strategy) };

    sockConnector.AsyncConnect(GetSocketManagerSharedPtr(), sockStream, sockAddress);
}

void Network::OnlySendingClient::Send(MAYBE_UNUSED uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (GetConfigurationStrategy().GetSocketSendMessage() == SocketSendMessage::Cache)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
            << SYSTEM_TEXT("当前客户端策略不支持缓存数据。")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }

    if (bufferSendStream.Insert(message))
    {
        ImmediatelySend(socketID);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("缓冲区大小不足！"s));
    }
}

void Network::OnlySendingClient::AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    if (GetConfigurationStrategy().GetSocketSendMessage() == SocketSendMessage::Cache)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
            << SYSTEM_TEXT("当前客户端策略不支持缓存数据。")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }

    if (bufferSendStream.Insert(message))
    {
        ImmediatelyAsyncSend(socketID);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("缓冲区大小不足！"s));
    }
}

void Network::OnlySendingClient::ImmediatelySend(MAYBE_UNUSED uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_9;

    if (!bufferSendStream.IsEmpty())
    {
        bufferSendStream.Save(buffer);

        MAYBE_UNUSED const auto index = sockStream->Send(buffer);

        bufferSendStream.Clear();
    }
}

void Network::OnlySendingClient::ImmediatelyAsyncSend(MAYBE_UNUSED uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_9;

    if (!bufferSendStream.IsEmpty())
    {
        bufferSendStream.Save(buffer);

        sockStream->AsyncSend(GetSocketManagerSharedPtr(), buffer);

        bufferSendStream.Clear();
    }
}

void Network::OnlySendingClient::Receive() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
        << SYSTEM_TEXT("当前客户端策略不支持接收数据。")
        << LOG_SINGLETON_TRIGGER_ASSERT;
}

void Network::OnlySendingClient::AsyncReceive() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
        << SYSTEM_TEXT("当前客户端策略不支持接收数据。")
        << LOG_SINGLETON_TRIGGER_ASSERT;
}

bool Network::OnlySendingClient::EventFunction(const CoreTools::CallbackParameters& callbackParameters)
{
    const auto eventType = System::UnderlyingCastEnum<SocketManagerEvent>(callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPoisition::Event)));

    switch (eventType)
    {
        case SocketManagerEvent::AsyncConnect:
        {
            const auto wrappersStrategy = callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy));
            const auto result = callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPoisition::Error));
            if (System::UnderlyingCastEnum<WrappersStrategy>(wrappersStrategy) == WrappersStrategy::ACE && result == 0)
            {
                auto socket = GetSocketManagerSharedPtr();
                const auto socketID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(CoreTools::UniqueIdSelect::Network);
                socket->InsertSocket(socketID);
                if (!socket->EventFunction(callbackParameters))
                {
                    LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                        << SYSTEM_TEXT("消息事件触发失败。")
                        << LOG_SINGLETON_TRIGGER_ASSERT;
                }

                return true;
            }
        }
        break;

        default:
            break;
    }

    return false;
}
