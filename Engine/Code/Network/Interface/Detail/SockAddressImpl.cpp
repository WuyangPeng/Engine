// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/11 11:27)

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

	THROW_EXCEPTION(SYSTEM_TEXT("����ACE��ַ�࣡"));
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

	THROW_EXCEPTION(SYSTEM_TEXT("����boost��ַ�࣡"));
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

	THROW_EXCEPTION(SYSTEM_TEXT("����WinSock��ַ�࣡"));
}

Network::WinSockInetAddressType& Network::SockAddressImpl
	::GetWinSockInetAddress()
{
	NETWORK_CLASS_IS_VALID_9;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(WinSockInetAddressType&, GetWinSockInetAddress);
}
