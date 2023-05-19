///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 09:37)

#include "Network/NetworkExport.h"

#include "NullSockStream.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

Network::NullSockStream::NullSockStream() noexcept
    : ParentType{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullSockStream)

int Network::NullSockStream::Send(const MessageBufferSharedPtr& messageBuffer) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(messageBuffer);

    return messageBuffer->GetCurrentWriteIndex();
}

int Network::NullSockStream::Receive(const MessageBufferSharedPtr& messageBuffer) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(messageBuffer);

    return 0;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::NullSockStream::AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(messageBuffer);

    CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy) };
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncSend));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Null));

    if (!eventInterface->EventFunction(callbackParameters))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("执行事件回调失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

#include STSTEM_WARNING_POP

void Network::NullSockStream::AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventInterface, messageBuffer);
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

std::string Network::NullSockStream::GetRemoteAddress() const noexcept
{
    return std::string{};
}

int Network::NullSockStream::GetRemotePort() const noexcept
{
    return 0;
}
