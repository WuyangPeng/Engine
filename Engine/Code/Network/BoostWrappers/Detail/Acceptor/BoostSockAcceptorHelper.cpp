//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 17:10)

#include "Network/NetworkExport.h"

#include "BoostSockAcceptorHelper.h"
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

    const auto GetAsynchronousAcceptSuccessDescription()
    {
        static const auto asynchronousAcceptSuccess = SYSTEM_TEXT("异步接受成功，地址："s);

        return asynchronousAcceptSuccess;
    }
}

void Network::BoostSockAcceptorHelper::EventFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData)
{
    auto process = eventInterface;

    CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPoisition::Count) };
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying<int>(SocketManagerEvent::AsyncAcceptor));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying<int>(WrappersStrategy::Boost));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), errorCode.value());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Port), addressData.GetPort());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Address), addressData.GetAddress());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Async), System::EnumCastUnderlying<int>(SocketManagerEvent::AsyncAcceptor));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::BytesTransferred), 0);

    if (!process->EventFunction(callbackParameters))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
            << SYSTEM_TEXT("事件回调执行失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }

    PrintAcceptSuccessLog(GetAsynchronousAcceptSuccessDescription(), addressData);
}

void Network::BoostSockAcceptorHelper::PrintAcceptLog(const String& prefix, const AddressData& addressData)
{
    LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Trace, Network, GetBoostLogName().c_str())
        << prefix << addressData.GetAddress() << GetPortDescription() << addressData.GetPort()
        << CoreTools::LogAppenderIOManageSign::Refresh;
}

void Network::BoostSockAcceptorHelper::PrintAcceptSuccessLog(const String& prefix, const AddressData& addressData)
{
    LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Info, Network, GetBoostLogName().c_str())
        << prefix << addressData.GetAddress() << GetPortDescription() << addressData.GetPort()
        << CoreTools::LogAppenderIOManageSign::Refresh;
}
