///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 13:50)

#include "Network/NetworkExport.h"

#include "ACESockAcceptor.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/ACEWrappers/Detail/Address/ACESockInternetAddress.h"
#include "Network/ACEWrappers/Using/ACEUsing.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

#ifdef NETWORK_USE_ACE

Network::ACESockAcceptor::ACESockAcceptor(int port)
    : ParentType{}, aceSockAcceptor{}
{
    if (ACEInternetAddress internetAddress{};
        internetAddress.set(boost::numeric_cast<uint16_t>(port)) != 0 || aceSockAcceptor.open(internetAddress) != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("设置地址失败！"s))
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACESockAcceptor::ACESockAcceptor(const std::string& hostName, int port)
    : ParentType{}, aceSockAcceptor{}
{
    if (ACEInternetAddress internetAddress{};
        internetAddress.set(boost::numeric_cast<uint16_t>(port), hostName.c_str()) != 0 || aceSockAcceptor.open(internetAddress) != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("设置地址失败！"s))
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACESockAcceptor::~ACESockAcceptor() noexcept
{
    EXCEPTION_TRY
    {
        aceSockAcceptor.close();
    }
    EXCEPTION_ALL_CATCH(Network)

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ACESockAcceptor)

bool Network::ACESockAcceptor::Accept(SockStream& sockStream, SockAddress& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    if (aceSockAcceptor.accept(sockStream.GetACESockStream(), &sockAddress.GetACEInternetAddress()) == 0)
        return true;
    else
        return false;
}

bool Network::ACESockAcceptor::Accept(SockStream& sockStream)
{
    NETWORK_CLASS_IS_VALID_9;

    if (aceSockAcceptor.accept(sockStream.GetACESockStream()) == 0)
        return true;
    else
        return false;
}

Network::ACEHandleType Network::ACESockAcceptor::GetACEHandle()
{
    NETWORK_CLASS_IS_VALID_9;

    return aceSockAcceptor.get_handle();
}

bool Network::ACESockAcceptor::EnableNonBlock()
{
    NETWORK_CLASS_IS_VALID_9;

    if (aceSockAcceptor.enable(gNonBlock) == 0)
        return true;
    else
        return false;
}

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26415)
    #include SYSTEM_WARNING_DISABLE(26418)

void Network::ACESockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
    NETWORK_CLASS_IS_VALID_9;

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

void Network::ACESockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

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

    #include STSTEM_WARNING_POP

std::string Network::ACESockAcceptor::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (ACESockInternetAddress address{};
        aceSockAcceptor.get_local_addr(address.GetACEInternetAddress()) == 0)
    {
        return address.GetAddress();
    }
    else
    {
        return std::string{};
    }
}

int Network::ACESockAcceptor::GetPort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (ACESockInternetAddress address{};
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