//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 19:13)

#include "Network/NetworkExport.h"

#include "NetworkSockStream.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/MessageBuffer.h"

using std::string;

Network::NetworkSockStream::NetworkSockStream() noexcept
    : ParentType{}, m_WinSocket{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkSockStream)

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
int Network::NetworkSockStream::Receive(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    return System::Recv(m_WinSocket, messageBuffer->GetCurrentWriteBufferedPtr(), messageBuffer->GetSize(), System::SocketRecv::Default);
}

int Network::NetworkSockStream::Send(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    return System::Send(m_WinSocket, messageBuffer->GetInitialBufferedPtr(), messageBuffer->GetSize(), System::SocketSend::Default);
}

void Network::NetworkSockStream::AsyncReceive([[maybe_unused]] const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    [[maybe_unused]] const auto result = System::Recv(m_WinSocket, messageBuffer->GetCurrentWriteBufferedPtr(), messageBuffer->GetSize(), System::SocketRecv::Default);
}

void Network::NetworkSockStream::AsyncSend([[maybe_unused]] const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    [[maybe_unused]] const auto result = System::Send(m_WinSocket, messageBuffer->GetInitialBufferedPtr(), messageBuffer->GetSize(), System::SocketSend::Default);
}
#include STSTEM_WARNING_POP

Network::WinSocketStreamType& Network::NetworkSockStream::GetNetworkSockStream() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return m_WinSocket;
}

bool Network::NetworkSockStream::CloseHandle() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return System::CloseSocket(m_WinSocket);
}

void Network::NetworkSockStream::SetNetworkHandle(WinSocketStreamType winSocket) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    m_WinSocket = winSocket;
}

bool Network::NetworkSockStream::EnableNonBlock() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    unsigned long nonblock{ 1 };
    return System::IoctlSocket(m_WinSocket, System::IoctlSocketCmd::FionBio, &nonblock);
}

const string Network::NetworkSockStream::GetRemoteAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return string{};
}

int Network::NetworkSockStream::GetRemotePort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}
