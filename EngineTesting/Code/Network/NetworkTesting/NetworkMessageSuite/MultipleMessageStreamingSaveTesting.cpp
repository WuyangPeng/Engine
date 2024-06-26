///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:50)

#include "MultipleMessageStreamingSaveTesting.h"
#include "Flags/MultipleMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MultipleMessageContainerDetail.h"
#include "Network/NetworkMessage/MultipleMessageStreamingSaveDetail.h"

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

    using TestingType = MultipleMessageStreamingSave<MultipleMessageSize<MultipleMessageType>::value, MultipleMessageType>;
}

Network::MultipleMessageStreamingSaveTesting::MultipleMessageStreamingSaveTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MultipleMessageStreamingSaveTesting)

void Network::MultipleMessageStreamingSaveTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::MultipleMessageStreamingSaveTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void Network::MultipleMessageStreamingSaveTesting::BaseTest()
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

    const TestingType multipleMessageStreamingSave{};

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    MessageTarget messageTarget{ buffer };

    multipleMessageStreamingSave.Save(multipleMessageContainer, messageTarget);

    if (auto initialBuffered = buffer.GetInitialBufferedPtr();
        initialBuffered != nullptr)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

        const auto resultInt8Value = *initialBuffered;
        ASSERT_EQUAL(resultInt8Value, int8Value);
        initialBuffered += CoreTools::GetStreamSize(resultInt8Value);

        const auto resultUInt8Value = *reinterpret_cast<uint8_t*>(initialBuffered);
        ASSERT_EQUAL(resultUInt8Value, uint8Value);
        initialBuffered += CoreTools::GetStreamSize(resultUInt8Value);

        const auto resultInt16Value = *reinterpret_cast<int16_t*>(initialBuffered);
        ASSERT_EQUAL(resultInt16Value, int16Value);
        initialBuffered += CoreTools::GetStreamSize(resultInt16Value);

        const auto resultUInt16Value = *reinterpret_cast<uint16_t*>(initialBuffered);
        ASSERT_EQUAL(resultUInt16Value, uint16Value);
        initialBuffered += CoreTools::GetStreamSize(resultUInt16Value);

        const auto resultInt32Value = *reinterpret_cast<int32_t*>(initialBuffered);
        ASSERT_EQUAL(resultInt32Value, int32Value);
        initialBuffered += CoreTools::GetStreamSize(resultInt32Value);

        const auto resultUInt32Value = *reinterpret_cast<uint32_t*>(initialBuffered);
        ASSERT_EQUAL(resultUInt32Value, uint32Value);
        initialBuffered += CoreTools::GetStreamSize(resultUInt32Value);

        const auto resultInt64Value = *reinterpret_cast<int64_t*>(initialBuffered);
        ASSERT_EQUAL(resultInt64Value, int64Value);
        initialBuffered += CoreTools::GetStreamSize(resultInt64Value);

        const auto resultUInt64Value = *reinterpret_cast<uint64_t*>(initialBuffered);
        ASSERT_EQUAL(resultUInt64Value, uint64Value);
        initialBuffered += CoreTools::GetStreamSize(resultUInt64Value);

        const auto length = *reinterpret_cast<int32_t*>(initialBuffered);
        ASSERT_EQUAL(length, boost::numeric_cast<int32_t>(stringValue.size()));
        initialBuffered += CoreTools::GetStreamSize(length);

        const std::string resultStringValue{ initialBuffered, initialBuffered + length };

#include SYSTEM_WARNING_POP

        ASSERT_EQUAL(resultStringValue, stringValue);
    }
}
