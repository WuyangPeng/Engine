// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 14:00)

#include "MessageSourceTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

#include <boost/numeric/conversion/cast.hpp>

using std::array;
using std::make_shared;
using std::ostream;
using std::string;
using std::vector;

const std::string Network::MessageSourceTesting ::sm_StringValue{ "StringValue" };

Network::MessageSourceTesting ::MessageSourceTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_BoolBuffer1{ true, false, true, false, true, false, false, false, true, true },
      m_BoolBuffer2{ false, true, false, true, false, true, false, false, true, true },
      m_ParserStrategyBuffer1{ ParserStrategy::LittleEndian, ParserStrategy::BigEndian, ParserStrategy::LittleEndian, ParserStrategy::BigEndian, ParserStrategy::LittleEndian, ParserStrategy::BigEndian,
                               ParserStrategy::BigEndian, ParserStrategy::LittleEndian, ParserStrategy::LittleEndian, ParserStrategy::BigEndian, ParserStrategy::LittleEndian },
      m_ParserStrategyBuffer2{ ParserStrategy::BigEndian, ParserStrategy::LittleEndian, ParserStrategy::BigEndian, ParserStrategy::LittleEndian, ParserStrategy::BigEndian, ParserStrategy::LittleEndian,
                               ParserStrategy::BigEndian, ParserStrategy::BigEndian, ParserStrategy::LittleEndian, ParserStrategy::LittleEndian, ParserStrategy::BigEndian },
      m_Int16Buffer1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }, m_Int16Buffer2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 },
      m_StringBuffer1{ "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13" }, m_StringBuffer2{ "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13" },
      m_Int32Vector{ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }, m_StringVector{ "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16" }, m_BytesRead{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageSourceTesting)
void Network::MessageSourceTesting::DoRunUnitTest() noexcept
{
    // ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::MessageSourceTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(SourceTest, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_1(SourceTest, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_1(IncrementBytesProcessedTest, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_1(IncrementBytesProcessedTest, ParserStrategy::BigEndian);
}

void Network::MessageSourceTesting ::SourceTest(ParserStrategy parserStrategy)
{
    m_BytesRead = 0;

    auto buffer = CreateTargetMessageBuffer(parserStrategy);

    TestingType messageSource{ buffer };

    ASSERT_EQUAL(messageSource.GetBytesTotal(), buffer->GetCurrentWriteIndex());
    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);

    ReadBoolTest(messageSource);
    ReadEnumTest(parserStrategy, messageSource);
    ReadInt16Test(messageSource);
    ReadStringTest(messageSource);
    ReadVectorTest(messageSource);
}

Network::MessageBufferSharedPtr Network::MessageSourceTesting ::CreateTargetMessageBuffer(ParserStrategy parserStrategy) const
{
    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size1024, parserStrategy) };
    MessageTarget messageTarget{ buffer };

    MessageTargetWriteBool(messageTarget);
    MessageTargetWriteEnum(messageTarget, parserStrategy);
    MessageTargetWriteInt16(messageTarget);
    MessageTargetWriteString(messageTarget);
    MessageTargetWriteVector(messageTarget);

    return buffer;
}

void Network::MessageSourceTesting ::IncrementBytesProcessedTest(ParserStrategy parserStrategy)
{
    auto buffer = CreateTargetMessageBuffer(parserStrategy);

    TestingType messageSource{ buffer };

    constexpr int bytesRead{ 0 };

    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);

    messageSource.IncrementBytesProcessed(10);
    ASSERT_EQUAL(messageSource.GetBytesRead(), 10);
}

void Network::MessageSourceTesting ::MessageTargetWriteBool(MessageTarget& messageTarget) const
{
    messageTarget.WriteBool(sm_BoolValue);

    messageTarget.WriteBoolWithNumber(sm_BoolArraySize, m_BoolBuffer1.data());
    messageTarget.WriteBoolWithoutNumber(sm_BoolArraySize, m_BoolBuffer2.data());
}

void Network::MessageSourceTesting ::MessageTargetWriteEnum(MessageTarget& messageTarget, ParserStrategy parserStrategy) const
{
    messageTarget.WriteEnum(parserStrategy);

    messageTarget.WriteEnumWithNumber(sm_EnumArraySize, m_ParserStrategyBuffer1.data());
    messageTarget.WriteEnumWithoutNumber(sm_EnumArraySize, m_ParserStrategyBuffer2.data());
}

void Network::MessageSourceTesting ::MessageTargetWriteInt16(MessageTarget& messageTarget) const
{
    messageTarget.Write(sm_Int16Value);

    messageTarget.WriteWithNumber(sm_Int16ArraySize, m_Int16Buffer1.data());
    messageTarget.WriteWithoutNumber(sm_Int16ArraySize, m_Int16Buffer2.data());
}

void Network::MessageSourceTesting ::MessageTargetWriteString(MessageTarget& messageTarget) const
{
    messageTarget.WriteString(sm_StringValue);

    messageTarget.WriteStringWithNumber(sm_StringArraySize, m_StringBuffer1.data());
    messageTarget.WriteStringWithoutNumber(sm_StringArraySize, m_StringBuffer2.data());
}

void Network::MessageSourceTesting ::MessageTargetWriteVector(MessageTarget& messageTarget) const
{
    messageTarget.Write(m_Int32Vector);
    messageTarget.Write(sm_StringValue);
    messageTarget.Write(m_StringVector);
}

void Network::MessageSourceTesting ::ReadBoolTest(TestingType& messageSource)
{
    const auto readValue = messageSource.ReadBool();

    ASSERT_EQUAL(readValue, sm_BoolValue);

    m_BytesRead += CORE_TOOLS_STREAM_SIZE(sm_BoolValue);
    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);

    int32_t boolBufferSize{ 0 };
    messageSource.Read(boolBufferSize);
    m_BytesRead += CORE_TOOLS_STREAM_SIZE(boolBufferSize);

    ASSERT_EQUAL(sm_BoolArraySize, boolBufferSize);
    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);

    array<bool, sm_BoolArraySize> resultBoolBuffer{};
    messageSource.ReadBool(sm_BoolArraySize, resultBoolBuffer.data());
    m_BytesRead += CORE_TOOLS_STREAM_SIZE(sm_BoolValue) * sm_BoolArraySize;

    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);
    ASSERT_EQUAL(resultBoolBuffer, m_BoolBuffer1);

    messageSource.ReadBool(sm_BoolArraySize, resultBoolBuffer.data());
    m_BytesRead += CORE_TOOLS_STREAM_SIZE(sm_BoolValue) * sm_BoolArraySize;

    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);
    ASSERT_EQUAL(resultBoolBuffer, m_BoolBuffer2);
}

void Network::MessageSourceTesting ::ReadEnumTest(ParserStrategy parserStrategy, TestingType& messageSource)
{
    ParserStrategy resultParserStrategy{ ParserStrategy::End };
    messageSource.ReadEnum(resultParserStrategy);

    ASSERT_ENUM_EQUAL(parserStrategy, resultParserStrategy);

    m_BytesRead += CORE_TOOLS_STREAM_SIZE(resultParserStrategy);
    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);

    int32_t parserStrategyBufferSize{ 0 };
    messageSource.Read(parserStrategyBufferSize);
    m_BytesRead += CORE_TOOLS_STREAM_SIZE(parserStrategyBufferSize);

    ASSERT_EQUAL(sm_EnumArraySize, parserStrategyBufferSize);
    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);

    array<ParserStrategy, sm_EnumArraySize> resultParserStrategyBuffer{};
    messageSource.ReadEnum(sm_EnumArraySize, resultParserStrategyBuffer.data());
    m_BytesRead += CORE_TOOLS_STREAM_SIZE(resultParserStrategy) * sm_EnumArraySize;

    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);
    ASSERT_EQUAL(resultParserStrategyBuffer, m_ParserStrategyBuffer1);

    messageSource.ReadEnum(sm_EnumArraySize, resultParserStrategyBuffer.data());
    m_BytesRead += CORE_TOOLS_STREAM_SIZE(resultParserStrategy) * sm_EnumArraySize;

    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);
    ASSERT_EQUAL(resultParserStrategyBuffer, m_ParserStrategyBuffer2);
}

void Network::MessageSourceTesting ::ReadInt16Test(TestingType& messageSource)
{
    int16_t resultInt16Value{ 0 };
    messageSource.Read(resultInt16Value);

    ASSERT_EQUAL(resultInt16Value, sm_Int16Value);

    m_BytesRead += CORE_TOOLS_STREAM_SIZE(resultInt16Value);
    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);

    int32_t int16BufferSize{ 0 };
    messageSource.Read(int16BufferSize);
    m_BytesRead += CORE_TOOLS_STREAM_SIZE(int16BufferSize);

    ASSERT_EQUAL(sm_Int16ArraySize, int16BufferSize);
    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);

    array<int16_t, sm_Int16ArraySize> resultInt16Buffer{};
    messageSource.Read(sm_Int16ArraySize, resultInt16Buffer.data());
    m_BytesRead += CORE_TOOLS_STREAM_SIZE(resultInt16Value) * sm_Int16ArraySize;

    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);
    ASSERT_EQUAL(resultInt16Buffer, m_Int16Buffer1);

    messageSource.Read(sm_Int16ArraySize, resultInt16Buffer.data());
    m_BytesRead += CORE_TOOLS_STREAM_SIZE(resultInt16Value) * sm_Int16ArraySize;

    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);
    ASSERT_EQUAL(resultInt16Buffer, m_Int16Buffer2);
}

void Network::MessageSourceTesting ::ReadStringTest(TestingType& messageSource)
{
    auto resultStringValue = messageSource.ReadString();

    ASSERT_EQUAL(resultStringValue, sm_StringValue);

    m_BytesRead += CORE_TOOLS_STREAM_SIZE(resultStringValue);
    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);

    int32_t stringBufferSize{ 0 };
    messageSource.Read(stringBufferSize);
    m_BytesRead += CORE_TOOLS_STREAM_SIZE(stringBufferSize);

    ASSERT_EQUAL(sm_StringArraySize, stringBufferSize);
    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);

    array<string, sm_StringArraySize> resultStringBuffer{};
    messageSource.ReadString(sm_StringArraySize, resultStringBuffer.data());
    for (const auto& value : resultStringBuffer)
    {
        m_BytesRead += CORE_TOOLS_STREAM_SIZE(value);
    }

    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);
    ASSERT_EQUAL(resultStringBuffer, m_StringBuffer1);

    messageSource.ReadString(sm_StringArraySize, resultStringBuffer.data());
    for (const auto& value : resultStringBuffer)
    {
        m_BytesRead += CORE_TOOLS_STREAM_SIZE(value);
    }

    ASSERT_EQUAL(resultStringBuffer, m_StringBuffer2);
    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);
}

void Network::MessageSourceTesting ::ReadVectorTest(TestingType& messageSource)
{
    vector<int32_t> int32Buffer{};
    messageSource.Read(int32Buffer);

    auto int32BufferSize = boost::numeric_cast<int32_t>(int32Buffer.size());
    ASSERT_EQUAL(int32BufferSize, sm_Int32VectorSize);

    m_BytesRead += CORE_TOOLS_STREAM_SIZE(int32Buffer);
    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);

    ASSERT_EQUAL(int32Buffer, m_Int32Vector);

    string resultStringValue;
    messageSource.Read(resultStringValue);

    m_BytesRead += CORE_TOOLS_STREAM_SIZE(resultStringValue);
    ASSERT_EQUAL(resultStringValue, sm_StringValue);

    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);

    vector<string> stringBuffer{};
    messageSource.Read(stringBuffer);

    auto stringBufferSize = boost::numeric_cast<int32_t>(stringBuffer.size());
    ASSERT_EQUAL(stringBufferSize, sm_StringVectorSize);

    m_BytesRead += CORE_TOOLS_STREAM_SIZE(stringBuffer);
    ASSERT_EQUAL(messageSource.GetBytesRead(), m_BytesRead);

    ASSERT_EQUAL(stringBuffer, m_StringVector);
}
