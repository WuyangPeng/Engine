// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/11 16:00)

#include "Network/NetworkExport.h" 

#include "BoostSockStreamHelper.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "CoreTools/MessageEvent/CallbackParameters.h" 
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/Data/AddressData.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::string;
using namespace std::literals;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26426)
namespace
{
	const auto g_PortDescription = SYSTEM_TEXT("，端口："s);
	const auto g_BytesTransferredDescription = SYSTEM_TEXT("，字节数："s);
	const auto g_AsynchronousSendSuccessDescription = SYSTEM_TEXT("异步发送消息成功，地址："s);
	const auto g_AsynchronousReceiveSuccessDescription = SYSTEM_TEXT("异步接收消息成功，地址："s);
}

void Network::BoostSockStreamHelper
	::EventSendFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData, int bytesTransferred)
{
	CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPoisition::Count) };
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncSend));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Boost));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), errorCode.value());
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Async), System::EnumCastUnderlying<int>(SocketManagerEvent::AsyncSend));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Port), addressData.GetPort());
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Address), addressData.GetAddress());
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::BytesTransferred), bytesTransferred);
	eventInterface->EventFunction(callbackParameters);

	PrintSuccessLog(g_AsynchronousSendSuccessDescription, addressData, bytesTransferred);
}

void Network::BoostSockStreamHelper
	::EventReceiveFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData, int bytesTransferred)
{
	CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPoisition::Count) };
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncReceive));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Boost));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), errorCode.value());
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Async), System::EnumCastUnderlying<int>(SocketManagerEvent::AsyncReceive));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Port), addressData.GetPort());
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Address), addressData.GetAddress());
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::BytesTransferred), bytesTransferred);
	eventInterface->EventFunction(callbackParameters);

	PrintSuccessLog(g_AsynchronousReceiveSuccessDescription, addressData, bytesTransferred);
}

void Network::BoostSockStreamHelper
	::PrintSuccessLog(const String& prefix, const AddressData& addressData, int bytesTransferred)
{
	if (0 < bytesTransferred)
	{
		LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Trace, Network, g_BoostLogName.c_str())
			<< prefix << addressData.GetAddress() << g_PortDescription << addressData.GetPort() << g_BytesTransferredDescription << bytesTransferred
			<< CoreTools::LogAppenderIOManageSign::Refresh;
	}
}
#include STSTEM_WARNING_POP