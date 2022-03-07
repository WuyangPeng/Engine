// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 14:28)

#include "MultipleMessageStreamingLoadTesting.h"
#include "Flags/MultipleMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MultipleMessageCast.h"
#include "Network/NetworkMessage/MultipleMessageContainerDetail.h"
#include "Network/NetworkMessage/MultipleMessageStreamingLoadDetail.h"

#include <string>

using std::make_shared;
using std::string;

namespace Network
{
    using MultipleMessageType = MultipleMessageContainer<MultipleMessageField, MultipleMessageByteType::Int8, MultipleMessageByteType::Uint8,
                                                         MultipleMessageByteType::Int16, MultipleMessageByteType::Uint16, MultipleMessageByteType::Int32,
                                                         MultipleMessageByteType::Uint32, MultipleMessageByteType::Int64, MultipleMessageByteType::Uint64,
                                                         MultipleMessageByteType::String>;

    using TestingType = MultipleMessageStreamingLoad<MultipleMessageSize<MultipleMessageType>::value, MultipleMessageType>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, MultipleMessageStreamingLoadTesting)

void Network::MultipleMessageStreamingLoadTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}
#include SYSTEM_WARNING_DISABLE(26414)
void Network::MultipleMessageStreamingLoadTesting ::BaseTest()
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

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

    multipleMessageContainer.Save(*messageTarget);

    MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

    TestingType multipleMessageStreamingLoad{};

    MultipleMessageType resultMultipleMessageContainer{};

    multipleMessageStreamingLoad.Load(resultMultipleMessageContainer, *messageSource);

    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int8>(), resultMultipleMessageContainer.GetValue<MultipleMessageField::Int8>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt8>(), resultMultipleMessageContainer.GetValue<MultipleMessageField::UInt8>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int16>(), resultMultipleMessageContainer.GetValue<MultipleMessageField::Int16>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt16>(), resultMultipleMessageContainer.GetValue<MultipleMessageField::UInt16>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int32>(), resultMultipleMessageContainer.GetValue<MultipleMessageField::Int32>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt32>(), resultMultipleMessageContainer.GetValue<MultipleMessageField::UInt32>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int64>(), resultMultipleMessageContainer.GetValue<MultipleMessageField::Int64>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt64>(), resultMultipleMessageContainer.GetValue<MultipleMessageField::UInt64>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::String>(), resultMultipleMessageContainer.GetValue<MultipleMessageField::String>());
}
