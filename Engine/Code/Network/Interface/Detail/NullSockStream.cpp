// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.2 (2019/07/01 17:23)

#include "Network/NetworkExport.h" 

#include "NullSockStream.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "System/Helper/UnusedMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h" 

using std::string;
using std::make_shared;
using std::to_string;

Network::NullSockStream
	::NullSockStream()
	:ParentType{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NullSockStream
	::~NullSockStream()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockStream)

int Network::NullSockStream
	::Send(const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(messageBuffer); 

	return 0;
}

int Network::NullSockStream
	::Receive(const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(messageBuffer); 

	return 0;
}

void Network::NullSockStream
	::AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(messageBuffer); 

	CoreTools::CallbackParameters callbackParameters{};
	callbackParameters.SetValue(0, System::EnumCastUnderlying(SocketManagerEvent::AsyncSend));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Null));
	eventInterface->EventFunction(callbackParameters);
}

void Network::NullSockStream
	::AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(eventInterface);
	SYSTEM_UNUSED_ARG(messageBuffer); 
}

bool Network::NullSockStream
	::CloseHandle()
{
	NETWORK_CLASS_IS_VALID_9;

	return false;
}

bool Network::NullSockStream
	::EnableNonBlock()
{
	NETWORK_CLASS_IS_VALID_9;

	return false;
}

const std::string Network::NullSockStream
	::GetRemoteAddress() const
{
	return "";
}

int Network::NullSockStream
	::GetRemotePort() const
{
	return 0;
}

