// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.4 (2020/03/11 11:22)

#include "Network/NetworkExport.h" 

#include "NullSockConnector.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"  
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::string;
using std::make_shared;
using std::to_string;

Network::NullSockConnector
	::NullSockConnector()
	:ParentType{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NullSockConnector
	::~NullSockConnector()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockConnector)

bool Network::NullSockConnector
	::Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(sockStream);
	SYSTEM_UNUSED_ARG(sockAddress);

	return true;
}

void Network::NullSockConnector
	::AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(sockStream);
	SYSTEM_UNUSED_ARG(sockAddress);

	CoreTools::CallbackParameters callbackParameters;
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncConnect));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Null));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), 0);

	eventInterface->EventFunction(callbackParameters);
}

const Network::NullSockConnector::SockConnectorPtr Network::NullSockConnector
	::Clone() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return make_shared<ClassType>(*this);
}