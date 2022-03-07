///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/21 17:03)

#include "Network/NetworkExport.h"

#include "SockAddress.h"
#include "Detail/SockAddressFactory.h"
#include "Detail/SockAddressImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Network, SockAddress)

Network::SockAddress::SockAddress(const string& hostName, int port, const ConfigurationStrategy& configurationStrategy)
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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetACEInetAddress, const Network::ACEInetAddressType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetACEInetAddress, Network::ACEInetAddressType&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetBoostInetAddress, const Network::BoostInetAddressType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetBoostInetAddress, Network::BoostInetAddressType&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetWinSockInetAddress, const Network::WinSockInetAddressType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetWinSockInetAddress, Network::WinSockInetAddressType&)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetAddress, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetPort, int)
