// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/20 19:00)


#include "Network/NetworkExport.h" 

#include "SockAddress.h"
#include "Detail/SockAddressFactory.h"
#include "Detail/SockAddressImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::string;

Network::SockAddress
	::SockAddress(const string& hostName, int port, const ConfigurationStrategy& configurationStrategy)
	:m_Impl{ SockAddressFactory::Create(hostName, port, configurationStrategy) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SockAddress
	::SockAddress(int port, const ConfigurationStrategy& configurationStrategy)
	:m_Impl{ SockAddressFactory::Create(port, configurationStrategy) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SockAddress
	::SockAddress(const ConfigurationStrategy& configurationStrategy)
	:m_Impl{ SockAddressFactory::Create(configurationStrategy) }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

COPY_CONSTRUCTION_CLONE_DEFINE(Network, SockAddress)
IMPL_MOVE_OPERATOR_COMPLETE_DEFINE(Network, SockAddress)
 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetACEInetAddress, const Network::ACEInetAddressType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetACEInetAddress, Network::ACEInetAddressType&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetBoostInetAddress, const Network::BoostInetAddressType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetBoostInetAddress, Network::BoostInetAddressType&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetWinSockInetAddress, const Network::WinSockInetAddressType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetWinSockInetAddress, Network::WinSockInetAddressType&)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetAddress, const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetPort, int)
