// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 14:27)

#include "MultipleMessageSizeTesting.h"  
#include "Flags/MultipleMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MultipleMessageCast.h"
#include "Network/NetworkMessage/MultipleMessageContainer.h"

#include <string>

using std::string;
using std::is_same_v;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, MultipleMessageSizeTesting)

void Network::MultipleMessageSizeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(NineSizeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FiveSizeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(TwoSizeTest);
}

void Network::MultipleMessageSizeTesting
	::NineSizeTest()
{
	using MultipleMessageContainer = MultipleMessageContainer<MultipleMessageField, MultipleMessageByteType::Int8, MultipleMessageByteType::Uint8,
															  MultipleMessageByteType::Int16, MultipleMessageByteType::Uint16, MultipleMessageByteType::Int32,
															  MultipleMessageByteType::Uint32, MultipleMessageByteType::Int64, MultipleMessageByteType::Uint64,
															  MultipleMessageByteType::String>;

	static_assert(MultipleMessageSize<MultipleMessageContainer>::value == 9, "MultipleMessageSize error");
}

void Network::MultipleMessageSizeTesting
	::FiveSizeTest()
{
	using MultipleMessageContainer = MultipleMessageContainer<MultipleMessageField, MultipleMessageByteType::Int8, MultipleMessageByteType::Uint8,
															  MultipleMessageByteType::Int16, MultipleMessageByteType::Uint16, MultipleMessageByteType::Int32>;

	static_assert(MultipleMessageSize<MultipleMessageContainer>::value == 5, "MultipleMessageSize error");
}

void Network::MultipleMessageSizeTesting
	::TwoSizeTest()
{
	using MultipleMessageContainer = MultipleMessageContainer<MultipleMessageField, MultipleMessageByteType::Int8, MultipleMessageByteType::Uint8>;

	static_assert(MultipleMessageSize<MultipleMessageContainer>::value == 2, "MultipleMessageSize error");
}

