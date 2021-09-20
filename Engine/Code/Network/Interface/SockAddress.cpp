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
    : impl{ SockAddressFactory::Create(hostName, port, configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SockAddress::SockAddress(int port, const ConfigurationStrategy& configurationStrategy)
    : impl{ SockAddressFactory::Create(port, configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::SockAddress::SockAddress(const ConfigurationStrategy& configurationStrategy)
    : impl{ SockAddressFactory::Create(configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
Network::SockAddress::SockAddress(const SockAddress& rhs)
    : impl{ rhs.impl->Clone() }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}
Network::SockAddress& Network::SockAddress::operator=(const SockAddress& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
    impl = rhs.impl->Clone();
    return *this;
}
void Network::SockAddress::Swap(SockAddress& rhs) noexcept
{
    ;
    std::swap(impl, rhs.impl);
}
Network::SockAddress::SockAddress(SockAddress&& rhs) noexcept
    : impl{ std::move(rhs.impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}
Network::SockAddress& Network::SockAddress::operator=(SockAddress&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
    impl = std::move(rhs.impl);
    return *this;
}
#include STSTEM_WARNING_POP

CLASS_INVARIANT_STUB_DEFINE(Network, SockAddress)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetACEInetAddress, const Network::ACEInetAddressType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetACEInetAddress, Network::ACEInetAddressType&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetBoostInetAddress, const Network::BoostInetAddressType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetBoostInetAddress, Network::BoostInetAddressType&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetWinSockInetAddress, const Network::WinSockInetAddressType&)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetWinSockInetAddress, Network::WinSockInetAddressType&)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetAddress, const string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Network, SockAddress, GetPort, int)
