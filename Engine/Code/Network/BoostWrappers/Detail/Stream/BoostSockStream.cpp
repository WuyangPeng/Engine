/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:23)

#include "Network/NetworkExport.h"

#include "BoostSockStream.h"
#include "BoostSockStreamHelper.h"
#include "System/Helper/PragmaWarning/AsioPlaceholders.h"
#include "System/Helper/PragmaWarning/Bind.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/Data/AddressData.h"
#include "Network/NetworkMessage/MessageBuffer.h"

using namespace std::literals;

namespace
{
    constexpr auto synchronizeSendSuccess = SYSTEM_TEXT("同步发送消息成功，字节数："sv);

    constexpr auto synchronizeReceiveSuccess = SYSTEM_TEXT("同步接收消息成功，字节数："sv);
}

Network::BoostSockStream::BoostSockStream(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{}, socket{ BASE_MAIN_MANAGER_SINGLETON.GetContext() }
{
    System::UnusedFunction(disableNotThrow);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockStream::~BoostSockStream() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostSockStream)

int Network::BoostSockStream::Send(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(messageBuffer);

    const auto originalReadIndex = messageBuffer->GetCurrentReadIndex();

    while (0 < messageBuffer->GetRemainingReadCount())
    {
        ErrorCodeType errorCode{};

        const auto sendCount = boost::numeric_cast<int>(socket.send(boost::asio::buffer(messageBuffer->GetCurrentReadBufferedPtr(), messageBuffer->GetRemainingReadCount()), 0, errorCode));

        if (boost::system::errc::operation_would_block == errorCode)
        {
            break;
        }
        else if (errorCode != ErrorCodeType{})
        {
            boost::asio::detail::throw_error(errorCode, "Send");
        }

        if (sendCount == 0)
        {
            break;
        }

        messageBuffer->AddCurrentReadIndex(sendCount);
    }

    const auto readCount = messageBuffer->GetCurrentReadIndex() - originalReadIndex;

    BoostSockStreamHelper::PrintSuccessLog(synchronizeSendSuccess.data(), AddressData{ *this }, readCount);

    return readCount;
}

void Network::BoostSockStream::AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto originalReadIndex = messageBuffer->GetCurrentReadIndex();

    socket.async_send(boost::asio::buffer(messageBuffer->GetCurrentReadBufferedPtr(),
                                          messageBuffer->GetRemainingReadCount()),
                      boost::bind(&ClassType::AsyncSendEvent,
                                  this,
                                  eventInterface,
                                  messageBuffer,
                                  originalReadIndex,
                                  boost::asio::placeholders::error,
                                  boost::asio::placeholders::bytes_transferred));
}

void Network::BoostSockStream::AsyncSendEvent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalReadIndex, const ErrorCodeType& errorCode, size_t bytesTransferred)
{
    if (errorCode)
    {
        boost::asio::detail::throw_error(errorCode, "DoAsyncSend");
    }

    const auto presentBytesTransferred = boost::numeric_cast<int>(bytesTransferred);

    messageBuffer->AddCurrentReadIndex(presentBytesTransferred);

    if (0 < messageBuffer->GetRemainingReadCount() && presentBytesTransferred != 0)
    {
        socket.async_send(boost::asio::buffer(messageBuffer->GetCurrentReadBufferedPtr(),
                                              messageBuffer->GetRemainingReadCount()),
                          boost::bind(&ClassType::AsyncSendEvent,
                                      this,
                                      eventInterface,
                                      messageBuffer,
                                      originalReadIndex,
                                      boost::asio::placeholders::error,
                                      boost::asio::placeholders::bytes_transferred));
    }
    else
    {
        BoostSockStreamHelper::EventSendFunction(errorCode, eventInterface, AddressData{ *this }, messageBuffer->GetCurrentReadIndex() - originalReadIndex);
    }
}

int Network::BoostSockStream::HandleReceive(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(messageBuffer);

    const auto originalWriteIndex = messageBuffer->GetCurrentWriteIndex();

    while (0 < messageBuffer->GetReceiveCount())
    {
        ErrorCodeType errorCode{};

        const auto receiveCount = boost::numeric_cast<int>(socket.receive(boost::asio::buffer(messageBuffer->GetCurrentWriteBufferedPtr(), messageBuffer->GetReceiveCount()), 0, errorCode));

        if (errorCode == boost::system::errc::operation_would_block || errorCode.value() == 10035)
        {
            break;
        }
        else if (errorCode != ErrorCodeType{})
        {
            boost::asio::detail::throw_error(errorCode, "Receive");
        }

        if (receiveCount == 0)
        {
            break;
        }

        messageBuffer->DecreaseReceiveCount(receiveCount);

        if (messageBuffer->IsMessageReceiveEnd())
        {
            break;
        }
    }

    return messageBuffer->GetCurrentWriteIndex() - originalWriteIndex;
}

void Network::BoostSockStream::HandleAsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex)
{
    NETWORK_CLASS_IS_VALID_9;

    socket.async_receive(boost::asio::buffer(messageBuffer->GetCurrentWriteBufferedPtr(),
                                             messageBuffer->GetReceiveCount()),
                         boost::bind(&ClassType::AsyncReceiveEvent,
                                     this,
                                     eventInterface,
                                     messageBuffer,
                                     originalWriteIndex,
                                     boost::asio::placeholders::error,
                                     boost::asio::placeholders::bytes_transferred));
}

void Network::BoostSockStream::AsyncReceiveEvent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex, const ErrorCodeType& errorCode, size_t bytesTransferred)
{
    if (errorCode)
    {
        boost::asio::detail::throw_error(errorCode, "DoAsyncReceive");
    }

    const auto presentBytesTransferred = boost::numeric_cast<int>(bytesTransferred);

    messageBuffer->DecreaseReceiveCount(presentBytesTransferred);

    if (0 < messageBuffer->GetReceiveCount() && presentBytesTransferred != 0 && !messageBuffer->IsMessageReceiveEnd())
    {
        socket.async_receive(boost::asio::buffer(messageBuffer->GetCurrentWriteBufferedPtr(),
                                                 messageBuffer->GetReceiveCount()),
                             boost::bind(&ClassType::AsyncReceiveEvent,
                                         this,
                                         eventInterface,
                                         messageBuffer,
                                         originalWriteIndex,
                                         boost::asio::placeholders::error,
                                         boost::asio::placeholders::bytes_transferred));
    }
    else
    {
        SubclassAsyncReceiveEvent(errorCode, eventInterface, messageBuffer, originalWriteIndex);
    }
}

Network::BoostSockStreamType& Network::BoostSockStream::GetBoostSockStream() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return socket;
}

bool Network::BoostSockStream::CloseHandle()
{
    NETWORK_CLASS_IS_VALID_9;

    ErrorCodeType errorCode{};

    socket.close(errorCode);

    if (errorCode == ErrorCodeType{})
        return true;
    else
        return false;
}

bool Network::BoostSockStream::EnableNonBlock()
{
    NETWORK_CLASS_IS_VALID_9;

    socket.non_blocking(true);

    return true;
}

std::string Network::BoostSockStream::GetRemoteAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return socket.remote_endpoint().address().to_string() + ":"s + std::to_string(GetRemotePort());
}

int Network::BoostSockStream::GetRemotePort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return socket.remote_endpoint().port();
}
