///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 14:18)

#include "Network/NetworkExport.h"

#include "BoostSockAcceptorHelper.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/Data/AddressData.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

using namespace std::literals;

namespace
{
    constexpr auto port = SYSTEM_TEXT("，端口："sv);
    constexpr auto asynchronousAcceptSuccess = SYSTEM_TEXT("异步接受成功，地址："sv);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::BoostSockAcceptorHelper::EventFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData)
{
    CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPosition::Count) };
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncAcceptor));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Boost));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Error), errorCode.value());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Port), addressData.GetPort());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Address), addressData.GetAddress());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Async), System::EnumCastUnderlying(SocketManagerEvent::AsyncAcceptor));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::BytesTransferred), 0);

    if (!eventInterface->EventFunction(callbackParameters))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("事件回调执行失败！"));
    }

    PrintAcceptSuccessLog(asynchronousAcceptSuccess.data(), addressData);
}

#include STSTEM_WARNING_POP

void Network::BoostSockAcceptorHelper::PrintAcceptLog(const String& prefix, const AddressData& addressData)
{
    LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Trace, Network, boostLogName.data(), prefix, addressData.GetAddress(), port.data(), addressData.GetPort());
}

void Network::BoostSockAcceptorHelper::PrintAcceptSuccessLog(const String& prefix, const AddressData& addressData)
{
    LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Info, Network, boostLogName.data(), prefix, addressData.GetAddress(), port.data(), addressData.GetPort());
}
