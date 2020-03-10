// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.1.0 (2019/10/23 10:06)


#include "Network/NetworkExport.h" 

#include "SockStream.h"
#include "Detail/SockStreamFactory.h"
#include "Detail/SockStreamImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::string;

Network::SockStream
	::SockStream(const ConfigurationStrategy& configurationStrategy)
	:m_Impl{ SockStreamFactory::Create(configurationStrategy) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, SockStream)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, GetACESockStream, Network::ACESockStreamNativeType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, GetBoostSockStream, Network::BoostSockStreamType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, GetNetworkSockStream, Network::WinSocketStreamType&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, GetACEHandle, Network::ACEHandleType)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, CloseHandle, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, SockStream, SetACEHandle, ACEHandleType, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Network, SockStream, SetNetworkHandle, WinSocketStreamType, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, EnableNonBlock, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, GetRemoteAddress, const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockStream, GetRemotePort, int)

int Network::SockStream
	::Send(const MessageBufferSharedPtr& messageBuffer)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Send(messageBuffer);
}

int Network::SockStream
	::Receive(const MessageBufferSharedPtr& messageBuffer)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Receive(messageBuffer);
}

void Network::SockStream
	::AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->AsyncSend(eventInterface, messageBuffer);
}

void Network::SockStream
	::AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->AsyncReceive(eventInterface, messageBuffer);
}  