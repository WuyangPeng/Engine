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
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MultipleMessageCast.h"
#include "Network/NetworkMessage/MultipleMessageContainerDetail.h"
#include "Network/NetworkMessage/MultipleMessageStreamingSizeDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
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

Network::MultipleMessageStreamingSizeTesting::MultipleMessageStreamingSizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MultipleMessageStreamingSizeTesting)

void Network::MultipleMessageStreamingSizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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

    const auto streamSize = CoreTools::GetStreamSize(int8Value) +
                            CoreTools::GetStreamSize(int16Value) +
                            CoreTools::GetStreamSize(int32Value) +
                            CoreTools::GetStreamSize(int64Value) +
                            CoreTools::GetStreamSize(uint8Value) +
                            CoreTools::GetStreamSize(uint16Value) +
                            CoreTools::GetStreamSize(uint32Value) +
                            CoreTools::GetStreamSize(uint64Value) +
                            CoreTools::GetStreamSize(stringValue);

    TestingType multipleMessageStreamingSize{};

    ASSERT_EQUAL(multipleMessageStreamingSize.GetStreamingSize(multipleMessageContainer), streamSize);
}
