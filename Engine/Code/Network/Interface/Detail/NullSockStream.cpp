///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 23:42)

#include "Network/NetworkExport.h"

#include "NullSockStream.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

using std::make_shared;
using std::string;
using std::to_string;

Network::NullSockStream::NullSockStream() noexcept
    : ParentType{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockStream)

int Network::NullSockStream::Send(MAYBE_UNUSED const MessageBufferSharedPtr& messageBuffer) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return 0;
}

int Network::NullSockStream::Receive(MAYBE_UNUSED const MessageBufferSharedPtr& messageBuffer) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return 0;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::NullSockStream::AsyncSend(const EventInterfaceSharedPtr& eventInterface, MAYBE_UNUSED const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy) };
    callbackParameters.SetValue(0, System::EnumCastUnderlying(SocketManagerEvent::AsyncSend));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Null));
    
    if (!eventInterface->EventFunction(callbackParameters))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
            << SYSTEM_TEXT("执行事件回调失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

#include STSTEM_WARNING_POP

void Network::NullSockStream::AsyncReceive(MAYBE_UNUSED const EventInterfaceSharedPtr& eventInterface, MAYBE_UNUSED const MessageBufferSharedPtr& messageBuffer) noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

bool Network::NullSockStream::CloseHandle() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return false;
}

bool Network::NullSockStream::EnableNonBlock() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return false;
}

string Network::NullSockStream::GetRemoteAddress() const noexcept
{
    return string{};
}

int Network::NullSockStream::GetRemotePort() const noexcept
{
    return 0;
}
