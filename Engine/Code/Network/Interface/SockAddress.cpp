//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 13:12)

#include "Network/NetworkExport.h"

#include "SockAddress.h"
#include "Detail/SockAddressFactory.h"
#include "Detail/SockAddressImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

Network::SockAddress::SockAddress(const string& hostName, int port, const ConfigurationStrategy& configurationStrategy)
    : m_Impl{ SockAddressFactory::Create(hostName, port, configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SockAddress::SockAddress(int port, const ConfigurationStrategy& configurationStrategy)
    : m_Impl{ SockAddressFactory::Create(port, configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SockAddress::SockAddress(const ConfigurationStrategy& configurationStrategy)
    : m_Impl{ SockAddressFactory::Create(configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
COPY_CONSTRUCTION_CLONE_DEFINE(Network, SockAddress)
#include STSTEM_WARNING_POP

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Network, SockAddress)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetACEInetAddress, const Network::ACEInetAddressType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetACEInetAddress, Network::ACEInetAddressType&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetBoostInetAddress, const Network::BoostInetAddressType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetBoostInetAddress, Network::BoostInetAddressType&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetWinSockInetAddress, const Network::WinSockInetAddressType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetWinSockInetAddress, Network::WinSockInetAddressType&)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetAddress, const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetPort, int)
