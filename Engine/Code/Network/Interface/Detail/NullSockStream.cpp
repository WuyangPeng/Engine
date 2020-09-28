// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.2.4 (2020/03/11 11:22)

#include "Network/NetworkExport.h"

#include "NullSockStream.h"
#include "System/Helper/EnumCast.h"

#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

using std::make_shared;
using std::string;
using std::to_string;

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

Network::NullSockStream ::NullSockStream() noexcept
    : ParentType{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockStream)

int Network::NullSockStream ::Send([[maybe_unused]] const MessageBufferSharedPtr& messageBuffer) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

 

    return 0;
}

int Network::NullSockStream ::Receive([[maybe_unused]] const MessageBufferSharedPtr& messageBuffer) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

 

    return 0;
}

void Network::NullSockStream ::AsyncSend(const EventInterfaceSharedPtr& eventInterface, [[maybe_unused]] const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

 

    CoreTools::CallbackParameters callbackParameters{};
    callbackParameters.SetValue(0, System::EnumCastUnderlying(SocketManagerEvent::AsyncSend));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Null));
    eventInterface->EventFunction(callbackParameters);
}

void Network::NullSockStream ::AsyncReceive([[maybe_unused]] const EventInterfaceSharedPtr& eventInterface, [[maybe_unused]] const MessageBufferSharedPtr& messageBuffer) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    
}

bool Network::NullSockStream ::CloseHandle() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return false;
}

bool Network::NullSockStream ::EnableNonBlock() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return false;
}

const std::string Network::NullSockStream ::GetRemoteAddress() const
{
    return "";
}

int Network::NullSockStream ::GetRemotePort() const noexcept
{
    return 0;
}
#include STSTEM_WARNING_POP