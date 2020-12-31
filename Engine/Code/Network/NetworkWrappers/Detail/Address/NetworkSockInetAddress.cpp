//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 19:10)

#include "Network/NetworkExport.h"

#include "NetworkSockInetAddress.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;
using std::string;
using std::to_string;
using namespace std::literals;

Network::NetworkSockInetAddress::NetworkSockInetAddress(const string& hostName, int port)
    : m_InetAddress{}, m_AddressName{ hostName }
{
    System::FillMemoryToZero(m_InetAddress);

    m_InetAddress.sin_family = boost::numeric_cast<uint16_t>(System::EnumCastUnderlying(System::AddressFamilies::Inet));
    m_InetAddress.sin_port = System::GetHostToNetShort(boost::numeric_cast<uint16_t>(port));
    m_InetAddress.sin_addr.s_addr = System::GetInetAddr(hostName.c_str());

    NETWORK_SELF_CLASS_IS_VALID_9;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Network::NetworkSockInetAddress::NetworkSockInetAddress()
    : m_InetAddress{}, m_AddressName{ "0.0.0.0" }
{
    m_InetAddress.sin_family = boost::numeric_cast<uint16_t>(System::EnumCastUnderlying(System::AddressFamilies::Inet));
    m_InetAddress.sin_port = System::GetHostToNetShort(0);
    m_InetAddress.sin_addr.s_addr = System::GetHostToNetLong(System::g_InAddrAny);

    NETWORK_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP

Network::NetworkSockInetAddress::NetworkSockInetAddress(int port)
    : m_InetAddress{}, m_AddressName{ "0.0.0.0" }
{
    System::FillMemoryToZero(m_InetAddress);

    m_InetAddress.sin_family = boost::numeric_cast<int16_t>(System::EnumCastUnderlying(System::AddressFamilies::Inet));
    m_InetAddress.sin_port = System::GetHostToNetShort(boost::numeric_cast<uint16_t>(port));
    m_InetAddress.sin_addr.s_addr = System::GetHostToNetLong(System::g_InAddrAny);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkSockInetAddress)

const Network::WinSockInetAddressType& Network::NetworkSockInetAddress::GetWinSockInetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_InetAddress;
}

Network::WinSockInetAddressType& Network::NetworkSockInetAddress::GetWinSockInetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return ParentType::GetWinSockInetAddress();
}

const Network::NetworkSockInetAddress::SockAddressPtr Network::NetworkSockInetAddress::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}

const string Network::NetworkSockInetAddress::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_AddressName + ":"s + to_string(GetPort());
}

int Network::NetworkSockInetAddress::GetPort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return System::GetNetToHostShort(boost::numeric_cast<uint16_t>(m_InetAddress.sin_port));
}
