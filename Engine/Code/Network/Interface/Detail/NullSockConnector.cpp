///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 09:26)

#include "Network/NetworkExport.h"

#include "NullSockConnector.h"
#include "System/Helper/EnumCast.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Detail/BufferSendStreamImpl.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

Network::NullSockConnector::NullSockConnector() noexcept
    : ParentType{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockConnector)

bool Network::NullSockConnector::Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(sockStream, sockAddress);

    return true;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::NullSockConnector::AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(sockStream, sockAddress);

    CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPosition::Error) };
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncConnect));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Null));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Error), EnumCastUnderlying(System::WindowError::Success));

    if (!eventInterface->EventFunction(callbackParameters))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("执行事件回调失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

#include STSTEM_WARNING_POP

Network::NullSockConnector::SockConnectorSharedPtr Network::NullSockConnector::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}
