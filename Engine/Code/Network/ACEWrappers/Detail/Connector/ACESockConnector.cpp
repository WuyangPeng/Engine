///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/22 18:23)

#include "Network/NetworkExport.h"

#ifdef NETWORK_USE_ACE

    #include "ACESockConnector.h"
    #include "System/Helper/EnumCast.h"
    #include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
    #include "CoreTools/Helper/ExceptionMacro.h"
    #include "CoreTools/MessageEvent/CallbackParameters.h"
    #include "CoreTools/MessageEvent/EventInterface.h"
    #include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
    #include "Network/Interface/SockAddress.h"
    #include "Network/Interface/SockStream.h"
    #include "Network/NetworkMessage/Flags/MessageEventFlags.h"

using std::make_shared;

Network::ACESockConnector::ACESockConnector() noexcept
    : aceSockConnector{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ACESockConnector)

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26415)
    #include SYSTEM_WARNING_DISABLE(26418)
bool Network::ACESockConnector::Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (aceSockConnector.connect(sockStream->GetACESockStream(), sockAddress->GetACEInetAddress()) == 0)
        return true;
    else
        return false;
}
    #include STSTEM_WARNING_POP

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26415)
    #include SYSTEM_WARNING_DISABLE(26418)
void Network::ACESockConnector::AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    CoreTools::CallbackParameters callbackParameters{ 0 };
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncConnect));

    const auto result = aceSockConnector.connect(sockStream->GetACESockStream(), sockAddress->GetACEInetAddress());

    if (result == 0)
    {
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), result);

        if (!eventInterface->EventFunction(callbackParameters))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                << SYSTEM_TEXT("事件回调执行失败！")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
    }
}
    #include STSTEM_WARNING_POP

Network::ACESockConnector::SockConnectorSharedPtr Network::ACESockConnector::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}

#endif  // NETWORK_USE_ACE