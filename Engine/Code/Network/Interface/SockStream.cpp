/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:28)

#include "Network/NetworkExport.h"

#include "SockStream.h"
#include "Detail/SockStreamFactory.h"
#include "Detail/SockStreamImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::SockStream::SockStream(const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockStream)

int Network::SockStream::Send(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->Send(messageBuffer);
}

int Network::SockStream::Receive(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->Receive(messageBuffer);
}

void Network::SockStream::AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->AsyncSend(eventInterface, messageBuffer);
}

void Network::SockStream::AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->AsyncReceive(eventInterface, messageBuffer);
}

Network::ACESockStreamType& Network::SockStream::GetACESockStream()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->GetACESockStream();
}

Network::BoostSockStreamType& Network::SockStream::GetBoostSockStream()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->GetBoostSockStream();
}

Network::WinSocketStreamType& Network::SockStream::GetNetworkSockStream()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->GetNetworkSockStream();
}

Network::ACEHandleType Network::SockStream::GetACEHandle() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetACEHandle();
}

void Network::SockStream::SetACEHandle(ACEHandleType handle)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->SetACEHandle(handle);
}

void Network::SockStream::SetNetworkHandle(WinSocketStreamType winSocket)
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->SetNetworkHandle(winSocket);
}

bool Network::SockStream::CloseHandle()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->CloseHandle();
}

bool Network::SockStream::EnableNonBlock()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->EnableNonBlock();
}

std::string Network::SockStream::GetRemoteAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetRemoteAddress();
}

int Network::SockStream::GetRemotePort() const
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->GetRemotePort();
}
