///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 19:28)

#include "Network/NetworkExport.h"

#include "BufferReceiveStreamImpl.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/SocketManager.h"

using std::make_shared;
using std::string;

Network::BufferReceiveStreamImpl::BufferReceiveStreamImpl(const MessageBufferSharedPtr& messageBuffer, ParserStrategy parserStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy)
    : topLevel{ ReceiveMessageLevel::Create() }, parserStrategy{ parserStrategy }, encryptedCompressionStrategy{ encryptedCompressionStrategy }, lastMessageBuffer{}
{
    AnalysisBuffer(messageBuffer);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

// private
void Network::BufferReceiveStreamImpl::AnalysisBuffer(const MessageBufferSharedPtr& messageBuffer)
{
    try
    {
        DoAnalysisBuffer(messageBuffer);
    }
    catch (...)
    {
        lastMessageBuffer.reset();
        throw;
    }
}

void Network::BufferReceiveStreamImpl::EncryptedCompression() noexcept
{
}

void Network::BufferReceiveStreamImpl::DoAnalysisBuffer(const MessageBufferSharedPtr& messageBuffer)
{
    SpliceMessageSource(messageBuffer);
    MessageSource messageSource{ lastMessageBuffer };

    int32_t messageLength{ 0 };
    messageSource.Read(messageLength);

    if (lastMessageBuffer->GetCurrentWriteIndex() < messageLength)
    {
        CopyToLastMessageSource();
        return;
    }

    EncryptedCompression();

    int32_t fullVersion{ 0 };
    messageSource.Read(fullVersion);
    int64_t timeInMicroseconds{ 0 };
    messageSource.Read(timeInMicroseconds);

    while (messageSource.GetBytesRead() < messageSource.GetBytesTotal() && messageSource.GetBytesRead() < messageLength)
    {
        ReadMessage(messageSource, fullVersion);
    }

    lastMessageBuffer.reset();
}

void Network::BufferReceiveStreamImpl::ReadMessage(MessageSource& messageSource, int fullVersion)
{
    // 读取类型
    int64_t messageType{ 0 };
    messageSource.Read(messageType);

    try
    {
        auto factory = MESSAGE_MANAGER_SINGLETON.Find(messageType, fullVersion);

        if (factory != nullptr)
        {
            // 从源缓冲器加载该对象。
            const auto message = (*factory)(messageSource, messageType);

            topLevel.Insert(message);
        }
    }
    catch (const CoreTools::Error& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, Network, error, SYSTEM_TEXT("（"), messageType, SYSTEM_TEXT("）"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

// private
void Network::BufferReceiveStreamImpl::SpliceMessageSource(const MessageBufferSharedPtr& messageBuffer)
{
    if (lastMessageBuffer)
    {
        const auto messageLength = lastMessageBuffer->GetMessageLength();

        if (messageLength < messageBuffer->GetCurrentWriteIndex() + lastMessageBuffer->GetCurrentWriteIndex())
        {
            THROW_EXCEPTION(SYSTEM_TEXT("消息长度读取错误！"s));
        }

        lastMessageBuffer->PushBack(*messageBuffer);
    }
    else
    {
        lastMessageBuffer = messageBuffer;
    }
}

// private
void Network::BufferReceiveStreamImpl::CopyToLastMessageSource()
{
    const auto messageLength = lastMessageBuffer->GetMessageLength();
    if (lastMessageBuffer->GetSize() < messageLength)
    {
        lastMessageBuffer = lastMessageBuffer->Expansion(messageLength);
    }

    lastMessageBuffer->ClearCurrentReadIndex();
}

CLASS_INVARIANT_STUB_DEFINE(Network, BufferReceiveStreamImpl)

void Network::BufferReceiveStreamImpl::OnEvent(uint64_t socketID, const SocketManagerSharedPtr& socketManager)
{
    auto process = socketManager;

    for (const auto& value : topLevel)
    {
        process->OnEvent(socketID, value->GetMessageID(), value);
    }
}

bool Network::BufferReceiveStreamImpl::IsFinish() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (lastMessageBuffer)
        return false;
    else
        return true;
}

void Network::BufferReceiveStreamImpl::PushBack(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    AnalysisBuffer(messageBuffer);
}
