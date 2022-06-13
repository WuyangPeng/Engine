///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 18:45)

#include "MultipleMessageCastTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MultipleMessageCast.h"

#include <string>

using std::is_same_v;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, MultipleMessageCastTesting)

void Network::MultipleMessageCastTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CastTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ParameterCastTest);
}

void Network::MultipleMessageCastTesting::CastTest() noexcept
{
    static_assert(is_same_v<MultipleMessageCast<MultipleMessageByteType::String>::ValueType, string>, "MultipleMessageCast string error.");
    static_assert(is_same_v<MultipleMessageCast<MultipleMessageByteType::Int8>::ValueType, int8_t>, "MultipleMessageCast int8_t error.");
    static_assert(is_same_v<MultipleMessageCast<MultipleMessageByteType::Uint8>::ValueType, uint8_t>, "MultipleMessageCast uint8_t error.");
    static_assert(is_same_v<MultipleMessageCast<MultipleMessageByteType::Int16>::ValueType, int16_t>, "MultipleMessageCast int16_t error.");
    static_assert(is_same_v<MultipleMessageCast<MultipleMessageByteType::Uint16>::ValueType, uint16_t>, "MultipleMessageCast uint16_t error.");
    static_assert(is_same_v<MultipleMessageCast<MultipleMessageByteType::Int32>::ValueType, int32_t>, "MultipleMessageCast int32_t error.");
    static_assert(is_same_v<MultipleMessageCast<MultipleMessageByteType::Uint32>::ValueType, uint32_t>, "MultipleMessageCast uint32_t error.");
    static_assert(is_same_v<MultipleMessageCast<MultipleMessageByteType::Int64>::ValueType, int64_t>, "MultipleMessageCast int64_t error.");
    static_assert(is_same_v<MultipleMessageCast<MultipleMessageByteType::Uint64>::ValueType, uint64_t>, "MultipleMessageCast uint64_t error.");
}

void Network::MultipleMessageCastTesting::ParameterCastTest() noexcept
{
    static_assert(is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::String>::ValueType, const string&>, "MultipleMessageParameterCast string error.");
    static_assert(is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Int8>::ValueType, int8_t>, "MultipleMessageParameterCast int8_t error.");
    static_assert(is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Uint8>::ValueType, uint8_t>, "MultipleMessageParameterCast uint8_t error.");
    static_assert(is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Int16>::ValueType, int16_t>, "MultipleMessageParameterCast int16_t error.");
    static_assert(is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Uint16>::ValueType, uint16_t>, "MultipleMessageParameterCast uint16_t error.");
    static_assert(is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Int32>::ValueType, int32_t>, "MultipleMessageParameterCast int32_t error.");
    static_assert(is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Uint32>::ValueType, uint32_t>, "MultipleMessageParameterCast uint32_t error.");
    static_assert(is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Int64>::ValueType, int64_t>, "MultipleMessageParameterCast int64_t error.");
    static_assert(is_same_v<MultipleMessageParameterCast<MultipleMessageByteType::Uint64>::ValueType, uint64_t>, "MultipleMessageParameterCast uint64_t error.");
}