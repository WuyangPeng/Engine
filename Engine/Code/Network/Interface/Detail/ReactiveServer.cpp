///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 11:25)

#include "Network/NetworkExport.h"

#include "ReactiveServer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/HandleSetIterator.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageEventManager.h"

Network::ReactiveServer::ReactiveServer(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager)
    : ParentType{ configurationStrategy, messageEventManager },
      sockAcceptor{ configurationStrategy.GetPort(), configurationStrategy },
      sockStream{ std::make_shared<SockStream>(configurationStrategy) },
      bufferSendStream{},
      masterHandleSet{ configurationStrategy, sockAcceptor.GetACEHandle() },
      activeHandles{ configurationStrategy },
      buffer(std::make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::ReceiveBufferSize), configurationStrategy.GetParserStrategy()))
{
    Init();

    NETWORK_SELF_CLASS_IS_VALID_9;
}

void Network::ReactiveServer::Init()
{
    if (!sockAcceptor.EnableNonBlock())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("启用非阻塞失败！"s))
    }
}

Network::ReactiveServer::~ReactiveServer() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        for (const auto& stream : bufferSendStream)
        {
            sockStream->SetACEHandle(stream.second->GetACEHandle());
            if (!sockStream->CloseHandle())
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("关闭句柄失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
            }
        }
    }
    EXCEPTION_ALL_CATCH(Network)
}

CLASS_INVARIANT_STUB_DEFINE(Network, ReactiveServer)

bool Network::ReactiveServer::WaitForMultipleEvents()
{
    activeHandles = masterHandleSet.GetCurrentHandleSet();

    if (const auto width = boost::numeric_cast<int>(activeHandles.GetMaxSet()) + 1;
        !activeHandles.Select(width))
    {
        return false;
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    activeHandles.Sync(reinterpret_cast<ACEHandle>(activeHandles.GetMaxSet() + 1));

#include STSTEM_WARNING_POP

    return true;
}

bool Network::ReactiveServer::HandleConnections()
{
    if (activeHandles.IsSet(sockAcceptor.GetACEHandle()))
    {
        const auto strategy = GetConfigurationStrategy();
        while (sockAcceptor.Accept(*sockStream))
        {
            masterHandleSet.SetBit(sockStream->GetACEHandle());

            const auto socketId = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(CoreTools::UniqueIdSelect::Network);

            bufferSendStream.Insert(socketId, sockStream->GetACEHandle(), strategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::SendBufferSize), strategy.GetParserStrategy(), strategy.GetEncryptedCompressionStrategy());
        }

        activeHandles.ClearBit(sockAcceptor.GetACEHandle());
    }
    return true;
}

bool Network::ReactiveServer::HandleData(const MessageEventManagerSharedPtr& aMessageEventManager)
{
    HandleSetIterator handleSetIterator{ GetConfigurationStrategy(), activeHandles };

    auto handle = handleSetIterator();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    while (System::IsSocketValid(reinterpret_cast<System::WinSocket>(handle)))

#include STSTEM_WARNING_POP
    {
        sockStream->SetACEHandle(handle);

        const auto container = bufferSendStream.GetBufferSendStreamContainerByHandle(handle);

        try
        {
            if (sockStream->Receive(buffer))
            {
                const auto strategy = GetConfigurationStrategy();

                BufferReceiveStream bufferReceiveStream(buffer, strategy.GetParserStrategy(), strategy.GetEncryptedCompressionStrategy());
                bufferReceiveStream.OnEvent(container->GetSocketId(), *aMessageEventManager);
                buffer->ClearCurrentWriteIndex();
            }
            else
            {
                masterHandleSet.ClearBit(handle);
                if (!sockStream->CloseHandle())
                {
                    LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("关闭句柄失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
                }
                bufferSendStream.Erase(container->GetSocketId());
            }
        }
        catch (CoreTools::Error&)
        {
            masterHandleSet.ClearBit(handle);
            if (!sockStream->CloseHandle())
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("关闭句柄失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
            }
            bufferSendStream.Erase(container->GetSocketId());
        }

        handle = handleSetIterator();
    }

    masterHandleSet.ToNextIndex();

    return true;
}

void Network::ReactiveServer::Send(int64_t socketId, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto container = bufferSendStream.GetBufferSendStreamContainerBySocketId(socketId);
    const auto strategy = GetConfigurationStrategy();

    if (container->Insert(message))
    {
        if (strategy.GetSocketSendMessage() == SocketSendMessage::Immediately)
        {
            if (!ImmediatelySend(socketId))
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息发送失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
            }
        }
    }
    else
    {
        if (!ImmediatelySend(socketId))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息发送失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }

        if (!container->Insert(message))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息发送失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }

        if (strategy.GetSocketSendMessage() == SocketSendMessage::Immediately)
        {
            if (!ImmediatelySend(socketId))
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息发送失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
            }
        }
    }
}

void Network::ReactiveServer::AsyncSend(int64_t socketId, const MessageInterfaceSharedPtr& message)
{
    AsyncSend(socketId, message);
}

bool Network::ReactiveServer::ImmediatelySend(int64_t socketId)
{
    if (const auto container = bufferSendStream.GetBufferSendStreamContainerBySocketId(socketId);
        !container->IsEmpty())
    {
        sockStream->SetACEHandle(container->GetACEHandle());

        container->Save(buffer);

        if (const auto result = sockStream->Send(buffer);
            result != buffer->GetSize())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息发送失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }

        container->Clear();
    }

    return true;
}

void Network::ReactiveServer::ImmediatelyAsyncSend(int64_t socketId) noexcept
{
    System::UnusedFunction(socketId);
}

bool Network::ReactiveServer::ImmediatelySend()
{
    for (const auto& value : bufferSendStream)
    {
        if (!value.second->IsEmpty())
        {
            sockStream->SetACEHandle(value.second->GetACEHandle());

            value.second->Save(buffer);

            if (const auto result = sockStream->Send(buffer);
                result != buffer->GetSize())
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息发送失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
            }

            value.second->Clear();
        }
    }

    return true;
}

bool Network::ReactiveServer::EventFunction(const CoreTools::CallbackParameters& callbackParameters) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(callbackParameters);

    return true;
}
