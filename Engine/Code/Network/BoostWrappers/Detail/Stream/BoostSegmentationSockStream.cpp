/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:24)

#include "Network/NetworkExport.h"

#include "BoostSegmentationSockStream.h"
#include "BoostSockStreamHelper.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/Interface/Data/AddressData.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/MessageBuffer.h"

Network::BoostSegmentationSockStream::BoostSegmentationSockStream(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }, streamReceive{ StreamReceive::Head }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostSegmentationSockStream)

int Network::BoostSegmentationSockStream::Receive(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    try
    {
        switch (streamReceive)
        {
            case StreamReceive::Head:
            {
                return ReceiveHead(messageBuffer);
            }
            case StreamReceive::Content:
            {
                return ReceiveContent(messageBuffer);
            }
            default:
            {
                break;
            }
        }

        return 0;
    }
    catch (...)
    {
        streamReceive = StreamReceive::Head;
        throw;
    }
}

int Network::BoostSegmentationSockStream::ReceiveHead(const MessageBufferSharedPtr& messageBuffer)
{
    messageBuffer->ClearCurrentIndex();
    messageBuffer->CheckingMessageHeadSize();
    messageBuffer->SetMessageHeadReceiveCount();

    const auto receiveSize = HandleReceive(messageBuffer);

    if (messageBuffer->GetReceiveCount() == 0)
    {
        streamReceive = StreamReceive::Content;

        return ReceiveContent(messageBuffer) + receiveSize;
    }
    else if (receiveSize != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("接收消息头错误！"s))
    }

    return receiveSize;
}

int Network::BoostSegmentationSockStream::ReceiveContent(const MessageBufferSharedPtr& messageBuffer)
{
    messageBuffer->CheckingMessageContentSize();
    messageBuffer->SetMessageContentReceiveCount();

    const auto receiveSize = HandleReceive(messageBuffer);

    if (0 < receiveSize)
    {
        streamReceive = StreamReceive::Head;

        if (0 < messageBuffer->GetReceiveCount())
        {
            THROW_EXCEPTION(SYSTEM_TEXT("接收消息内容错误！"s))
        }
    }

    return receiveSize;
}

void Network::BoostSegmentationSockStream::AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    try
    {
        switch (streamReceive)
        {
            case StreamReceive::Head:
                return AsyncReceiveHead(eventInterface, messageBuffer);
            case StreamReceive::Content:
                return AsyncReceiveContent(eventInterface, messageBuffer, messageBuffer->GetCurrentWriteIndex());
            default:
                break;
        }
    }
    catch (...)
    {
        streamReceive = StreamReceive::Head;
        throw;
    }
}

void Network::BoostSegmentationSockStream::AsyncReceiveHead(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    messageBuffer->ClearCurrentIndex();
    messageBuffer->CheckingMessageHeadSize();
    messageBuffer->SetMessageHeadReceiveCount();

    HandleAsyncReceive(eventInterface, messageBuffer, messageBuffer->GetCurrentWriteIndex());
}

void Network::BoostSegmentationSockStream::AsyncReceiveContent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex)
{
    messageBuffer->CheckingMessageContentSize();
    messageBuffer->SetMessageContentReceiveCount();

    HandleAsyncReceive(eventInterface, messageBuffer, originalWriteIndex);
}

void Network::BoostSegmentationSockStream::SubclassAsyncReceiveEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex)
{
    try
    {
        switch (streamReceive)
        {
            case StreamReceive::Head:
                return SubclassAsyncReceiveHeadEvent(errorCode, eventInterface, messageBuffer, originalWriteIndex);
            case StreamReceive::Content:
                return SubclassAsyncReceiveContentEvent(errorCode, eventInterface, messageBuffer, originalWriteIndex);
            default:
                break;
        }
    }
    catch (...)
    {
        streamReceive = StreamReceive::Head;
        throw;
    }
}

void Network::BoostSegmentationSockStream::SubclassAsyncReceiveHeadEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex)
{
    if (errorCode != ErrorCodeType{})
    {
        boost::asio::detail::throw_error(errorCode, "SubclassAsyncReceiveHeadEvent");
    }

    if (messageBuffer->GetReceiveCount() == 0)
    {
        streamReceive = StreamReceive::Content;

        return AsyncReceiveContent(eventInterface, messageBuffer, originalWriteIndex);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("接收消息头长度错误！"s))
    }
}

void Network::BoostSegmentationSockStream::SubclassAsyncReceiveContentEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex)
{
    System::UnusedFunction(eventInterface, messageBuffer);

    streamReceive = StreamReceive::Head;

    BoostSockStreamHelper::EventReceiveFunction(errorCode, eventInterface, AddressData{ *this }, messageBuffer->GetCurrentWriteIndex() - originalWriteIndex);
}
