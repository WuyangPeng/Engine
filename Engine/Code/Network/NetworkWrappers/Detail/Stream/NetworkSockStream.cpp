///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:42)

#include "Network/NetworkExport.h"

#include "NetworkSockStream.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/MessageBuffer.h"

Network::NetworkSockStream::NetworkSockStream() noexcept
    : ParentType{}, winSocket{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkSockStream)

int Network::NetworkSockStream::Receive(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(messageBuffer);

    return System::Recv(winSocket, messageBuffer->GetCurrentWriteBufferedPtr(), messageBuffer->GetSize(), System::SocketRecv::Default);
}

int Network::NetworkSockStream::Send(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(messageBuffer);

    return System::Send(winSocket, messageBuffer->GetInitialBufferedPtr(), messageBuffer->GetSize(), System::SocketSend::Default);
}

void Network::NetworkSockStream::AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventInterface, messageBuffer);

    MAYBE_UNUSED const auto result = Recv(winSocket, messageBuffer->GetCurrentWriteBufferedPtr(), messageBuffer->GetSize(), System::SocketRecv::Default);
}

void Network::NetworkSockStream::AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventInterface, messageBuffer);

    MAYBE_UNUSED const auto result = System::Send(winSocket, messageBuffer->GetInitialBufferedPtr(), messageBuffer->GetSize(), System::SocketSend::Default);
}

Network::WinSocketStreamType& Network::NetworkSockStream::GetNetworkSockStream() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return winSocket;
}

bool Network::NetworkSockStream::CloseHandle() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return System::CloseSocket(winSocket);
}

void Network::NetworkSockStream::SetNetworkHandle(WinSocketStreamType newWinSocket) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    winSocket = newWinSocket;
}

bool Network::NetworkSockStream::EnableNonBlock() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    unsigned long nonBlock{ 1 };
    return System::IoctlSocket(winSocket, System::IoctlSocketCmd::FionBio, &nonBlock);
}

std::string Network::NetworkSockStream::GetRemoteAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::string{};
}

int Network::NetworkSockStream::GetRemotePort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}
