///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:48)

#include "MessageSourceTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

const std::string Network::MessageSourceTesting::stringValue{ "StringValue" };

Network::MessageSourceTesting::MessageSourceTesting(const OStreamShared& stream)
    : ParentType{ stream },
      boolBuffer0{ true, false, true, false, true, false, false, false, true, true },
      boolBuffer1{ false, true, false, true, false, true, false, false, true, true },
      parserStrategyBuffer0{ ParserStrategy::LittleEndian,
                             ParserStrategy::BigEndian,
                             ParserStrategy::LittleEndian,
                             ParserStrategy::BigEndian,
                             ParserStrategy::LittleEndian,
                             ParserStrategy::BigEndian,
                             ParserStrategy::BigEndian,
                             ParserStrategy::LittleEndian,
                             ParserStrategy::LittleEndian,
                             ParserStrategy::BigEndian,
                             ParserStrategy::LittleEndian },
      parserStrategyBuffer1{ ParserStrategy::BigEndian,
                             ParserStrategy::LittleEndian,
                             ParserStrategy::BigEndian,
                             ParserStrategy::LittleEndian,
                             ParserStrategy::BigEndian,
                             ParserStrategy::LittleEndian,
                             ParserStrategy::BigEndian,
                             ParserStrategy::BigEndian,
                             ParserStrategy::LittleEndian,
                             ParserStrategy::LittleEndian,
                             ParserStrategy::BigEndian },
      int16Buffer0{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 },
      int16Buffer1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 },
      stringBuffer0{ "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13" },
      stringBuffer1{ "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13" },
      int32Vector{ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
      stringVector{ "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16" },
      bytesRead{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageSourceTesting)

void Network::MessageSourceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::MessageSourceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(SourceTest, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_1(SourceTest, ParserStrategy::BigEndian);
    ASSERT_NOT_THROW_EXCEPTION_1(IncrementBytesProcessedTest, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_1(IncrementBytesProcessedTest, ParserStrategy::BigEndian);
}

void Network::MessageSourceTesting::SourceTest(ParserStrategy parserStrategy)
{
    bytesRead = 0;

    const auto buffer = CreateTargetMessageBuffer(parserStrategy);

    TestingType messageSource{ *buffer };

    ASSERT_EQUAL(messageSource.GetBytesTotal(), buffer->GetCurrentWriteIndex());
    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);

    ReadBoolTest(messageSource);
    ReadEnumTest(parserStrategy, messageSource);
    ReadInt16Test(messageSource);
    ReadStringTest(messageSource);
    ReadVectorTest(messageSource);
}

Network::MessageBufferSharedPtr Network::MessageSourceTesting::CreateTargetMessageBuffer(ParserStrategy parserStrategy) const
{
    const auto buffer = std::make_shared<MessageBuffer>(BuffBlockSize::Size1024, parserStrategy);
    MessageTarget messageTarget{ *buffer };

    MessageTargetWriteBool(messageTarget);
    MessageTargetWriteEnum(messageTarget, parserStrategy);
    MessageTargetWriteInt16(messageTarget);
    MessageTargetWriteString(messageTarget);
    MessageTargetWriteVector(messageTarget);

    return buffer;
}

void Network::MessageSourceTesting::IncrementBytesProcessedTest(ParserStrategy parserStrategy)
{
    const auto buffer = CreateTargetMessageBuffer(parserStrategy);

    TestingType messageSource{ *buffer };

    constexpr int aBytesRead{ 0 };

    ASSERT_EQUAL(messageSource.GetBytesRead(), aBytesRead);

    messageSource.IncrementBytesProcessed(10);
    ASSERT_EQUAL(messageSource.GetBytesRead(), 10);
}

void Network::MessageSourceTesting::MessageTargetWriteBool(MessageTarget& messageTarget) const
{
    messageTarget.WriteBool(boolValue);

    messageTarget.WriteBoolWithNumber(boolArraySize, boolBuffer0.data());
    messageTarget.WriteBoolWithoutNumber(boolArraySize, boolBuffer1.data());
}

void Network::MessageSourceTesting::MessageTargetWriteEnum(MessageTarget& messageTarget, ParserStrategy parserStrategy) const
{
    messageTarget.WriteEnum(parserStrategy);

    messageTarget.WriteEnumWithNumber(enumArraySize, parserStrategyBuffer0.data());
    messageTarget.WriteEnumWithoutNumber(enumArraySize, parserStrategyBuffer1.data());
}

void Network::MessageSourceTesting::MessageTargetWriteInt16(MessageTarget& messageTarget) const
{
    messageTarget.Write(int16Value);

    messageTarget.WriteWithNumber(int16ArraySize, int16Buffer0.data());
    messageTarget.WriteWithoutNumber(int16ArraySize, int16Buffer1.data());
}

void Network::MessageSourceTesting::MessageTargetWriteString(MessageTarget& messageTarget) const
{
    messageTarget.WriteString(stringValue);

    messageTarget.WriteStringWithNumber(stringArraySize, stringBuffer0.data());
    messageTarget.WriteStringWithoutNumber(stringArraySize, stringBuffer1.data());
}

void Network::MessageSourceTesting::MessageTargetWriteVector(MessageTarget& messageTarget) const
{
    messageTarget.Write(int32Vector);
    messageTarget.Write(stringValue);
    messageTarget.Write(stringVector);
}

void Network::MessageSourceTesting::ReadBoolTest(TestingType& messageSource)
{
    const auto readValue = messageSource.ReadBool();

    ASSERT_EQUAL(readValue, boolValue);

    bytesRead += CoreTools::GetStreamSize(boolValue);
    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);

    int32_t boolBufferSize{ 0 };
    messageSource.Read(boolBufferSize);
    bytesRead += CoreTools::GetStreamSize(boolBufferSize);

    ASSERT_EQUAL(boolArraySize, boolBufferSize);
    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);

    std::array<bool, boolArraySize> resultBoolBuffer{};
    messageSource.ReadBool(boolArraySize, resultBoolBuffer.data());
    bytesRead += CoreTools::GetStreamSize(boolValue) * boolArraySize;

    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);
    ASSERT_EQUAL(resultBoolBuffer, boolBuffer0);

    messageSource.ReadBool(boolArraySize, resultBoolBuffer.data());
    bytesRead += CoreTools::GetStreamSize(boolValue) * boolArraySize;

    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);
    ASSERT_EQUAL(resultBoolBuffer, boolBuffer1);
}

void Network::MessageSourceTesting::ReadEnumTest(ParserStrategy parserStrategy, TestingType& messageSource)
{
    auto resultParserStrategy = ParserStrategy::End;
    messageSource.ReadEnum(resultParserStrategy);

    ASSERT_ENUM_EQUAL(parserStrategy, resultParserStrategy);

    bytesRead += CoreTools::GetStreamSize(resultParserStrategy);
    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);

    int32_t parserStrategyBufferSize{ 0 };
    messageSource.Read(parserStrategyBufferSize);
    bytesRead += CoreTools::GetStreamSize(parserStrategyBufferSize);

    ASSERT_EQUAL(enumArraySize, parserStrategyBufferSize);
    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);

    std::array<ParserStrategy, enumArraySize> resultParserStrategyBuffer{};
    messageSource.ReadEnum(enumArraySize, resultParserStrategyBuffer.data());
    bytesRead += CoreTools::GetStreamSize(resultParserStrategy) * enumArraySize;

    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);
    ASSERT_EQUAL(resultParserStrategyBuffer, parserStrategyBuffer0);

    messageSource.ReadEnum(enumArraySize, resultParserStrategyBuffer.data());
    bytesRead += CoreTools::GetStreamSize(resultParserStrategy) * enumArraySize;

    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);
    ASSERT_EQUAL(resultParserStrategyBuffer, parserStrategyBuffer1);
}

void Network::MessageSourceTesting::ReadInt16Test(TestingType& messageSource)
{
    int16_t resultInt16Value{ 0 };
    messageSource.Read(resultInt16Value);

    ASSERT_EQUAL(resultInt16Value, int16Value);

    bytesRead += CoreTools::GetStreamSize(resultInt16Value);
    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);

    int32_t int16BufferSize{ 0 };
    messageSource.Read(int16BufferSize);
    bytesRead += CoreTools::GetStreamSize(int16BufferSize);

    ASSERT_EQUAL(int16ArraySize, int16BufferSize);
    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);

    std::array<int16_t, int16ArraySize> resultInt16Buffer{};
    messageSource.Read(int16ArraySize, resultInt16Buffer.data());
    bytesRead += CoreTools::GetStreamSize(resultInt16Value) * int16ArraySize;

    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);
    ASSERT_EQUAL(resultInt16Buffer, int16Buffer0);

    messageSource.Read(int16ArraySize, resultInt16Buffer.data());
    bytesRead += CoreTools::GetStreamSize(resultInt16Value) * int16ArraySize;

    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);
    ASSERT_EQUAL(resultInt16Buffer, int16Buffer1);
}

void Network::MessageSourceTesting::ReadStringTest(TestingType& messageSource)
{
    const auto resultStringValue = messageSource.ReadString();

    ASSERT_EQUAL(resultStringValue, stringValue);

    bytesRead += CoreTools::GetStreamSize(resultStringValue);
    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);

    int32_t stringBufferSize{ 0 };
    messageSource.Read(stringBufferSize);
    bytesRead += CoreTools::GetStreamSize(stringBufferSize);

    ASSERT_EQUAL(stringArraySize, stringBufferSize);
    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);

    std::array<std::string, stringArraySize> resultStringBuffer{};
    messageSource.ReadString(stringArraySize, resultStringBuffer.data());
    for (const auto& value : resultStringBuffer)
    {
        bytesRead += CoreTools::GetStreamSize(value);
    }

    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);
    ASSERT_EQUAL(resultStringBuffer, stringBuffer0);

    messageSource.ReadString(stringArraySize, resultStringBuffer.data());
    for (const auto& value : resultStringBuffer)
    {
        bytesRead += CoreTools::GetStreamSize(value);
    }

    ASSERT_EQUAL(resultStringBuffer, stringBuffer1);
    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);
}

void Network::MessageSourceTesting::ReadVectorTest(TestingType& messageSource)
{
    std::vector<int32_t> int32Buffer{};
    messageSource.Read(int32Buffer);

    const auto int32BufferSize = boost::numeric_cast<int32_t>(int32Buffer.size());
    ASSERT_EQUAL(int32BufferSize, int32VectorSize);

    bytesRead += CoreTools::GetStreamSize(int32Buffer);
    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);

    ASSERT_EQUAL(int32Buffer, int32Vector);

    std::string resultStringValue;
    messageSource.Read(resultStringValue);

    bytesRead += CoreTools::GetStreamSize(resultStringValue);
    ASSERT_EQUAL(resultStringValue, stringValue);

    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);

    std::vector<std::string> stringBuffer{};
    messageSource.Read(stringBuffer);

    const auto stringBufferSize = boost::numeric_cast<int32_t>(stringBuffer.size());
    ASSERT_EQUAL(stringBufferSize, stringVectorSize);

    bytesRead += CoreTools::GetStreamSize(stringBuffer);
    ASSERT_EQUAL(messageSource.GetBytesRead(), bytesRead);

    ASSERT_EQUAL(stringBuffer, stringVector);
}
