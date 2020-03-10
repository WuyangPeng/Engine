// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 17:22)

#include "Network/NetworkExport.h" 

#include "NullSockAcceptor.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

using std::string;
using std::make_shared;
using std::to_string;

Network::NullSockAcceptor
	::NullSockAcceptor()
	:ParentType{}
{	
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NullSockAcceptor
	::~NullSockAcceptor()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockAcceptor) 

bool Network::NullSockAcceptor
	::Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(sockStream);
	SYSTEM_UNUSED_ARG(sockAddress);

	return false;
}

void Network::NullSockAcceptor
	::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(eventInterface);
	SYSTEM_UNUSED_ARG(sockStream);
}

bool Network::NullSockAcceptor
	::EnableNonBlock()
{
	NETWORK_CLASS_IS_VALID_9;

	return false;
}

void Network::NullSockAcceptor
	::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(eventInterface);
	SYSTEM_UNUSED_ARG(sockStream);
	SYSTEM_UNUSED_ARG(sockAddress);	
}

bool Network::NullSockAcceptor
	::Accept(const SockStreamSharedPtr& sockStream)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(sockStream);

	return false;
}

const std::string Network::NullSockAcceptor
	::GetAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9; 

	return "";
}

int Network::NullSockAcceptor
	::GetPort() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return 0;
}
