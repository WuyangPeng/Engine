/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:25)

#include "Network/NetworkExport.h"

#include "BoostSockConnectorHelper.h"
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
    constexpr auto port = SYSTEM_TEXT("���˿ڣ�"sv);

    constexpr auto asynchronousConnectorSuccess = SYSTEM_TEXT("�첽���ӳɹ�����ַ��"sv);
}

void Network::BoostSockConnectorHelper::EventFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData)
{
    System::UnusedFunction(eventInterface);

    CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPosition::Count) };
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncConnect));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Boost));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Error), errorCode.value());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Port), addressData.GetPort());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Address), addressData.GetAddress());
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Async), System::EnumCastUnderlying(SocketManagerEvent::AsyncConnect));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::BytesTransferred), 0);

    if (!eventInterface->EventFunction(callbackParameters))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("�¼��ص�ִ��ʧ�ܣ�"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }

    PrintConnectorSuccessLog(asynchronousConnectorSuccess.data(), addressData);
}

void Network::BoostSockConnectorHelper::PrintConnectorLog(const String& prefix, const AddressData& addressData)
{
    LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Trace, Network, boostLogName.data(), prefix, addressData.GetAddress(), port.data(), addressData.GetPort());
}

void Network::BoostSockConnectorHelper::PrintConnectorSuccessLog(const String& prefix, const AddressData& addressData)
{
    LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Info, Network, boostLogName.data(), prefix, addressData.GetAddress(), port.data(), addressData.GetPort());
}
