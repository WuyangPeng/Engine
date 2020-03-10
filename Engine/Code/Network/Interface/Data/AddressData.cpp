// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.1.0 (2019/11/29 10:20)


#include "Network/NetworkExport.h" 

#include "AddressData.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/SockStream.h"
#include "Network/Interface/SockAddress.h"
#include "Network/BoostWrappers/Detail/Stream/BoostSockStream.h"
#include "Network/BoostWrappers/Detail/Acceptor/BoostSockAcceptor.h"

using std::string;

Network::AddressData
	::AddressData(const string& address, int port)
	:m_Address{ address }, m_Port{ port }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AddressData
	::AddressData(const SockStreamSharedPtr& sockStream)
	:m_Address{ sockStream->GetRemoteAddress() }, m_Port{ sockStream->GetRemotePort() }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AddressData
	::AddressData(const BoostSockAcceptor& boostSockAcceptor)
	:m_Address{ boostSockAcceptor.GetAddress() }, m_Port{ boostSockAcceptor.GetPort() }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AddressData
	::AddressData(const BoostSockStream& boostSockStream)
	:m_Address{ boostSockStream.GetRemoteAddress() }, m_Port{ boostSockStream.GetRemotePort() }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AddressData
	::AddressData(const SockAddressSharedPtr& sockAddress)
	:m_Address{ sockAddress->GetAddress() }, m_Port{ sockAddress->GetPort() }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, AddressData)

std::string Network::AddressData
	::GetAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Address;
}

int Network::AddressData
	::GetPort() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Port;
}

