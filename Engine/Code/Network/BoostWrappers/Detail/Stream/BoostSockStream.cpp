//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 18:31)

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

using std::string;
using std::to_string;
using namespace std::literals;
using boost::bind;
using boost::numeric_cast;
using boost::asio::detail::throw_error;

namespace
{
    const auto GetSynchronizeSendSuccessDescription()
    {
        static const auto synchronizeSendSuccess = SYSTEM_TEXT("同步发送消息成功，字节数："s);

        return synchronizeSendSuccess;
    }

    const auto GetSynchronizeReceiveSuccessDescription()
    {
        static const auto synchronizeReceiveSuccess = SYSTEM_TEXT("同步接收消息成功，字节数："s);

        return synchronizeReceiveSuccess; 
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Network::BoostSockStream::BoostSockStream()
    : ParentType{}, m_Socket{ BASE_MAIN_MANAGER_SINGLETON.GetIOContext() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP

Network::BoostSockStream::~BoostSockStream() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostSockStream)

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
int Network::BoostSockStream::Send(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto originalReadIndex = messageBuffer->GetCurrentReadIndex();

    while (0 < messageBuffer->GetRemainingReadCount())
    {
        ErrorCodeType errorCode{};

        auto sendCount = numeric_cast<int>(m_Socket.send(boost::asio::buffer(messageBuffer->GetCurrentReadBufferedPtr(), messageBuffer->GetRemainingReadCount()), 0, errorCode));

        if (boost::system::errc::operation_would_block == errorCode)
        {
            break;
        }
        else if (errorCode != ErrorCodeType{})
        {
            throw_error(errorCode, "Send");
        }

        if (sendCount == 0)
        {
            break;
        }

        messageBuffer->AddCurrentReadIndex(sendCount);
    }

    const auto readCount = messageBuffer->GetCurrentReadIndex() - originalReadIndex;

    BoostSockStreamHelper::PrintSuccessLog(GetSynchronizeSendSuccessDescription(), AddressData{ *this }, readCount);

    return readCount;
}
#include STSTEM_WARNING_POP

void Network::BoostSockStream::AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto originalReadIndex = messageBuffer->GetCurrentReadIndex();

    m_Socket.async_send(boost::asio::buffer(messageBuffer->GetCurrentReadBufferedPtr(), messageBuffer->GetRemainingReadCount()),
                        bind(&ClassType::AsyncSendEvent, this, eventInterface, messageBuffer, originalReadIndex, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Network::BoostSockStream::AsyncSendEvent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalReadIndex, const ErrorCodeType& errorCode, size_t bytesTransferred)
{
    if (errorCode)
    {
        throw_error(errorCode, "DoAsyncSend");
    }

    auto presentBytesTransferred = numeric_cast<int>(bytesTransferred);

    messageBuffer->AddCurrentReadIndex(presentBytesTransferred);

    if (0 < messageBuffer->GetRemainingReadCount() && presentBytesTransferred != 0)
    {
        m_Socket.async_send(boost::asio::buffer(messageBuffer->GetCurrentReadBufferedPtr(), messageBuffer->GetRemainingReadCount()),
                            bind(&ClassType::AsyncSendEvent, this, eventInterface, messageBuffer, originalReadIndex, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    }
    else
    {
        BoostSockStreamHelper::EventSendFunction(errorCode, eventInterface, AddressData{ *this }, messageBuffer->GetCurrentReadIndex() - originalReadIndex);
    }
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
int Network::BoostSockStream::HandleReceive(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    const auto originalWriteIndex = messageBuffer->GetCurrentWriteIndex();

    while (0 < messageBuffer->GetReceiveCount())
    {
        ErrorCodeType errorCode;

        auto receiveCount = numeric_cast<int>(m_Socket.receive(boost::asio::buffer(messageBuffer->GetCurrentWriteBufferedPtr(), messageBuffer->GetReceiveCount()), 0, errorCode));

        if (boost::system::errc::operation_would_block == errorCode)
        {
            break;
        }
        else if (errorCode != ErrorCodeType{})
        {
            throw_error(errorCode, "Receive");
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
#include STSTEM_WARNING_POP

void Network::BoostSockStream::HandleAsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex)
{
    NETWORK_CLASS_IS_VALID_9;

    m_Socket.async_receive(boost::asio::buffer(messageBuffer->GetCurrentWriteBufferedPtr(), messageBuffer->GetReceiveCount()),
                           bind(&ClassType::AsyncReceiveEvent, this, eventInterface, messageBuffer, originalWriteIndex, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

// private
void Network::BoostSockStream::AsyncReceiveEvent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex, const ErrorCodeType& errorCode, size_t bytesTransferred)
{
    if (errorCode)
    {
        throw_error(errorCode, "DoAsyncReceive");
    }

    auto presentBytesTransferred = numeric_cast<int>(bytesTransferred);

    messageBuffer->DecreaseReceiveCount(presentBytesTransferred);

    if (0 < messageBuffer->GetReceiveCount() && presentBytesTransferred != 0 && !messageBuffer->IsMessageReceiveEnd())
    {
        m_Socket.async_receive(boost::asio::buffer(messageBuffer->GetCurrentWriteBufferedPtr(), messageBuffer->GetReceiveCount()),
                               bind(&ClassType::AsyncReceiveEvent, this, eventInterface, messageBuffer, originalWriteIndex, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    }
    else
    {
        SubclassAsyncReceiveEvent(errorCode, eventInterface, messageBuffer, originalWriteIndex);
    }
}

Network::BoostSockStreamType& Network::BoostSockStream::GetBoostSockStream() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return m_Socket;
}

bool Network::BoostSockStream::CloseHandle()
{
    NETWORK_CLASS_IS_VALID_9;

    ErrorCodeType errorCode;

    m_Socket.close(errorCode);

    if (errorCode == ErrorCodeType{})
        return true;
    else
        return false;
}

bool Network::BoostSockStream::EnableNonBlock()
{
    NETWORK_CLASS_IS_VALID_9;

    m_Socket.non_blocking(true);

    return true;
}

const std::string Network::BoostSockStream::GetRemoteAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Socket.remote_endpoint().address().to_string() + ":"s + to_string(GetRemotePort());
}

int Network::BoostSockStream::GetRemotePort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Socket.remote_endpoint().port();
}
