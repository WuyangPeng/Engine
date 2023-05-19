///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/12 09:24)

#include "MultipleMessageStreamingLoadTesting.h"
#include "Flags/MultipleMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MultipleMessageCast.h"
#include "Network/NetworkMessage/MultipleMessageContainerDetail.h"
#include "Network/NetworkMessage/MultipleMessageStreamingLoadDetail.h"

#include <string>

namespace Network
{
    using MultipleMessageType = MultipleMessageContainer<MultipleMessageField,
                                                         MultipleMessageByteType::Int8,
                                                         MultipleMessageByteType::Uint8,
                                                         MultipleMessageByteType::Int16,
                                                         MultipleMessageByteType::Uint16,
                                                         MultipleMessageByteType::Int32,
                                                         MultipleMessageByteType::Uint32,
                                                         MultipleMessageByteType::Int64,
                                                         MultipleMessageByteType::Uint64,
                                                         MultipleMessageByteType::String>;

    using TestingType = MultipleMessageStreamingLoad<MultipleMessageSize<MultipleMessageType>::value, MultipleMessageType>;
}

Network::MultipleMessageStreamingLoadTesting::MultipleMessageStreamingLoadTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MultipleMessageStreamingLoadTesting)

void Network::MultipleMessageStreamingLoadTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::MultipleMessageStreamingLoadTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void Network::MultipleMessageStreamingLoadTesting::BaseTest()
{
    constexpr int8_t int8Value{ -8 };
    constexpr int16_t int16Value{ 24 };
    constexpr int32_t int32Value{ -24 };
    constexpr int64_t int64Value{ 56 };

    constexpr uint8_t uint8Value{ 18 };
    constexpr uint16_t uint16Value{ 124 };
    constexpr uint32_t uint32Value{ 224 };
    constexpr uint64_t uint64Value{ 156 };

    const std::string stringValue{ "string" };

    const MultipleMessageType multipleMessageContainer{ int8Value, uint8Value, int16Value, uint16Value, int32Value, uint32Value, int64Value, uint64Value, stringValue };

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };

    MessageTarget messageTarget{ buffer };

    multipleMessageContainer.Save(messageTarget);

    MessageSource messageSource{ buffer };

    const TestingType multipleMessageStreamingLoad{};

    MultipleMessageType resultMultipleMessageContainer{};

    multipleMessageStreamingLoad.Load(resultMultipleMessageContainer, messageSource);

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
