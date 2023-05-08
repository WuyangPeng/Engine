///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/23 0:11)

#include "Network/NetworkExport.h"

#include "BoostSockStreamHelper.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/Data/AddressData.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

using std::string;
using namespace std::literals;

namespace
{
    constexpr auto port = SYSTEM_TEXT("，端口："sv);

    constexpr auto g_BytesTransferred = SYSTEM_TEXT("，字节数："sv);

    constexpr auto asynchronousSendSuccess = SYSTEM_TEXT("异步发送消息成功，地址："sv);

    constexpr auto asynchronousReceiveSuccess = SYSTEM_TEXT("异步接收消息成功，地址："sv);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::BoostSockStreamHelper::EventSendFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData, int bytesTransferred)
{
    CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPosition::Count) };
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncSend));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Boost));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Error), errorCode.value());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Async), System::EnumCastUnderlying<int>(SocketManagerEvent::AsyncSend));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Port), addressData.GetPort());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Address), addressData.GetAddress());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::BytesTransferred), bytesTransferred);

    if (!eventInterface->EventFunction(callbackParameters))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("事件回调执行失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }

    PrintSuccessLog(asynchronousSendSuccess.data(), addressData, bytesTransferred);
}

#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::BoostSockStreamHelper::EventReceiveFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData, int bytesTransferred)
{
    CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPosition::Count) };
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncReceive));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Boost));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Error), errorCode.value());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Async), System::EnumCastUnderlying<int>(SocketManagerEvent::AsyncReceive));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Port), addressData.GetPort());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Address), addressData.GetAddress());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::BytesTransferred), bytesTransferred);

    if (!eventInterface->EventFunction(callbackParameters))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("事件回调执行失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }

    PrintSuccessLog(asynchronousReceiveSuccess.data(), addressData, bytesTransferred);
}

#include STSTEM_WARNING_POP

void Network::BoostSockStreamHelper::PrintSuccessLog(const String& prefix, const AddressData& addressData, int bytesTransferred)
{
    if (0 < bytesTransferred)
    {
        LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Trace, Network, g_BoostLogName.data(), prefix, addressData.GetAddress(), port.data(), addressData.GetPort(), g_BytesTransferred.data(), bytesTransferred, CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}
