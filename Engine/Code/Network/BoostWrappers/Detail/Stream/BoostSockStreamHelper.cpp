/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:23)

#include "Network/NetworkExport.h"

#include "BoostSockStreamHelper.h"
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

    constexpr auto gBytesTransferred = SYSTEM_TEXT("���ֽ�����"sv);

    constexpr auto asynchronousSendSuccess = SYSTEM_TEXT("�첽������Ϣ�ɹ�����ַ��"sv);

    constexpr auto asynchronousReceiveSuccess = SYSTEM_TEXT("�첽������Ϣ�ɹ�����ַ��"sv);
}

void Network::BoostSockStreamHelper::EventSendFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData, int bytesTransferred)
{
    System::UnusedFunction(eventInterface);

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
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("�¼��ص�ִ��ʧ�ܣ�"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }

    PrintSuccessLog(asynchronousSendSuccess.data(), addressData, bytesTransferred);
}

void Network::BoostSockStreamHelper::EventReceiveFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData, int bytesTransferred)
{
    System::UnusedFunction(eventInterface);

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
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("�¼��ص�ִ��ʧ�ܣ�"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }

    PrintSuccessLog(asynchronousReceiveSuccess.data(), addressData, bytesTransferred);
}

void Network::BoostSockStreamHelper::PrintSuccessLog(const String& prefix, const AddressData& addressData, int bytesTransferred)
{
    if (0 < bytesTransferred)
    {
        LOG_SINGLETON_FILE_AND_CONSOLE_APPENDER(Trace, Network, boostLogName.data(), prefix, addressData.GetAddress(), port.data(), addressData.GetPort(), gBytesTransferred.data(), bytesTransferred);
    }
}
