// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/02 10:18)

#include "Network/NetworkExport.h" 

#include "NetworkSockInetAddress.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/MemoryTools/MemoryHelperDetail.h"

#include <boost/numeric/conversion/cast.hpp>

using std::string;
using std::to_string;
using std::make_shared;

Network::NetworkSockInetAddress
	::NetworkSockInetAddress(const string& hostName, int port)
	:m_InetAddress{}, m_AddressName{ hostName }
{	
	System::FillMemoryToZero(m_InetAddress);

	m_InetAddress.sin_family = boost::numeric_cast<uint16_t>(System::EnumCastUnderlying(System::AddressFamilies::Inet));
	m_InetAddress.sin_port = System::GetHostToNetShort(boost::numeric_cast<uint16_t>(port));
	m_InetAddress.sin_addr.s_addr = System::GetInetAddr(hostName.c_str());

	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockInetAddress
	::NetworkSockInetAddress()
	:m_InetAddress{}, m_AddressName{ "0.0.0.0" }
{
	System::FillMemoryToZero(m_InetAddress);

	m_InetAddress.sin_family = boost::numeric_cast<uint16_t>(System::EnumCastUnderlying(System::AddressFamilies::Inet));
	m_InetAddress.sin_port = System::GetHostToNetShort(0); 
	m_InetAddress.sin_addr.s_addr = System::GetHostToNetLong(System::g_InAddrAny);

	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockInetAddress
	::NetworkSockInetAddress(int port)
	:m_InetAddress{}, m_AddressName{ "0.0.0.0" }
{
	System::FillMemoryToZero(m_InetAddress);

	m_InetAddress.sin_family = boost::numeric_cast<int16_t>(System::EnumCastUnderlying(System::AddressFamilies::Inet));
	m_InetAddress.sin_port = System::GetHostToNetShort(boost::numeric_cast<uint16_t>(port));
	m_InetAddress.sin_addr.s_addr = System::GetHostToNetLong(System::g_InAddrAny);
 
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockInetAddress
	::~NetworkSockInetAddress()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkSockInetAddress)

const Network::WinSockInetAddressType& Network::NetworkSockInetAddress
	::GetWinSockInetAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_InetAddress;
}

Network::WinSockInetAddressType& Network::NetworkSockInetAddress
	::GetWinSockInetAddress()
{
	NETWORK_CLASS_IS_VALID_9;

	return ParentType::GetWinSockInetAddress();
}

const Network::NetworkSockInetAddress::SockAddressPtr Network::NetworkSockInetAddress
	::Clone() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return make_shared<ClassType>(*this);
}

const std::string Network::NetworkSockInetAddress
	::GetAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_AddressName + ":" + to_string(GetPort());
}

int Network::NetworkSockInetAddress
	::GetPort() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return System::GetNetToHostShort(boost::numeric_cast<uint16_t>(m_InetAddress.sin_port));
}
