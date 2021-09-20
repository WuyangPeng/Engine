// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 13:26)

#include "BufferSendStreamTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"

using std::make_shared;
using std::ostream;

Network::BufferSendStreamTesting ::BufferSendStreamTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_TestMessage{ make_shared<TestNullMessage>(sm_MessageID) }
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

void Network::BufferSendStreamTesting ::MainTest()
{
    constexpr auto segment = 100;

    const auto testLoopCount = GetTestLoopCount();
    auto actualTestLoopCount = testLoopCount / segment;
    auto remainder = testLoopCount % segment;

    ASSERT_NOT_THROW_EXCEPTION_1(SendTest, remainder);

    for (auto i = 0; i < actualTestLoopCount; ++i)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(SendTest, segment);
    }
}

void Network::BufferSendStreamTesting ::SendTest(int testLoopCount)
{
    ASSERT_NOT_THROW_EXCEPTION_2(FinishSendTest, testLoopCount, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_2(FinishSendTest, testLoopCount, ParserStrategy::BigEndian);
}

void Network::BufferSendStreamTesting ::FinishSendTest(int testLoopCount, ParserStrategy parserStrategy)
{
    TestingType bufferSendStream{ sm_BufferSize, parserStrategy };

    ASSERT_EQUAL(bufferSendStream.GetCurrentSize(), MessageInterface::GetMessageHeadSize());
    ASSERT_TRUE(bufferSendStream.IsEmpty());

    for (auto i = 0; i < testLoopCount; ++i)
    {
        [[maybe_unused]] auto result = bufferSendStream.Insert(m_TestMessage);
    }

    ASSERT_FALSE(bufferSendStream.IsEmpty());
    ASSERT_LESS(MessageInterface::GetMessageHeadSize(), bufferSendStream.GetCurrentSize());
    ASSERT_EQUAL(MessageInterface::GetMessageHeadSize() + m_TestMessage->GetStreamingSize() * testLoopCount, bufferSendStream.GetCurrentSize());

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size1024, parserStrategy) };

    bufferSendStream.Save(buffer);

    ASSERT_EQUAL(buffer->GetCurrentWriteIndex(), bufferSendStream.GetCurrentSize());

    bufferSendStream.Clear();

    ASSERT_EQUAL(bufferSendStream.GetCurrentSize(), MessageInterface::GetMessageHeadSize());
    ASSERT_TRUE(bufferSendStream.IsEmpty());
}
