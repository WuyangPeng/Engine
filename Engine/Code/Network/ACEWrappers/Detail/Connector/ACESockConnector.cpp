// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.4 (2020/03/11 13:47)

#include "Network/NetworkExport.h" 

#ifdef NETWORK_USE_ACE

#include "ACESockConnector.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "Network/Interface/SockStream.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::make_shared;

Network::ACESockConnector
	::ACESockConnector()
	:m_ACESockConnector{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACESockConnector
	::~ACESockConnector()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ACESockConnector)

bool Network::ACESockConnector
	::Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	if (m_ACESockConnector.connect(sockStream->GetACESockStream(), sockAddress->GetACEInetAddress()) == 0)
		return true;
	else
		return false;
}

void Network::ACESockConnector
	::AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	CoreTools::CallbackParameters callbackParameters{};
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncConnect));

	auto result = m_ACESockConnector.connect(sockStream->GetACESockStream(), sockAddress->GetACEInetAddress());

	if (result == 0)
	{
		callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
		callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), result);

		eventInterface->EventFunction(callbackParameters);
	}
}

const Network::ACESockConnector::SockConnectorPtr Network::ACESockConnector
	::Clone() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return make_shared<ClassType>(*this);
}

#endif // NETWORK_USE_ACE