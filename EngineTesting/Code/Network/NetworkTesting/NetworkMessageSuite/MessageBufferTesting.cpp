///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/12 14:55)

#include "MessageBufferTesting.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"

Network::MessageBufferTesting::MessageBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }, testMessage{ std::make_shared<TestNullMessage>(messageId) }
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

void Network::MessageBufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);

    constexpr auto segment = 100;

    const auto aTestLoopCount = GetTestLoopCount();
    auto remainderLoopCount = aTestLoopCount;
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

void Network::MessageBufferTesting::LoopTest(int aTestLoopCount)
{
    ASSERT_NOT_THROW_EXCEPTION_2(PushBackTest, aTestLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(PushBackTest, aTestLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(ExpansionTest, aTestLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(ExpansionTest, aTestLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(CloneTest, aTestLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(CloneTest, aTestLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(ReadTest, aTestLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(ReadTest, aTestLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(BufferedTest, aTestLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(BufferedTest, aTestLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(LengthTest, aTestLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(LengthTest, aTestLoopCount, ParserStrategy::BigEndian);
}

void Network::MessageBufferTesting::InitTest()
{
    const TestingType messageBuffer0{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    ASSERT_ENUM_EQUAL(messageBuffer0.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_EQUAL(messageBuffer0.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size256));

    const TestingType messageBuffer1{ BuffBlockSize::Size512, ParserStrategy::BigEndian };
    ASSERT_ENUM_EQUAL(messageBuffer1.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(messageBuffer1.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size512));

    const TestingType messageBuffer2{ BuffBlockSize::Size1024, ParserStrategy::LittleEndian };
    ASSERT_ENUM_EQUAL(messageBuffer2.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_EQUAL(messageBuffer2.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size1024));

    const TestingType messageBuffer3{ BuffBlockSize::Size2048, ParserStrategy::BigEndian };
    ASSERT_ENUM_EQUAL(messageBuffer3.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(messageBuffer3.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size2048));

    const TestingType messageBuffer4{ BuffBlockSize::Size4096, ParserStrategy::LittleEndian };
    ASSERT_ENUM_EQUAL(messageBuffer4.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_EQUAL(messageBuffer4.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size4096));

    const TestingType messageBuffer5{ BuffBlockSize::Size8K, ParserStrategy::BigEndian };
    ASSERT_ENUM_EQUAL(messageBuffer5.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(messageBuffer5.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size8K));

    const TestingType messageBuffer6{ BuffBlockSize::Size16K, ParserStrategy::LittleEndian };
    ASSERT_ENUM_EQUAL(messageBuffer6.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_EQUAL(messageBuffer6.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size16K));

    const TestingType messageBuffer7{ BuffBlockSize::Size32K, ParserStrategy::BigEndian };
    ASSERT_ENUM_EQUAL(messageBuffer7.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(messageBuffer7.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size32K));

    const TestingType messageBuffer8{ BuffBlockSize::Size64K, ParserStrategy::LittleEndian };
    ASSERT_ENUM_EQUAL(messageBuffer8.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_EQUAL(messageBuffer8.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size64K));

    const TestingType messageBuffer9{ BuffBlockSize::Size128K, ParserStrategy::BigEndian };
    ASSERT_ENUM_EQUAL(messageBuffer9.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(messageBuffer9.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size128K));

    const TestingType messageBuffer10{ BuffBlockSize::Size256K, ParserStrategy::LittleEndian };
    ASSERT_ENUM_EQUAL(messageBuffer10.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_EQUAL(messageBuffer10.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size256K));

    const TestingType messageBuffer11{ BuffBlockSize::Size512K, 0, ParserStrategy::BigEndian };
    ASSERT_ENUM_EQUAL(messageBuffer11.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(messageBuffer11.GetSize(), System::EnumCastUnderlying(BuffBlockSize::Size512K));

    constexpr auto size = 256;
    const TestingType messageBuffer12{ BuffBlockSize::Automatic, size, ParserStrategy::LittleEndian };
    ASSERT_ENUM_EQUAL(messageBuffer12.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_EQUAL(messageBuffer12.GetSize(), size);

    const TestingType messageBuffer13{ size * 2, ParserStrategy::BigEndian };
    ASSERT_ENUM_EQUAL(messageBuffer13.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(messageBuffer13.GetSize(), size * 2);

    const TestingType messageBuffer14{ messageBuffer13 };
    ASSERT_ENUM_EQUAL(messageBuffer14.GetParserStrategy(), messageBuffer13.GetParserStrategy());
    ASSERT_EQUAL(messageBuffer14.GetSize(), messageBuffer13.GetSize());
}

void Network::MessageBufferTesting::PushBackTest(int aTestLoopCount, ParserStrategy parserStrategy)
{
    const auto buffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);

    AddBufferLength(aTestLoopCount, *buffer);
    const auto currentWriteIndex = buffer->GetCurrentWriteIndex();

    const auto addBuffer = CreateAddMessageBuffer(aTestLoopCount, parserStrategy);
    const auto addBufferCurrentWriteIndex = addBuffer->GetCurrentWriteIndex();

    buffer->PushBack(*addBuffer);

    ASSERT_EQUAL(buffer->GetCurrentWriteIndex(), currentWriteIndex + addBufferCurrentWriteIndex);
}

void Network::MessageBufferTesting::ExpansionTest(int aTestLoopCount, ParserStrategy parserStrategy)
{
    const auto buffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);

    constexpr auto expansionSize = 4096;
    constexpr auto stepping = 20;
    constexpr auto receiveCount = 30;
    buffer->AddCurrentReadIndex(stepping);
    buffer->SetReceiveCount(receiveCount);

    const auto expansionBuffer = buffer->Expansion(expansionSize);

    ASSERT_EQUAL(buffer->GetReceiveCount(), expansionBuffer->GetReceiveCount());
    ASSERT_EQUAL(buffer->GetCurrentReadIndex(), expansionBuffer->GetCurrentReadIndex());
    ASSERT_EQUAL(buffer->GetCurrentWriteIndex(), expansionBuffer->GetCurrentWriteIndex());
    ASSERT_EQUAL(expansionBuffer->GetSize(), expansionSize);

    buffer->ClearCurrentIndex();

    ASSERT_UNEQUAL(buffer->GetReceiveCount(), expansionBuffer->GetReceiveCount());
    ASSERT_UNEQUAL(buffer->GetCurrentReadIndex(), expansionBuffer->GetCurrentReadIndex());
    ASSERT_UNEQUAL(buffer->GetCurrentWriteIndex(), expansionBuffer->GetCurrentWriteIndex());
}

void Network::MessageBufferTesting::ExpansionExceptionTest(ParserStrategy parserStrategy)
{
    constexpr auto aTestLoopCount = 100;

    const auto buffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);
    constexpr auto expansionSize = 1024;

    auto expansionBuffer = buffer->Expansion(expansionSize);
}

void Network::MessageBufferTesting::CloneTest(int aTestLoopCount, ParserStrategy parserStrategy)
{
    const auto buffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);

    constexpr auto stepping = 20;
    constexpr auto receiveCount = 30;
    buffer->AddCurrentReadIndex(stepping);
    buffer->SetReceiveCount(receiveCount);

    const auto cloneBuffer = buffer->Clone();

    ASSERT_EQUAL(buffer->GetReceiveCount(), cloneBuffer->GetReceiveCount());
    ASSERT_EQUAL(buffer->GetCurrentReadIndex(), cloneBuffer->GetCurrentReadIndex());
    ASSERT_EQUAL(buffer->GetCurrentWriteIndex(), cloneBuffer->GetCurrentWriteIndex());
    ASSERT_EQUAL(buffer->GetSize(), cloneBuffer->GetSize());

    buffer->ClearCurrentIndex();

    ASSERT_UNEQUAL(buffer->GetReceiveCount(), cloneBuffer->GetReceiveCount());
    ASSERT_UNEQUAL(buffer->GetCurrentReadIndex(), cloneBuffer->GetCurrentReadIndex());
    ASSERT_UNEQUAL(buffer->GetCurrentWriteIndex(), cloneBuffer->GetCurrentWriteIndex());
}

void Network::MessageBufferTesting::ReadTest(int aTestLoopCount, ParserStrategy parserStrategy)
{
    constexpr auto stepping = 20;

    const auto buffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);

    ASSERT_EQUAL(buffer->GetCurrentReadIndex(), 0);
    ASSERT_EQUAL(buffer->GetRemainingReadCount(), buffer->GetCurrentWriteIndex());

    buffer->AddCurrentReadIndex(stepping);
    ASSERT_EQUAL(buffer->GetCurrentReadIndex(), stepping);
    ASSERT_EQUAL(buffer->GetRemainingReadCount(), buffer->GetCurrentWriteIndex() - stepping);

    buffer->ClearCurrentReadIndex();
    ASSERT_EQUAL(buffer->GetCurrentReadIndex(), 0);
    ASSERT_EQUAL(buffer->GetRemainingReadCount(), buffer->GetCurrentWriteIndex());

    int32_t messageLength{ 0 };

    buffer->Read(CoreTools::GetStreamSize(messageLength), &messageLength);
    ASSERT_EQUAL(messageLength, buffer->GetCurrentWriteIndex());

    buffer->ClearCurrentReadIndex();
    messageLength = 0;

    buffer->Read(CoreTools::GetStreamSize(messageLength), 1, &messageLength);
    ASSERT_EQUAL(messageLength, buffer->GetCurrentWriteIndex());
}

void Network::MessageBufferTesting::WriteTest(ParserStrategy parserStrategy)
{
    TestingType buffer{ BuffBlockSize::Size1024, parserStrategy };

    ASSERT_EQUAL(buffer.GetCurrentWriteIndex(), 0);
    ASSERT_EQUAL(buffer.GetRemainingWriteCount(), buffer.GetSize());

    const auto messageLength = boost::numeric_cast<int32_t>(testMessage->GetStreamingSize());
    const auto streamLength = CoreTools::GetStreamSize(messageLength);

    buffer.Write(streamLength, &messageLength);
    ASSERT_EQUAL(streamLength, buffer.GetCurrentWriteIndex());
    ASSERT_EQUAL(buffer.GetRemainingWriteCount(), buffer.GetSize() - streamLength);

    buffer.ClearCurrentWriteIndex();
    ASSERT_EQUAL(buffer.GetCurrentWriteIndex(), 0);
    ASSERT_EQUAL(buffer.GetRemainingWriteCount(), buffer.GetSize());

    buffer.Write(streamLength, 1, &messageLength);
    ASSERT_EQUAL(streamLength, buffer.GetCurrentWriteIndex());
    ASSERT_EQUAL(buffer.GetRemainingWriteCount(), buffer.GetSize() - streamLength);
}

void Network::MessageBufferTesting::BufferedTest(int aTestLoopCount, ParserStrategy parserStrategy)
{
    constexpr auto stepping = 20;
    constexpr auto receiveCount = 10;

    const auto buffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    ASSERT_EQUAL(buffer->GetCurrentReadBufferedPtr(), buffer->GetInitialBufferedPtr());
    ASSERT_EQUAL(buffer->GetCurrentWriteBufferedPtr(), buffer->GetInitialBufferedPtr() + buffer->GetCurrentWriteIndex());

    buffer->AddCurrentReadIndex(stepping);
    ASSERT_EQUAL(buffer->GetCurrentReadBufferedPtr(), buffer->GetInitialBufferedPtr() + stepping);
    ASSERT_EQUAL(buffer->GetCurrentWriteBufferedPtr(), buffer->GetInitialBufferedPtr() + buffer->GetCurrentWriteIndex());

    buffer->ClearCurrentReadIndex();
    ASSERT_EQUAL(buffer->GetCurrentReadBufferedPtr(), buffer->GetInitialBufferedPtr());
    ASSERT_EQUAL(buffer->GetCurrentWriteBufferedPtr(), buffer->GetInitialBufferedPtr() + buffer->GetCurrentWriteIndex());

#include STSTEM_WARNING_POP

    buffer->AddCurrentReadIndex(stepping);
    buffer->SetReceiveCount(receiveCount);
    buffer->ClearCurrentWriteIndex();
    ASSERT_EQUAL(buffer->GetCurrentReadBufferedPtr(), buffer->GetInitialBufferedPtr());
    ASSERT_EQUAL(buffer->GetCurrentWriteBufferedPtr(), buffer->GetInitialBufferedPtr());
    ASSERT_EQUAL(buffer->GetReceiveCount(), receiveCount);
}

void Network::MessageBufferTesting::LengthTest(int aTestLoopCount, ParserStrategy parserStrategy)
{
    const auto buffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);

    ASSERT_EQUAL(buffer->GetMessageLength(), MessageInterface::GetMessageHeadSize() + testMessage->GetStreamingSize() * aTestLoopCount);

    ASSERT_TRUE(buffer->IsMessageReceiveEnd());

    AddBufferLength(aTestLoopCount, *buffer);

    ASSERT_FALSE(buffer->IsMessageReceiveEnd());

    buffer->CheckingMessageHeadSize();
    buffer->CheckingMessageContentSize();
}

void Network::MessageBufferTesting::CheckingMessageHeadSizeExceptionTest(ParserStrategy parserStrategy)
{
    TestingType buffer{ BuffBlockSize::Automatic, MessageInterface::GetMessageHeadSize() - 1, parserStrategy };

    buffer.CheckingMessageHeadSize();
}

void Network::MessageBufferTesting::CheckingMessageContentSizeExceptionTest(ParserStrategy parserStrategy)
{
    constexpr auto loopCount = 100;

    TestingType buffer{ BuffBlockSize::Automatic, MessageInterface::GetMessageHeadSize(), parserStrategy };

    AddBufferLength(loopCount, buffer);

    buffer.CheckingMessageContentSize();
}

Network::MessageBufferSharedPtr Network::MessageBufferTesting::CreateAddMessageBuffer(int aTestLoopCount, ParserStrategy parserStrategy) const
{
    auto messageBuffer = std::make_shared<TestingType>(BuffBlockSize::Size1024, parserStrategy);

    auto initialBuffered = messageBuffer->GetInitialBufferedPtr();

    for (auto i = 0; i < aTestLoopCount; ++i)
    {
        const auto streamSize = CoreTools::GetStreamSize(messageId);
        messageBuffer->AddCurrentWriteIndex(streamSize);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        const auto messageNumber = reinterpret_cast<int64_t*>(initialBuffered);

#include STSTEM_WARNING_POP

        if (messageNumber != nullptr)
        {
            *messageNumber = messageId;

            if (parserStrategy == ParserStrategy::BigEndian)
            {
                CoreTools::Endian::SwapByteOrder(streamSize, messageNumber);
            }
        }

        initialBuffered = messageBuffer->GetCurrentWriteBufferedPtr();
    }

    return messageBuffer;
}

void Network::MessageBufferTesting::AddBufferLength(int aTestLoopCount, MessageBuffer& messageBuffer)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto& length = *reinterpret_cast<int32_t*>(messageBuffer.GetInitialBufferedPtr());

#include STSTEM_WARNING_POP

    const auto streamSize = CoreTools::GetStreamSize(length);

    if (messageBuffer.GetParserStrategy() == ParserStrategy::BigEndian)
    {
        CoreTools::Endian::SwapByteOrder(streamSize, &length);
    }

    length += testMessage->GetStreamingSize() * aTestLoopCount;

    if (messageBuffer.GetParserStrategy() == ParserStrategy::BigEndian)
    {
        CoreTools::Endian::SwapByteOrder(streamSize, &length);
    }
}

Network::MessageBufferSharedPtr Network::MessageBufferTesting::CreateSendMessageBuffer(int aTestLoopCount, ParserStrategy parserStrategy)
{
    BufferSendStream bufferSendStream{ bufferSize, parserStrategy, EncryptedCompressionStrategy::Default };

    for (auto i = 0; i < aTestLoopCount; ++i)
    {
        ASSERT_TRUE(bufferSendStream.Insert(testMessage));
    }

    auto buffer = std::make_shared<TestingType>(BuffBlockSize::Size2048, parserStrategy);

    bufferSendStream.Save(buffer);

    return buffer;
}
