///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 15:55)

#include "BufferSendStreamTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"

using std::make_shared;
using std::ostream;

Network::BufferSendStreamTesting::BufferSendStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }, testMessage{ make_shared<TestNullMessage>(messageID) }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BufferSendStreamTesting)

void Network::BufferSendStreamTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = BufferSendStream;
}

void Network::BufferSendStreamTesting::MainTest()
{
    constexpr auto segment = 100;

    const auto testLoopCount = GetTestLoopCount();
    const auto actualTestLoopCount = testLoopCount / segment;
    auto remainder = testLoopCount % segment;

    ASSERT_NOT_THROW_EXCEPTION_1(SendTest, remainder);

    for (auto i = 0; i < actualTestLoopCount; ++i)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(SendTest, segment);
    }
}

void Network::BufferSendStreamTesting::SendTest(int testLoopCount)
{
    ASSERT_NOT_THROW_EXCEPTION_2(FinishSendTest, testLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(FinishSendTest, testLoopCount, ParserStrategy::BigEndian);
}

void Network::BufferSendStreamTesting::FinishSendTest(int testLoopCount, ParserStrategy parserStrategy)
{
    TestingType bufferSendStream{ bufferSize, parserStrategy, EncryptedCompressionStrategy::Default };

    ASSERT_EQUAL(bufferSendStream.GetCurrentSize(), MessageInterface::GetMessageHeadSize());
    ASSERT_TRUE(bufferSendStream.IsEmpty());

    for (auto i = 0; i < testLoopCount; ++i)
    {
        MAYBE_UNUSED auto result = bufferSendStream.Insert(testMessage);
    }

    ASSERT_FALSE(bufferSendStream.IsEmpty());
    ASSERT_LESS(MessageInterface::GetMessageHeadSize(), bufferSendStream.GetCurrentSize());
    ASSERT_EQUAL(MessageInterface::GetMessageHeadSize() + testMessage->GetStreamingSize() * testLoopCount, bufferSendStream.GetCurrentSize());

    auto buffer = make_shared<MessageBuffer>(BuffBlockSize::Size1024, parserStrategy);

    bufferSendStream.Save(buffer);

    ASSERT_EQUAL(buffer->GetCurrentWriteIndex(), bufferSendStream.GetCurrentSize());

    bufferSendStream.Clear();

    ASSERT_EQUAL(bufferSendStream.GetCurrentSize(), MessageInterface::GetMessageHeadSize());
    ASSERT_TRUE(bufferSendStream.IsEmpty());
}
