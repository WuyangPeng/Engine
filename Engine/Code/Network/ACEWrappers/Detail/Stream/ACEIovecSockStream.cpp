///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/22 18:23)

#include "Network/NetworkExport.h"

#ifdef NETWORK_USE_ACE

    #include "ACEIovecSockStream.h"
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

using std::array;
using std::string;

Network::ACEIovecSockStream::ACEIovecSockStream() noexcept
    : ParentType{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ACEIovecSockStream)

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26415)
    #include SYSTEM_WARNING_DISABLE(26418)

int Network::ACEIovecSockStream::Send(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    static constexpr auto headSize = MessageInterface::GetMessageHeadSize();

    if (messageBuffer->GetCurrentWriteIndex() <= headSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数据大小错误！"s));
    }

    array<iovec, 2> iov;

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26446)
    #include SYSTEM_WARNING_DISABLE(26481)

    iov[0].iov_base = messageBuffer->GetInitialBufferedPtr();
    iov[0].iov_len = headSize;
    iov[1].iov_base = messageBuffer->GetInitialBufferedPtr() + headSize;
    iov[1].iov_len = messageBuffer->GetCurrentWriteIndex() - headSize;

    #include STSTEM_WARNING_POP

    if (GetACESockStream().sendv_n(iov.data(), 2) != messageBuffer->GetCurrentWriteIndex())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("发送数据失败！"s));
    }

    return messageBuffer->GetCurrentWriteIndex();
}

    #include STSTEM_WARNING_POP

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26415)
    #include SYSTEM_WARNING_DISABLE(26418)

void Network::ACEIovecSockStream::AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    MAYBE_UNUSED const auto currentWriteIndex = Send(messageBuffer);

    CoreTools::CallbackParameters callbackParameters{ 0 };
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncSend));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
    if (!eventInterface->EventFunction(callbackParameters))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
            << SYSTEM_TEXT("事件回调执行失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

    #include STSTEM_WARNING_POP

#endif  // NETWORK_USE_ACE