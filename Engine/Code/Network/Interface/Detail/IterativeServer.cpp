//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//	ÁªÏµ×÷Õß£º94458936@qq.com
//
//	±ê×¼£ºstd:c++17
//	ÒýÇæ°æ±¾£º0.5.2.1 (2020/10/28 11:23)

#include "Network/NetworkExport.h"

#include "IterativeServer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/SocketManager.h"

#include <vector>

using std::make_pair;
using std::make_shared;
using std::string;
using std::vector;

Network::IterativeServer::IterativeServer(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy)
    : ParentType{ socketManager, configurationStrategy },
      m_SockAcceptor{ configurationStrategy.GetPort(), configurationStrategy },
      m_StreamContainer{},
      m_ReceiveBuffer(make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy())),
      m_SendBuffer(make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy()))
{
    if (!m_SockAcceptor.EnableNonBlock())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
            << SYSTEM_TEXT("ÉèÖÃ·Ç×èÈûÊ§°Ü£¡")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, IterativeServer)

bool Network::IterativeServer::HandleConnections(const SocketManagerSharedPtr& socketManager)
{
    auto process = socketManager;

    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(GetConfigurationStrategy()) };
    SockStreamSharedPtr sockStream{ make_shared<SockStream>(GetConfigurationStrategy()) };

    if (m_SockAcceptor.Accept(sockStream->shared_from_this(), sockAddress))
    {
        auto socketID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(CoreTools::UniqueIDSelect::Network);
        process->InsertSocket(socketID);

        if (!sockStream->EnableNonBlock())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                << SYSTEM_TEXT("ÉèÖÃ·Ç×èÈûÊ§°Ü£¡")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }

        StreamContainer streamContainer{ GetConfigurationStrategy(), sockStream };

        m_StreamContainer.insert({ socketID, streamContainer });

        CoreTools::CallbackParameters callbackParameters{};
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncAcceptor));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), 0);

        if (!process->EventFunction(callbackParameters))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                << SYSTEM_TEXT("»Øµ÷º¯ÊýÖ´ÐÐ´íÎó£¡")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
    }

    return true;
}

bool Network::IterativeServer::HandleData(const SocketManagerSharedPtr& socketManager)
{
    for (auto iter = m_StreamContainer.begin(); iter != m_StreamContainer.end();)
    {
        auto sockStream = iter->second.GetSockStream();

        try
        {
            m_ReceiveBuffer->ClearCurrentIndex();
            const auto result = sockStream->Receive(m_ReceiveBuffer);
            if (0 < result)
            {
                BufferReceiveStream bufferReceiveStream(m_ReceiveBuffer, GetConfigurationStrategy().GetParserStrategy());
                bufferReceiveStream.OnEvent(iter->first, socketManager);
                m_ReceiveBuffer->ClearCurrentIndex();
                ++iter;
            }
            else if (result < 0)
            {
                if (!sockStream->CloseHandle())
                {
                    LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                        << SYSTEM_TEXT("¹Ø±Õ¾ä±úÊ§°Ü£¡")
                        << LOG_SINGLETON_TRIGGER_ASSERT;
                }
                socketManager->RemoveSocket(iter->first);
                m_StreamContainer.erase(iter++);
            }
            else
            {
                ++iter;
            }
        }
        catch (CoreTools::Error&)
        {
            if (!sockStream->CloseHandle())
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                    << SYSTEM_TEXT("¹Ø±Õ¾ä±úÊ§°Ü£¡")
                    << LOG_SINGLETON_TRIGGER_ASSERT;
            }
            socketManager->RemoveSocket(iter->first);
            m_StreamContainer.erase(iter++);
        }
    }

    return true;
}

bool Network::IterativeServer::ImmediatelySend() noexcept
{
    return true;
}

void Network::IterativeServer::Send(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto iter = m_StreamContainer.find(socketID);

    if (iter != m_StreamContainer.cend())
    {
        auto sockStream = iter->second.GetSockStream();
        auto& bufferSendStream = iter->second.GetBufferSendStream();

        if (bufferSendStream.Insert(message))
        {
            m_SendBuffer->ClearCurrentIndex();
            bufferSendStream.Save(m_SendBuffer);

            [[maybe_unused]] const auto index = sockStream->Send(m_SendBuffer);

            bufferSendStream.Clear();
        }
    }
}

void Network::IterativeServer::AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto iter = m_StreamContainer.find(socketID);

    if (iter != m_StreamContainer.cend())
    {
        auto sockStream = iter->second.GetSockStream();
        auto& bufferSendStream = iter->second.GetBufferSendStream();

        if (bufferSendStream.Insert(message))
        {
            m_SendBuffer->ClearCurrentIndex();
            bufferSendStream.Save(m_SendBuffer);

            sockStream->AsyncSend(GetSocketManagerSharedPtr(), m_SendBuffer);

            bufferSendStream.Clear();
        }
    }
}
