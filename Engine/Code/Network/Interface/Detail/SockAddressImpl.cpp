//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 12:53)

#include "Network/NetworkExport.h"

#include "SockAddressImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CLASS_INVARIANT_STUB_DEFINE(Network, SockAddressImpl)

const Network::ACEInetAddressType& Network::SockAddressImpl::GetACEInetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����ACE��ַ�࣡"s));
}

Network::ACEInetAddressType& Network::SockAddressImpl::GetACEInetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(ACEInetAddressType&, GetACEInetAddress);
}

const Network::BoostInetAddressType& Network::SockAddressImpl::GetBoostInetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����boost��ַ�࣡"s));
}

Network::BoostInetAddressType& Network::SockAddressImpl::GetBoostInetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(BoostInetAddressType&, GetBoostInetAddress);
}

const Network::WinSockInetAddressType& Network::SockAddressImpl::GetWinSockInetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����WinSock��ַ�࣡"s));
}

Network::WinSockInetAddressType& Network::SockAddressImpl::GetWinSockInetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(WinSockInetAddressType&, GetWinSockInetAddress);
}
