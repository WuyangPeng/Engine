// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/11 11:22)

#include "Network/NetworkExport.h" 

#include "NullSockConnector.h"

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

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

Network::NullSockConnector
	::NullSockConnector() noexcept
	:ParentType{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockConnector)

bool Network::NullSockConnector ::Connect([[maybe_unused]] const SockStreamSharedPtr& sockStream, [[maybe_unused]] const SockAddressSharedPtr& sockAddress) noexcept
{
	NETWORK_CLASS_IS_VALID_9;
 

	return true;
}

void Network::NullSockConnector ::AsyncConnect(const EventInterfaceSharedPtr& eventInterface, [[maybe_unused]] const SockStreamSharedPtr& sockStream, [[maybe_unused]] const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_9;

 

	CoreTools::CallbackParameters callbackParameters;
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncConnect));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Null));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), 0);

	 if (!eventInterface->EventFunction(callbackParameters))
        {
        }
}

const Network::NullSockConnector::SockConnectorPtr Network::NullSockConnector
	::Clone() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return make_shared<ClassType>(*this);
}
#include STSTEM_WARNING_POP