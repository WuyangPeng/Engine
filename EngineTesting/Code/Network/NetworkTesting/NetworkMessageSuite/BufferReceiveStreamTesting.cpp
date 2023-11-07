///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:37)

#include "BufferReceiveStreamTesting.h"
#include "Detail/TestNetworkMessageEvent.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/FileManager/Endian.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/BufferReceiveStream.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageEventManager.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"

Network::BufferReceiveStreamTesting::BufferReceiveStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }, testMessage{ std::make_shared<TestNullMessage>(messageId) }, socketId{ 1 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BufferReceiveStreamTesting)

void Network::BufferReceiveStreamTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BufferReceiveStreamTesting::MainTest()
{
    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), TestNullMessage::Factory);

    auto remainderLoopCount = GetTestLoopCount();
    auto currentLoopCount = 1;
    while (0 < remainderLoopCount)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(ReceiveTest, currentLoopCount);
        remainderLoopCount -= currentLoopCount;
        ++currentLoopCount;
    }

    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
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
    const auto buffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);

    const auto networkMessageEvent = std::make_shared<TestNetworkMessageEvent>();

    ASSERT_EQUAL(networkMessageEvent->GetValue(), 0);

    BufferReceiveStream bufferReceiveStream{ buffer, parserStrategy, EncryptedCompressionStrategy::Default };

    ASSERT_TRUE(bufferReceiveStream.IsFinish());

    auto messageEventManager = MessageEventManager::Create();
    messageEventManager.Insert(messageId, networkMessageEvent);

    bufferReceiveStream.OnEvent(socketId, messageEventManager);

    ASSERT_EQUAL(networkMessageEvent->GetValue(), messageId * aTestLoopCount);
}

void Network::BufferReceiveStreamTesting::UnFinishReceiveTest(int aTestLoopCount, ParserStrategy parserStrategy)
{
    const auto buffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);

    AddBufferLength(*buffer);

    const auto networkMessageEvent = std::make_shared<TestNetworkMessageEvent>();

    ASSERT_EQUAL(networkMessageEvent->GetValue(), 0);

    BufferReceiveStream bufferReceiveStream{ buffer, parserStrategy, EncryptedCompressionStrategy::Default };

    ASSERT_FALSE(bufferReceiveStream.IsFinish());

    bufferReceiveStream.PushBack(CreateAddMessageBuffer(parserStrategy));

    ASSERT_TRUE(bufferReceiveStream.IsFinish());

    auto messageEventManager = MessageEventManager::Create();
    messageEventManager.Insert(messageId, networkMessageEvent);

    bufferReceiveStream.OnEvent(socketId, messageEventManager);

    const auto receiveCount = aTestLoopCount + 1;
    ASSERT_EQUAL(networkMessageEvent->GetValue(), messageId * receiveCount);
}

void Network::BufferReceiveStreamTesting::CopyFinishReceiveTest(int aTestLoopCount, ParserStrategy parserStrategy)
{
    const auto buffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);

    const auto networkMessageEvent = std::make_shared<TestNetworkMessageEvent>();

    ASSERT_EQUAL(networkMessageEvent->GetValue(), 0);

    const BufferReceiveStream bufferReceiveStream{ buffer, parserStrategy, EncryptedCompressionStrategy::Default };

    ASSERT_TRUE(bufferReceiveStream.IsFinish());

    BufferReceiveStream copyBufferReceiveStream{ bufferReceiveStream };

    ASSERT_TRUE(copyBufferReceiveStream.IsFinish());

    auto messageEventManager = MessageEventManager::Create();
    messageEventManager.Insert(messageId, networkMessageEvent);

    copyBufferReceiveStream.OnEvent(socketId, messageEventManager);

    ASSERT_EQUAL(networkMessageEvent->GetValue(), messageId * aTestLoopCount);
}

void Network::BufferReceiveStreamTesting::CopyUnFinishReceiveTest(int aTestLoopCount, ParserStrategy parserStrategy)
{
    const auto buffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);

    AddBufferLength(*buffer);

    const auto networkMessageEvent = std::make_shared<TestNetworkMessageEvent>();

    ASSERT_EQUAL(networkMessageEvent->GetValue(), 0);

    const BufferReceiveStream bufferReceiveStream{ buffer, parserStrategy, EncryptedCompressionStrategy::Default };

    ASSERT_FALSE(bufferReceiveStream.IsFinish());

    const auto noUseBuffer = CreateSendMessageBuffer(aTestLoopCount, parserStrategy);

    BufferReceiveStream copyBufferReceiveStream{ noUseBuffer, parserStrategy, EncryptedCompressionStrategy::Default };
    copyBufferReceiveStream = bufferReceiveStream;

    ASSERT_FALSE(copyBufferReceiveStream.IsFinish());

    copyBufferReceiveStream.PushBack(CreateAddMessageBuffer(parserStrategy));

    ASSERT_FALSE(bufferReceiveStream.IsFinish());
    ASSERT_TRUE(copyBufferReceiveStream.IsFinish());

    auto messageEventManager = MessageEventManager::Create();
    messageEventManager.Insert(messageId, networkMessageEvent);

    copyBufferReceiveStream.OnEvent(socketId, messageEventManager);

    const auto receiveCount = aTestLoopCount + 1;
    ASSERT_EQUAL(networkMessageEvent->GetValue(), messageId * receiveCount);
}

Network::MessageBufferSharedPtr Network::BufferReceiveStreamTesting::CreateAddMessageBuffer(ParserStrategy parserStrategy) const
{
    auto messageBuffer = std::make_shared<MessageBuffer>(BuffBlockSize::Size256, parserStrategy);

    const auto initialBuffered = messageBuffer->GetInitialBufferedPtr();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto messageNumber = reinterpret_cast<int32_t*>(initialBuffered);

#include SYSTEM_WARNING_POP

    if (messageNumber == nullptr)
    {
        return messageBuffer;
    }

    *messageNumber = System::EnumCastUnderlying(MessageHeadStrategy::Default);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    messageNumber += 1;

#include SYSTEM_WARNING_POP

    *messageNumber = boost::numeric_cast<int32_t>(messageId);

    const auto streamSize = CoreTools::GetStreamSize(messageId);

    if (parserStrategy == ParserStrategy::BigEndian)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        messageNumber = reinterpret_cast<int32_t*>(initialBuffered);

#include SYSTEM_WARNING_POP

        CoreTools::Endian::SwapByteOrder(4, messageNumber);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        messageNumber += 1;

#include SYSTEM_WARNING_POP

        CoreTools::Endian::SwapByteOrder(4, messageNumber);
    }

    messageBuffer->AddCurrentWriteIndex(streamSize);

    return messageBuffer;
}

Network::MessageBufferSharedPtr Network::BufferReceiveStreamTesting::CreateSendMessageBuffer(int aTestLoopCount, ParserStrategy parserStrategy)
{
    BufferSendStream bufferSendStream{ bufferSize, parserStrategy, EncryptedCompressionStrategy::Default };

    for (auto i = 0; i < aTestLoopCount; ++i)
    {
        ASSERT_TRUE(bufferSendStream.Insert(testMessage));
    }

    auto buffer = std::make_shared<MessageBuffer>(BuffBlockSize::Size1024, parserStrategy);

    bufferSendStream.Save(buffer);

    return buffer;
}

void Network::BufferReceiveStreamTesting::AddBufferLength(MessageBuffer& messageBuffer)
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto& length = *reinterpret_cast<int32_t*>(messageBuffer.GetInitialBufferedPtr());

#include SYSTEM_WARNING_POP

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
