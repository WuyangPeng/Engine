///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/12 09:43)

#include "MultipleMessageContainerTesting.h"
#include "Flags/MultipleMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MultipleMessageContainerDetail.h"

Network::MultipleMessageContainerTesting::MultipleMessageContainerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MultipleMessageContainerTesting)

void Network::MultipleMessageContainerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = MultipleMessageContainer<MultipleMessageField,
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

void Network::MultipleMessageContainerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
}

void Network::MultipleMessageContainerTesting::BaseTest()
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

    TestingType multipleMessageContainer{ int8Value, uint8Value, int16Value, uint16Value, int32Value, uint32Value, int64Value, uint64Value, stringValue };

    ASSERT_EQUAL(multipleMessageContainer.GetSize(), boost::numeric_cast<int>(MultipleMessageSize<TestingType>::value));

    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int8>(), int8Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt8>(), uint8Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int16>(), int16Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt16>(), uint16Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int32>(), int32Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt32>(), uint32Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int64>(), int64Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt64>(), uint64Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::String>(), stringValue);

    multipleMessageContainer.SetValue<0>(int8Value + 1);
    multipleMessageContainer.SetValue<1>(uint8Value + 1);
    multipleMessageContainer.SetValue<2>(int16Value + 1);
    multipleMessageContainer.SetValue<3>(uint16Value + 1);
    multipleMessageContainer.SetValue<4>(int32Value + 1);
    multipleMessageContainer.SetValue<5>(uint32Value + 1);
    multipleMessageContainer.SetValue<6>(int64Value + 1);
    multipleMessageContainer.SetValue<7>(uint64Value + 1);
    multipleMessageContainer.SetValue<8>(stringValue + "1");

    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int8>(), int8Value + 1);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt8>(), uint8Value + 1);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int16>(), int16Value + 1);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt16>(), uint16Value + 1);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int32>(), int32Value + 1);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt32>(), uint32Value + 1);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int64>(), int64Value + 1);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt64>(), uint64Value + 1);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::String>(), stringValue + "1");
}

void Network::MultipleMessageContainerTesting::StreamingTest()
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

    const TestingType multipleMessageContainer{ int8Value, uint8Value, int16Value, uint16Value, int32Value, uint32Value, int64Value, uint64Value, stringValue };

    const auto streamSize = CoreTools::GetStreamSize(int8Value) +
                            CoreTools::GetStreamSize(int16Value) +
                            CoreTools::GetStreamSize(int32Value) +
                            CoreTools::GetStreamSize(int64Value) +
                            CoreTools::GetStreamSize(uint8Value) +
                            CoreTools::GetStreamSize(uint16Value) +
                            CoreTools::GetStreamSize(uint32Value) +
                            CoreTools::GetStreamSize(uint64Value) +
                            CoreTools::GetStreamSize(stringValue);

    ASSERT_EQUAL(multipleMessageContainer.GetStreamingSize(), streamSize);

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    MessageTarget messageTarget{ buffer };

    multipleMessageContainer.Save(messageTarget);

    MessageSource messageSource{ buffer };

    TestingType resultMessageContainer{};

    resultMessageContainer.Load(messageSource);

    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int8>(), resultMessageContainer.GetValue<MultipleMessageField::Int8>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt8>(), resultMessageContainer.GetValue<MultipleMessageField::UInt8>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int16>(), resultMessageContainer.GetValue<MultipleMessageField::Int16>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt16>(), resultMessageContainer.GetValue<MultipleMessageField::UInt16>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int32>(), resultMessageContainer.GetValue<MultipleMessageField::Int32>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt32>(), resultMessageContainer.GetValue<MultipleMessageField::UInt32>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int64>(), resultMessageContainer.GetValue<MultipleMessageField::Int64>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt64>(), resultMessageContainer.GetValue<MultipleMessageField::UInt64>());
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::String>(), resultMessageContainer.GetValue<MultipleMessageField::String>());
}