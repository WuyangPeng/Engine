///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/12 09:15)

#include "MultipleMessageCastTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MultipleMessageCast.h"

#include <string>

Network::MultipleMessageCastTesting::MultipleMessageCastTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MultipleMessageCastTesting)

void Network::MultipleMessageCastTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::MultipleMessageCastTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CastTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ParameterCastTest);
}

void Network::MultipleMessageCastTesting::CastTest() noexcept
{
    static_assert(std::is_same_v<MultipleMessageCast<MultipleMessageByteType::String>::ValueType, std::string>, "MultipleMessageCast string error.");
    static_assert(std::is_same_v<MultipleMessageCast<MultipleMessageByteType::Int8>::ValueType, int8_t>, "MultipleMessageCast int8_t error.");
    static_assert(std::is_same_v<MultipleMessageCast<MultipleMessageByteType::Uint8>::ValueType, uint8_t>, "MultipleMessageCast uint8_t error.");
    static_assert(std::is_same_v<MultipleMessageCast<MultipleMessageByteType::Int16>::ValueType, int16_t>, "MultipleMessageCast int16_t error.");
    static_assert(std::is_same_v<MultipleMessageCast<MultipleMessageByteType::Uint16>::ValueType, uint16_t>, "MultipleMessageCast uint16_t error.");
    static_assert(std::is_same_v<MultipleMessageCast<MultipleMessageByteType::Int32>::ValueType, int32_t>, "MultipleMessageCast int32_t error.");
    static_assert(std::is_same_v<MultipleMessageCast<MultipleMessageByteType::Uint32>::ValueType, uint32_t>, "MultipleMessageCast uint32_t error.");
    static_assert(std::is_same_v<MultipleMessageCast<MultipleMessageByteType::Int64>::ValueType, int64_t>, "MultipleMessageCast int64_t error.");
    static_assert(std::is_same_v<MultipleMessageCast<MultipleMessageByteType::Uint64>::ValueType, uint64_t>, "MultipleMessageCast uint64_t error.");
    static_assert(std::is_same_v<MultipleMessageCast<MultipleMessageByteType::Bool>::ValueType, bool>, "MultipleMessageCast bool error.");
    static_assert(std::is_same_v<MultipleMessageCast<MultipleMessageByteType::Float>::ValueType, float>, "MultipleMessageCast float error.");
    static_assert(std::is_same_v<MultipleMessageCast<MultipleMessageByteType::Double>::ValueType, double>, "MultipleMessageCast double error.");
}

void Network::MultipleMessageCastTesting::ParameterCastTest() noexcept
{
    static_assert(std::is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::String>::ValueType, const std::string&>, "MultipleMessageParameterCast string error.");
    static_assert(std::is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Int8>::ValueType, int8_t>, "MultipleMessageParameterCast int8_t error.");
    static_assert(std::is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Uint8>::ValueType, uint8_t>, "MultipleMessageParameterCast uint8_t error.");
    static_assert(std::is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Int16>::ValueType, int16_t>, "MultipleMessageParameterCast int16_t error.");
    static_assert(std::is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Uint16>::ValueType, uint16_t>, "MultipleMessageParameterCast uint16_t error.");
    static_assert(std::is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Int32>::ValueType, int32_t>, "MultipleMessageParameterCast int32_t error.");
    static_assert(std::is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Uint32>::ValueType, uint32_t>, "MultipleMessageParameterCast uint32_t error.");
    static_assert(std::is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Int64>::ValueType, int64_t>, "MultipleMessageParameterCast int64_t error.");
    static_assert(std::is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Uint64>::ValueType, uint64_t>, "MultipleMessageParameterCast uint64_t error.");
    static_assert(std::is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Bool>::ValueType, bool>, "MultipleMessageCast bool error.");
    static_assert(std::is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Float>::ValueType, float>, "MultipleMessageCast float error.");
    static_assert(std::is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Double>::ValueType, double>, "MultipleMessageCast double error.");
}