/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:29)

#include "Network/NetworkExport.h"

#include "SockAddressImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CLASS_INVARIANT_STUB_DEFINE(Network, SockAddressImpl)

const Network::ACEInternetAddressType& Network::SockAddressImpl::GetACEInternetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("不是ACE地址类！"s))
}

Network::ACEInternetAddressType& Network::SockAddressImpl::GetACEInternetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(ACEInternetAddressType&, GetACEInternetAddress);
}

const Network::BoostInternetAddressType& Network::SockAddressImpl::GetBoostInternetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("不是boost地址类！"s))
}

Network::BoostInternetAddressType& Network::SockAddressImpl::GetBoostInternetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(BoostInternetAddressType&, GetBoostInternetAddress);
}

const Network::WinSockInternetAddressType& Network::SockAddressImpl::GetWinSockInternetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("不是WinSock地址类！"s))
}

Network::WinSockInternetAddressType& Network::SockAddressImpl::GetWinSockInternetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(WinSockInternetAddressType&, GetWinSockInternetAddress);
}
