// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 14:03)

#include "MessageTargetTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

#include <boost/numeric/conversion/cast.hpp> 

using std::array;
using std::vector;
using std::string;
using std::ostream;
using std::make_shared;

const string Network::MessageTargetTesting
	::sm_StringValue{ "StringValue" };

Network::MessageTargetTesting
	::MessageTargetTesting(const OStreamShared& osPtr)
	:ParentType{ osPtr }, m_BoolBuffer1{ true,false,true,false,true,false,false,false,true,true },
	 m_BoolBuffer2{ false,true,false,true,false,true,false,false,true,true },
	 m_ParserStrategyBuffer1{ ParserStrategy::LittleEndian,ParserStrategy::BigEndian,ParserStrategy::LittleEndian,ParserStrategy::BigEndian,ParserStrategy::LittleEndian,ParserStrategy::BigEndian,
							  ParserStrategy::BigEndian ,ParserStrategy::LittleEndian ,ParserStrategy::LittleEndian ,ParserStrategy::BigEndian ,ParserStrategy::LittleEndian },
	 m_ParserStrategyBuffer2{ ParserStrategy::BigEndian ,ParserStrategy::LittleEndian,ParserStrategy::BigEndian,ParserStrategy::LittleEndian,ParserStrategy::BigEndian,ParserStrategy::LittleEndian,
							 ParserStrategy::BigEndian,ParserStrategy::BigEndian ,ParserStrategy::LittleEndian ,ParserStrategy::LittleEndian ,ParserStrategy::BigEndian },
	 m_Int16Buffer1{ 1,2,3,4,5,6,7,8,9,10,11,12 }, m_Int16Buffer2{ 0,1,2,3,4,5,6,7,8,9,10,11 },
	 m_StringBuffer1{ "1","2","3","4","5","6","7","8","9","10","11","12","13" }, m_StringBuffer2{ "x1","x2","x3","x4","x5","x6","x7","x8","x9","x10","x11","x12","x13" },
	 m_Int32Vector{ 2,3,4,5,6,7,8,9,10,11,12,13,14,15 }, m_StringVector{ "2","3","4","5","6","7","8","9","10","11","12","13","14","15","16" }, m_BytesWrite{ 0 }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

 CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageTargetTesting)
void Network::MessageTargetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::MessageTargetTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_1(SourceTest, ParserStrategy::LittleEndian);
	ASSERT_NOT_THROW_EXCEPTION_1(SourceTest, ParserStrategy::BigEndian);
}

void Network::MessageTargetTesting
	::SourceTest(ParserStrategy parserStrategy)
{
	auto buffer = CreateTargetMessageBuffer(parserStrategy);

	MessageSource messageSource{ buffer };

	VerificationBool(messageSource);
	VerificationEnum(parserStrategy, messageSource);
	VerificationInt16(messageSource);
	VerificationString(messageSource);
	VerificationVector(messageSource);
}

Network::MessageBufferSharedPtr Network::MessageTargetTesting
	::CreateTargetMessageBuffer(ParserStrategy parserStrategy)
{
	m_BytesWrite = 0;

	MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size1024,parserStrategy) };
	MessageTarget messageTarget{ buffer };

	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);

	MessageTargetWriteBool(messageTarget);
	MessageTargetWriteEnum(messageTarget, parserStrategy);
	MessageTargetWriteInt16(messageTarget);
	MessageTargetWriteString(messageTarget);
	MessageTargetWriteVector(messageTarget);

	return buffer;
}

void Network::MessageTargetTesting
	::MessageTargetWriteBool(TestingType& messageTarget)
{
	messageTarget.WriteBool(sm_BoolValue);

	m_BytesWrite += CORE_TOOLS_STREAM_SIZE(sm_BoolValue);
	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);

	messageTarget.WriteBoolWithNumber(sm_BoolArraySize, m_BoolBuffer1.data());

	m_BytesWrite += CORE_TOOLS_STREAM_SIZE(sm_BoolArraySize) + CORE_TOOLS_STREAM_SIZE(m_BoolBuffer1[0]) * sm_BoolArraySize;
	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);

	messageTarget.WriteBoolWithoutNumber(sm_BoolArraySize, m_BoolBuffer2.data());

	m_BytesWrite += CORE_TOOLS_STREAM_SIZE(m_BoolBuffer2[0]) * sm_BoolArraySize;
	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);
}

void Network::MessageTargetTesting
	::MessageTargetWriteEnum(TestingType& messageTarget, ParserStrategy parserStrategy)
{
	messageTarget.WriteEnum(parserStrategy);

	m_BytesWrite += CORE_TOOLS_STREAM_SIZE(parserStrategy);
	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);

	messageTarget.WriteEnumWithNumber(sm_EnumArraySize, m_ParserStrategyBuffer1.data());

	m_BytesWrite += CORE_TOOLS_STREAM_SIZE(sm_EnumArraySize) + CORE_TOOLS_STREAM_SIZE(m_ParserStrategyBuffer1[0]) * sm_EnumArraySize;
	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);

	messageTarget.WriteEnumWithoutNumber(sm_EnumArraySize, m_ParserStrategyBuffer2.data());

	m_BytesWrite += CORE_TOOLS_STREAM_SIZE(m_ParserStrategyBuffer2[0]) * sm_EnumArraySize;
	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);
}

void Network::MessageTargetTesting
	::MessageTargetWriteInt16(TestingType& messageTarget)
{
	messageTarget.Write(sm_Int16Value);

	m_BytesWrite += CORE_TOOLS_STREAM_SIZE(sm_Int16Value);
	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);

	messageTarget.WriteWithNumber(sm_Int16ArraySize, m_Int16Buffer1.data());

	m_BytesWrite += CORE_TOOLS_STREAM_SIZE(sm_Int16ArraySize) + CORE_TOOLS_STREAM_SIZE(m_Int16Buffer1[0]) * sm_Int16ArraySize;
	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);

	messageTarget.WriteWithoutNumber(sm_Int16ArraySize, m_Int16Buffer2.data());

	m_BytesWrite += CORE_TOOLS_STREAM_SIZE(m_Int16Buffer2[0]) * sm_Int16ArraySize;
	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);
}

void Network::MessageTargetTesting
	::MessageTargetWriteString(TestingType& messageTarget)
{
	messageTarget.WriteString(sm_StringValue);

	m_BytesWrite += CORE_TOOLS_STREAM_SIZE(sm_StringValue);
	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);

	messageTarget.WriteStringWithNumber(sm_StringArraySize, m_StringBuffer1.data());

	m_BytesWrite += CORE_TOOLS_STREAM_SIZE(sm_StringArraySize);

	for (const auto& value : m_StringBuffer1)
	{
		m_BytesWrite += CORE_TOOLS_STREAM_SIZE(value);
	}
	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);

	messageTarget.WriteStringWithoutNumber(sm_StringArraySize, m_StringBuffer2.data());

	for (const auto& value : m_StringBuffer2)
	{
		m_BytesWrite += CORE_TOOLS_STREAM_SIZE(value);
	}
	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);
}

void Network::MessageTargetTesting
	::MessageTargetWriteVector(TestingType& messageTarget)
{
	messageTarget.Write(m_Int32Vector);

	m_BytesWrite += CORE_TOOLS_STREAM_SIZE(m_Int32Vector);
	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);

	messageTarget.Write(sm_StringValue);

	m_BytesWrite += CORE_TOOLS_STREAM_SIZE(sm_StringValue);
	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);

	messageTarget.Write(m_StringVector);

	m_BytesWrite += CORE_TOOLS_STREAM_SIZE(m_StringVector);
	ASSERT_EQUAL(messageTarget.GetBytesWritten(), m_BytesWrite);
}

void Network::MessageTargetTesting
	::VerificationBool(MessageSource& messageSource)
{
	auto readValue = messageSource.ReadBool();

	ASSERT_EQUAL(readValue, sm_BoolValue);

	int32_t boolBufferSize{ 0 };
	messageSource.Read(boolBufferSize);
	ASSERT_EQUAL(sm_BoolArraySize, boolBufferSize);

	array<bool, sm_BoolArraySize> resultBoolBuffer{};
	messageSource.ReadBool(sm_BoolArraySize, resultBoolBuffer.data());
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(resultBoolBuffer, m_BoolBuffer1);

	messageSource.ReadBool(sm_BoolArraySize, resultBoolBuffer.data());
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(resultBoolBuffer, m_BoolBuffer2);
}

void Network::MessageTargetTesting
	::VerificationEnum(ParserStrategy parserStrategy, MessageSource& messageSource)
{
	ParserStrategy resultParserStrategy{ ParserStrategy::End };
	messageSource.ReadEnum(resultParserStrategy);

	ASSERT_ENUM_EQUAL(parserStrategy, resultParserStrategy);

	int32_t parserStrategyBufferSize{ 0 };
	messageSource.Read(parserStrategyBufferSize);
	ASSERT_EQUAL(sm_EnumArraySize, parserStrategyBufferSize);

	array<ParserStrategy, sm_EnumArraySize> resultParserStrategyBuffer{};
	messageSource.ReadEnum(sm_EnumArraySize, resultParserStrategyBuffer.data());
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(resultParserStrategyBuffer, m_ParserStrategyBuffer1);

	messageSource.ReadEnum(sm_EnumArraySize, resultParserStrategyBuffer.data());
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(resultParserStrategyBuffer, m_ParserStrategyBuffer2);
}

void Network::MessageTargetTesting
	::VerificationInt16(MessageSource& messageSource)
{
	int16_t resultInt16Value{ 0 };
	messageSource.Read(resultInt16Value);

	ASSERT_EQUAL(resultInt16Value, sm_Int16Value);

	int32_t int16BufferSize{ 0 };
	messageSource.Read(int16BufferSize);
	ASSERT_EQUAL(sm_Int16ArraySize, int16BufferSize);

	array<int16_t, sm_Int16ArraySize> resultInt16Buffer{};
	messageSource.Read(sm_Int16ArraySize, resultInt16Buffer.data());
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(resultInt16Buffer, m_Int16Buffer1);

	messageSource.Read(sm_Int16ArraySize, resultInt16Buffer.data());
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(resultInt16Buffer, m_Int16Buffer2);
}

void Network::MessageTargetTesting
	::VerificationString(MessageSource& messageSource)
{
	auto resultStringValue = messageSource.ReadString();

	ASSERT_EQUAL(resultStringValue, sm_StringValue);

	int32_t stringBufferSize{ 0 };
	messageSource.Read(stringBufferSize);
	ASSERT_EQUAL(sm_StringArraySize, stringBufferSize);

	array<string, sm_StringArraySize> resultStringBuffer{};
	messageSource.ReadString(sm_StringArraySize, resultStringBuffer.data());
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(resultStringBuffer, m_StringBuffer1);

	messageSource.ReadString(sm_StringArraySize, resultStringBuffer.data());
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(resultStringBuffer, m_StringBuffer2);
}

void Network::MessageTargetTesting
	::VerificationVector(MessageSource& messageSource)
{
	vector<int32_t> int32Buffer{};
	messageSource.Read(int32Buffer);

	auto int32BufferSize = boost::numeric_cast<int32_t>(int32Buffer.size());
	ASSERT_EQUAL(int32BufferSize, sm_Int32VectorSize);
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(int32Buffer, m_Int32Vector);

	string resultStringValue;
	messageSource.Read(resultStringValue);
	ASSERT_EQUAL(resultStringValue, sm_StringValue);

	vector<string> stringBuffer{};
	messageSource.Read(stringBuffer);

	auto stringBufferSize = boost::numeric_cast<int32_t>(stringBuffer.size());
	ASSERT_EQUAL(stringBufferSize, sm_StringVectorSize);
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(stringBuffer, m_StringVector);
}
