// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 11:24)

#include "Network/NetworkExport.h"

#include "ReactiveServer.h"
#include "System/Helper/UnusedMacro.h"
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

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <vector>

using std::make_pair;
using std::make_shared;
using std::vector;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26486)

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
void Network::ReactiveServer ::Init()
{
    if (!m_SockAcceptor.EnableNonBlock())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("∆Ù”√∑«◊Ë»˚ ß∞‹£°"s));
    }
}

Network::ReactiveServer ::~ReactiveServer()
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
        for (const auto& stream : m_BufferSendStream)
        {
            m_SockStream->SetACEHandle(stream.second->GetACEHandle());
            m_SockStream->CloseHandle();
        }
#include STSTEM_WARNING_POP
    }
    EXCEPTION_ALL_CATCH(Network)
}

CLASS_INVARIANT_STUB_DEFINE(Network, ReactiveServer)

bool Network::ReactiveServer ::WaitForMultipleEvents()
{
    m_ActiveHandles = m_MasterHandleSet.GetCurrentHandleSet();

    const auto width = boost::numeric_cast<int>(m_ActiveHandles.GetMaxSet()) + 1;
    if (!m_ActiveHandles.Select(width))
    {
        return false;
    }

    m_ActiveHandles.Sync(reinterpret_cast<ACEHandle>(m_ActiveHandles.GetMaxSet() + 1));

    return true;
}

bool Network::ReactiveServer ::HandleConnections(const SocketManagerSharedPtr& socketManager)
{
    if (m_ActiveHandles.IsSet(m_SockAcceptor.GetACEHandle()))
    {
        while (m_SockAcceptor.Accept(m_SockStream))
        {
            m_MasterHandleSet.SetBit(m_SockStream->GetACEHandle());

            const auto socketID = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(CoreTools::UniqueIDSelect::Network);
            socketManager->Insert(socketID);

            m_BufferSendStream.Insert(socketID, m_SockStream->GetACEHandle(), 1024, GetConfigurationStrategy().GetParserStrategy());
        }

        m_ActiveHandles.ClearBit(m_SockAcceptor.GetACEHandle());
    }
    return true;
}

bool Network::ReactiveServer ::HandleData(const SocketManagerSharedPtr& socketManager)
{
    HandleSetIterator handleSetIterator{ GetConfigurationStrategy(), m_ActiveHandles };

    auto handle = handleSetIterator();

    while (System::IsSocketValid(reinterpret_cast<System::WinSocket>(handle)))
    {
        m_SockStream->SetACEHandle(handle);

        auto ptr = m_BufferSendStream.GetBufferSendStreamContainerPtrByHandle(handle);

        try
        {
            if (m_SockStream->Receive(m_Buffer))
            {
                BufferReceiveStream bufferReceiveStream(m_Buffer, GetConfigurationStrategy().GetParserStrategy());
                bufferReceiveStream.OnEvent(ptr->GetSocketID(), socketManager);
                m_Buffer->ClearCurrentWriteIndex();
            }
            else
            {
                m_MasterHandleSet.ClearBit(handle);
                m_SockStream->CloseHandle();
                m_BufferSendStream.Erase(ptr->GetSocketID());
            }
        }
        catch (CoreTools::Error&)
        {
            m_MasterHandleSet.ClearBit(handle);
            m_SockStream->CloseHandle();
            m_BufferSendStream.Erase(ptr->GetSocketID());
        }

        handle = handleSetIterator();
    }

    m_MasterHandleSet.ToNextIndex();

    return true;
}

void Network::ReactiveServer ::Send(uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    auto ptr = m_BufferSendStream.GetBufferSendStreamContainerPtrBySocketID(socketID);

    if (ptr->Insert(message))
    {
        if (GetConfigurationStrategy().GetSocketSendMessage() == SocketSendMessage::Immediately)
        {
            ImmediatelySend(socketID);
        }
    }
    else
    {
        ImmediatelySend(socketID);

        ptr->Insert(message);

        if (GetConfigurationStrategy().GetSocketSendMessage() == SocketSendMessage::Immediately)
        {
            ImmediatelySend(socketID);
        }
    }
}

bool Network::ReactiveServer ::ImmediatelySend(uint64_t socketID)
{
    auto ptr = m_BufferSendStream.GetBufferSendStreamContainerPtrBySocketID(socketID);

    if (!ptr->IsEmpty())
    {
        m_SockStream->SetACEHandle(ptr->GetACEHandle());

        ptr->Save(m_Buffer);

        m_SockStream->Send(m_Buffer);

        ptr->Clear();
    }

    return true;
}

bool Network::ReactiveServer ::ImmediatelySend()
{
    for (const auto& value : m_BufferSendStream)
    {
        if (!value.second->IsEmpty())
        {
            m_SockStream->SetACEHandle(value.second->GetACEHandle());

            value.second->Save(m_Buffer);

            m_SockStream->Send(m_Buffer);

            value.second->Clear();
        }
    }

    return true;
}
#include STSTEM_WARNING_POP