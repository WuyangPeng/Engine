///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/22 22:24)

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
    constexpr auto port = SYSTEM_TEXT("���˿ڣ�"sv);
    constexpr auto asynchronousAcceptSuccess = SYSTEM_TEXT("�첽���ܳɹ�����ַ��"sv);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
void Network::BoostSockAcceptorHelper::EventFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData)
{
    CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPoisition::Count) };
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying<int>(SocketManagerEvent::AsyncAcceptor));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying<int>(WrappersStrategy::Boost));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), errorCode.value());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Port), addressData.GetPort());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Address), addressData.GetAddress());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Async), System::EnumCastUnderlying<int>(SocketManagerEvent::AsyncAcceptor));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::BytesTransferred), 0);

    if (!eventInterface->EventFunction(callbackParameters))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("�¼��ص�ִ��ʧ�ܣ�"));
    }

    PrintAcceptSuccessLog(asynchronousAcceptSuccess.data(), addressData);
}
#include STSTEM_WARNING_POP

void Network::BoostSockAcceptorHelper::PrintAcceptLog(const String& prefix, const AddressData& addressData)
{
    LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Trace, Network, g_BoostLogName.data(), prefix, addressData.GetAddress(), port.data(), addressData.GetPort(), CoreTools::LogAppenderIOManageSign::TriggerAssert);
}

void Network::BoostSockAcceptorHelper::PrintAcceptSuccessLog(const String& prefix, const AddressData& addressData)
{
    LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Info, Network, g_BoostLogName.data(), prefix, addressData.GetAddress(), port.data(), addressData.GetPort(), CoreTools::LogAppenderIOManageSign::TriggerAssert);
}
