// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 11:22)

#include "Network/NetworkExport.h" 

#include "NullSockAddress.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::string;
using std::make_shared;
using std::to_string;

Network::NullSockAddress
	::NullSockAddress(const string& address, int ip)
	:ParentType{}, m_Address{ address }, m_IP{ ip }
{
	if (m_Address.empty())
	{
		m_Address = "0.0.0.0";
	}
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NullSockAddress
	::~NullSockAddress()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockAddress)

const string Network::NullSockAddress
	::GetAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Address + ":" + to_string(GetPort());
}

const Network::SockAddressImpl::SockAddressPtr Network::NullSockAddress
	::Clone() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return make_shared<ClassType>(*this);
}

int Network::NullSockAddress
	::GetPort() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_IP;
}

