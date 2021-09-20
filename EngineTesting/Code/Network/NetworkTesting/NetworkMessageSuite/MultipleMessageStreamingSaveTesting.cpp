// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 14:28)

#include "MultipleMessageStreamingSaveTesting.h"  
#include "Flags/MultipleMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MultipleMessageCast.h"
#include "Network/NetworkMessage/MultipleMessageContainerDetail.h"
#include "Network/NetworkMessage/MultipleMessageStreamingSaveDetail.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

#include <string>

using std::string;
using std::make_shared;

namespace Network
{
	using MultipleMessageType = MultipleMessageContainer<MultipleMessageField, MultipleMessageByteType::Int8, MultipleMessageByteType::Uint8,
														 MultipleMessageByteType::Int16, MultipleMessageByteType::Uint16, MultipleMessageByteType::Int32,
														 MultipleMessageByteType::Uint32, MultipleMessageByteType::Int64, MultipleMessageByteType::Uint64,
														 MultipleMessageByteType::String>;

	using TestingType = MultipleMessageStreamingSave<MultipleMessageSize<MultipleMessageType>::value, MultipleMessageType>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, MultipleMessageStreamingSaveTesting)

void Network::MultipleMessageStreamingSaveTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void Network::MultipleMessageStreamingSaveTesting
	::BaseTest()
{
	constexpr int8_t int8Value{ -8 };
	constexpr int16_t int16Value{ 24 };
	constexpr int32_t int32Value{ -24 };
	constexpr int64_t int64Value{ 56 };

	constexpr uint8_t uint8Value{ 18 };
	constexpr uint16_t uint16Value{ 124 };
	constexpr uint32_t uint32Value{ 224 };
	constexpr uint64_t uint64Value{ 156 };

	const string stringValue{ "string" };

	MultipleMessageType multipleMessageContainer{ int8Value, uint8Value, int16Value, uint16Value, int32Value, uint32Value, int64Value, uint64Value, stringValue };

	TestingType multipleMessageStreamingSave{};

	MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256,ParserStrategy::LittleEndian) };
	MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

	multipleMessageStreamingSave.Save(multipleMessageContainer, messageTarget);

	auto initialBuffered = buffer->GetInitialBufferedPtr();

	auto resultInt8Value = *reinterpret_cast<int8_t*>(initialBuffered);
	ASSERT_EQUAL(resultInt8Value, int8Value);
	initialBuffered += CORE_TOOLS_STREAM_SIZE(resultInt8Value);

	auto resultUInt8Value = *reinterpret_cast<uint8_t*>(initialBuffered);
	ASSERT_EQUAL(resultUInt8Value, uint8Value);
	initialBuffered += CORE_TOOLS_STREAM_SIZE(resultUInt8Value);

	auto resultInt16Value = *reinterpret_cast<int16_t*>(initialBuffered);
	ASSERT_EQUAL(resultInt16Value, int16Value);
	initialBuffered += CORE_TOOLS_STREAM_SIZE(resultInt16Value);

	auto resultUInt16Value = *reinterpret_cast<uint16_t*>(initialBuffered);
	ASSERT_EQUAL(resultUInt16Value, uint16Value);
	initialBuffered += CORE_TOOLS_STREAM_SIZE(resultUInt16Value);

	auto resultInt32Value = *reinterpret_cast<int32_t*>(initialBuffered);
	ASSERT_EQUAL(resultInt32Value, int32Value);
	initialBuffered += CORE_TOOLS_STREAM_SIZE(resultInt32Value);

	auto resultUInt32Value = *reinterpret_cast<uint32_t*>(initialBuffered);
	ASSERT_EQUAL(resultUInt32Value, uint32Value);
	initialBuffered += CORE_TOOLS_STREAM_SIZE(resultUInt32Value);

	auto resultInt64Value = *reinterpret_cast<int64_t*>(initialBuffered);
	ASSERT_EQUAL(resultInt64Value, int64Value);
	initialBuffered += CORE_TOOLS_STREAM_SIZE(resultInt64Value);

	auto resultUInt64Value = *reinterpret_cast<uint64_t*>(initialBuffered);
	ASSERT_EQUAL(resultUInt64Value, uint64Value);
	initialBuffered += CORE_TOOLS_STREAM_SIZE(resultUInt64Value);

	auto lenght = *reinterpret_cast<int32_t*>(initialBuffered);
	ASSERT_EQUAL(lenght, boost::numeric_cast<int32_t>(stringValue.size()));
	initialBuffered += CORE_TOOLS_STREAM_SIZE(lenght);

	string resultStringValue{ initialBuffered ,initialBuffered + lenght };

	ASSERT_EQUAL(resultStringValue, stringValue);
}


