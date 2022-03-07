///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/22 22:26)

#include "Network/NetworkExport.h"

#include "BoostSockInetAddress.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using boost::numeric_cast;
using boost::asio::ip::make_address;
using std::make_shared;
using std::move;
using std::string;
using std::to_string;
using TcpType = boost::asio::ip::tcp;
using namespace std::literals;

Network::BoostSockInetAddress::BoostSockInetAddress(const string& hostName, int port)
    : endpoint{ make_address(hostName), numeric_cast<uint16_t>(port) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockInetAddress::BoostSockInetAddress() noexcept
    : endpoint{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockInetAddress::BoostSockInetAddress(int port)
    : endpoint{ TcpType::v4(), numeric_cast<uint16_t>(port) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostSockInetAddress)

const Network::BoostInetAddressType& Network::BoostSockInetAddress::GetBoostInetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return endpoint;
}

Network::BoostInetAddressType& Network::BoostSockInetAddress::GetBoostInetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return ParentType::GetBoostInetAddress();
}

Network::BoostSockInetAddress::SockAddressSharedPtr Network::BoostSockInetAddress::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}

std::string Network::BoostSockInetAddress::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return endpoint.address().to_string() + ":"s + to_string(GetPort());
}

int Network::BoostSockInetAddress::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return endpoint.port();
}
