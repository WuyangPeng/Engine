///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 17:15)

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

using std::make_shared;
using std::string;
using std::vector;

Network::CacheClient::CacheClient(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& socketManager)
    : ParentType{ configurationStrategy, socketManager },
      sockConnector{ configurationStrategy },
      sockStream{ make_shared<SockStream>(configurationStrategy) },
      sockAddress{ make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy) },
      bufferSendStream{ configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::SendBufferSize),
                        configurationStrategy.GetParserStrategy(),
                        configurationStrategy.GetEncryptedCompressionStrategy() },
      m_SocketID{ 0 },
      sendBuffer(make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::SendBufferSize), configurationStrategy.GetParserStrategy())),
      receiveBuffer(make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::ReceiveBufferSize), configurationStrategy.GetParserStrategy()))
{
    NETWORK_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, CacheClient)

uint64_t Network::CacheClient::Connect()
{
    NETWORK_CLASS_IS_VALID_9;

    const auto strategy = GetConfigurationStrategy();
    auto socket = GetSocketManagerSharedPtr();

    auto address = make_shared<SockAddress>(strategy.GetHost(), strategy.GetPort(), strategy);
    if (socket && sockConnector.Connect(sockStream, address))
    {
        m_SocketID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(CoreTools::UniqueIdSelect::Network);
        //  socket->InsertSocket(m_SocketID);

        return m_SocketID;
    }

    return 0;
}

void Network::CacheClient::AsyncConnect()
{
    NETWORK_CLASS_IS_VALID_9;

    sockConnector.AsyncConnect(shared_from_this(), sockStream, sockAddress);
}

void Network::CacheClient::Send(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (m_SocketID == socketID)
    {
        if (GetConfigurationStrategy().GetSocketSendMessage() == SocketSendMessage::Immediately)
        {
            ImmediatelySend(socketID);
        }
        else
        {
            if (!bufferSendStream.Insert(message))
            {
                ImmediatelySend(socketID);

                if (!bufferSendStream.Insert(message))
                {
                    LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息包长度过长，包被丢弃。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
                }
            }
        }
    }
}

void Network::CacheClient::AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (GetConfigurationStrategy().GetSocketSendMessage() == SocketSendMessage::Immediately)
    {
        ImmediatelyAsyncSend(socketID);
    }
    else
    {
        if (!bufferSendStream.Insert(message))
        {
            ImmediatelyAsyncSend(socketID);

            if (!bufferSendStream.Insert(message))
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息包长度过长，包被丢弃。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
            }
        }
    }
}

void Network::CacheClient::ImmediatelySend(uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_9;

    if (m_SocketID == socketID && !bufferSendStream.IsEmpty())
    {
        sendBuffer->ClearCurrentIndex();
        bufferSendStream.Save(sendBuffer);

        MAYBE_UNUSED const auto index = sockStream->Send(sendBuffer);

        bufferSendStream.Clear();
    }
}

void Network::CacheClient::ImmediatelyAsyncSend(uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_9;

    if (m_SocketID == socketID && !bufferSendStream.IsEmpty())
    {
        sendBuffer->ClearCurrentIndex();
        bufferSendStream.Save(sendBuffer);

        //  sockStream->AsyncSend(GetSocketManagerSharedPtr(), sendBuffer);

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
            bufferReceiveStream.OnEvent(m_SocketID, *GetSocketManagerSharedPtr());
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

uint64_t Network::CacheClient::GetSocketID() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_SocketID;
}

bool Network::CacheClient::EventFunction(const CoreTools::CallbackParameters& callbackParameters)
{
    auto eventType = System::UnderlyingCastEnum<SocketManagerEvent>(callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPosition::Event)));

    auto socket = GetSocketManagerSharedPtr();

    switch (eventType)
    {
        case SocketManagerEvent::AsyncConnect:
        {
            const auto result = callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPosition::Error));
            if (result == 0)
            {
                m_SocketID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(CoreTools::UniqueIdSelect::Network);
                // socket->InsertSocket(m_SocketID);
                /*  if (!socket->EventFunction(callbackParameters))
                  {
                      LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("事件触发失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
                  }*/

                return true;
            }
        }
        break;

        case SocketManagerEvent::AsyncReceive:
        {
            const auto strategy = GetConfigurationStrategy();
            BufferReceiveStream bufferReceiveStream{ receiveBuffer, strategy.GetParserStrategy(), strategy.GetEncryptedCompressionStrategy() };
            bufferReceiveStream.OnEvent(m_SocketID, *socket);

            /* if (!socket->EventFunction(callbackParameters))
             {
                 LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("事件触发失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
             }*/

            return true;
        }
        break;

        default:
            break;
    }

    return false;
}
