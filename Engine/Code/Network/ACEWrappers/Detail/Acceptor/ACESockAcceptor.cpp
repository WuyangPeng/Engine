///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/22 13:51)

#include "Network/NetworkExport.h"

#ifdef NETWORK_USE_ACE

    #include "ACESockAcceptor.h"
    #include "System/Helper/EnumCast.h"
    #include "System/Helper/PragmaWarning.h"
    #include "System/Helper/PragmaWarning/NumericCast.h"
    #include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
    #include "CoreTools/Helper/ExceptionMacro.h"
    #include "CoreTools/MessageEvent/CallbackParameters.h"
    #include "CoreTools/MessageEvent/EventInterface.h"
    #include "Network/ACEWrappers/Detail/Address/ACESockInetAddress.h"
    #include "Network/ACEWrappers/Using/ACEUsing.h"
    #include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
    #include "Network/Interface/SockAddress.h"
    #include "Network/Interface/SockStream.h"
    #include "Network/NetworkMessage/Flags/MessageEventFlags.h"

using std::string;

Network::ACESockAcceptor::ACESockAcceptor(int port)
    : ParentType{}, aceSockAcceptor{}
{
    ACEInetAddress inetAddress{};

    if (inetAddress.set(boost::numeric_cast<uint16_t>(port)) != 0 || aceSockAcceptor.open(inetAddress) != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("设置地址失败！"s));
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACESockAcceptor::ACESockAcceptor(const string& hostName, int port)
    : ParentType{}, aceSockAcceptor{}
{
    ACEInetAddress inetAddress{};

    if (inetAddress.set(boost::numeric_cast<uint16_t>(port), hostName.c_str()) != 0 || aceSockAcceptor.open(inetAddress) != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("设置地址失败！"s));
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

    if (aceSockAcceptor.accept(sockStream.GetACESockStream(), &sockAddress.GetACEInetAddress()) == 0)
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

Network::ACEHandle Network::ACESockAcceptor::GetACEHandle()
{
    NETWORK_CLASS_IS_VALID_9;

    return aceSockAcceptor.get_handle();
}

bool Network::ACESockAcceptor::EnableNonBlock()
{
    NETWORK_CLASS_IS_VALID_9;

    if (aceSockAcceptor.enable(g_NonBlock) == 0)
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

    const auto result = aceSockAcceptor.accept(sockStream->GetACESockStream());

    if (result == 0)
    {
        CoreTools::CallbackParameters callbackParameters{ 0 };
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncAcceptor));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), result);

        if (!eventInterface->EventFunction(callbackParameters))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                << SYSTEM_TEXT("事件回调执行失败！")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
    }
}

    #include STSTEM_WARNING_POP

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26415)
    #include SYSTEM_WARNING_DISABLE(26418)

void Network::ACESockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto result = aceSockAcceptor.accept(sockStream->GetACESockStream(), &sockAddress->GetACEInetAddress());

    if (result == 0)
    {
        CoreTools::CallbackParameters callbackParameters{ 0 };
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncAcceptor));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), result);

        if (!eventInterface->EventFunction(callbackParameters))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                << SYSTEM_TEXT("事件回调执行失败！")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
    }
}

    #include STSTEM_WARNING_POP

string Network::ACESockAcceptor::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    ACESockInetAddress address{};

    if (aceSockAcceptor.get_local_addr(address.GetACEInetAddress()) == 0)
    {
        return address.GetAddress();
    }
    else
    {
        return string{};
    }
}

int Network::ACESockAcceptor::GetPort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    ACESockInetAddress address{};

    if (aceSockAcceptor.get_local_addr(address.GetACEInetAddress()) == 0)
    {
        return address.GetPort();
    }
    else
    {
        return 0;
    }
}

#endif  // NETWORK_USE_ACE