///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 11:18)

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
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"

Network::OnlySendingClient::OnlySendingClient(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager)
    : ParentType{ configurationStrategy, messageEventManager },
      sockConnector{ configurationStrategy },
      sockStream{ std::make_shared<SockStream>(configurationStrategy) },
      bufferSendStream{ configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::SendBufferSize), configurationStrategy.GetParserStrategy(), configurationStrategy.GetEncryptedCompressionStrategy() },
      buffer(std::make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::SendBufferSize), configurationStrategy.GetParserStrategy()))
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, OnlySendingClient)

int64_t Network::OnlySendingClient::Connect()
{
    NETWORK_CLASS_IS_VALID_9;

    const auto configuration = GetConfigurationStrategy();

    if (const SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configuration.GetHost(), configuration.GetPort(), configuration) };
        sockConnector.Connect(sockStream, sockAddress))
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

    const SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(strategy.GetHost(), strategy.GetPort(), strategy) };

    sockConnector.AsyncConnect(shared_from_this(), sockStream, sockAddress);
}

void Network::OnlySendingClient::Send(int64_t socketId, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (GetConfigurationStrategy().GetSocketSendMessage() == SocketSendMessage::Cache)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("当前客户端策略不支持缓存数据。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }

    if (bufferSendStream.Insert(message))
    {
        ImmediatelySend(socketId);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("缓冲区大小不足！"s))
    }
}

void Network::OnlySendingClient::AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message)
{
    if (GetConfigurationStrategy().GetSocketSendMessage() == SocketSendMessage::Cache)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("当前客户端策略不支持缓存数据。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }

    if (bufferSendStream.Insert(message))
    {
        ImmediatelyAsyncSend(socketId);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("缓冲区大小不足！"s))
    }
}

void Network::OnlySendingClient::ImmediatelySend(int64_t socketId)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(socketId);

    if (!bufferSendStream.IsEmpty())
    {
        buffer->ClearCurrentIndex();
        bufferSendStream.Save(buffer);

        if (const auto result = sockStream->Send(buffer);
            result != buffer->GetCurrentWriteIndex())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息发送失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }

        bufferSendStream.Clear();
    }
}

void Network::OnlySendingClient::ImmediatelyAsyncSend(int64_t socketId)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(socketId);

    if (!bufferSendStream.IsEmpty())
    {
        buffer->ClearCurrentIndex();
        bufferSendStream.Save(buffer);

        sockStream->AsyncSend(shared_from_this(), buffer);

        bufferSendStream.Clear();
    }
}

void Network::OnlySendingClient::Receive() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("当前客户端策略不支持接收数据。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
}

void Network::OnlySendingClient::AsyncReceive() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("当前客户端策略不支持接收数据。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
}

bool Network::OnlySendingClient::EventFunction(const CoreTools::CallbackParameters& callbackParameters)
{
    switch (const auto eventType = System::UnderlyingCastEnum<SocketManagerEvent>(callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPosition::Event)));
            eventType)
    {
        case SocketManagerEvent::AsyncConnect:
        {
            const auto wrappersStrategy = callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy));

            if (const auto result = callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPosition::Error));
                result == 0)
            {
                if (const auto event = GetMessageEventManagerSharedPtr()->GetCallbackEvent();
                    event != nullptr && !event->EventFunction(callbackParameters))
                {
                    LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息事件触发失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
                }

                return true;
            }
        }
        break;

        default:
            break;
    }

    return true;
}
