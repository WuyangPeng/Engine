///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 13:42)

#include "Network/NetworkExport.h"

#include "SockAddress.h"
#include "Detail/SockAddressFactory.h"
#include "Detail/SockAddressImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Network, SockAddress)

Network::SockAddress::SockAddress(const std::string& hostName, int port, const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, hostName, port, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SockAddress::SockAddress(int port, const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, port, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::SockAddress::SockAddress(const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockAddress)

const Network::ACEInternetAddressType& Network::SockAddress::GetACEInternetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetACEInternetAddress();
}

Network::ACEInternetAddressType& Network::SockAddress::GetACEInternetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->GetACEInternetAddress();
}

const Network::BoostInternetAddressType& Network::SockAddress::GetBoostInternetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetBoostInternetAddress();
}

Network::BoostInternetAddressType& Network::SockAddress::GetBoostInternetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->GetBoostInternetAddress();
}

const Network::WinSockInternetAddressType& Network::SockAddress::GetWinSockInternetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetWinSockInternetAddress();
}

Network::WinSockInternetAddressType& Network::SockAddress::GetWinSockInternetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->GetWinSockInternetAddress();
}

std::string Network::SockAddress::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetAddress();
}

int Network::SockAddress::GetPort() const
{
    NETWORK_CLASS_IS_VALID_9;

    return impl->GetPort();
}
