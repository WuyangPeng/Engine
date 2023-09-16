///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:21)

#include "Network/NetworkExport.h"

#include "BoostSockInternetAddress.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

Network::BoostSockInternetAddress::BoostSockInternetAddress(const std::string& hostName, int port)
    : endpoint{ boost::asio::ip::make_address(hostName), boost::numeric_cast<uint16_t>(port) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockInternetAddress::BoostSockInternetAddress() noexcept
    : endpoint{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockInternetAddress::BoostSockInternetAddress(int port)
    : endpoint{ boost::asio::ip::tcp::v4(), boost::numeric_cast<uint16_t>(port) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostSockInternetAddress)

const Network::BoostInternetAddressType& Network::BoostSockInternetAddress::GetBoostInternetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return endpoint;
}

Network::BoostInternetAddressType& Network::BoostSockInternetAddress::GetBoostInternetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return ParentType::GetBoostInternetAddress();
}

Network::BoostSockInternetAddress::SockAddressSharedPtr Network::BoostSockInternetAddress::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

std::string Network::BoostSockInternetAddress::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return endpoint.address().to_string() + ":"s + std::to_string(GetPort());
}

int Network::BoostSockInternetAddress::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return endpoint.port();
}
