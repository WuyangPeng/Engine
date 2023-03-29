///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 23:44)

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
#include "Network/NetworkMessage/SocketManager.h"

#include <vector>

using std::make_pair;
using std::make_shared;
using std::vector;

Network::ReactiveServer::ReactiveServer(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy)
    : ParentType{ socketManager, configurationStrategy },
      sockAcceptor{ configurationStrategy.GetPort(), configurationStrategy },
      sockStream{ make_shared<SockStream>(configurationStrategy) },
      bufferSendStream{},
      masterHandleSet{ configurationStrategy, sockAcceptor.GetACEHandle() },
      activeHandles{ configurationStrategy },
      buffer(make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy()))
{
    Init();

    NETWORK_SELF_CLASS_IS_VALID_9;
}

// private
void Network::ReactiveServer::Init()
{
    if (!sockAcceptor.EnableNonBlock())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("启用非阻塞失败！"s));
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

    const auto width = boost::numeric_cast<int>(activeHandles.GetMaxSet()) + 1;
    if (!activeHandles.Select(width))
    {
        return false;
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    activeHandles.Sync(reinterpret_cast<ACEHandle>(activeHandles.GetMaxSet() + 1));

#include STSTEM_WARNING_POP

    return true;
}

bool Network::ReactiveServer::HandleConnections(SocketManager& socketManager)
{
    if (activeHandles.IsSet(sockAcceptor.GetACEHandle()))
    {
        const auto strategy = GetConfigurationStrategy();
        while (sockAcceptor.Accept(*sockStream))
        {
            masterHandleSet.SetBit(sockStream->GetACEHandle());

            const auto socketID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(CoreTools::UniqueIdSelect::Network);
            socketManager.InsertSocket(socketID);

            bufferSendStream.Insert(socketID, sockStream->GetACEHandle(), strategy.GetBufferSize(), strategy.GetParserStrategy(), strategy.GetEncryptedCompressionStrategy());
        }

        activeHandles.ClearBit(sockAcceptor.GetACEHandle());
    }
    return true;
}

bool Network::ReactiveServer::HandleData(const SocketManagerSharedPtr& socketManager)
{
    HandleSetIterator handleSetIterator{ GetConfigurationStrategy(), activeHandles };

    auto handle = handleSetIterator();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    while (System::IsSocketValid(reinterpret_cast<System::WinSocket>(handle)))
#include STSTEM_WARNING_POP
    {
        sockStream->SetACEHandle(handle);

        auto container = bufferSendStream.GetBufferSendStreamContainerByHandle(handle);

        try
        {
            if (sockStream->Receive(buffer))
            {
                const auto strategy = GetConfigurationStrategy();

                BufferReceiveStream bufferReceiveStream(buffer, strategy.GetParserStrategy(), strategy.GetEncryptedCompressionStrategy());
                bufferReceiveStream.OnEvent(container->GetSocketID(), socketManager);
                buffer->ClearCurrentWriteIndex();
            }
            else
            {
                masterHandleSet.ClearBit(handle);
                if (!sockStream->CloseHandle())
                {
                    LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("关闭句柄失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
                }
                bufferSendStream.Erase(container->GetSocketID());
            }
        }
        catch (CoreTools::Error&)
        {
            masterHandleSet.ClearBit(handle);
            if (!sockStream->CloseHandle())
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("关闭句柄失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
            }
            bufferSendStream.Erase(container->GetSocketID());
        }

        handle = handleSetIterator();
    }

    masterHandleSet.ToNextIndex();

    return true;
}

void Network::ReactiveServer::Send(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    auto container = bufferSendStream.GetBufferSendStreamContainerBySocketID(socketID);
    const auto strategy = GetConfigurationStrategy();

    if (container->Insert(message))
    {
        if (strategy.GetSocketSendMessage() == SocketSendMessage::Immediately)
        {
            if (!ImmediatelySend(socketID))
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息发送失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
            }
        }
    }
    else
    {
        if (!ImmediatelySend(socketID))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息发送失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }

        if (!container->Insert(message))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息发送失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }

        if (strategy.GetSocketSendMessage() == SocketSendMessage::Immediately)
        {
            if (!ImmediatelySend(socketID))
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息发送失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
            }
        }
    }
}

void Network::ReactiveServer::AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    AsyncSend(socketID, message);
}

bool Network::ReactiveServer::ImmediatelySend(uint64_t socketID)
{
    auto container = bufferSendStream.GetBufferSendStreamContainerBySocketID(socketID);

    if (!container->IsEmpty())
    {
        sockStream->SetACEHandle(container->GetACEHandle());

        container->Save(buffer);

        MAYBE_UNUSED const auto index = sockStream->Send(buffer);

        container->Clear();
    }

    return true;
}

void Network::ReactiveServer::ImmediatelyAsyncSend(MAYBE_UNUSED uint64_t socketID) noexcept
{
}

bool Network::ReactiveServer::ImmediatelySend()
{
    for (const auto& value : bufferSendStream)
    {
        if (!value.second->IsEmpty())
        {
            sockStream->SetACEHandle(value.second->GetACEHandle());

            value.second->Save(buffer);

            MAYBE_UNUSED const auto index = sockStream->Send(buffer);

            value.second->Clear();
        }
    }

    return true;
}

bool Network::ReactiveServer::EventFunction(MAYBE_UNUSED const CoreTools::CallbackParameters& callbackParameters) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return true;
}
