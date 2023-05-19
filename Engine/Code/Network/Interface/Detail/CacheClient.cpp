///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 10:32)

#include "Network/NetworkExport.h"

#include "CacheClient.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIDManager.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkMessage/BufferReceiveStream.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageEventManager.h"

#include <vector>

Network::CacheClient::CacheClient(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager)
    : ParentType{ configurationStrategy, messageEventManager },
      sockConnector{ configurationStrategy },
      sockStream{ std::make_shared<SockStream>(configurationStrategy) },
      sockAddress{ make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy) },
      bufferSendStream{ configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::SendBufferSize),
                        configurationStrategy.GetParserStrategy(),
                        configurationStrategy.GetEncryptedCompressionStrategy() },
      clientSocketId{ 0 },
      sendBuffer(std::make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::SendBufferSize), configurationStrategy.GetParserStrategy())),
      receiveBuffer(std::make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::ReceiveBufferSize), configurationStrategy.GetParserStrategy()))
{
    NETWORK_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, CacheClient)

int64_t Network::CacheClient::Connect()
{
    NETWORK_CLASS_IS_VALID_9;

    const auto configuration = GetConfigurationStrategy();

    if (const auto address = make_shared<SockAddress>(configuration.GetHost(), configuration.GetPort(), configuration);
        sockConnector.Connect(sockStream, address))
    {
        clientSocketId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(CoreTools::UniqueIdSelect::Network);

        return clientSocketId;
    }

    return 0;
}

void Network::CacheClient::AsyncConnect()
{
    NETWORK_CLASS_IS_VALID_9;

    sockConnector.AsyncConnect(shared_from_this(), sockStream, sockAddress);
}

void Network::CacheClient::Send(int64_t socketId, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (clientSocketId == socketId)
    {
        if (GetConfigurationStrategy().GetSocketSendMessage() == SocketSendMessage::Immediately)
        {
            ImmediatelySend(socketId);
        }
        else
        {
            if (!bufferSendStream.Insert(message))
            {
                ImmediatelySend(socketId);

                if (!bufferSendStream.Insert(message))
                {
                    LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息包长度过长，包被丢弃。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
                }
            }
        }
    }
}

void Network::CacheClient::AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (GetConfigurationStrategy().GetSocketSendMessage() == SocketSendMessage::Immediately)
    {
        ImmediatelyAsyncSend(socketId);
    }
    else
    {
        if (!bufferSendStream.Insert(message))
        {
            ImmediatelyAsyncSend(socketId);

            if (!bufferSendStream.Insert(message))
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息包长度过长，包被丢弃。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
            }
        }
    }
}

void Network::CacheClient::ImmediatelySend(int64_t socketId)
{
    NETWORK_CLASS_IS_VALID_9;

    if (clientSocketId == socketId && !bufferSendStream.IsEmpty())
    {
        sendBuffer->ClearCurrentIndex();
        bufferSendStream.Save(sendBuffer);

        if (const auto result = sockStream->Send(sendBuffer);
            result != sendBuffer->GetCurrentWriteIndex())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息发送失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }

        bufferSendStream.Clear();
    }
}

void Network::CacheClient::ImmediatelyAsyncSend(int64_t socketId)
{
    NETWORK_CLASS_IS_VALID_9;

    if (clientSocketId == socketId && !bufferSendStream.IsEmpty())
    {
        sendBuffer->ClearCurrentIndex();
        bufferSendStream.Save(sendBuffer);

        sockStream->AsyncSend(shared_from_this(), sendBuffer);

        bufferSendStream.Clear();
    }
}

void Network::CacheClient::Receive()
{
    NETWORK_CLASS_IS_VALID_9;

    try
    {
        if (sockStream->Receive(receiveBuffer))
        {
            BufferReceiveStream bufferReceiveStream{ receiveBuffer, GetConfigurationStrategy().GetParserStrategy(), GetConfigurationStrategy().GetEncryptedCompressionStrategy() };
            bufferReceiveStream.OnEvent(clientSocketId, *GetMessageEventManagerSharedPtr());
            receiveBuffer->ClearCurrentIndex();
        }
    }
    catch (const CoreTools::Error& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

void Network::CacheClient::AsyncReceive()
{
    NETWORK_CLASS_IS_VALID_9;

    receiveBuffer->ClearCurrentIndex();
    sockStream->AsyncReceive(shared_from_this(), receiveBuffer);
}

int64_t Network::CacheClient::GetSocketId() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return clientSocketId;
}

bool Network::CacheClient::EventFunction(const CoreTools::CallbackParameters& callbackParameters)
{
    switch (const auto eventType = System::UnderlyingCastEnum<SocketManagerEvent>(callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPosition::Event)));
            eventType)
    {
        case SocketManagerEvent::AsyncConnect:
        {
            if (const auto result = callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPosition::Error));
                result == 0)
            {
                clientSocketId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(CoreTools::UniqueIdSelect::Network);

                if (const auto callbackEvent = GetMessageEventManagerSharedPtr()->GetCallbackEvent();
                    callbackEvent != nullptr)
                {
                    return callbackEvent->EventFunction(callbackParameters);
                }
            }

            return true;
        }
        break;

        case SocketManagerEvent::AsyncReceive:
        {
            const auto strategy = GetConfigurationStrategy();
            BufferReceiveStream bufferReceiveStream{ receiveBuffer, strategy.GetParserStrategy(), strategy.GetEncryptedCompressionStrategy() };
            bufferReceiveStream.OnEvent(clientSocketId, *GetMessageEventManagerSharedPtr());

            if (const auto callbackEvent = GetMessageEventManagerSharedPtr()->GetCallbackEvent();
                callbackEvent != nullptr)
            {
                return callbackEvent->EventFunction(callbackParameters);
            }

            return true;
        }
        break;

        case SocketManagerEvent::AsyncSend:
        {
            if (const auto callbackEvent = GetMessageEventManagerSharedPtr()->GetCallbackEvent();
                callbackEvent != nullptr)
            {
                return callbackEvent->EventFunction(callbackParameters);
            }

            return true;
        }
        break;

        default:
            break;
    }

    return true;
}
