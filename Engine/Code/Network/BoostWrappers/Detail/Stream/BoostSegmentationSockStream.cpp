//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 18:14)

#include "Network/NetworkExport.h"

#include "BoostSegmentationSockStream.h"
#include "BoostSockStreamHelper.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/Interface/Data/AddressData.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/MessageBuffer.h"

using boost::asio::detail::throw_error;
using std::string;

Network::BoostSegmentationSockStream::BoostSegmentationSockStream() noexcept
    : ParentType{}, m_StreamReceive{ StreamReceive::Head }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostSegmentationSockStream)

int Network::BoostSegmentationSockStream::Receive(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    try
    {
        switch (m_StreamReceive)
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
        m_StreamReceive = StreamReceive::Head;
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
        m_StreamReceive = StreamReceive::Content;

        return ReceiveContent(messageBuffer) + receiveSize;
    }
    else if (receiveSize != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("������Ϣͷ����"s));
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
        m_StreamReceive = StreamReceive::Head;

        if (0 < messageBuffer->GetReceiveCount())
        {
            THROW_EXCEPTION(SYSTEM_TEXT("������Ϣ���ݴ���"s));
        }
    }

    return receiveSize;
}

void Network::BoostSegmentationSockStream::AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    try
    {
        switch (m_StreamReceive)
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
        m_StreamReceive = StreamReceive::Head;
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
        switch (m_StreamReceive)
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
        m_StreamReceive = StreamReceive::Head;
        throw;
    }
}

void Network::BoostSegmentationSockStream::SubclassAsyncReceiveHeadEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex)
{
    if (errorCode != ErrorCodeType{})
    {
        throw_error(errorCode, "SubclassAsyncReceiveHeadEvent");
    }

    if (messageBuffer->GetReceiveCount() == 0)
    {
        m_StreamReceive = StreamReceive::Content;

        return AsyncReceiveContent(eventInterface, messageBuffer, originalWriteIndex);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("������Ϣͷ���ȴ���"s));
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
void Network::BoostSegmentationSockStream::SubclassAsyncReceiveContentEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex)
{
    m_StreamReceive = StreamReceive::Head;

    BoostSockStreamHelper::EventReceiveFunction(errorCode, eventInterface, AddressData{ *this }, messageBuffer->GetCurrentWriteIndex() - originalWriteIndex);
}
#include STSTEM_WARNING_POP