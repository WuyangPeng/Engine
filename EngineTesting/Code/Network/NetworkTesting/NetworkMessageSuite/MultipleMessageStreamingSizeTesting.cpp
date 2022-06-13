///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 11:08)

#include "MultipleMessageStreamingSizeTesting.h"
#include "Flags/MultipleMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MultipleMessageCast.h"
#include "Network/NetworkMessage/MultipleMessageContainerDetail.h"
#include "Network/NetworkMessage/MultipleMessageStreamingSizeDetail.h"

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

    using TestingType = MultipleMessageStreamingSize<MultipleMessageSize<MultipleMessageType>::value, MultipleMessageType>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, MultipleMessageStreamingSizeTesting)

void Network::MultipleMessageStreamingSizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void Network::MultipleMessageStreamingSizeTesting::BaseTest()
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

    const auto streamSize = CORE_TOOLS_STREAM_SIZE(int8Value) +
                            CORE_TOOLS_STREAM_SIZE(int16Value) +
                            CORE_TOOLS_STREAM_SIZE(int32Value) +
                            CORE_TOOLS_STREAM_SIZE(int64Value) +
                            CORE_TOOLS_STREAM_SIZE(uint8Value) +
                            CORE_TOOLS_STREAM_SIZE(uint16Value) +
                            CORE_TOOLS_STREAM_SIZE(uint32Value) +
                            CORE_TOOLS_STREAM_SIZE(uint64Value) +
                            CORE_TOOLS_STREAM_SIZE(stringValue);

    TestingType multipleMessageStreamingSize{};

    ASSERT_EQUAL(multipleMessageStreamingSize.GetStreamingSize(multipleMessageContainer), streamSize);
}
