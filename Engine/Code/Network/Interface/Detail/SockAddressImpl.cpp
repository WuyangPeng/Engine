/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:29)

#include "Network/NetworkExport.h"

#include "SockAddressImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CLASS_INVARIANT_STUB_DEFINE(Network, SockAddressImpl)

const Network::ACEInternetAddressType& Network::SockAddressImpl::GetACEInternetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����ACE��ַ�࣡"s))
}

Network::ACEInternetAddressType& Network::SockAddressImpl::GetACEInternetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(ACEInternetAddressType&, GetACEInternetAddress);
}

const Network::BoostInternetAddressType& Network::SockAddressImpl::GetBoostInternetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����boost��ַ�࣡"s))
}

Network::BoostInternetAddressType& Network::SockAddressImpl::GetBoostInternetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(BoostInternetAddressType&, GetBoostInternetAddress);
}

const Network::WinSockInternetAddressType& Network::SockAddressImpl::GetWinSockInternetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����WinSock��ַ�࣡"s))
}

Network::WinSockInternetAddressType& Network::SockAddressImpl::GetWinSockInternetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(WinSockInternetAddressType&, GetWinSockInternetAddress);
}
