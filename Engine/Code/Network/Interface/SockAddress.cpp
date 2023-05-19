///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 09:00)

#include "Network/NetworkExport.h"

#include "SockAddress.h"
#include "Detail/SockAddressFactory.h"
#include "Detail/SockAddressImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Network, SockAddress)

Network::SockAddress::SockAddress(const std::string& hostName, int port, const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, hostName, port, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SockAddress::SockAddress(int port, const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, port, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SockAddress::SockAddress(const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockAddress)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetACEInternetAddress, const Network::ACEInternetAddressType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetACEInternetAddress, Network::ACEInternetAddressType&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetBoostInternetAddress, const Network::BoostInternetAddressType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetBoostInternetAddress, Network::BoostInternetAddressType&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetWinSockInternetAddress, const Network::WinSockInternetAddressType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetWinSockInternetAddress, Network::WinSockInternetAddressType&)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetAddress, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetPort, int)
