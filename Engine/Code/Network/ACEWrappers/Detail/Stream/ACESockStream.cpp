///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 14:06)

#include "Network/NetworkExport.h"

#include "ACESockStream.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/ACEWrappers/Detail/Address/ACESockInternetAddress.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageInterface.h"

#ifdef NETWORK_USE_ACE

Network::ACESockStream::ACESockStream() noexcept
    : ParentType{}, aceSockStream{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACESockStream::~ACESockStream() noexcept
{
    EXCEPTION_TRY
    {
        aceSockStream.close();
    }
    EXCEPTION_ALL_CATCH(Network)

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ACESockStream)

Network::ACESockStreamNativeType& Network::ACESockStream::GetACESockStream() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return aceSockStream;
}

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26415)
    #include SYSTEM_WARNING_DISABLE(26418)

int Network::ACESockStream::Receive(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto bytesTotal = messageBuffer->GetSize();

    static constexpr auto headSize = MessageInterface::GetMessageHeadSize();

    if (bytesTotal <= headSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("接收消息头容量不足！"s))
    }

    const auto buffer = messageBuffer->GetCurrentWriteBufferedPtr();

    if (buffer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("当前写指针为空！"s))
    }

    if (const auto receiveSize = aceSockStream.recv_n(buffer, headSize);
        receiveSize == headSize)
    {
        messageBuffer->AddCurrentWriteIndex(headSize);

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)

        const auto totalLength = *reinterpret_cast<int*>(buffer);

    #include STSTEM_WARNING_POP

        if (bytesTotal < totalLength)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("接收数据长度不足！"s))
        }

        const auto remainLength = totalLength - headSize;

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26481)

        if (aceSockStream.recv_n(buffer + headSize, remainLength) != remainLength)

    #include STSTEM_WARNING_POP
        {
            THROW_EXCEPTION(SYSTEM_TEXT("接收数据长度错误！"s))
        }

        messageBuffer->AddCurrentWriteIndex(remainLength);

        return totalLength;
    }
    else
    {
        return 0;
    }
}

    #include STSTEM_WARNING_POP

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26415)
    #include SYSTEM_WARNING_DISABLE(26418)

int Network::ACESockStream::Send(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    if (aceSockStream.send_n(messageBuffer->GetInitialBufferedPtr(), messageBuffer->GetCurrentWriteIndex()) != messageBuffer->GetCurrentWriteIndex())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("发送数据失败！"s))
    }

    return messageBuffer->GetCurrentWriteIndex();
}

    #include STSTEM_WARNING_POP

Network::ACEHandleType Network::ACESockStream::GetACEHandle() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return aceSockStream.get_handle();
}

void Network::ACESockStream::SetACEHandle(ACEHandleType handle)
{
    NETWORK_CLASS_IS_VALID_9;

    aceSockStream.set_handle(handle);
}

bool Network::ACESockStream::CloseHandle()
{
    NETWORK_CLASS_IS_VALID_9;

    if (aceSockStream.close() == 0)
    {
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)

        aceSockStream.set_handle(reinterpret_cast<ACEHandle>(System::invalidSocket));

    #include STSTEM_WARNING_POP

        return true;
    }
    else
    {
        return false;
    }
}

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26415)
    #include SYSTEM_WARNING_DISABLE(26418)

void Network::ACESockStream::AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    if (aceSockStream.send_n(messageBuffer->GetInitialBufferedPtr(), messageBuffer->GetCurrentWriteIndex()) != messageBuffer->GetCurrentWriteIndex())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("发送数据失败！"s))
    }

    CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy) };
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncSend));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Ace));
    if (!eventInterface->EventFunction(callbackParameters))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("事件回调执行失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

    #include STSTEM_WARNING_POP

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26415)
    #include SYSTEM_WARNING_DISABLE(26418)

void Network::ACESockStream::AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto bytesTotal = messageBuffer->GetSize();

    static constexpr auto headSize = MessageInterface::GetMessageHeadSize();

    if (bytesTotal <= headSize)
    {
        return;
    }

    auto buffer = messageBuffer->GetCurrentWriteBufferedPtr();

    if (buffer == nullptr)
    {
        return;
    }

    const auto recvSize = aceSockStream.recv_n(buffer, headSize);

    if (recvSize == headSize)
    {
        messageBuffer->AddCurrentWriteIndex(headSize);

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)

        const auto totalLength = *reinterpret_cast<int*>(buffer);

    #include STSTEM_WARNING_POP

        if (bytesTotal < totalLength)
        {
            return;
        }

        const auto remainLength = totalLength - headSize;

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26481)

        if (aceSockStream.recv_n(buffer + headSize, remainLength) != remainLength)

    #include STSTEM_WARNING_POP
        {
            return;
        }

        messageBuffer->AddCurrentWriteIndex(remainLength);

        CoreTools::CallbackParameters callbackParameters{ System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy) };
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncReceive));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPosition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::Ace));
        if (!eventInterface->EventFunction(callbackParameters))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("事件回调执行失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
    else
    {
        return;
    }
}

    #include STSTEM_WARNING_POP

std::string Network::ACESockStream::GetRemoteAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (ACESockInternetAddress address{};
        aceSockStream.get_remote_addr(address.GetACEInternetAddress()) == 0)
    {
        return address.GetAddress();
    }
    else
    {
        return std::string{};
    }
}

int Network::ACESockStream::GetRemotePort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (ACESockInternetAddress address{};
        aceSockStream.get_remote_addr(address.GetACEInternetAddress()) == 0)
    {
        return address.GetPort();
    }
    else
    {
        return 0;
    }
}

bool Network::ACESockStream::EnableNonBlock()
{
    NETWORK_CLASS_IS_VALID_9;

    if (aceSockStream.enable(gNonBlock) == 0)
        return true;
    else
        return false;
}

#endif  // NETWORK_USE_ACE