///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 10:48)

#include "MultipleMessageInitValueTesting.h"
#include "Flags/MultipleMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MultipleMessageCast.h"
#include "Network/NetworkMessage/MultipleMessageContainerDetail.h"
#include "Network/NetworkMessage/MultipleMessageInitValueDetail.h"

#include <string>

using std::string;

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

    using TestingType = MultipleMessageInitValue<MultipleMessageSize<MultipleMessageType>::value, MultipleMessageType>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, MultipleMessageInitValueTesting)

void Network::MultipleMessageInitValueTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void Network::MultipleMessageInitValueTesting::BaseTest()
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

    MultipleMessageType multipleMessageContainer{};

    TestingType multipleMessageInitValue{ multipleMessageContainer,
                                          int8Value,
                                          uint8Value,
                                          int16Value,
                                          uint16Value,
                                          int32Value,
                                          uint32Value,
                                          int64Value,
                                          uint64Value,
                                          stringValue };

    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int8>(), int8Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt8>(), uint8Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int16>(), int16Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt16>(), uint16Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int32>(), int32Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt32>(), uint32Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::Int64>(), int64Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::UInt64>(), uint64Value);
    ASSERT_EQUAL(multipleMessageContainer.GetValue<MultipleMessageField::String>(), stringValue);
}
