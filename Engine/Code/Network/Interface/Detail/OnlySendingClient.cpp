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
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
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
      m_SockConnector{ configurationStrategy },
      m_SockStream{ make_shared<SockStream>(configurationStrategy) },
      m_BufferSendStream{ configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy() },
      m_Buffer(make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy()))
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, OnlySendingClient)

uint64_t Network::OnlySendingClient::Connect()
{
    NETWORK_CLASS_IS_VALID_9;

    const auto configurationStrategy = GetConfigurationStrategy();

    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetIP(), configurationStrategy.GetPort(), GetConfigurationStrategy()) };

    if (m_SockConnector.Connect(m_SockStream, sockAddress))
    {
        return UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(CoreTools::UniqueIDSelect::Network);
    }
    else
    {
        return 0;
    }
}

void Network::OnlySendingClient::AsyncConnect()
{
    NETWORK_CLASS_IS_VALID_9;

    const auto configurationStrategy = GetConfigurationStrategy();

    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetIP(), configurationStrategy.GetPort(), GetConfigurationStrategy()) };

    m_SockConnector.AsyncConnect(GetSocketManagerSharedPtr(), m_SockStream, sockAddress);
}

void Network::OnlySendingClient::Send([[maybe_unused]] uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (GetConfigurationStrategy().GetSocketSendMessage() == SocketSendMessage::Cache)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
            << SYSTEM_TEXT("当前客户端策略不支持缓存数据。")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }

    if (m_BufferSendStream.Insert(message))
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

    if (m_BufferSendStream.Insert(message))
    {
        ImmediatelyAsyncSend(socketID);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("缓冲区大小不足！"s));
    }
}

void Network::OnlySendingClient::ImmediatelySend([[maybe_unused]] uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_9;

    if (!m_BufferSendStream.IsEmpty())
    {
        m_BufferSendStream.Save(m_Buffer);

        [[maybe_unused]] const auto index = m_SockStream->Send(m_Buffer);

        m_BufferSendStream.Clear();
    }
}

void Network::OnlySendingClient::ImmediatelyAsyncSend([[maybe_unused]] uint64_t socketID)
{
    NETWORK_CLASS_IS_VALID_9;

    if (!m_BufferSendStream.IsEmpty())
    {
        m_BufferSendStream.Save(m_Buffer);

        m_SockStream->AsyncSend(GetSocketManagerSharedPtr(), m_Buffer);

        m_BufferSendStream.Clear();
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
    auto eventType = System::UnderlyingCastEnum<SocketManagerEvent>(callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPoisition::Event)));

    switch (eventType)
    {
        case SocketManagerEvent::AsyncConnect:
        {
            const auto wrappersStrategy = callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy));
            const auto result = callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPoisition::Error));
            if (System::UnderlyingCastEnum<WrappersStrategy>(wrappersStrategy) == WrappersStrategy::ACE && result == 0)
            {
                const auto socketID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(CoreTools::UniqueIDSelect::Network);
                GetSocketManagerSharedPtr()->InsertSocket(socketID);
                if (!GetSocketManagerSharedPtr()->EventFunction(callbackParameters))
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
