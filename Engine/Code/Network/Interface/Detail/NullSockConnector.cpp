//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 11:41)

#include "Network/NetworkExport.h"

#include "NullSockConnector.h"
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

Network::NullSockConnector::NullSockConnector() noexcept
    : ParentType{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockConnector)

bool Network::NullSockConnector::Connect([[maybe_unused]] const SockStreamSharedPtr& sockStream, [[maybe_unused]] const SockAddressSharedPtr& sockAddress) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return true;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
void Network::NullSockConnector::AsyncConnect(const EventInterfaceSharedPtr& eventInterface, [[maybe_unused]] const SockStreamSharedPtr& sockStream, [[maybe_unused]] const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::CallbackParameters callbackParameters;
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncConnect));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Null));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), 0);

    if (!eventInterface->EventFunction(callbackParameters))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
            << SYSTEM_TEXT("执行事件回调失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}
#include STSTEM_WARNING_POP

const Network::NullSockConnector::SockConnectorPtr Network::NullSockConnector::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}
