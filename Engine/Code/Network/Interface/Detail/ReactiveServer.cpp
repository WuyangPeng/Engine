//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 11:57)

#include "Network/NetworkExport.h"

#include "ReactiveServer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
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
      m_SockAcceptor{ configurationStrategy.GetPort(), configurationStrategy },
      m_SockStream{ make_shared<SockStream>(configurationStrategy) },
      m_BufferSendStream{},
      m_MasterHandleSet{ configurationStrategy, m_SockAcceptor.GetACEHandle() },
      m_ActiveHandles{ configurationStrategy },
      m_Buffer(make_shared<MessageBuffer>(BuffBlockSize::Automatic, configurationStrategy.GetBufferSize(), configurationStrategy.GetParserStrategy()))
{
    Init();

    NETWORK_SELF_CLASS_IS_VALID_9;
}

// private
void Network::ReactiveServer::Init()
{
    if (!m_SockAcceptor.EnableNonBlock())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("启用非阻塞失败！"s));
    }
}

Network::ReactiveServer::~ReactiveServer() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        for (const auto& stream : m_BufferSendStream)
        {
            m_SockStream->SetACEHandle(stream.second->GetACEHandle());
            if (!m_SockStream->CloseHandle())
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                    << SYSTEM_TEXT("关闭句柄失败。")
                    << LOG_SINGLETON_TRIGGER_ASSERT;
            }
        }
    }
    EXCEPTION_ALL_CATCH(Network)
}

CLASS_INVARIANT_STUB_DEFINE(Network, ReactiveServer)

bool Network::ReactiveServer::WaitForMultipleEvents()
{
    m_ActiveHandles = m_MasterHandleSet.GetCurrentHandleSet();

    const auto width = boost::numeric_cast<int>(m_ActiveHandles.GetMaxSet()) + 1;
    if (!m_ActiveHandles.Select(width))
    {
        return false;
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    m_ActiveHandles.Sync(reinterpret_cast<ACEHandle>(m_ActiveHandles.GetMaxSet() + 1));

#include STSTEM_WARNING_POP

    return true;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
bool Network::ReactiveServer::HandleConnections(const SocketManagerSharedPtr& socketManager)
{
    if (m_ActiveHandles.IsSet(m_SockAcceptor.GetACEHandle()))
    {
        while (m_SockAcceptor.Accept(m_SockStream))
        {
            m_MasterHandleSet.SetBit(m_SockStream->GetACEHandle());

            const auto socketID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(CoreTools::UniqueIDSelect::Network);
            socketManager->InsertSocket(socketID);

            m_BufferSendStream.Insert(socketID, m_SockStream->GetACEHandle(), GetConfigurationStrategy().GetBufferSize(), GetConfigurationStrategy().GetParserStrategy());
        }

        m_ActiveHandles.ClearBit(m_SockAcceptor.GetACEHandle());
    }
    return true;
}
#include STSTEM_WARNING_POP

bool Network::ReactiveServer::HandleData(const SocketManagerSharedPtr& socketManager)
{
    HandleSetIterator handleSetIterator{ GetConfigurationStrategy(), m_ActiveHandles };

    auto handle = handleSetIterator();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
    while (System::IsSocketValid(reinterpret_cast<System::WinSocket>(handle)))
#include STSTEM_WARNING_POP
    {
        m_SockStream->SetACEHandle(handle);

        auto container = m_BufferSendStream.GetBufferSendStreamContainerByHandle(handle);

        try
        {
            if (m_SockStream->Receive(m_Buffer))
            {
                BufferReceiveStream bufferReceiveStream(m_Buffer, GetConfigurationStrategy().GetParserStrategy());
                bufferReceiveStream.OnEvent(container->GetSocketID(), socketManager);
                m_Buffer->ClearCurrentWriteIndex();
            }
            else
            {
                m_MasterHandleSet.ClearBit(handle);
                if (!m_SockStream->CloseHandle())
                {
                    LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                        << SYSTEM_TEXT("关闭句柄失败。")
                        << LOG_SINGLETON_TRIGGER_ASSERT;
                }
                m_BufferSendStream.Erase(container->GetSocketID());
            }
        }
        catch (CoreTools::Error&)
        {
            m_MasterHandleSet.ClearBit(handle);
            if (!m_SockStream->CloseHandle())
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                    << SYSTEM_TEXT("关闭句柄失败。")
                    << LOG_SINGLETON_TRIGGER_ASSERT;
            }
            m_BufferSendStream.Erase(container->GetSocketID());
        }

        handle = handleSetIterator();
    }

    m_MasterHandleSet.ToNextIndex();

    return true;
}

void Network::ReactiveServer::Send(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    auto container = m_BufferSendStream.GetBufferSendStreamContainerBySocketID(socketID);

    if (container->Insert(message))
    {
        if (GetConfigurationStrategy().GetSocketSendMessage() == SocketSendMessage::Immediately)
        {
            if (!ImmediatelySend(socketID))
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                    << SYSTEM_TEXT("消息发送失败。")
                    << LOG_SINGLETON_TRIGGER_ASSERT;
            }
        }
    }
    else
    {
        if (!ImmediatelySend(socketID))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                << SYSTEM_TEXT("消息发送失败。")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }

        if (!container->Insert(message))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                << SYSTEM_TEXT("消息发送失败。")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }

        if (GetConfigurationStrategy().GetSocketSendMessage() == SocketSendMessage::Immediately)
        {
            if (!ImmediatelySend(socketID))
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                    << SYSTEM_TEXT("消息发送失败。")
                    << LOG_SINGLETON_TRIGGER_ASSERT;
            }
        }
    }
}

bool Network::ReactiveServer::ImmediatelySend(uint64_t socketID)
{
    auto container = m_BufferSendStream.GetBufferSendStreamContainerBySocketID(socketID);

    if (!container->IsEmpty())
    {
        m_SockStream->SetACEHandle(container->GetACEHandle());

        container->Save(m_Buffer);

        [[maybe_unused]] const auto index = m_SockStream->Send(m_Buffer);

        container->Clear();
    }

    return true;
}

bool Network::ReactiveServer::ImmediatelySend()
{
    for (const auto& value : m_BufferSendStream)
    {
        if (!value.second->IsEmpty())
        {
            m_SockStream->SetACEHandle(value.second->GetACEHandle());

            value.second->Save(m_Buffer);

            [[maybe_unused]] const auto index = m_SockStream->Send(m_Buffer);

            value.second->Clear();
        }
    }

    return true;
}
