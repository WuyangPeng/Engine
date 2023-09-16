///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:50)

#include "MultipleMessageSizeTesting.h"
#include "Flags/MultipleMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MultipleMessageContainer.h"

Network::MultipleMessageSizeTesting::MultipleMessageSizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MultipleMessageSizeTesting)

void Network::MultipleMessageSizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::MultipleMessageSizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NineSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FiveSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TwoSizeTest);
}

void Network::MultipleMessageSizeTesting::NineSizeTest() noexcept
{
    using MultipleMessageContainer = MultipleMessageContainer<MultipleMessageField,
                                                              MultipleMessageByteType::Int8,
                                                              MultipleMessageByteType::Uint8,
                                                              MultipleMessageByteType::Int16,
                                                              MultipleMessageByteType::Uint16,
                                                              MultipleMessageByteType::Int32,
                                                              MultipleMessageByteType::Uint32,
                                                              MultipleMessageByteType::Int64,
                                                              MultipleMessageByteType::Uint64,
                                                              MultipleMessageByteType::String>;

    static_assert(MultipleMessageSize<MultipleMessageContainer>::value == 9, "MultipleMessageSize error");
}

void Network::MultipleMessageSizeTesting::FiveSizeTest() noexcept
{
    using MultipleMessageContainer = MultipleMessageContainer<MultipleMessageField,
                                                              MultipleMessageByteType::Int8,
                                                              MultipleMessageByteType::Uint8,
                                                              MultipleMessageByteType::Int16,
                                                              MultipleMessageByteType::Uint16,
                                                              MultipleMessageByteType::Int32>;

    static_assert(MultipleMessageSize<MultipleMessageContainer>::value == 5, "MultipleMessageSize error");
}

void Network::MultipleMessageSizeTesting::TwoSizeTest() noexcept
{
    using MultipleMessageContainer = MultipleMessageContainer<MultipleMessageField, MultipleMessageByteType::Int8, MultipleMessageByteType::Uint8>;

    static_assert(MultipleMessageSize<MultipleMessageContainer>::value == 2, "MultipleMessageSize error");
}
