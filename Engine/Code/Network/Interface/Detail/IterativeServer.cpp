///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++17
///	ÒýÇæ°æ±¾£º0.8.0.1 (2022/01/20 18:24)

#include "Network/NetworkExport.h"

#include "IterativeServer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
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
      sockAcceptor{ configurationStrategy.GetPort(), configurationStrategy },
      streamContainer{},
      receiveBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy()) },
      sendBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy()) }
{
    if (!sockAcceptor.EnableNonBlock())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
            << SYSTEM_TEXT("ÉèÖÃ·Ç×èÈûÊ§°Ü£¡")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, IterativeServer)

bool Network::IterativeServer::WaitForMultipleEvents() noexcept
{
    return true;
}

bool Network::IterativeServer::HandleConnections(SocketManager& socketManager)
{
    const auto strategy = GetConfigurationStrategy();

    SockAddress sockAddress{ strategy };
    auto sockStream = make_shared<SockStream>(strategy);

    if (sockAcceptor.Accept(*sockStream, sockAddress))
    {
        const auto socketID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(CoreTools::UniqueIdSelect::Network);
        socketManager.InsertSocket(socketID);

        if (!sockStream->EnableNonBlock())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                << SYSTEM_TEXT("ÉèÖÃ·Ç×èÈûÊ§°Ü£¡")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }

        StreamContainer container{ strategy, sockStream };

        streamContainer.insert({ socketID, container });

        CoreTools::CallbackParameters callbackParameters{ 0 };
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncAcceptor));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), 0);

        if (!socketManager.EventFunction(callbackParameters))
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
    for (auto iter = streamContainer.begin(); iter != streamContainer.end();)
    {
        auto sockStream = iter->second.GetSockStream();

        try
        {
            receiveBuffer->ClearCurrentIndex();
            const auto result = sockStream->Receive(receiveBuffer);
            if (0 < result)
            {
                const auto strategy = GetConfigurationStrategy();
                BufferReceiveStream bufferReceiveStream(receiveBuffer, strategy.GetParserStrategy(), strategy.GetEncryptedCompressionStrategy());
                bufferReceiveStream.OnEvent(iter->first, socketManager);
                receiveBuffer->ClearCurrentIndex();
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
                streamContainer.erase(iter++);
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
            streamContainer.erase(iter++);
        }
    }

    return true;
}

bool Network::IterativeServer::ImmediatelySend() noexcept
{
    return true;
}

bool Network::IterativeServer::ImmediatelySend(MAYBE_UNUSED uint64_t socketID) noexcept
{
    return true;
}

void Network::IterativeServer::ImmediatelyAsyncSend(MAYBE_UNUSED uint64_t socketID) noexcept
{
}

void Network::IterativeServer::Send(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto iter = streamContainer.find(socketID);

    if (iter != streamContainer.cend())
    {
        auto sockStream = iter->second.GetSockStream();
        auto& bufferSendStream = iter->second.GetBufferSendStream();

        if (bufferSendStream.Insert(message))
        {
            sendBuffer->ClearCurrentIndex();
            bufferSendStream.Save(sendBuffer);

            MAYBE_UNUSED const auto index = sockStream->Send(sendBuffer);

            bufferSendStream.Clear();
        }
    }
}

void Network::IterativeServer::AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto iter = streamContainer.find(socketID);

    if (iter != streamContainer.cend())
    {
        auto sockStream = iter->second.GetSockStream();
        auto& bufferSendStream = iter->second.GetBufferSendStream();

        if (bufferSendStream.Insert(message))
        {
            sendBuffer->ClearCurrentIndex();
            bufferSendStream.Save(sendBuffer);

            sockStream->AsyncSend(GetSocketManagerSharedPtr(), sendBuffer);

            bufferSendStream.Clear();
        }
    }
}

bool Network::IterativeServer::EventFunction(MAYBE_UNUSED const CoreTools::CallbackParameters& callbackParameters) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return true;
}
