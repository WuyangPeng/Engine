///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 18:45)

#include "MultipleMessageContainerGroupTesting.h"
#include "Flags/MultipleMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MultipleMessageContainer.h"
#include "Network/NetworkMessage/MultipleMessageContainerGroupDetail.h"

using std::make_shared;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, MultipleMessageContainerGroupTesting)

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

    using TestingType = MultipleMessageContainerGroup<MultipleMessageField,
                                                      MultipleMessageByteType::Int8,
                                                      MultipleMessageByteType::Uint8,
                                                      MultipleMessageByteType::Int16,
                                                      MultipleMessageByteType::Uint16,
                                                      MultipleMessageByteType::Int32,
                                                      MultipleMessageByteType::Uint32,
                                                      MultipleMessageByteType::Int64,
                                                      MultipleMessageByteType::Uint64,
                                                      MultipleMessageByteType::String>;
}

void Network::MultipleMessageContainerGroupTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
}

void Network::MultipleMessageContainerGroupTesting::BaseTest()
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

    MultipleMessageType multipleMessageContainer1{ int8Value, uint8Value, int16Value, uint16Value, int32Value, uint32Value, int64Value, uint64Value, stringValue };
    MultipleMessageType multipleMessageContainer2{ boost::numeric_cast<int8_t>(int8Value + 1),
                                                   boost::numeric_cast<uint8_t>(uint8Value + 1),
                                                   boost::numeric_cast<int16_t>(int16Value + 1),
                                                   boost::numeric_cast<uint16_t>(uint16Value + 1),
                                                   int32Value + 1,
                                                   uint32Value + 1,
                                                   int64Value + 1,
                                                   uint64Value + 1,
                                                   stringValue + "1" };
    MultipleMessageType multipleMessageContainer3{ boost::numeric_cast<int8_t>(int8Value + 2),
                                                   boost::numeric_cast<uint8_t>(uint8Value + 2),
                                                   boost::numeric_cast<int16_t>(int16Value + 2),
                                                   boost::numeric_cast<uint16_t>(uint16Value + 2),
                                                   int32Value + 2,
                                                   uint32Value + 2,
                                                   int64Value + 2,
                                                   uint64Value + 2,
                                                   stringValue + "2" };
    TestingType::GroupType group{ multipleMessageContainer1, multipleMessageContainer2, multipleMessageContainer3 };

    TestingType multipleMessageContainerGroup{ group };

    ASSERT_EQUAL(multipleMessageContainerGroup.GetSize(), boost::numeric_cast<int>(group.size()));

    auto index = 0;
    for (const auto& value : multipleMessageContainerGroup)
    {
        const auto& multipleMessage = group.at(index);

        ASSERT_EQUAL(multipleMessage.GetValue<MultipleMessageField::Int8>(), value.GetValue<MultipleMessageField::Int8>());
        ASSERT_EQUAL(multipleMessage.GetValue<MultipleMessageField::UInt8>(), value.GetValue<MultipleMessageField::UInt8>());
        ASSERT_EQUAL(multipleMessage.GetValue<MultipleMessageField::Int16>(), value.GetValue<MultipleMessageField::Int16>());
        ASSERT_EQUAL(multipleMessage.GetValue<MultipleMessageField::UInt16>(), value.GetValue<MultipleMessageField::UInt16>());
        ASSERT_EQUAL(multipleMessage.GetValue<MultipleMessageField::Int32>(), value.GetValue<MultipleMessageField::Int32>());
        ASSERT_EQUAL(multipleMessage.GetValue<MultipleMessageField::UInt32>(), value.GetValue<MultipleMessageField::UInt32>());
        ASSERT_EQUAL(multipleMessage.GetValue<MultipleMessageField::Int64>(), value.GetValue<MultipleMessageField::Int64>());
        ASSERT_EQUAL(multipleMessage.GetValue<MultipleMessageField::UInt64>(), value.GetValue<MultipleMessageField::UInt64>());
        ASSERT_EQUAL(multipleMessage.GetValue<MultipleMessageField::String>(), value.GetValue<MultipleMessageField::String>());

        ++index;
    }
}

void Network::MultipleMessageContainerGroupTesting::StreamingTest()
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

    MultipleMessageType multipleMessageContainer1{ int8Value, uint8Value, int16Value, uint16Value, int32Value, uint32Value, int64Value, uint64Value, stringValue };
    MultipleMessageType multipleMessageContainer2{ boost::numeric_cast<int8_t>(int8Value + 1), boost::numeric_cast<uint8_t>(uint8Value + 1),
                                                   boost::numeric_cast<int16_t>(int16Value + 1), boost::numeric_cast<uint16_t>(uint16Value + 1),
                                                   int32Value + 1, uint32Value + 1, int64Value + 1, uint64Value + 1, stringValue + "1" };
    MultipleMessageType multipleMessageContainer3{ boost::numeric_cast<int8_t>(int8Value + 2), boost::numeric_cast<uint8_t>(uint8Value + 2),
                                                   boost::numeric_cast<int16_t>(int16Value + 2), boost::numeric_cast<uint16_t>(uint16Value + 2),
                                                   int32Value + 2, uint32Value + 2, int64Value + 2, uint64Value + 2, stringValue + "2" };
    TestingType::GroupType group{ multipleMessageContainer1, multipleMessageContainer2, multipleMessageContainer3 };

    TestingType multipleMessageContainerGroup{ group };

    const auto streamSize = multipleMessageContainer1.GetStreamingSize() +
                            multipleMessageContainer2.GetStreamingSize() +
                            multipleMessageContainer1.GetStreamingSize() +
                            CORE_TOOLS_STREAM_SIZE(int32_t{});

    ASSERT_EQUAL(multipleMessageContainerGroup.GetStreamingSize(), streamSize);

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

    multipleMessageContainerGroup.Save(*messageTarget);

    MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

    TestingType resultMultipleMessageContainerGroup{};

    resultMultipleMessageContainerGroup.Load(*messageSource);

    ASSERT_EQUAL_FAILURE_THROW(resultMultipleMessageContainerGroup.GetSize(), multipleMessageContainerGroup.GetSize(), "数组大小不相等！");

    auto index = 0;
    for (const auto& resultValue : resultMultipleMessageContainerGroup)
    {
        const auto& value = multipleMessageContainerGroup.GetValue(index);

        ASSERT_EQUAL_FAILURE_THROW(value.GetSize(), resultValue.GetSize(), "数组大小不相等！");

        ASSERT_EQUAL(resultValue.GetValue<MultipleMessageField::Int8>(), value.GetValue<MultipleMessageField::Int8>());
        ASSERT_EQUAL(resultValue.GetValue<MultipleMessageField::UInt8>(), value.GetValue<MultipleMessageField::UInt8>());
        ASSERT_EQUAL(resultValue.GetValue<MultipleMessageField::Int16>(), value.GetValue<MultipleMessageField::Int16>());
        ASSERT_EQUAL(resultValue.GetValue<MultipleMessageField::UInt16>(), value.GetValue<MultipleMessageField::UInt16>());
        ASSERT_EQUAL(resultValue.GetValue<MultipleMessageField::Int32>(), value.GetValue<MultipleMessageField::Int32>());
        ASSERT_EQUAL(resultValue.GetValue<MultipleMessageField::UInt32>(), value.GetValue<MultipleMessageField::UInt32>());
        ASSERT_EQUAL(resultValue.GetValue<MultipleMessageField::Int64>(), value.GetValue<MultipleMessageField::Int64>());
        ASSERT_EQUAL(resultValue.GetValue<MultipleMessageField::UInt64>(), value.GetValue<MultipleMessageField::UInt64>());
        ASSERT_EQUAL(resultValue.GetValue<MultipleMessageField::String>(), value.GetValue<MultipleMessageField::String>());

        ++index;
    }
}