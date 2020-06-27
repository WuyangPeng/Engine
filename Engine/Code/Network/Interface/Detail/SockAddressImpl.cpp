// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/11 11:27)

#include "Network/NetworkExport.h" 

#include "SockAddressImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::SockAddressImpl
	::SockAddressImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SockAddressImpl
	::~SockAddressImpl()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockAddressImpl)

const Network::ACEInetAddressType& Network::SockAddressImpl
	::GetACEInetAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("不是ACE地址类！"));
}

Network::ACEInetAddressType& Network::SockAddressImpl
	::GetACEInetAddress()
{
	NETWORK_CLASS_IS_VALID_9;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(ACEInetAddressType&, GetACEInetAddress);
}

const Network::BoostInetAddressType& Network::SockAddressImpl
	::GetBoostInetAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("不是boost地址类！"));
}

Network::BoostInetAddressType& Network::SockAddressImpl
	::GetBoostInetAddress()
{
	NETWORK_CLASS_IS_VALID_9;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(BoostInetAddressType&, GetBoostInetAddress);
}

const Network::WinSockInetAddressType& Network::SockAddressImpl
	::GetWinSockInetAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("不是WinSock地址类！"));
}

Network::WinSockInetAddressType& Network::SockAddressImpl
	::GetWinSockInetAddress()
{
	NETWORK_CLASS_IS_VALID_9;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(WinSockInetAddressType&, GetWinSockInetAddress);
}
