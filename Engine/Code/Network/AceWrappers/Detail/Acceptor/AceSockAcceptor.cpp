/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:30)

#include "Network/NetworkExport.h"

#include "AceSockAcceptor.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/ACEWrappers/Detail/Address/AceSockInternetAddress.h"
#include "Network/AceWrappers/Using/AceUsing.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

#ifdef NETWORK_USE_ACE

Network::AceSockAcceptor::AceSockAcceptor(int port)
    : ParentType{}, aceSockAcceptor{}
{
    if (ACEInternetAddress internetAddress{};
        internetAddress.set(boost::numeric_cast<uint16_t>(port)) != 0 || aceSockAcceptor.open(internetAddress) != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("设置地址失败！"s))
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AceSockAcceptor::AceSockAcceptor(const std::string& hostName, int port)
    : ParentType{}, aceSockAcceptor{}
{
    if (ACEInternetAddress internetAddress{};
        internetAddress.set(boost::numeric_cast<uint16_t>(port), hostName.c_str()) != 0 || aceSockAcceptor.open(internetAddress) != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("设置地址失败！"s))
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AceSockAcceptor::~AceSockAcceptor() noexcept
{
    EXCEPTION_TRY
    {
        aceSockAcceptor.close();
    }
    EXCEPTION_ALL_CATCH(Network)

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, AceSockAcceptor)

bool Network::AceSockAcceptor::Accept(SockStream& sockStream, SockAddress& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    if (aceSockAcceptor.accept(sockStream.GetACESockStream(), &sockAddress.GetACEInternetAddress()) == 0)
        return true;
    else
        return false;
}

bool Network::AceSockAcceptor::Accept(SockStream& sockStream)
{
    NETWORK_CLASS_IS_VALID_9;

    if (aceSockAcceptor.accept(sockStream.GetACESockStream()) == 0)
        return true;
    else
        return false;
}

Network::ACEHandleType Network::AceSockAcceptor::GetACEHandle()
{
    NETWORK_CLASS_IS_VALID_9;

    return aceSockAcceptor.get_handle();
}

bool Network::AceSockAcceptor::EnableNonBlock()
{
    NETWORK_CLASS_IS_VALID_9;

    if (aceSockAcceptor.enable(gNonBlock) == 0)
        return true;
    else
        return false;
}

void Network::AceSockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventInterface, sockStream);

    if (const auto result = aceSockAcceptor.accept(sockStream->GetACESockStream());
        result == 0)
    {
        CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPosition::Error) };
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncAcceptor));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Ace));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Error), result);

        if (!eventInterface->EventFunction(callbackParameters))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("事件回调执行失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
}

void Network::AceSockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventInterface, sockStream, sockAddress);

    if (const auto result = aceSockAcceptor.accept(sockStream->GetACESockStream(), &sockAddress->GetACEInternetAddress());
        result == 0)
    {
        CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPosition::Error) };
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncAcceptor));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Ace));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Error), result);

        if (!eventInterface->EventFunction(callbackParameters))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("事件回调执行失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
}

std::string Network::AceSockAcceptor::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (AceSockInternetAddress address{};
        aceSockAcceptor.get_local_addr(address.GetACEInternetAddress()) == 0)
    {
        return address.GetAddress();
    }
    else
    {
        return std::string{};
    }
}

int Network::AceSockAcceptor::GetPort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (AceSockInternetAddress address{};
        aceSockAcceptor.get_local_addr(address.GetACEInternetAddress()) == 0)
    {
        return address.GetPort();
    }
    else
    {
        return 0;
    }
}

#endif  // NETWORK_USE_ACE