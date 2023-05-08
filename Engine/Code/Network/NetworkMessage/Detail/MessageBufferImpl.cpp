///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/08 11:30)

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
    : currentReadIndex{ 0 }, currentWriteIndex{ 0 }, receiveCount{ -1 }, parserStrategy{ parserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageBufferImpl::MessageBufferImpl(const MessageBufferImpl& rhs) noexcept
    : currentReadIndex{ rhs.currentReadIndex.operator int() },
      currentWriteIndex{ rhs.currentWriteIndex.operator int() },
      receiveCount{ rhs.receiveCount.operator int() },
      parserStrategy{ rhs.parserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageBufferImpl::MessageBufferImpl(MessageBufferImpl&& rhs) noexcept
    : currentReadIndex{ rhs.currentReadIndex.operator int() },
      currentWriteIndex{ rhs.currentWriteIndex.operator int() },
      receiveCount{ rhs.receiveCount.operator int() },
      parserStrategy{ rhs.parserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::MessageBufferImpl& Network::MessageBufferImpl::operator=(const MessageBufferImpl& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    currentReadIndex = rhs.currentReadIndex.operator int();
    currentWriteIndex = rhs.currentWriteIndex.operator int();
    receiveCount = rhs.receiveCount.operator int();
    parserStrategy = rhs.parserStrategy;

    return *this;
}

Network::MessageBufferImpl& Network::MessageBufferImpl::operator=(MessageBufferImpl&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    currentReadIndex = rhs.currentReadIndex.operator int();
    currentWriteIndex = rhs.currentWriteIndex.operator int();
    receiveCount = rhs.receiveCount.operator int();
    parserStrategy = rhs.parserStrategy;

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

bool Network::MessageBufferImpl::IsValid() const noexcept
{
    if (0 <= currentReadIndex && currentReadIndex <= currentWriteIndex)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Network::MessageBufferImpl::GetCurrentReadIndex() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return currentReadIndex;
}

int Network::MessageBufferImpl::GetRemainingReadCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return currentWriteIndex - currentReadIndex;
}

void Network::MessageBufferImpl::ClearCurrentReadIndex() noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    currentReadIndex = 0;
}

void Network::MessageBufferImpl::AddCurrentReadIndex(int stepping)
{
    NETWORK_CLASS_IS_VALID_1;

    if (currentReadIndex + stepping <= currentWriteIndex)
    {
        currentReadIndex += stepping;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("增加读索引越界。"s))
    }
}

int Network::MessageBufferImpl::GetCurrentWriteIndex() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return currentWriteIndex;
}

void Network::MessageBufferImpl::ClearCurrentWriteIndex() noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    ClearCurrentReadIndex();
    currentWriteIndex = 0;
}

int Network::MessageBufferImpl::GetRemainingWriteCount() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return GetSize() - currentWriteIndex;
}

void Network::MessageBufferImpl::AddCurrentWriteIndex(int stepping)
{
    NETWORK_CLASS_IS_VALID_1;

    if (currentWriteIndex + stepping < GetSize())
    {
        currentWriteIndex += stepping;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("增加写索引越界。"s))
    }
}

const char* Network::MessageBufferImpl::GetCurrentReadBufferedPtr() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;
    NETWORK_ASSERTION_0(currentReadIndex < GetSize(), "索引越界");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return GetInitialBufferedPtr() + currentReadIndex;

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
    NETWORK_ASSERTION_0(currentWriteIndex < GetSize(), "索引越界");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return GetInitialBufferedPtr() + currentWriteIndex;

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

    if (receiveCount < 0)
        return GetRemainingWriteCount();
    else
        return receiveCount;
}

void Network::MessageBufferImpl::SetReceiveCount(int aReceiveCount)
{
    NETWORK_CLASS_IS_VALID_1;

    if (aReceiveCount == -1)
    {
        receiveCount = aReceiveCount;
    }
    else if (currentWriteIndex + receiveCount <= GetSize())
    {
        receiveCount = aReceiveCount;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("接收数据越界。"s))
    }
}

void Network::MessageBufferImpl::DecreaseReceiveCount(int aReceiveCount)
{
    if (receiveCount == -1)
    {
        AddCurrentWriteIndex(aReceiveCount);
    }
    else if (aReceiveCount <= receiveCount)
    {
        receiveCount -= aReceiveCount;
        AddCurrentWriteIndex(aReceiveCount);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("接收数据数量不足。"s))
    }
}

void Network::MessageBufferImpl::ClearCurrentIndex() noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    ClearCurrentWriteIndex();

    if (0 < receiveCount)
    {
        receiveCount = 0;
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
        THROW_EXCEPTION(SYSTEM_TEXT("无法获取数据长度。"s))
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
        THROW_EXCEPTION(SYSTEM_TEXT("接收消息头容量不足！"s))
    }
}

void Network::MessageBufferImpl::CheckingMessageContentSize()
{
    NETWORK_CLASS_IS_VALID_1;

    const auto bytesTotal = GetRemainingWriteCount();
    const auto totalLength = GetMessageLength();

    if (bytesTotal < totalLength)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("接收数据长度不足！"s))
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

    const auto numberToCopy = boost::numeric_cast<int>(itemSize * itemsNumber);

    if (GetRemainingReadCount() < numberToCopy)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("可读取的缓冲区大小不足！"s))
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

    const auto numberToCopy = boost::numeric_cast<int>(itemSize * itemsNumber);

    if (GetSize() < numberToCopy)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("可写入的缓冲区大小不足！"s))
    }

    const auto currentWritePtr = GetCurrentWriteBufferedPtr();

    System::MemoryCopy(currentWritePtr, data, numberToCopy);

    if (1 < itemSize && IsNeedSwap())
    {
        CoreTools::Endian::SwapByteOrder(itemSize, itemsNumber, currentWritePtr);
    }

    AddCurrentWriteIndex(numberToCopy);
}

bool Network::MessageBufferImpl::IsNeedSwap() const
{
    if ((CoreTools::Endian::IsLittleEndian() && parserStrategy != ParserStrategy::LittleEndian) ||
        (CoreTools::Endian::IsBigEndian() && parserStrategy != ParserStrategy::BigEndian))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Network::MessageBufferImpl ::PushBack(const MessageBufferImpl& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_1;

    const auto writeIndex = messageBuffer.GetCurrentWriteIndex();

    if (GetSize() < GetCurrentWriteIndex() + writeIndex)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("缓冲区大小不足！"s))
    }

    System::MemoryCopy(GetCurrentWriteBufferedPtr(), messageBuffer.GetInitialBufferedPtr(), writeIndex);

    AddCurrentWriteIndex(writeIndex);
}

Network::ParserStrategy Network::MessageBufferImpl::GetParserStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return parserStrategy;
}
