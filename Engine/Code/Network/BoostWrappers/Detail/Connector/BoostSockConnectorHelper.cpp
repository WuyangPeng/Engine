// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.1.0 (2019/10/21 17:25)


#include "Network/NetworkExport.h" 

#include "BoostSockConnectorHelper.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "CoreTools/MessageEvent/CallbackParameters.h" 
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/Data/AddressData.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::string;

namespace
{
	const System::String g_PortDescription{ SYSTEM_TEXT("，端口：") };
	const System::String g_AsynchronousConnectorSuccessDescription{ SYSTEM_TEXT("异步连接成功，地址：") };
}

void Network::BoostSockConnectorHelper
	::EventFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData)
{
	CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPoisition::Count) };
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncConnect));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Boost));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), errorCode.value());
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Port), addressData.GetPort());
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Address), addressData.GetAddress());
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Async), System::EnumCastUnderlying(SocketManagerEvent::AsyncConnect));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::BytesTransferred), 0);

	eventInterface->EventFunction(callbackParameters);

	PrintConnectorSuccessLog(g_AsynchronousConnectorSuccessDescription, addressData);
}

void Network::BoostSockConnectorHelper
	::PrintConnectorLog(const String& prefix, const AddressData& addressData)
{
	LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Trace, Network, g_BoostLogName)
		<< prefix << addressData.GetAddress() << g_PortDescription << addressData.GetPort()
		<< CoreTools::LogAppenderIOManageSign::Refresh;
}

void Network::BoostSockConnectorHelper
	::PrintConnectorSuccessLog(const String& prefix, const AddressData& addressData)
{
	LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Info, Network, g_BoostLogName)
		<< prefix << addressData.GetAddress() << g_PortDescription << addressData.GetPort()
		<< CoreTools::LogAppenderIOManageSign::Refresh;
}
