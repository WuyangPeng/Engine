//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 17:34)

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
    : m_Endpoint{ make_address(hostName), numeric_cast<uint16_t>(port) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockInetAddress::BoostSockInetAddress() noexcept
    : m_Endpoint{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockInetAddress::BoostSockInetAddress(int port)
    : m_Endpoint{ TcpType::v4(), numeric_cast<uint16_t>(port) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockInetAddress::BoostSockInetAddress(BoostSockInetAddress&& rhs) noexcept
    : m_Endpoint{ move(rhs.m_Endpoint) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockInetAddress::BoostSockInetAddress(const BoostSockInetAddress& rhs) noexcept
    : m_Endpoint{ rhs.m_Endpoint }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockInetAddress& Network::BoostSockInetAddress::operator=(const BoostSockInetAddress& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    m_Endpoint = rhs.m_Endpoint;

    return *this;
}

Network::BoostSockInetAddress& Network::BoostSockInetAddress::operator=(BoostSockInetAddress&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    m_Endpoint = std::move(rhs.m_Endpoint);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostSockInetAddress)

const Network::BoostInetAddressType& Network::BoostSockInetAddress::GetBoostInetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Endpoint;
}

Network::BoostInetAddressType& Network::BoostSockInetAddress::GetBoostInetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return ParentType::GetBoostInetAddress();
}

const Network::BoostSockInetAddress::SockAddressPtr Network::BoostSockInetAddress::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}

const std::string Network::BoostSockInetAddress::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Endpoint.address().to_string() + ":"s + to_string(GetPort());
}

int Network::BoostSockInetAddress::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Endpoint.port();
}
