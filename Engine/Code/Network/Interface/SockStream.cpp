///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 09:34)

#include "Network/NetworkExport.h"

#include "SockStream.h"
#include "Detail/SockStreamFactory.h"
#include "Detail/SockStreamImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Network::SockStream::SockStream(const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockStream)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, GetACESockStream, Network::ACESockStreamNativeType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, GetBoostSockStream, Network::BoostSockStreamType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, GetNetworkSockStream, Network::WinSocketStreamType&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, GetACEHandle, Network::ACEHandleType)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, CloseHandle, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, SockStream, SetACEHandle, ACEHandleType, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, SockStream, SetNetworkHandle, WinSocketStreamType, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, EnableNonBlock, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, GetRemoteAddress, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, GetRemotePort, int)

int Network::SockStream::Send(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Send(messageBuffer);
}

int Network::SockStream::Receive(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Receive(messageBuffer);
}

void Network::SockStream::AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->AsyncSend(eventInterface, messageBuffer);
}

void Network::SockStream::AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->AsyncReceive(eventInterface, messageBuffer);
}