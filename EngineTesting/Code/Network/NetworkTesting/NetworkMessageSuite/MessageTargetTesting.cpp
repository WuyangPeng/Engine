///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 18:26)

#include "MessageTargetTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <boost/numeric/conversion/cast.hpp>

using std::array;
using std::make_shared;
using std::ostream;
using std::string;
using std::vector;

const string Network::MessageTargetTesting::stringValue{ "StringValue" };

Network::MessageTargetTesting::MessageTargetTesting(const OStreamShared& stream)
    : ParentType{ stream },
      boolBuffer1{ true, false, true, false, true, false, false, false, true, true },
      boolBuffer2{ false, true, false, true, false, true, false, false, true, true },
      parserStrategyBuffer1{ ParserStrategy::LittleEndian,
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
      parserStrategyBuffer2{ ParserStrategy::BigEndian,
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
      int16Buffer1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 },
      int16Buffer2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 },
      stringBuffer1{ "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13" },
      stringBuffer2{ "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13" },
      int32Vector{ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 },
      stringVector{ "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16" },
      bytesWrite{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageTargetTesting)

void Network::MessageTargetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::MessageTargetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(SourceTest, ParserStrategy::LittleEndian);
    ASSERT_NOT_THROW_EXCEPTION_1(SourceTest, ParserStrategy::BigEndian);
}

void Network::MessageTargetTesting::SourceTest(ParserStrategy parserStrategy)
{
    auto buffer = CreateTargetMessageBuffer(parserStrategy);

    MessageSource messageSource{ *buffer };

    VerificationBool(messageSource);
    VerificationEnum(parserStrategy, messageSource);
    VerificationInt16(messageSource);
    VerificationString(messageSource);
    VerificationVector(messageSource);
}

Network::MessageBufferSharedPtr Network::MessageTargetTesting::CreateTargetMessageBuffer(ParserStrategy parserStrategy)
{
    bytesWrite = 0;

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size1024, parserStrategy) };
    MessageTarget messageTarget{ *buffer };

    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);

    MessageTargetWriteBool(messageTarget);
    MessageTargetWriteEnum(messageTarget, parserStrategy);
    MessageTargetWriteInt16(messageTarget);
    MessageTargetWriteString(messageTarget);
    MessageTargetWriteVector(messageTarget);

    return buffer;
}

void Network::MessageTargetTesting::MessageTargetWriteBool(TestingType& messageTarget)
{
    messageTarget.WriteBool(boolValue);

    bytesWrite += CoreTools::GetStreamSize(boolValue);
    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);

    messageTarget.WriteBoolWithNumber(boolArraySize, boolBuffer1.data());

    bytesWrite += CoreTools::GetStreamSize(boolArraySize) + CoreTools::GetStreamSize(boolBuffer1.at(0)) * boolArraySize;
    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);

    messageTarget.WriteBoolWithoutNumber(boolArraySize, boolBuffer2.data());

    bytesWrite += CoreTools::GetStreamSize(boolBuffer2.at(0)) * boolArraySize;
    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);
}

void Network::MessageTargetTesting::MessageTargetWriteEnum(TestingType& messageTarget, ParserStrategy parserStrategy)
{
    messageTarget.WriteEnum(parserStrategy);

    bytesWrite += CoreTools::GetStreamSize(parserStrategy);
    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);

    messageTarget.WriteEnumWithNumber(enumArraySize, parserStrategyBuffer1.data());

    bytesWrite += CoreTools::GetStreamSize(enumArraySize) + CoreTools::GetStreamSize(parserStrategyBuffer1.at(0)) * enumArraySize;
    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);

    messageTarget.WriteEnumWithoutNumber(enumArraySize, parserStrategyBuffer2.data());

    bytesWrite += CoreTools::GetStreamSize(parserStrategyBuffer2.at(0)) * enumArraySize;
    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);
}

void Network::MessageTargetTesting::MessageTargetWriteInt16(TestingType& messageTarget)
{
    messageTarget.Write(int16Value);

    bytesWrite += CoreTools::GetStreamSize(int16Value);
    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);

    messageTarget.WriteWithNumber(int16ArraySize, int16Buffer1.data());

    bytesWrite += CoreTools::GetStreamSize(int16ArraySize) + CoreTools::GetStreamSize(int16Buffer1.at(0)) * int16ArraySize;
    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);

    messageTarget.WriteWithoutNumber(int16ArraySize, int16Buffer2.data());

    bytesWrite += CoreTools::GetStreamSize(int16Buffer2.at(0)) * int16ArraySize;
    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);
}

void Network::MessageTargetTesting::MessageTargetWriteString(TestingType& messageTarget)
{
    messageTarget.WriteString(stringValue);

    bytesWrite += CoreTools::GetStreamSize(stringValue);
    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);

    messageTarget.WriteStringWithNumber(stringArraySize, stringBuffer1.data());

    bytesWrite += CoreTools::GetStreamSize(stringArraySize);

    for (const auto& value : stringBuffer1)
    {
        bytesWrite += CoreTools::GetStreamSize(value);
    }
    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);

    messageTarget.WriteStringWithoutNumber(stringArraySize, stringBuffer2.data());

    for (const auto& value : stringBuffer2)
    {
        bytesWrite += CoreTools::GetStreamSize(value);
    }
    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);
}

void Network::MessageTargetTesting::MessageTargetWriteVector(TestingType& messageTarget)
{
    messageTarget.Write(int32Vector);

    bytesWrite += CoreTools::GetStreamSize(int32Vector);
    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);

    messageTarget.Write(stringValue);

    bytesWrite += CoreTools::GetStreamSize(stringValue);
    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);

    messageTarget.Write(stringVector);

    bytesWrite += CoreTools::GetStreamSize(stringVector);
    ASSERT_EQUAL(messageTarget.GetBytesWritten(), bytesWrite);
}

void Network::MessageTargetTesting::VerificationBool(MessageSource& messageSource)
{
    const auto readValue = messageSource.ReadBool();

    ASSERT_EQUAL(readValue, boolValue);

    int32_t boolBufferSize{ 0 };
    messageSource.Read(boolBufferSize);
    ASSERT_EQUAL(boolArraySize, boolBufferSize);

    array<bool, boolArraySize> resultBoolBuffer{};
    messageSource.ReadBool(boolArraySize, resultBoolBuffer.data());
    ASSERT_EQUAL(resultBoolBuffer, boolBuffer1);

    messageSource.ReadBool(boolArraySize, resultBoolBuffer.data());
    ASSERT_EQUAL(resultBoolBuffer, boolBuffer2);
}

void Network::MessageTargetTesting::VerificationEnum(ParserStrategy parserStrategy, MessageSource& messageSource)
{
    ParserStrategy resultParserStrategy{ ParserStrategy::End };
    messageSource.ReadEnum(resultParserStrategy);

    ASSERT_ENUM_EQUAL(parserStrategy, resultParserStrategy);

    int32_t parserStrategyBufferSize{ 0 };
    messageSource.Read(parserStrategyBufferSize);
    ASSERT_EQUAL(enumArraySize, parserStrategyBufferSize);

    array<ParserStrategy, enumArraySize> resultParserStrategyBuffer{};
    messageSource.ReadEnum(enumArraySize, resultParserStrategyBuffer.data());
    ASSERT_EQUAL(resultParserStrategyBuffer, parserStrategyBuffer1);

    messageSource.ReadEnum(enumArraySize, resultParserStrategyBuffer.data());
    ASSERT_EQUAL(resultParserStrategyBuffer, parserStrategyBuffer2);
}

void Network::MessageTargetTesting::VerificationInt16(MessageSource& messageSource)
{
    int16_t resultInt16Value{ 0 };
    messageSource.Read(resultInt16Value);

    ASSERT_EQUAL(resultInt16Value, int16Value);

    int32_t int16BufferSize{ 0 };
    messageSource.Read(int16BufferSize);
    ASSERT_EQUAL(int16ArraySize, int16BufferSize);

    array<int16_t, int16ArraySize> resultInt16Buffer{};
    messageSource.Read(int16ArraySize, resultInt16Buffer.data());
    ASSERT_EQUAL(resultInt16Buffer, int16Buffer1);

    messageSource.Read(int16ArraySize, resultInt16Buffer.data());
    ASSERT_EQUAL(resultInt16Buffer, int16Buffer2);
}

void Network::MessageTargetTesting::VerificationString(MessageSource& messageSource)
{
    auto resultStringValue = messageSource.ReadString();

    ASSERT_EQUAL(resultStringValue, stringValue);

    int32_t stringBufferSize{ 0 };
    messageSource.Read(stringBufferSize);
    ASSERT_EQUAL(stringArraySize, stringBufferSize);

    array<string, stringArraySize> resultStringBuffer{};
    messageSource.ReadString(stringArraySize, resultStringBuffer.data());
    ASSERT_EQUAL(resultStringBuffer, stringBuffer1);

    messageSource.ReadString(stringArraySize, resultStringBuffer.data());
    ASSERT_EQUAL(resultStringBuffer, stringBuffer2);
}

void Network::MessageTargetTesting::VerificationVector(MessageSource& messageSource)
{
    vector<int32_t> int32Buffer{};
    messageSource.Read(int32Buffer);

    auto int32BufferSize = boost::numeric_cast<int32_t>(int32Buffer.size());
    ASSERT_EQUAL(int32BufferSize, int32VectorSize);
    ASSERT_EQUAL(int32Buffer, int32Vector);

    string resultStringValue;
    messageSource.Read(resultStringValue);
    ASSERT_EQUAL(resultStringValue, stringValue);

    vector<string> stringBuffer{};
    messageSource.Read(stringBuffer);

    auto stringBufferSize = boost::numeric_cast<int32_t>(stringBuffer.size());
    ASSERT_EQUAL(stringBufferSize, stringVectorSize);
    ASSERT_EQUAL(stringBuffer, stringVector);
}
