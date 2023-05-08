///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 15:49)

#include "BufferReceiveStreamTesting.h"
#include "Detail/NullSocketManager.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/BufferReceiveStream.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
using std::make_shared;
using std::ostream;

Network::BufferReceiveStreamTesting::BufferReceiveStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }, testMessage{ make_shared<TestNullMessage>(messageID) }, socketID{ 1 }
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

void Network::BufferReceiveStreamTesting::MainTest()
{
    MESSAGE_MANAGER_SINGLETON.Insert(messageID, MessageTypeCondition::CreateNullCondition(), TestNullMessage::Factory);

    constexpr auto segment = 100;

    const auto aTestLoopCount = GetTestLoopCount();
    auto remainderLoopCount = aTestLoopCount;
    auto currentLoopCount = 1;
    while (0 < remainderLoopCount)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(ReceiveTest, currentLoopCount);
        remainderLoopCount -= currentLoopCount;
        ++currentLoopCount;
    }

    MESSAGE_MANAGER_SINGLETON.Remove(messageID);
}

void Network::BufferReceiveStreamTesting::ReceiveTest(int aTestLoopCount)
{
    ASSERT_NOT_THROW_EXCEPTION_2(FinishReceiveTest, aTestLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(FinishReceiveTest, aTestLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(UnFinishReceiveTest, aTestLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(UnFinishReceiveTest, aTestLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(CopyFinishReceiveTest, aTestLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(CopyFinishReceiveTest, aTestLoopCount, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(CopyUnFinishReceiveTest, aTestLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(CopyUnFinishReceiveTest, aTestLoopCount, ParserStrategy::BigEndian);
}

void Network::BufferReceiveStreamTesting::FinishReceiveTest(int aTestLoopCount, ParserStrategy parserStrategy)
{
    auto buffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
    auto socketManager = make_shared<NullSocketManager>(messageID);
#include STSTEM_WARNING_POP
   // socketManager->InsertSocket(socketID);
    ASSERT_EQUAL(socketManager->GetValue(), 0);

    TestingType bufferReceiveStream{ buffer, parserStrategy, EncryptedCompressionStrategy::Default };

    ASSERT_TRUE(bufferReceiveStream.IsFinish());

  //  bufferReceiveStream.OnEvent(socketID, *socketManager);

    ASSERT_EQUAL(socketManager->GetValue(), messageID * aTestLoopCount);
}

void Network::BufferReceiveStreamTesting::UnFinishReceiveTest(int aTestLoopCount, ParserStrategy parserStrategy)
{
    auto buffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);

    AddBufferLength(*buffer);
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
    auto socketManager = make_shared<NullSocketManager>(messageID);
  //  socketManager->InsertSocket(socketID);
    ASSERT_EQUAL(socketManager->GetValue(), 0);
#include STSTEM_WARNING_POP
    TestingType bufferReceiveStream{ buffer, parserStrategy, EncryptedCompressionStrategy::Default };

    ASSERT_FALSE(bufferReceiveStream.IsFinish());

    bufferReceiveStream.PushBack(CreateAddMessageBuffer(parserStrategy));

    ASSERT_TRUE(bufferReceiveStream.IsFinish());

 //   bufferReceiveStream.OnEvent(socketID, *socketManager);

    const auto receiveCount = aTestLoopCount + 1;
    ASSERT_EQUAL(socketManager->GetValue(), messageID * receiveCount);
}

void Network::BufferReceiveStreamTesting::CopyFinishReceiveTest(int aTestLoopCount, ParserStrategy parserStrategy)
{
    auto buffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
    auto socketManager = make_shared<NullSocketManager>(messageID);
#include STSTEM_WARNING_POP
   // socketManager->InsertSocket(socketID);
    ASSERT_EQUAL(socketManager->GetValue(), 0);

    TestingType bufferReceiveStream{ buffer, parserStrategy, EncryptedCompressionStrategy::Default };

    ASSERT_TRUE(bufferReceiveStream.IsFinish());

    TestingType copyBufferReceiveStream{ bufferReceiveStream };

    ASSERT_TRUE(copyBufferReceiveStream.IsFinish());

  //  copyBufferReceiveStream.OnEvent(socketID, *socketManager);

    ASSERT_EQUAL(socketManager->GetValue(), messageID * aTestLoopCount);
}

void Network::BufferReceiveStreamTesting::CopyUnFinishReceiveTest(int aTestLoopCount, ParserStrategy parserStrategy)
{
    auto buffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);

    AddBufferLength(*buffer);
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
    auto socketManager = make_shared<NullSocketManager>(messageID);
#include STSTEM_WARNING_POP
   // socketManager->InsertSocket(socketID);
    ASSERT_EQUAL(socketManager->GetValue(), 0);

    TestingType bufferReceiveStream{ buffer, parserStrategy, EncryptedCompressionStrategy::Default };

    ASSERT_FALSE(bufferReceiveStream.IsFinish());

    auto noUseBuffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);

    TestingType copyBufferReceiveStream{ noUseBuffer, parserStrategy, EncryptedCompressionStrategy::Default };
    copyBufferReceiveStream = bufferReceiveStream;

    ASSERT_FALSE(copyBufferReceiveStream.IsFinish());

    copyBufferReceiveStream.PushBack(CreateAddMessageBuffer(parserStrategy));

    ASSERT_FALSE(bufferReceiveStream.IsFinish());
    ASSERT_TRUE(copyBufferReceiveStream.IsFinish());

    //copyBufferReceiveStream.OnEvent(socketID, *socketManager);

    const auto receiveCount = aTestLoopCount + 1;
    ASSERT_EQUAL(socketManager->GetValue(), messageID * receiveCount);
}

Network::MessageBufferSharedPtr Network::BufferReceiveStreamTesting::CreateAddMessageBuffer(ParserStrategy parserStrategy) const
{
    auto messageBuffer = make_shared<MessageBuffer>(BuffBlockSize::Size256, parserStrategy);

    auto initialBuffered = messageBuffer->GetInitialBufferedPtr();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto messageNumber = reinterpret_cast<int64_t*>(initialBuffered);

#include STSTEM_WARNING_POP

    if (messageNumber == nullptr)
        return messageBuffer;

    *messageNumber = messageID;

    const auto streamSize = CoreTools::GetStreamSize(messageID);

    if (parserStrategy == ParserStrategy::BigEndian)
    {
        CoreTools::Endian::SwapByteOrder(streamSize, messageNumber);
    }

    messageBuffer->AddCurrentWriteIndex(streamSize);

    return messageBuffer;
}

Network::MessageBufferSharedPtr Network::BufferReceiveStreamTesting::CreateSendMessageBuffer(int aTestLoopCount, ParserStrategy parserStrategy) const
{
    BufferSendStream bufferSendStream{ bufferSize, parserStrategy, EncryptedCompressionStrategy::Default };

    for (auto i = 0; i < aTestLoopCount; ++i)
    {
        MAYBE_UNUSED auto value = bufferSendStream.Insert(testMessage);
    }

    auto buffer = make_shared<MessageBuffer>(BuffBlockSize::Size1024, parserStrategy);

    bufferSendStream.Save(buffer);

    return buffer;
}

void Network::BufferReceiveStreamTesting::AddBufferLength(MessageBuffer& messageBuffer)
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

    length += testMessage->GetStreamingSize();

    if (messageBuffer.GetParserStrategy() == ParserStrategy::BigEndian)
    {
        CoreTools::Endian::SwapByteOrder(streamSize, &length);
    }
}
