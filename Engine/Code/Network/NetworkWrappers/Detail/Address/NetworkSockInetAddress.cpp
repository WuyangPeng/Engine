///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/23 17:32)

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
    : inetAddress{}, addressName{ hostName }
{
    inetAddress.sin_family = boost::numeric_cast<uint16_t>(System::EnumCastUnderlying(System::AddressFamilies::Internet));
    inetAddress.sin_port = System::GetHostToNetShort(boost::numeric_cast<uint16_t>(port));
    inetAddress.sin_addr.s_addr = System::GetInternetAddress(hostName.c_str());

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockInetAddress::NetworkSockInetAddress(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : inetAddress{}, addressName{ "0.0.0.0" }
{
    inetAddress.sin_family = boost::numeric_cast<uint16_t>(System::EnumCastUnderlying(System::AddressFamilies::Internet));
    inetAddress.sin_port = System::GetHostToNetShort(0);
    inetAddress.sin_addr.s_addr = System::GetHostToNetLong(System::internetAddrAny);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockInetAddress::NetworkSockInetAddress(int port)
    : inetAddress{}, addressName{ "0.0.0.0" }
{
    inetAddress.sin_family = boost::numeric_cast<int16_t>(System::EnumCastUnderlying(System::AddressFamilies::Internet));
    inetAddress.sin_port = System::GetHostToNetShort(boost::numeric_cast<uint16_t>(port));
    inetAddress.sin_addr.s_addr = System::GetHostToNetLong(System::internetAddrAny);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkSockInetAddress)

const Network::WinSockInetAddressType& Network::NetworkSockInetAddress::GetWinSockInetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return inetAddress;
}

Network::WinSockInetAddressType& Network::NetworkSockInetAddress::GetWinSockInetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return ParentType::GetWinSockInetAddress();
}

Network::NetworkSockInetAddress::SockAddressSharedPtr Network::NetworkSockInetAddress::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}

string Network::NetworkSockInetAddress::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return addressName + ":"s + to_string(GetPort());
}

int Network::NetworkSockInetAddress::GetPort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return System::GetNetToHostShort(boost::numeric_cast<uint16_t>(inetAddress.sin_port));
}
