/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:09)

#include "Network/NetworkExport.h"

#include "NetworkSockInternetAddress.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

Network::NetworkSockInternetAddress::NetworkSockInternetAddress(const std::string& hostName, int port)
    : internetAddress{}, addressName{ hostName }
{
    internetAddress.sin_family = boost::numeric_cast<uint16_t>(System::EnumCastUnderlying(System::AddressFamilies::Internet));
    internetAddress.sin_port = System::GetHostToNetShort(boost::numeric_cast<uint16_t>(port));

#ifdef TCRE_USE_GCC

    if (inet_pton(AF_INET, addressName.c_str(), &internetAddress.sin_addr) <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Invalid address / Address not supported \n"))
    }

#else  // !TCRE_USE_GCC

    internetAddress.sin_addr.s_addr = System::GetInternetAddress(hostName.c_str());

#endif  // TCRE_USE_GCC

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockInternetAddress::NetworkSockInternetAddress(CoreTools::DisableNotThrow disableNotThrow)
    : internetAddress{}, addressName{ "0.0.0.0" }
{
    System::UnusedFunction(disableNotThrow);

    internetAddress.sin_family = boost::numeric_cast<uint16_t>(System::EnumCastUnderlying(System::AddressFamilies::Internet));
    internetAddress.sin_port = System::GetHostToNetShort(0);

#ifdef TCRE_USE_GCC

    if (inet_pton(AF_INET, addressName.c_str(), &internetAddress.sin_addr) <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Invalid address / Address not supported \n"))
    }

#else  // !TCRE_USE_GCC

    internetAddress.sin_addr.s_addr = System::GetHostToNetLong(System::internetAddressAny);

#endif  // TCRE_USE_GCC

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockInternetAddress::NetworkSockInternetAddress(int port)
    : internetAddress{}, addressName{ "0.0.0.0" }
{
    internetAddress.sin_family = boost::numeric_cast<int16_t>(System::EnumCastUnderlying(System::AddressFamilies::Internet));
    internetAddress.sin_port = System::GetHostToNetShort(boost::numeric_cast<uint16_t>(port));

#ifdef TCRE_USE_GCC

    if (inet_pton(AF_INET, addressName.c_str(), &internetAddress.sin_addr) <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Invalid address / Address not supported \n"))
    }

#else  // !TCRE_USE_GCC

    internetAddress.sin_addr.s_addr = System::GetHostToNetLong(System::internetAddressAny);

#endif  // TCRE_USE_GCC

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkSockInternetAddress)

const Network::WinSockInternetAddressType& Network::NetworkSockInternetAddress::GetWinSockInternetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return internetAddress;
}

Network::WinSockInternetAddressType& Network::NetworkSockInternetAddress::GetWinSockInternetAddress()
{
    NETWORK_CLASS_IS_VALID_9;

    return ParentType::GetWinSockInternetAddress();
}

Network::NetworkSockInternetAddress::SockAddressSharedPtr Network::NetworkSockInternetAddress::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

std::string Network::NetworkSockInternetAddress::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return addressName + ":"s + std::to_string(GetPort());
}

int Network::NetworkSockInternetAddress::GetPort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return System::GetNetToHostShort(boost::numeric_cast<uint16_t>(internetAddress.sin_port));
}
