//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 11:58)

#include "Network/NetworkExport.h"

#include "MessageBufferImpl.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/MessageInterface.h"

Network::MessageBufferImpl::MessageBufferImpl(ParserStrategy parserStrategy) noexcept
    : m_CurrentReadIndex{ 0 }, m_CurrentWriteIndex{ 0 }, m_ReceiveCount{ -1 }, m_ParserStrategy{ parserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageBufferImpl::MessageBufferImpl(const MessageBufferImpl& rhs) noexcept
    : m_CurrentReadIndex{ rhs.m_CurrentReadIndex.operator int() }, m_CurrentWriteIndex{ rhs.m_CurrentWriteIndex.operator int() },
      m_ReceiveCount{ rhs.m_ReceiveCount.operator int() }, m_ParserStrategy{ rhs.m_ParserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageBufferImpl::MessageBufferImpl(MessageBufferImpl&& rhs) noexcept
    : m_CurrentReadIndex{ rhs.m_CurrentReadIndex.operator int() }, m_CurrentWriteIndex{ rhs.m_CurrentWriteIndex.operator int() },
      m_ReceiveCount{ rhs.m_ReceiveCount.operator int() }, m_ParserStrategy{ rhs.m_ParserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
Network::MessageBufferImpl& Network::MessageBufferImpl::operator=(const MessageBufferImpl& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    m_CurrentReadIndex = rhs.m_CurrentReadIndex.operator int();
    m_CurrentWriteIndex = rhs.m_CurrentWriteIndex.operator int();
    m_ReceiveCount = rhs.m_ReceiveCount.operator int();
    m_ParserStrategy = rhs.m_ParserStrategy;

    return *this;
}

Network::MessageBufferImpl& Network::MessageBufferImpl::operator=(MessageBufferImpl&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    m_CurrentReadIndex = rhs.m_CurrentReadIndex.operator int();
    m_CurrentWriteIndex = rhs.m_CurrentWriteIndex.operator int();
    m_ReceiveCount = rhs.m_ReceiveCount.operator int();
    m_ParserStrategy = rhs.m_ParserStrategy;

    return *this;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
bool Network::MessageBufferImpl::IsValid() const noexcept
{
    if (0 <= m_CurrentReadIndex && m_CurrentReadIndex <= m_CurrentWriteIndex)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

int Network::MessageBufferImpl::GetCurrentReadIndex() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return m_CurrentReadIndex;
}

int Network::MessageBufferImpl::GetRemainingReadCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return m_CurrentWriteIndex - m_CurrentReadIndex;
}

void Network::MessageBufferImpl::ClearCurrentReadIndex() noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    m_CurrentReadIndex = 0;
}

void Network::MessageBufferImpl::AddCurrentReadIndex(int stepping)
{
    NETWORK_CLASS_IS_VALID_1;

    if (m_CurrentReadIndex + stepping <= m_CurrentWriteIndex)
    {
        m_CurrentReadIndex += stepping;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("增加读索引越界。"s));
    }
}

int Network::MessageBufferImpl::GetCurrentWriteIndex() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return m_CurrentWriteIndex;
}

void Network::MessageBufferImpl::ClearCurrentWriteIndex() noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    ClearCurrentReadIndex();
    m_CurrentWriteIndex = 0;
}

int Network::MessageBufferImpl::GetRemainingWriteCount() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return GetSize() - m_CurrentWriteIndex;
}

void Network::MessageBufferImpl::AddCurrentWriteIndex(int stepping)
{
    NETWORK_CLASS_IS_VALID_1;

    if (m_CurrentWriteIndex + stepping < GetSize())
    {
        m_CurrentWriteIndex += stepping;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("增加写索引越界。"s));
    }
}

const char* Network::MessageBufferImpl::GetCurrentReadBufferedPtr() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;
    NETWORK_ASSERTION_0(m_CurrentReadIndex < GetSize(), "索引越界");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
    return GetInitialBufferedPtr() + m_CurrentReadIndex;
#include STSTEM_WARNING_POP
}

char* Network::MessageBufferImpl::GetCurrentReadBufferedPtr()
{
    NETWORK_CLASS_IS_VALID_1;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(char*, GetCurrentReadBufferedPtr);
}

const char* Network::MessageBufferImpl::GetCurrentWriteBufferedPtr() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;
    NETWORK_ASSERTION_0(m_CurrentWriteIndex < GetSize(), "索引越界");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
    return GetInitialBufferedPtr() + m_CurrentWriteIndex;
#include STSTEM_WARNING_POP
}

char* Network::MessageBufferImpl::GetCurrentWriteBufferedPtr()
{
    NETWORK_CLASS_IS_VALID_1;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(char*, GetCurrentWriteBufferedPtr);
}

int Network::MessageBufferImpl::GetReceiveCount() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    if (m_ReceiveCount < 0)
        return GetRemainingWriteCount();
    else
        return m_ReceiveCount;
}

void Network::MessageBufferImpl::SetReceiveCount(int receiveCount)
{
    NETWORK_CLASS_IS_VALID_1;

    if (receiveCount == -1)
    {
        m_ReceiveCount = receiveCount;
    }
    else if (m_CurrentWriteIndex + m_ReceiveCount <= GetSize())
    {
        m_ReceiveCount = receiveCount;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("接收数据越界。"s));
    }
}

void Network::MessageBufferImpl::DecreaseReceiveCount(int receiveCount)
{
    if (m_ReceiveCount == -1)
    {
        AddCurrentWriteIndex(receiveCount);
    }
    else if (receiveCount <= m_ReceiveCount)
    {
        m_ReceiveCount -= receiveCount;
        AddCurrentWriteIndex(receiveCount);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("接收数据数量不足。"s));
    }
}

void Network::MessageBufferImpl::ClearCurrentIndex() noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    ClearCurrentWriteIndex();

    if (0 < m_ReceiveCount)
    {
        m_ReceiveCount = 0;
    }
}

int Network::MessageBufferImpl::GetMessageLength() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    if (CoreTools::GetStreamSize<int32_t>() <= GetCurrentWriteIndex())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
        auto totalLength = *reinterpret_cast<const int32_t*>(GetInitialBufferedPtr());
#include STSTEM_WARNING_POP

        // 处理字节序问题
        if (IsNeedSwap())
        {
            CoreTools::Endian::Swap4ByteOrder(&totalLength);
        }

        return totalLength;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无法获取数据长度。"s));
    }
}

bool Network::MessageBufferImpl::IsMessageReceiveEnd() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    if (GetMessageLength() <= GetCurrentWriteIndex())
        return true;
    else
        return false;
}

void Network::MessageBufferImpl::SetMessageHeadReceiveCount()
{
    NETWORK_CLASS_IS_VALID_1;

    constexpr auto headSize = MessageInterface::GetMessageHeadSize();

    SetReceiveCount(headSize);
}

void Network::MessageBufferImpl::CheckingMessageHeadSize()
{
    NETWORK_CLASS_IS_VALID_1;

    if (GetRemainingWriteCount() <= MessageInterface::GetMessageHeadSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("接收消息头容量不足！"s));
    }
}

void Network::MessageBufferImpl::CheckingMessageContentSize()
{
    NETWORK_CLASS_IS_VALID_1;

    const auto bytesTotal = GetRemainingWriteCount();
    const auto totalLength = GetMessageLength();

    if (bytesTotal < totalLength)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("接收数据长度不足！"s));
    }
}

void Network::MessageBufferImpl::SetMessageContentReceiveCount()
{
    NETWORK_CLASS_IS_VALID_1;

    const auto totalLength = GetMessageLength();

    constexpr auto headSize = MessageInterface::GetMessageHeadSize();

    const auto remainLength = totalLength - headSize;

    SetReceiveCount(remainLength);
}

void Network::MessageBufferImpl::Read(int itemSize, void* data)
{
    NETWORK_CLASS_IS_VALID_1;

    Read(itemSize, 1, data);
}

void Network::MessageBufferImpl::Read(int itemSize, int itemsNumber, void* data)
{
    NETWORK_CLASS_IS_VALID_1;

    auto numberToCopy = boost::numeric_cast<int>(itemSize * itemsNumber);

    if (GetRemainingReadCount() < numberToCopy)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("可读取的缓冲区大小不足！"s));
    }

    const auto* const currentReadPtr = GetCurrentReadBufferedPtr();

    System::MemoryCopy(data, currentReadPtr, numberToCopy);

    if (1 < itemSize && IsNeedSwap())
    {
        CoreTools::Endian::SwapByteOrder(itemSize, itemsNumber, data);
    }

    AddCurrentReadIndex(numberToCopy);
}

void Network::MessageBufferImpl::Write(int itemSize, const void* data)
{
    NETWORK_CLASS_IS_VALID_1;

    Write(itemSize, 1, data);
}

void Network::MessageBufferImpl::Write(int itemSize, int itemsNumber, const void* data)
{
    NETWORK_CLASS_IS_VALID_1;

    auto numberToCopy = boost::numeric_cast<int>(itemSize * itemsNumber);

    if (GetSize() < numberToCopy)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("可写入的缓冲区大小不足！"s));
    }

    auto currentWritePtr = GetCurrentWriteBufferedPtr();

    System::MemoryCopy(currentWritePtr, data, numberToCopy);

    if (1 < itemSize && IsNeedSwap())
    {
        CoreTools::Endian::SwapByteOrder(itemSize, itemsNumber, currentWritePtr);
    }

    AddCurrentWriteIndex(numberToCopy);
}

bool Network::MessageBufferImpl::IsNeedSwap() const
{
    if (CoreTools::Endian::IsLittleEndian() && m_ParserStrategy != ParserStrategy::LittleEndian ||
        CoreTools::Endian::IsBigEndian() && m_ParserStrategy != ParserStrategy::BigEndian)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Network::MessageBufferImpl ::PushBack(const ConstImplPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_1;

    auto process = messageBuffer;

    const auto writeIndex = process->GetCurrentWriteIndex();

    if (GetSize() < GetCurrentWriteIndex() + writeIndex)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("缓冲区大小不足！"s));
    }

    System::MemoryCopy(GetCurrentWriteBufferedPtr(), process->GetInitialBufferedPtr(), writeIndex);

    AddCurrentWriteIndex(writeIndex);
}

Network::ParserStrategy Network::MessageBufferImpl::GetParserStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return m_ParserStrategy;
}
