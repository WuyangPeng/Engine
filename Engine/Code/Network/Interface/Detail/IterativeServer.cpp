///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 11:06)

#include "Network/NetworkExport.h"

#include "IterativeServer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageEventManager.h"

Network::IterativeServer::IterativeServer(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager)
    : ParentType{ configurationStrategy, messageEventManager },
      sockAcceptor{ configurationStrategy.GetPort(), configurationStrategy },
      streamContainer{},
      receiveBuffer{ std::make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::ReceiveBufferSize), configurationStrategy.GetParserStrategy()) },
      sendBuffer{ std::make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::SendBufferSize), configurationStrategy.GetParserStrategy()) }
{
    if (!sockAcceptor.EnableNonBlock())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("设置非阻塞失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, IterativeServer)

bool Network::IterativeServer::WaitForMultipleEvents() noexcept
{
    return true;
}

bool Network::IterativeServer::HandleConnections()
{
    const auto configuration = GetConfigurationStrategy();

    SockAddress sockAddress{ configuration };

    if (const auto sockStream = std::make_shared<SockStream>(configuration);
        sockAcceptor.Accept(*sockStream, sockAddress))
    {
        const auto socketId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(CoreTools::UniqueIdSelect::Network);

        if (!sockStream->EnableNonBlock())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("设置非阻塞失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }

        StreamContainer container{ configuration, sockStream };

        streamContainer.emplace(socketId, container);

        CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPosition::Error) };
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncAcceptor));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy), System::EnumCastUnderlying(configuration.GetWrappersStrategy()));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Error), System::EnumCastUnderlying(System::WindowError::Success));

        if (!EventFunction(callbackParameters))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("回调函数执行错误！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }

    return true;
}

bool Network::IterativeServer::HandleData(const MessageEventManagerSharedPtr& aMessageEventManager)
{
    for (auto iter = streamContainer.begin(); iter != streamContainer.end();)
    {
        const auto sockStream = iter->second.GetSockStream();

        try
        {
            receiveBuffer->ClearCurrentIndex();

            if (const auto result = sockStream->Receive(receiveBuffer);
                0 < result)
            {
                const auto strategy = GetConfigurationStrategy();
                BufferReceiveStream bufferReceiveStream(receiveBuffer, strategy.GetParserStrategy(), strategy.GetEncryptedCompressionStrategy());
                bufferReceiveStream.OnEvent(iter->first, *aMessageEventManager);
                receiveBuffer->ClearCurrentIndex();
                ++iter;
            }
            else if (result < 0)
            {
                if (!sockStream->CloseHandle())
                {
                    LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("关闭句柄失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
                }

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
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("关闭句柄失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
            }

            streamContainer.erase(iter++);
        }
    }

    return true;
}

bool Network::IterativeServer::ImmediatelySend() noexcept
{
    return true;
}

bool Network::IterativeServer::ImmediatelySend(int64_t socketId) noexcept
{
    System::UnusedFunction(socketId);

    return true;
}

void Network::IterativeServer::ImmediatelyAsyncSend(int64_t socketId) noexcept
{
    System::UnusedFunction(socketId);
}

void Network::IterativeServer::Send(int64_t socketId, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (const auto iter = streamContainer.find(socketId);
        iter != streamContainer.cend())
    {
        const auto sockStream = iter->second.GetSockStream();

        if (auto& bufferSendStream = iter->second.GetBufferSendStream();
            bufferSendStream.Insert(message))
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
}

void Network::IterativeServer::AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (const auto iter = streamContainer.find(socketId);
        iter != streamContainer.cend())
    {
        const auto sockStream = iter->second.GetSockStream();

        if (auto& bufferSendStream = iter->second.GetBufferSendStream();
            bufferSendStream.Insert(message))
        {
            const auto buffer = std::make_shared<MessageBuffer>(BuffBlockSize::Automatic, GetConfigurationStrategy().GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::SendBufferSize), GetConfigurationStrategy().GetParserStrategy());

            bufferSendStream.Save(buffer);

            sockStream->AsyncSend(shared_from_this(), buffer);

            bufferSendStream.Clear();
        }
    }
}

bool Network::IterativeServer::EventFunction(const CoreTools::CallbackParameters& callbackParameters)
{
    NETWORK_CLASS_IS_VALID_9;

    if (const auto callbackEvent = GetMessageEventManagerSharedPtr()->GetCallbackEvent();
        callbackEvent != nullptr)
    {
        return callbackEvent->EventFunction(callbackParameters);
    }

    return true;
}
