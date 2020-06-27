// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/11 11:31)

#include "Network/NetworkExport.h" 

#include "SockStreamImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

Network::SockStreamImpl
	::SockStreamImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SockStreamImpl
	::~SockStreamImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockStreamImpl)

Network::ACESockStreamNativeType& Network::SockStreamImpl
	::GetACESockStream()
{
	NETWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("不是ACE Stream类！"));
}

Network::ACEHandleType Network::SockStreamImpl
	::GetACEHandle() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("不是ACE Stream类！"));
}

void Network::SockStreamImpl
	::SetACEHandle(ACEHandleType handle)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(handle);

	THROW_EXCEPTION(SYSTEM_TEXT("不是ACE Stream类！"));
}

void Network::SockStreamImpl
	::SetNetworkHandle(WinSocketStreamType winSocket)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(winSocket);

	THROW_EXCEPTION(SYSTEM_TEXT("不是Network Stream类！"));
}

Network::BoostSockStreamType& Network::SockStreamImpl
	::GetBoostSockStream()
{
	NETWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("不是boost Stream类！"));
}

Network::WinSocketStreamType& Network::SockStreamImpl
	::GetNetworkSockStream()
{
	NETWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("不是Network Stream类！"));
}

