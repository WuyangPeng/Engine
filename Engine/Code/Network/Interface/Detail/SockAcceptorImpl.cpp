// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.1.0 (2019/10/18 13:41)


#include "Network/NetworkExport.h" 

#include "SockAcceptorImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::SockAcceptorImpl
	::SockAcceptorImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SockAcceptorImpl
	::~SockAcceptorImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;	
}

CLASS_INVARIANT_STUB_DEFINE(Network,SockAcceptorImpl)

Network::ACEHandleType Network::SockAcceptorImpl
	::GetACEHandle()
{
	NETWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("����ACE Acceptor�࣡"));
}

Network::BoostHandleType Network::SockAcceptorImpl
	::GetBoostHandle()
{
	NETWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("����boost Acceptor�࣡"));
}

Network::WinSocketType Network::SockAcceptorImpl
	::GetWinSocket()
{
	NETWORK_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("����Network Acceptor�࣡"));
}

