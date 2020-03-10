// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/20 18:59)


#include "Network/NetworkExport.h" 

#include "BoostSockInetAddress.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

using std::move;
using std::string;
using std::to_string;
using std::make_shared;
using boost::numeric_cast;
using boost::asio::ip::make_address;
using TcpType = boost::asio::ip::tcp;

Network::BoostSockInetAddress
	::BoostSockInetAddress(const string& hostName, int port)
	:m_Endpoint{ make_address(hostName), numeric_cast<uint16_t>(port) }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockInetAddress
	::BoostSockInetAddress()
	:m_Endpoint{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockInetAddress
	::BoostSockInetAddress(int port)
	:m_Endpoint{ TcpType::v4(), numeric_cast<uint16_t>(port) }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockInetAddress
	::BoostSockInetAddress(BoostSockInetAddress&& rhs) noexcept
	:m_Endpoint{ move(rhs.m_Endpoint) }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockInetAddress
	::BoostSockInetAddress(const BoostSockInetAddress& rhs) 
	:m_Endpoint{ rhs.m_Endpoint }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockInetAddress& Network::BoostSockInetAddress
	::operator=(const BoostSockInetAddress& rhs)
{
	NETWORK_CLASS_IS_VALID_9;

	m_Endpoint = rhs.m_Endpoint;

	return *this;
}

Network::BoostSockInetAddress& Network::BoostSockInetAddress
	::operator=(BoostSockInetAddress&& rhs) noexcept
{
	NETWORK_CLASS_IS_VALID_9;

	m_Endpoint = move(rhs.m_Endpoint);

	return *this;
}

Network::BoostSockInetAddress
	::~BoostSockInetAddress()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostSockInetAddress)

const Network::BoostInetAddressType& Network::BoostSockInetAddress
	::GetBoostInetAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Endpoint;
}

Network::BoostInetAddressType& Network::BoostSockInetAddress
	::GetBoostInetAddress()
{
	NETWORK_CLASS_IS_VALID_9;

	return ParentType::GetBoostInetAddress();
}

const Network::BoostSockInetAddress::SockAddressPtr Network::BoostSockInetAddress
	::Clone() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return make_shared<ClassType>(*this);
}

const std::string Network::BoostSockInetAddress
	::GetAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Endpoint.address().to_string() + ":" + to_string(GetPort());
}

int Network::BoostSockInetAddress
	::GetPort() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Endpoint.port();
}

