//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 17:57)

#include "Network/NetworkExport.h"

#include "BoostSockConnectorHelper.h"
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
    const auto GetPortDescription()
    {
        static const auto port = SYSTEM_TEXT("，端口："s);

        return port;
    }

    const auto GetAsynchronousConnectorSuccessDescription()
    {
        static const auto asynchronousConnectorSuccess = SYSTEM_TEXT("异步连接成功，地址："s);

        return asynchronousConnectorSuccess;
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
void Network::BoostSockConnectorHelper::EventFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData)
{
    CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPoisition::Count) };
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncConnect));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Boost));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), errorCode.value());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Port), addressData.GetPort());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Address), addressData.GetAddress());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Async), System::EnumCastUnderlying(SocketManagerEvent::AsyncConnect));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::BytesTransferred), 0);

    if (!eventInterface->EventFunction(callbackParameters))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
            << SYSTEM_TEXT("事件回调执行失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }

    PrintConnectorSuccessLog(GetAsynchronousConnectorSuccessDescription(), addressData);
}
#include STSTEM_WARNING_POP

void Network::BoostSockConnectorHelper::PrintConnectorLog(const String& prefix, const AddressData& addressData)
{
    LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Trace, Network, GetBoostLogName().c_str())
        << prefix << addressData.GetAddress() << GetPortDescription() << addressData.GetPort()
        << CoreTools::LogAppenderIOManageSign::Refresh;
}

void Network::BoostSockConnectorHelper::PrintConnectorSuccessLog(const String& prefix, const AddressData& addressData)
{
    LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Info, Network, GetBoostLogName().c_str())
        << prefix << addressData.GetAddress() << GetPortDescription() << addressData.GetPort()
        << CoreTools::LogAppenderIOManageSign::Refresh;
}
