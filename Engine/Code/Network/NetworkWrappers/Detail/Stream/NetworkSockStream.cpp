///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/23 17:44)

#include "Network/NetworkExport.h"

#include "NetworkSockStream.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/MessageBuffer.h"

using std::string;

Network::NetworkSockStream::NetworkSockStream() noexcept
    : ParentType{}, winSocket{ 0 }
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

    return System::Recv(winSocket, messageBuffer->GetCurrentWriteBufferedPtr(), messageBuffer->GetSize(), System::SocketRecv::Default);
}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
int Network::NetworkSockStream::Send(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    return System::Send(winSocket, messageBuffer->GetInitialBufferedPtr(), messageBuffer->GetSize(), System::SocketSend::Default);
}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
void Network::NetworkSockStream::AsyncReceive(MAYBE_UNUSED const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    MAYBE_UNUSED const auto result = System::Recv(winSocket, messageBuffer->GetCurrentWriteBufferedPtr(), messageBuffer->GetSize(), System::SocketRecv::Default);
}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
void Network::NetworkSockStream::AsyncSend(MAYBE_UNUSED const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    MAYBE_UNUSED const auto result = System::Send(winSocket, messageBuffer->GetInitialBufferedPtr(), messageBuffer->GetSize(), System::SocketSend::Default);
}
#include STSTEM_WARNING_POP

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

    unsigned long nonblock{ 1 };
    return System::IoctlSocket(winSocket, System::IoctlSocketCmd::FionBio, &nonblock);
}

string Network::NetworkSockStream::GetRemoteAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return string{};
}

int Network::NetworkSockStream::GetRemotePort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}
