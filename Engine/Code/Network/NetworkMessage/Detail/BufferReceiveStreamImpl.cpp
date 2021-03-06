//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 11:51)

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
using std::move;
using std::string;

Network::BufferReceiveStreamImpl::BufferReceiveStreamImpl(const MessageBufferSharedPtr& messageBuffer, ParserStrategy parserStrategy)
    : m_TopLevel{}, m_ParserStrategy{ parserStrategy }, m_LastMessageBuffer{}
{
    AnalysisBuffer(messageBuffer);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BufferReceiveStreamImpl::BufferReceiveStreamImpl(const BufferReceiveStreamImpl& rhs)
    : m_TopLevel{ rhs.m_TopLevel }, m_ParserStrategy{ rhs.m_ParserStrategy }, m_LastMessageBuffer{ rhs.m_LastMessageBuffer ? rhs.m_LastMessageBuffer->Clone() : nullptr }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BufferReceiveStreamImpl& Network::BufferReceiveStreamImpl::operator=(const BufferReceiveStreamImpl& rhs)
{
    NETWORK_CLASS_IS_VALID_9;

    m_TopLevel = rhs.m_TopLevel;
    m_ParserStrategy = rhs.m_ParserStrategy;
    m_LastMessageBuffer = rhs.m_LastMessageBuffer ? rhs.m_LastMessageBuffer->Clone() : nullptr;

    return *this;
}

Network::BufferReceiveStreamImpl::BufferReceiveStreamImpl(BufferReceiveStreamImpl&& rhs) noexcept
    : m_TopLevel{ move(rhs.m_TopLevel) }, m_ParserStrategy{ rhs.m_ParserStrategy }, m_LastMessageBuffer{ move(rhs.m_LastMessageBuffer) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BufferReceiveStreamImpl& Network::BufferReceiveStreamImpl::operator=(BufferReceiveStreamImpl&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    m_TopLevel = move(rhs.m_TopLevel);
    m_ParserStrategy = rhs.m_ParserStrategy;
    m_LastMessageBuffer = move(rhs.m_LastMessageBuffer);

    return *this;
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
        m_LastMessageBuffer.reset();
        throw;
    }
}

void Network::BufferReceiveStreamImpl::DoAnalysisBuffer(const MessageBufferSharedPtr& messageBuffer)
{
    SpliceMessageSource(messageBuffer);
    MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(m_LastMessageBuffer) };

    int32_t messageLength{ 0 };
    messageSource->Read(messageLength);

    if (m_LastMessageBuffer->GetCurrentWriteIndex() < messageLength)
    {
        CopyToLastMessageSource();
        return;
    }

    int32_t fullVersion{ 0 };
    messageSource->Read(fullVersion);
    int64_t timeInMicroseconds{ 0 };
    messageSource->Read(timeInMicroseconds);

    while (messageSource->GetBytesRead() < messageSource->GetBytesTotal() && messageSource->GetBytesRead() < messageLength)
    {
        ReadMessage(messageSource, fullVersion);
    }

    m_LastMessageBuffer.reset();
}

void Network::BufferReceiveStreamImpl::ReadMessage(const MessageSourceSharedPtr& messageSource, int fullVersion)
{
    // 读取类型
    int64_t messageType{ 0 };
    messageSource->Read(messageType);

    try
    {
        auto process = messageSource;

        auto factory = MESSAGE_MANAGER_SINGLETON.Find(messageType, fullVersion);

        if (factory != nullptr)
        {
            // 从源缓冲器加载该对象。
            const auto message = (*factory)(process, messageType);

            m_TopLevel.Insert(message);
        }
    }
    catch (const CoreTools::Error& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, Network)
            << error
            << SYSTEM_TEXT("（")
            << messageType
            << SYSTEM_TEXT("）")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

// private
void Network::BufferReceiveStreamImpl::SpliceMessageSource(const MessageBufferSharedPtr& messageBuffer)
{
    if (m_LastMessageBuffer)
    {
        const auto messageLength = m_LastMessageBuffer->GetMessageLength();

        if (messageLength < messageBuffer->GetCurrentWriteIndex() + m_LastMessageBuffer->GetCurrentWriteIndex())
        {
            THROW_EXCEPTION(SYSTEM_TEXT("消息长度读取错误！"s));
        }

        m_LastMessageBuffer->PushBack(*messageBuffer);
    }
    else
    {
        m_LastMessageBuffer = messageBuffer;
    }
}

// private
void Network::BufferReceiveStreamImpl::CopyToLastMessageSource()
{
    const auto messageLength = m_LastMessageBuffer->GetMessageLength();
    if (m_LastMessageBuffer->GetSize() < messageLength)
    {
        m_LastMessageBuffer = m_LastMessageBuffer->Expansion(messageLength);
    }

    m_LastMessageBuffer->ClearCurrentReadIndex();
}

CLASS_INVARIANT_STUB_DEFINE(Network, BufferReceiveStreamImpl)

void Network::BufferReceiveStreamImpl::OnEvent(uint64_t socketID, const SocketManagerSharedPtr& socketManager)
{
    auto process = socketManager;

    for (const auto& value : m_TopLevel)
    {
        process->OnEvent(socketID, value->GetMessageID(), value);
    }
}

bool Network::BufferReceiveStreamImpl::IsFinish() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (m_LastMessageBuffer)
        return false;
    else
        return true;
}

void Network::BufferReceiveStreamImpl::PushBack(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    AnalysisBuffer(messageBuffer);
}
