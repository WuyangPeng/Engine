// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 13:25)

#include "BufferReceiveStreamTesting.h"
#include "Detail/NullSocketManager.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/BufferReceiveStream.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"

using std::make_shared;
using std::ostream;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26414)
Network::BufferReceiveStreamTesting ::BufferReceiveStreamTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_TestMessage{ make_shared<TestNullMessage>(sm_MessageID) }, m_SocketID{ 1 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BufferReceiveStreamTesting)
void Network::BufferReceiveStreamTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = BufferReceiveStream;
}

void Network::BufferReceiveStreamTesting ::MainTest()
{
    MESSAGE_MANAGER_SINGLETON.Insert(sm_MessageID, MessageTypeCondition::CreateNullCondition(), TestNullMessage::Factory);

    constexpr auto segment = 100;

    const auto testLoopCount = GetTestLoopCount();
    auto remainderLoopCount = testLoopCount;
    auto currentLoopCount = 1;
    while (0 < remainderLoopCount)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(ReceiveTest, currentLoopCount);
        remainderLoopCount -= currentLoopCount;
        ++currentLoopCount;
    }

    MESSAGE_MANAGER_SINGLETON.Remove(sm_MessageID);
}

void Network::BufferReceiveStreamTesting ::ReceiveTest(int testLoopCount)
{
    ASSERT_NOT_THROW_EXCEPTION_2(FinishReceiveTest, testLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(FinishReceiveTest, testLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(UnFinishReceiveTest, testLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(UnFinishReceiveTest, testLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(CopyFinishReceiveTest, testLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(CopyFinishReceiveTest, testLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(CopyUnFinishReceiveTest, testLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(CopyUnFinishReceiveTest, testLoopCount, ParserStrategy::BigEndian);
}

void Network::BufferReceiveStreamTesting ::FinishReceiveTest(int testLoopCount, ParserStrategy parserStrategy)
{
    auto buffer = CreateSendMessageBuffer(testLoopCount, parserStrategy);

    NullSocketManagerSharedPtr socketManager{ make_shared<NullSocketManager>(sm_MessageID) };
    socketManager->InsertSocket(m_SocketID);
    ASSERT_EQUAL(socketManager->GetValue(), 0);

    TestingType bufferReceiveStream{ buffer, parserStrategy, EncryptedCompressionStrategy::Default };

    ASSERT_TRUE(bufferReceiveStream.IsFinish());

    bufferReceiveStream.OnEvent(m_SocketID, socketManager);

    ASSERT_EQUAL(socketManager->GetValue(), sm_MessageID * testLoopCount);
}

void Network::BufferReceiveStreamTesting ::UnFinishReceiveTest(int testLoopCount, ParserStrategy parserStrategy)
{
    auto buffer = CreateSendMessageBuffer(testLoopCount, parserStrategy);

    AddBufferLength(*buffer);

    NullSocketManagerSharedPtr socketManager{ make_shared<NullSocketManager>(sm_MessageID) };
    socketManager->InsertSocket(m_SocketID);
    ASSERT_EQUAL(socketManager->GetValue(), 0);

    TestingType bufferReceiveStream{ buffer, parserStrategy, EncryptedCompressionStrategy::Default };

    ASSERT_FALSE(bufferReceiveStream.IsFinish());

    bufferReceiveStream.PushBack(CreateAddMessageBuffer(parserStrategy));

    ASSERT_TRUE(bufferReceiveStream.IsFinish());

    bufferReceiveStream.OnEvent(m_SocketID, socketManager);

    const auto receiveCount = testLoopCount + 1;
    ASSERT_EQUAL(socketManager->GetValue(), sm_MessageID * receiveCount);
}

void Network::BufferReceiveStreamTesting ::CopyFinishReceiveTest(int testLoopCount, ParserStrategy parserStrategy)
{
    auto buffer = CreateSendMessageBuffer(testLoopCount, parserStrategy);

    NullSocketManagerSharedPtr socketManager{ make_shared<NullSocketManager>(sm_MessageID) };

    socketManager->InsertSocket(m_SocketID);
    ASSERT_EQUAL(socketManager->GetValue(), 0);

    TestingType bufferReceiveStream{ buffer, parserStrategy, EncryptedCompressionStrategy::Default };

    ASSERT_TRUE(bufferReceiveStream.IsFinish());

    TestingType copyBufferReceiveStream{ bufferReceiveStream };

    ASSERT_TRUE(copyBufferReceiveStream.IsFinish());

    copyBufferReceiveStream.OnEvent(m_SocketID, socketManager);

    ASSERT_EQUAL(socketManager->GetValue(), sm_MessageID * testLoopCount);
}

void Network::BufferReceiveStreamTesting ::CopyUnFinishReceiveTest(int testLoopCount, ParserStrategy parserStrategy)
{
    auto buffer = CreateSendMessageBuffer(testLoopCount, parserStrategy);

    AddBufferLength(*buffer);

    NullSocketManagerSharedPtr socketManager{ make_shared<NullSocketManager>(sm_MessageID) };

    socketManager->InsertSocket(m_SocketID);
    ASSERT_EQUAL(socketManager->GetValue(), 0);

    TestingType bufferReceiveStream{ buffer, parserStrategy, EncryptedCompressionStrategy::Default };

    ASSERT_FALSE(bufferReceiveStream.IsFinish());

    auto noUseBuffer = CreateSendMessageBuffer(testLoopCount, parserStrategy);

    TestingType copyBufferReceiveStream{ noUseBuffer, parserStrategy, EncryptedCompressionStrategy::Default };
    copyBufferReceiveStream = bufferReceiveStream;

    ASSERT_FALSE(copyBufferReceiveStream.IsFinish());

    copyBufferReceiveStream.PushBack(CreateAddMessageBuffer(parserStrategy));

    ASSERT_FALSE(bufferReceiveStream.IsFinish());
    ASSERT_TRUE(copyBufferReceiveStream.IsFinish());

    copyBufferReceiveStream.OnEvent(m_SocketID, socketManager);

    const auto receiveCount = testLoopCount + 1;
    ASSERT_EQUAL(socketManager->GetValue(), sm_MessageID * receiveCount);
}
#include STSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26490)
Network::MessageBufferSharedPtr Network::BufferReceiveStreamTesting ::CreateAddMessageBuffer(ParserStrategy parserStrategy) const
{
    MessageBufferSharedPtr messageBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, parserStrategy) };

    auto initialBuffered = messageBuffer->GetInitialBufferedPtr();

    auto messageNumber = reinterpret_cast<int64_t*>(initialBuffered);
    if (messageNumber == nullptr)
        return messageBuffer;

    *messageNumber = sm_MessageID;

    const auto streamSize = CORE_TOOLS_STREAM_SIZE(sm_MessageID);

    if (parserStrategy == ParserStrategy::BigEndian)
    {
        CoreTools::Endian::SwapByteOrder(streamSize, messageNumber);
    }

    messageBuffer->AddCurrentWriteIndex(streamSize);

    return messageBuffer;
}

Network::MessageBufferSharedPtr Network::BufferReceiveStreamTesting ::CreateSendMessageBuffer(int testLoopCount, ParserStrategy parserStrategy) const
{
    BufferSendStream bufferSendStream{ sm_BufferSize, parserStrategy, EncryptedCompressionStrategy::Default };

    for (auto i = 0; i < testLoopCount; ++i)
    {
        [[maybe_unused]] auto value = bufferSendStream.Insert(m_TestMessage);
    }

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size1024, parserStrategy) };

    bufferSendStream.Save(buffer);

    return buffer;
}

void Network::BufferReceiveStreamTesting ::AddBufferLength(MessageBuffer& messageBuffer)
{
    auto& length = *reinterpret_cast<int32_t*>(messageBuffer.GetInitialBufferedPtr());

    const auto streamSize = CORE_TOOLS_STREAM_SIZE(length);

    if (messageBuffer.GetParserStrategy() == ParserStrategy::BigEndian)
    {
        CoreTools::Endian::SwapByteOrder(streamSize, &length);
    }

    length += m_TestMessage->GetStreamingSize();

    if (messageBuffer.GetParserStrategy() == ParserStrategy::BigEndian)
    {
        CoreTools::Endian::SwapByteOrder(streamSize, &length);
    }
}
