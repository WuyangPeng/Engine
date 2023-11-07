///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:40)

#include "BufferSendStreamTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"

Network::BufferSendStreamTesting::BufferSendStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }, testMessage{ std::make_shared<TestNullMessage>(messageId) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BufferSendStreamTesting)

void Network::BufferSendStreamTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BufferSendStreamTesting::MainTest()
{
    constexpr auto segment = 100;

    const auto actualTestLoopCount = GetTestLoopCount() / segment;
    auto remainder = GetTestLoopCount() % segment;

    ASSERT_NOT_THROW_EXCEPTION_1(SendTest, remainder);

    for (auto i = 0; i < actualTestLoopCount; ++i)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(SendTest, segment);
    }
}

void Network::BufferSendStreamTesting::SendTest(int aTestLoopCount)
{
    ASSERT_NOT_THROW_EXCEPTION_2(FinishSendTest, aTestLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(FinishSendTest, aTestLoopCount, ParserStrategy::BigEndian);
}

void Network::BufferSendStreamTesting::FinishSendTest(int aTestLoopCount, ParserStrategy parserStrategy)
{
    BufferSendStream bufferSendStream{ bufferSize, parserStrategy, EncryptedCompressionStrategy::Default };

    ASSERT_EQUAL(bufferSendStream.GetCurrentSize(), MessageInterface::GetMessageHeadSize());
    ASSERT_TRUE(bufferSendStream.IsEmpty());

    for (auto i = 0; i < aTestLoopCount; ++i)
    {
        MAYBE_UNUSED const auto result = bufferSendStream.Insert(testMessage);
    }

    ASSERT_FALSE(bufferSendStream.IsEmpty());
    ASSERT_LESS(MessageInterface::GetMessageHeadSize(), bufferSendStream.GetCurrentSize());
    ASSERT_EQUAL(MessageInterface::GetMessageHeadSize() + testMessage->GetStreamingSize() * aTestLoopCount, bufferSendStream.GetCurrentSize());

    const auto buffer = std::make_shared<MessageBuffer>(BuffBlockSize::Size1024, parserStrategy);

    bufferSendStream.Save(buffer);

    ASSERT_EQUAL(buffer->GetCurrentWriteIndex(), bufferSendStream.GetCurrentSize());

    bufferSendStream.Clear();

    ASSERT_EQUAL(bufferSendStream.GetCurrentSize(), MessageInterface::GetMessageHeadSize());
    ASSERT_TRUE(bufferSendStream.IsEmpty());
}
