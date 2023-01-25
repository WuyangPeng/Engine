///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/22 18:24)

#include "Network/NetworkExport.h"

#ifdef NETWORK_USE_ACE

    #include "ACESockStream.h"
    #include "System/Helper/PragmaWarning/NumericCast.h"
    #include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
    #include "CoreTools/Helper/ExceptionMacro.h"
    #include "CoreTools/MessageEvent/CallbackParameters.h"
    #include "CoreTools/MessageEvent/EventInterface.h"
    #include "Network/ACEWrappers/Detail/Address/ACESockInetAddress.h"
    #include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
    #include "Network/NetworkMessage/BufferSendStream.h"
    #include "Network/NetworkMessage/Flags/MessageEventFlags.h"
    #include "Network/NetworkMessage/MessageBuffer.h"
    #include "Network/NetworkMessage/MessageInterface.h"

using std::array;
using std::string;

Network::ACESockStream::ACESockStream() noexcept
    : ParentType{}, aceSockStream{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACESockStream::~ACESockStream()
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
        THROW_EXCEPTION(SYSTEM_TEXT("接收消息头容量不足！"s));
    }

    auto buffer = messageBuffer->GetCurrentWriteBufferedPtr();

    if (buffer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("当前写指针为空！"s));
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
            THROW_EXCEPTION(SYSTEM_TEXT("接收数据长度不足！"s));
        }

        const auto remainLength = totalLength - headSize;

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26481)

        if (aceSockStream.recv_n(buffer + headSize, remainLength) != remainLength)

    #include STSTEM_WARNING_POP
        {
            THROW_EXCEPTION(SYSTEM_TEXT("接收数据长度错误！"s));
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
        THROW_EXCEPTION(SYSTEM_TEXT("发送数据失败！"s));
    }

    return messageBuffer->GetSize();
}

    #include STSTEM_WARNING_POP

Network::ACEHandle Network::ACESockStream::GetACEHandle() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return aceSockStream.get_handle();
}

void Network::ACESockStream::SetACEHandle(ACEHandle handle)
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
        THROW_EXCEPTION(SYSTEM_TEXT("发送数据失败！"s));
    }

    CoreTools::CallbackParameters callbackParameters{ 0 };
    callbackParameters.SetValue(0, System::EnumCastUnderlying(SocketManagerEvent::AsyncSend));
    callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
    if (!eventInterface->EventFunction(callbackParameters))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
            << SYSTEM_TEXT("事件回调执行失败！")
            << LOG_SINGLETON_TRIGGER_ASSERT;
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

        CoreTools::CallbackParameters callbackParameters{ 0 };
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncReceive));
        callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
        if (!eventInterface->EventFunction(callbackParameters))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
                << SYSTEM_TEXT("事件回调执行失败！")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
    }
    else
    {
        return;
    }
}

    #include STSTEM_WARNING_POP

string Network::ACESockStream::GetRemoteAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    ACESockInetAddress address{};

    if (aceSockStream.get_remote_addr(address.GetACEInetAddress()) == 0)
    {
        return address.GetAddress();
    }
    else
    {
        return string{};
    }
}

int Network::ACESockStream::GetRemotePort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    ACESockInetAddress address{};

    if (aceSockStream.get_remote_addr(address.GetACEInetAddress()) == 0)
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

    if (aceSockStream.enable(g_NonBlock) == 0)
        return true;
    else
        return false;
}

#endif  // NETWORK_USE_ACE