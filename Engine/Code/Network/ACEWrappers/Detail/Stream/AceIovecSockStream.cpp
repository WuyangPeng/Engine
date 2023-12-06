///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 15:49)

#include "Network/NetworkExport.h"

#include "AceIovecSockStream.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageInterface.h"

#include <array>

#ifdef NETWORK_USE_ACE

Network::AceIovecSockStream::AceIovecSockStream() noexcept
    : ParentType{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, AceIovecSockStream)

int Network::AceIovecSockStream::Send(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(messageBuffer);

    static constexpr auto headSize = MessageInterface::GetMessageHeadSize();

    if (messageBuffer->GetCurrentWriteIndex() <= headSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据大小错误！"s))
    }

    std::array<iovec, 2> iov{};

    #include SYSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26481)

    iov.at(0).iov_base = messageBuffer->GetInitialBufferedPtr();
    iov.at(0).iov_len = headSize;
    iov.at(1).iov_base = messageBuffer->GetInitialBufferedPtr() + headSize;
    iov.at(1).iov_len = messageBuffer->GetCurrentWriteIndex() - headSize;

    #include SYSTEM_WARNING_POP

    if (GetACESockStream().sendv_n(iov.data(), 2) != messageBuffer->GetCurrentWriteIndex())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("发送数据失败！"s))
    }

    return messageBuffer->GetCurrentWriteIndex();
}

void Network::AceIovecSockStream::AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventInterface, messageBuffer);

    if (const auto currentWriteIndex = Send(messageBuffer);
        currentWriteIndex != messageBuffer->GetCurrentWriteIndex())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息发送失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }

    CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy) };
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncSend));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Ace));
    if (!eventInterface->EventFunction(callbackParameters))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("事件回调执行失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

#endif  // NETWORK_USE_ACE