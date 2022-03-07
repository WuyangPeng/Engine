///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 23:40)

#include "Network/NetworkExport.h"

#include "NullSockAddress.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;
using std::to_string;

Network::NullSockAddress::NullSockAddress(const string& address, int ip)
    : ParentType{}, address{ address.empty() ? "0.0.0.0" : address }, ip{ ip }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockAddress)

string Network::NullSockAddress::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return address + ":" + to_string(GetPort());
}

Network::SockAddressImpl::SockAddressSharedPtr Network::NullSockAddress::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}

int Network::NullSockAddress::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ip;
}
