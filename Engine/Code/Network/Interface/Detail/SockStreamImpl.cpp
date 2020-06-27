// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/11 11:31)

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

	THROW_EXCEPTION(SYSTEM_TEXT("����ACE Stream�࣡"));
}

Network::ACEHandleType Network::SockStreamImpl
	::GetACEHandle() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("����ACE Stream�࣡"));
}

void Network::SockStreamImpl
	::SetACEHandle(ACEHandleType handle)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(handle);

	THROW_EXCEPTION(SYSTEM_TEXT("����ACE Stream�࣡"));
}

void Network::SockStreamImpl
	::SetNetworkHandle(WinSocketStreamType winSocket)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(winSocket);

	THROW_EXCEPTION(SYSTEM_TEXT("����Network Stream�࣡"));
}

Network::BoostSockStreamType& Network::SockStreamImpl
	::GetBoostSockStream()
{
	NETWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("����boost Stream�࣡"));
}

Network::WinSocketStreamType& Network::SockStreamImpl
	::GetNetworkSockStream()
{
	NETWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("����Network Stream�࣡"));
}

