// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 13:50)

#include "MessageBufferTesting.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"

using std::make_shared;
using std::ostream;

Network::MessageBufferTesting ::MessageBufferTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_TestMessage{ make_shared<TestNullMessage>(sm_MessageID) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageBufferTesting)
void Network::MessageBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = MessageBuffer;
    using TestingTypeSharedPtr = MessageBufferSharedPtr;
}

void Network::MessageBufferTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);

    constexpr auto segment = 100;

    const auto testLoopCount = GetTestLoopCount();
    auto remainderLoopCount = testLoopCount;
    auto currentLoopCount = 1;
    while (0 < remainderLoopCount)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(LoopTest, currentLoopCount);
        remainderLoopCount -= currentLoopCount;
        ++currentLoopCount;
    }

    ASSERT_THROW_EXCEPTION_1(ExpansionExceptionTest, ParserStrategy::LittleEndian);
    ASSERT_THROW_EXCEPTION_1(ExpansionExceptionTest, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_1(WriteTest, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_1(WriteTest, ParserStrategy::BigEndian);
    ASSERT_THROW_EXCEPTION_1(CheckingMessageHeadSizeExceptionTest, ParserStrategy::LittleEndian);
    ASSERT_THROW_EXCEPTION_1(CheckingMessageHeadSizeExceptionTest, ParserStrategy::BigEndian);
    ASSERT_THROW_EXCEPTION_1(CheckingMessageContentSizeExceptionTest, ParserStrategy::LittleEndian);
    ASSERT_THROW_EXCEPTION_1(CheckingMessageContentSizeExceptionTest, ParserStrategy::BigEndian);
}

void Network::MessageBufferTesting ::LoopTest(int testLoopCount)
{
    ASSERT_NOT_THROW_EXCEPTION_2(PushBackTest, testLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(PushBackTest, testLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(ExpansionTest, testLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(ExpansionTest, testLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(CloneTest, testLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(CloneTest, testLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(ReadTest, testLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(ReadTest, testLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(BufferedTest, testLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(BufferedTest, testLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(LengthTest, testLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(LengthTest, testLoopCount, ParserStrategy::BigEndian);
}

void Network::MessageBufferTesting ::InitTest()
{
    TestingType messageBuffer1{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    ASSERT_ENUM_EQUAL(messageBuffer1.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_EQUAL(messageBuffer1.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size256));

    TestingType messageBuffer2{ BuffBlockSize::Size512, ParserStrategy::BigEndian };
    ASSERT_ENUM_EQUAL(messageBuffer2.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(messageBuffer2.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size512));

    TestingType messageBuffer3{ BuffBlockSize::Size1024, ParserStrategy::LittleEndian };
    ASSERT_ENUM_EQUAL(messageBuffer3.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_EQUAL(messageBuffer3.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size1024));

    TestingType messageBuffer4{ BuffBlockSize::Size2048, ParserStrategy::BigEndian };
    ASSERT_ENUM_EQUAL(messageBuffer4.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(messageBuffer4.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size2048));

    TestingType messageBuffer5{ BuffBlockSize::Size4096, ParserStrategy::LittleEndian };
    ASSERT_ENUM_EQUAL(messageBuffer5.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_EQUAL(messageBuffer5.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size4096));

    TestingType messageBuffer6{ BuffBlockSize::Size8K, ParserStrategy::BigEndian };
    ASSERT_ENUM_EQUAL(messageBuffer6.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(messageBuffer6.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size8K));

    TestingType messageBuffer7{ BuffBlockSize::Size16K, ParserStrategy::LittleEndian };
    ASSERT_ENUM_EQUAL(messageBuffer7.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_EQUAL(messageBuffer7.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size16K));

    TestingType messageBuffer8{ BuffBlockSize::Size32K, ParserStrategy::BigEndian };
    ASSERT_ENUM_EQUAL(messageBuffer8.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(messageBuffer8.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size32K));

    TestingType messageBuffer9{ BuffBlockSize::Size64K, ParserStrategy::LittleEndian };
    ASSERT_ENUM_EQUAL(messageBuffer9.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_EQUAL(messageBuffer9.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size64K));

    TestingType messageBuffer10{ BuffBlockSize::Size128K, ParserStrategy::BigEndian };
    ASSERT_ENUM_EQUAL(messageBuffer10.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(messageBuffer10.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size128K));

    TestingType messageBuffer11{ BuffBlockSize::Size256K, ParserStrategy::LittleEndian };
    ASSERT_ENUM_EQUAL(messageBuffer11.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_EQUAL(messageBuffer11.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size256K));

    TestingType messageBuffer12{ BuffBlockSize::Size512K, 0, ParserStrategy::BigEndian };
    ASSERT_ENUM_EQUAL(messageBuffer12.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(messageBuffer12.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size512K));

    constexpr auto bufferSize = 256;
    TestingType messageBuffer13{ BuffBlockSize::Automatic, bufferSize, ParserStrategy::LittleEndian };
    ASSERT_ENUM_EQUAL(messageBuffer13.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_EQUAL(messageBuffer13.GetSize(), bufferSize);

    TestingType messageBuffer14{ bufferSize * 2, ParserStrategy::BigEndian };
    ASSERT_ENUM_EQUAL(messageBuffer14.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(messageBuffer14.GetSize(), bufferSize * 2);

    TestingType messageBuffer15{ messageBuffer14 };
    ASSERT_ENUM_EQUAL(messageBuffer15.GetParserStrategy(), messageBuffer14.GetParserStrategy());
    ASSERT_EQUAL(messageBuffer15.GetSize(), messageBuffer14.GetSize());
}

void Network::MessageBufferTesting ::PushBackTest(int testLoopCount, ParserStrategy parserStrategy)
{
    auto buffer = CreateSendMessageBuffer(testLoopCount, parserStrategy);

    AddBufferLength(testLoopCount, buffer);
    auto currentWriteIndex = buffer->GetCurrentWriteIndex();

    auto addBuffer = CreateAddMessageBuffer(testLoopCount, parserStrategy);
    auto addBufferCurrentWriteIndex = addBuffer->GetCurrentWriteIndex();

    buffer->PushBack(*addBuffer);

    ASSERT_EQUAL(buffer->GetCurrentWriteIndex(), currentWriteIndex + addBufferCurrentWriteIndex);
}

void Network::MessageBufferTesting ::ExpansionTest(int testLoopCount, ParserStrategy parserStrategy)
{
    auto buffer = CreateSendMessageBuffer(testLoopCount, parserStrategy);
    constexpr auto expansionSize = 4096;
    constexpr auto stepping = 20;
    constexpr auto receiveCount = 30;
    buffer->AddCurrentReadIndex(stepping);
    buffer->SetReceiveCount(receiveCount);

    auto expansionBuffer = buffer->Expansion(expansionSize);

    ASSERT_EQUAL(buffer->GetReceiveCount(), expansionBuffer->GetReceiveCount());
    ASSERT_EQUAL(buffer->GetCurrentReadIndex(), expansionBuffer->GetCurrentReadIndex());
    ASSERT_EQUAL(buffer->GetCurrentWriteIndex(), expansionBuffer->GetCurrentWriteIndex());
    ASSERT_EQUAL(expansionBuffer->GetSize(), expansionSize);

    buffer->ClearCurrentIndex();

    ASSERT_UNEQUAL(buffer->GetReceiveCount(), expansionBuffer->GetReceiveCount());
    ASSERT_UNEQUAL(buffer->GetCurrentReadIndex(), expansionBuffer->GetCurrentReadIndex());
    ASSERT_UNEQUAL(buffer->GetCurrentWriteIndex(), expansionBuffer->GetCurrentWriteIndex());
}

void Network::MessageBufferTesting ::ExpansionExceptionTest(ParserStrategy parserStrategy)
{
    constexpr auto testLoopCount = 100;

    auto buffer = CreateSendMessageBuffer(testLoopCount, parserStrategy);
    constexpr auto expansionSize = 1024;

    auto expansionBuffer = buffer->Expansion(expansionSize);
}

void Network::MessageBufferTesting ::CloneTest(int testLoopCount, ParserStrategy parserStrategy)
{
    auto buffer = CreateSendMessageBuffer(testLoopCount, parserStrategy);
    constexpr auto stepping = 20;
    constexpr auto receiveCount = 30;
    buffer->AddCurrentReadIndex(stepping);
    buffer->SetReceiveCount(receiveCount);

    auto cloneBuffer = buffer->Clone();

    ASSERT_EQUAL(buffer->GetReceiveCount(), cloneBuffer->GetReceiveCount());
    ASSERT_EQUAL(buffer->GetCurrentReadIndex(), cloneBuffer->GetCurrentReadIndex());
    ASSERT_EQUAL(buffer->GetCurrentWriteIndex(), cloneBuffer->GetCurrentWriteIndex());
    ASSERT_EQUAL(buffer->GetSize(), cloneBuffer->GetSize());

    buffer->ClearCurrentIndex();

    ASSERT_UNEQUAL(buffer->GetReceiveCount(), cloneBuffer->GetReceiveCount());
    ASSERT_UNEQUAL(buffer->GetCurrentReadIndex(), cloneBuffer->GetCurrentReadIndex());
    ASSERT_UNEQUAL(buffer->GetCurrentWriteIndex(), cloneBuffer->GetCurrentWriteIndex());
}

void Network::MessageBufferTesting ::ReadTest(int testLoopCount, ParserStrategy parserStrategy)
{
    constexpr auto stepping = 20;

    auto buffer = CreateSendMessageBuffer(testLoopCount, parserStrategy);

    ASSERT_EQUAL(buffer->GetCurrentReadIndex(), 0);
    ASSERT_EQUAL(buffer->GetRemainingReadCount(), buffer->GetCurrentWriteIndex());

    buffer->AddCurrentReadIndex(stepping);
    ASSERT_EQUAL(buffer->GetCurrentReadIndex(), stepping);
    ASSERT_EQUAL(buffer->GetRemainingReadCount(), buffer->GetCurrentWriteIndex() - stepping);

    buffer->ClearCurrentReadIndex();
    ASSERT_EQUAL(buffer->GetCurrentReadIndex(), 0);
    ASSERT_EQUAL(buffer->GetRemainingReadCount(), buffer->GetCurrentWriteIndex());

    int32_t messageLength{ 0 };

    buffer->Read(CORE_TOOLS_STREAM_SIZE(messageLength), &messageLength);
    ASSERT_EQUAL(messageLength, buffer->GetCurrentWriteIndex());

    buffer->ClearCurrentReadIndex();
    messageLength = 0;

    buffer->Read(CORE_TOOLS_STREAM_SIZE(messageLength), 1, &messageLength);
    ASSERT_EQUAL(messageLength, buffer->GetCurrentWriteIndex());
}

void Network::MessageBufferTesting ::WriteTest(ParserStrategy parserStrategy)
{
    TestingTypeSharedPtr buffer{ make_shared<TestingType>(BuffBlockSize::Size1024, parserStrategy) };

    ASSERT_EQUAL(buffer->GetCurrentWriteIndex(), 0);
    ASSERT_EQUAL(buffer->GetRemainingWriteCount(), buffer->GetSize());

    int32_t messageLength = boost::numeric_cast<int32_t>(m_TestMessage->GetStreamingSize());
    auto streamLength = CORE_TOOLS_STREAM_SIZE(messageLength);

    buffer->Write(streamLength, &messageLength);
    ASSERT_EQUAL(streamLength, buffer->GetCurrentWriteIndex());
    ASSERT_EQUAL(buffer->GetRemainingWriteCount(), buffer->GetSize() - streamLength);

    buffer->ClearCurrentWriteIndex();
    ASSERT_EQUAL(buffer->GetCurrentWriteIndex(), 0);
    ASSERT_EQUAL(buffer->GetRemainingWriteCount(), buffer->GetSize());

    buffer->Write(streamLength, 1, &messageLength);
    ASSERT_EQUAL(streamLength, buffer->GetCurrentWriteIndex());
    ASSERT_EQUAL(buffer->GetRemainingWriteCount(), buffer->GetSize() - streamLength);
}

void Network::MessageBufferTesting ::BufferedTest(int testLoopCount, ParserStrategy parserStrategy)
{
    constexpr auto stepping = 20;
    constexpr auto receiveCount = 10;

    auto buffer = CreateSendMessageBuffer(testLoopCount, parserStrategy);

    ASSERT_EQUAL(buffer->GetCurrentReadBufferedPtr(), buffer->GetInitialBufferedPtr());
    ASSERT_EQUAL(buffer->GetCurrentWriteBufferedPtr(), buffer->GetInitialBufferedPtr() + buffer->GetCurrentWriteIndex());

    buffer->AddCurrentReadIndex(stepping);
    ASSERT_EQUAL(buffer->GetCurrentReadBufferedPtr(), buffer->GetInitialBufferedPtr() + stepping);
    ASSERT_EQUAL(buffer->GetCurrentWriteBufferedPtr(), buffer->GetInitialBufferedPtr() + buffer->GetCurrentWriteIndex());

    buffer->ClearCurrentReadIndex();
    ASSERT_EQUAL(buffer->GetCurrentReadBufferedPtr(), buffer->GetInitialBufferedPtr());
    ASSERT_EQUAL(buffer->GetCurrentWriteBufferedPtr(), buffer->GetInitialBufferedPtr() + buffer->GetCurrentWriteIndex());

    buffer->AddCurrentReadIndex(stepping);
    buffer->SetReceiveCount(receiveCount);
    buffer->ClearCurrentWriteIndex();
    ASSERT_EQUAL(buffer->GetCurrentReadBufferedPtr(), buffer->GetInitialBufferedPtr());
    ASSERT_EQUAL(buffer->GetCurrentWriteBufferedPtr(), buffer->GetInitialBufferedPtr());
    ASSERT_EQUAL(buffer->GetReceiveCount(), receiveCount);
}

void Network::MessageBufferTesting ::LengthTest(int testLoopCount, ParserStrategy parserStrategy)
{
    auto buffer = CreateSendMessageBuffer(testLoopCount, parserStrategy);

    ASSERT_EQUAL(buffer->GetMessageLength(), MessageInterface::GetMessageHeadSize() + m_TestMessage->GetStreamingSize() * testLoopCount);

    ASSERT_TRUE(buffer->IsMessageReceiveEnd());

    AddBufferLength(testLoopCount, buffer);

    ASSERT_FALSE(buffer->IsMessageReceiveEnd());

    buffer->CheckingMessageHeadSize();
    buffer->CheckingMessageContentSize();
}

void Network::MessageBufferTesting ::CheckingMessageHeadSizeExceptionTest(ParserStrategy parserStrategy)
{
    TestingTypeSharedPtr buffer{ make_shared<TestingType>(BuffBlockSize::Automatic, MessageInterface::GetMessageHeadSize() - 1, parserStrategy) };

    buffer->CheckingMessageHeadSize();
}

void Network::MessageBufferTesting ::CheckingMessageContentSizeExceptionTest(ParserStrategy parserStrategy)
{
    constexpr auto testLoopCount = 100;
    TestingTypeSharedPtr buffer{ make_shared<TestingType>(BuffBlockSize::Automatic, MessageInterface::GetMessageHeadSize(), parserStrategy) };
    AddBufferLength(testLoopCount, buffer);

    buffer->CheckingMessageContentSize();
}

Network::MessageBufferSharedPtr Network::MessageBufferTesting ::CreateAddMessageBuffer(int testLoopCount, ParserStrategy parserStrategy) const
{
    TestingTypeSharedPtr messageBuffer{ make_shared<TestingType>(BuffBlockSize::Size1024, parserStrategy) };

    auto initialBuffered = messageBuffer->GetInitialBufferedPtr();

    for (auto i = 0; i < testLoopCount; ++i)
    {
        auto streamSize = CORE_TOOLS_STREAM_SIZE(sm_MessageID);
        messageBuffer->AddCurrentWriteIndex(streamSize);

        auto messageNumber = reinterpret_cast<int64_t*>(initialBuffered);
        *messageNumber = sm_MessageID;

        if (parserStrategy == ParserStrategy::BigEndian)
        {
            CoreTools::Endian::SwapByteOrder(streamSize, messageNumber);
        }

        initialBuffered = messageBuffer->GetCurrentWriteBufferedPtr();
    }

    return messageBuffer;
}

void Network::MessageBufferTesting ::AddBufferLength(int testLoopCount, MessageBufferSharedPtr& messageBuffer)
{
    auto& length = *reinterpret_cast<int32_t*>(messageBuffer->GetInitialBufferedPtr());

    auto streamSize = CORE_TOOLS_STREAM_SIZE(length);

    if (messageBuffer->GetParserStrategy() == ParserStrategy::BigEndian)
    {
        CoreTools::Endian::SwapByteOrder(streamSize, &length);
    }

    length += m_TestMessage->GetStreamingSize() * testLoopCount;

    if (messageBuffer->GetParserStrategy() == ParserStrategy::BigEndian)
    {
        CoreTools::Endian::SwapByteOrder(streamSize, &length);
    }
}

Network::MessageBufferSharedPtr Network::MessageBufferTesting ::CreateSendMessageBuffer(int testLoopCount, ParserStrategy parserStrategy) const
{
    BufferSendStream bufferSendStream{ sm_BufferSize, parserStrategy };

    for (auto i = 0; i < testLoopCount; ++i)
    {
        [[maybe_unused]] auto value = bufferSendStream.Insert(m_TestMessage);
    }

    TestingTypeSharedPtr buffer{ make_shared<TestingType>(BuffBlockSize::Size2048, parserStrategy) };

    bufferSendStream.Save(buffer);

    return buffer;
}
