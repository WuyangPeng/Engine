//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 11:41)

#include "Network/NetworkExport.h"

#include "NullSockAddress.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;
using std::to_string;

Network::NullSockAddress::NullSockAddress(const string& address, int ip)
    : ParentType{}, m_Address{ address }, m_IP{ ip }
{
    if (m_Address.empty())
    {
        m_Address = "0.0.0.0";
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockAddress)

const string Network::NullSockAddress::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Address + ":" + to_string(GetPort());
}

const Network::SockAddressImpl::SockAddressPtr Network::NullSockAddress::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}

int Network::NullSockAddress::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_IP;
}
