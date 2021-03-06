//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 11:11)

#include "Network/NetworkExport.h"

#include "CacheClient.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManager.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkMessage/BufferReceiveStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/SocketManager.h"

#include <vector>

using std::make_shared;
using std::string;
using std::vector;

Network::CacheClient::CacheClient(const ConfigurationStrategy& configurationStrategy, const SocketManagerSharedPtr& socketManager)
    : ParentType{ configurationStrategy, socketManager },
      m_SockConnector{ configurationStrategy },
      m_SockStream{ make_shared<SockStream>(configurationStrategy) },
      m_SockAddress{ make_shared<SockAddress>(configurationStrategy.GetIP(), configurationStrategy.GetPort(), configurationStrategy) },
      m_BufferSendStream{ configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy() }, m_SocketID{ 0 },
      m_SendBuffer(make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy())),
      m_ReceiveBuffer(make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy()))
{
    NETWORK_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, CacheClient)

uint64_t Network::CacheClient::Connect()
{
    NETWORK_CLASS_IS_VALID_9;

    const auto configurationStrategy = GetConfigurationStrategy();
    auto socketManager = GetSocketManagerSharedPtr();

    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetIP(), configurationStrategy.GetPort(), GetConfigurationStrategy()) };
    if (socketManager && m_SockConnector.Connect(m_SockStream, sockAddress))
    {
        m_SocketID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(CoreTools::UniqueIDSelect::Network);
        socketManager->InsertSocket(m_SocketID);

        return m_SocketID;
    }

    return 0;
}

void Network::CacheClient::AsyncConnect()
{
    NETWORK_CLASS_IS_VALID_9;

    m_SockConnector.AsyncConnect(shared_from_this(), m_SockStream, m_SockAddress);
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
            if (!m_BufferSendStream.Insert(message))
            {
                ImmediatelySend(socketID);

                if (!m_BufferSendStream.Insert(message))
                {
                    LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                        << SYSTEM_TEXT("消息包长度过长，包被丢弃。")
                        << LOG_SINGLETON_TRIGGER_ASSERT;
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
        if (!m_BufferSendStream.Insert(message))
        {
            ImmediatelyAsyncSend(socketID);

            if (!m_BufferSendStream.Insert(message))
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                    << SYSTEM_TEXT("消息包长度过长，包被丢弃。")
                    << LOG_SINGLETON_TRIGGER_ASSERT;
            }
        }
    }
}

void Network::CacheClient::ImmediatelySend(uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_9;

    if (m_SocketID == socketID && !m_BufferSendStream.IsEmpty())
    {
        m_SendBuffer->ClearCurrentIndex();
        m_BufferSendStream.Save(m_SendBuffer);

        [[maybe_unused]] const auto index = m_SockStream->Send(m_SendBuffer);

        m_BufferSendStream.Clear();
    }
}

void Network::CacheClient::ImmediatelyAsyncSend(uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_9;

    if (m_SocketID == socketID && !m_BufferSendStream.IsEmpty())
    {
        m_SendBuffer->ClearCurrentIndex();
        m_BufferSendStream.Save(m_SendBuffer);

        m_SockStream->AsyncSend(GetSocketManagerSharedPtr(), m_SendBuffer);

        m_BufferSendStream.Clear();
    }
}

void Network::CacheClient::Receive()
{
    NETWORK_CLASS_IS_VALID_9;

    try
    {
        if (m_SockStream->Receive(m_ReceiveBuffer))
        {
            BufferReceiveStream bufferReceiveStream{ m_ReceiveBuffer, GetConfigurationStrategy().GetParserStrategy() };
            bufferReceiveStream.OnEvent(m_SocketID, GetSocketManagerSharedPtr());
            m_ReceiveBuffer->ClearCurrentIndex();
        }
    }
    catch (const CoreTools::Error& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
            << error
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

void Network::CacheClient::AsyncReceive()
{
    NETWORK_CLASS_IS_VALID_9;

    m_ReceiveBuffer->ClearCurrentIndex();
    m_SockStream->AsyncReceive(shared_from_this(), m_ReceiveBuffer);
}

uint64_t Network::CacheClient::GetSocketID() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_SocketID;
}

bool Network::CacheClient::EventFunction(const CoreTools::CallbackParameters& callbackParameters)
{
    auto eventType = System::UnderlyingCastEnum<SocketManagerEvent>(callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPoisition::Event)));

    switch (eventType)
    {
        case SocketManagerEvent::AsyncConnect:
        {
            const auto result = callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPoisition::Error));
            if (result == 0)
            {
                m_SocketID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(CoreTools::UniqueIDSelect::Network);
                GetSocketManagerSharedPtr()->InsertSocket(m_SocketID);
                if (!GetSocketManagerSharedPtr()->EventFunction(callbackParameters))
                {
                    LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                        << SYSTEM_TEXT("事件触发失败。")
                        << LOG_SINGLETON_TRIGGER_ASSERT;
                }

                return true;
            }
        }
        break;

        case SocketManagerEvent::AsyncReceive:
        {
            BufferReceiveStream bufferReceiveStream{ m_ReceiveBuffer, GetConfigurationStrategy().GetParserStrategy() };
            bufferReceiveStream.OnEvent(m_SocketID, GetSocketManagerSharedPtr());

            if (!GetSocketManagerSharedPtr()->EventFunction(callbackParameters))
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                    << SYSTEM_TEXT("事件触发失败。")
                    << LOG_SINGLETON_TRIGGER_ASSERT;
            }

            return true;
        }
        break;

        default:
            break;
    }

    return false;
}
