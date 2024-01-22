/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:29)

#include "Network/NetworkExport.h"

#include "NullSockAddress.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::NullSockAddress::NullSockAddress(int ip)
    : ClassType{ "0.0.0.0", ip }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NullSockAddress::NullSockAddress(const std::string& address, int ip)
    : ParentType{}, address{ address.empty() ? "0.0.0.0" : address }, ip{ ip }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockAddress)

std::string Network::NullSockAddress::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return address + ":" + std::to_string(GetPort());
}

Network::SockAddressImpl::SockAddressSharedPtr Network::NullSockAddress::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

int Network::NullSockAddress::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ip;
}
