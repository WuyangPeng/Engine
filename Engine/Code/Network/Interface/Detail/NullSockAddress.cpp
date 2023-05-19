///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 09:04)

#include "Network/NetworkExport.h"

#include "NullSockAddress.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

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
