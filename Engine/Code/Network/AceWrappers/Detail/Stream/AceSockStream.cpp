/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:28)

#include "Network/NetworkExport.h"

#include "AceSockStream.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/AceWrappers/Detail/Address/AceSockInternetAddress.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageInterface.h"

#ifdef NETWORK_USE_ACE

Network::AceSockStream::AceSockStream() noexcept
    : ParentType{}, aceSockStream{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AceSockStream::~AceSockStream() noexcept
{
    EXCEPTION_TRY
    {
        aceSockStream.close();
    }
    EXCEPTION_ALL_CATCH(Network)

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, AceSockStream)

Network::ACESockStreamNativeType& Network::AceSockStream::GetACESockStream() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return aceSockStream;
}

int Network::AceSockStream::Receive(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(messageBuffer);

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

    #include SYSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)

        const auto totalLength = *reinterpret_cast<int*>(buffer);

    #include SYSTEM_WARNING_POP

        if (bytesTotal < totalLength)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("接收数据长度不足！"s))
        }

        const auto remainLength = totalLength - headSize;

    #include SYSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26481)

        if (aceSockStream.recv_n(buffer + headSize, remainLength) != remainLength)

    #include SYSTEM_WARNING_POP
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

int Network::AceSockStream::Send(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(messageBuffer);

    if (aceSockStream.send_n(messageBuffer->GetInitialBufferedPtr(), messageBuffer->GetCurrentWriteIndex()) != messageBuffer->GetCurrentWriteIndex())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("发送数据失败！"s))
    }

    return messageBuffer->GetCurrentWriteIndex();
}

Network::ACEHandleType Network::AceSockStream::GetACEHandle() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return aceSockStream.get_handle();
}

void Network::AceSockStream::SetACEHandle(ACEHandleType handle)
{
    NETWORK_CLASS_IS_VALID_9;

    aceSockStream.set_handle(handle);
}

bool Network::AceSockStream::CloseHandle()
{
    NETWORK_CLASS_IS_VALID_9;

    if (aceSockStream.close() == 0)
    {
    #ifdef TCRE_USE_GCC

        aceSockStream.set_handle(static_cast<ACEHandle>(System::invalidSocket));

    #else  // !TCRE_USE_GCC

        #include SYSTEM_WARNING_PUSH
        #include SYSTEM_WARNING_DISABLE(26490)

        aceSockStream.set_handle(reinterpret_cast<ACEHandle>(System::invalidSocket));

        #include SYSTEM_WARNING_POP

    #endif  // TCRE_USE_GCC

        return true;
    }
    else
    {
        return false;
    }
}

void Network::AceSockStream::AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventInterface, messageBuffer);

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

void Network::AceSockStream::AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventInterface, messageBuffer);

    const auto bytesTotal = messageBuffer->GetSize();

    static constexpr auto headSize = MessageInterface::GetMessageHeadSize();

    if (bytesTotal <= headSize)
    {
        return;
    }

    const auto buffer = messageBuffer->GetCurrentWriteBufferedPtr();

    if (buffer == nullptr)
    {
        return;
    }

    const auto recvSize = aceSockStream.recv_n(buffer, headSize);

    if (recvSize == headSize)
    {
        messageBuffer->AddCurrentWriteIndex(headSize);

    #include SYSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)

        const auto totalLength = *reinterpret_cast<int*>(buffer);

    #include SYSTEM_WARNING_POP

        if (bytesTotal < totalLength)
        {
            return;
        }

        const auto remainLength = totalLength - headSize;

    #include SYSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26481)

        if (aceSockStream.recv_n(buffer + headSize, remainLength) != remainLength)

    #include SYSTEM_WARNING_POP
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

std::string Network::AceSockStream::GetRemoteAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (AceSockInternetAddress address{};
        aceSockStream.get_remote_addr(address.GetACEInternetAddress()) == 0)
    {
        return address.GetAddress();
    }
    else
    {
        return std::string{};
    }
}

int Network::AceSockStream::GetRemotePort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (AceSockInternetAddress address{};
        aceSockStream.get_remote_addr(address.GetACEInternetAddress()) == 0)
    {
        return address.GetPort();
    }
    else
    {
        return 0;
    }
}

bool Network::AceSockStream::EnableNonBlock()
{
    NETWORK_CLASS_IS_VALID_9;

    if (aceSockStream.enable(gNonBlock) == 0)
        return true;
    else
        return false;
}

#endif  // NETWORK_USE_ACE