// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/11 15:57)

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
using namespace std::literals;

namespace
{
	const auto g_PortDescription = SYSTEM_TEXT("���˿ڣ�"s);
	const auto g_AsynchronousConnectorSuccessDescription = SYSTEM_TEXT("�첽���ӳɹ�����ַ��"s);
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
	LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Trace, Network, g_BoostLogName.c_str())
		<< prefix << addressData.GetAddress() << g_PortDescription << addressData.GetPort()
		<< CoreTools::LogAppenderIOManageSign::Refresh;
}

void Network::BoostSockConnectorHelper
	::PrintConnectorSuccessLog(const String& prefix, const AddressData& addressData)
{
	LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Info, Network, g_BoostLogName.c_str())
		<< prefix << addressData.GetAddress() << g_PortDescription << addressData.GetPort()
		<< CoreTools::LogAppenderIOManageSign::Refresh;
}
