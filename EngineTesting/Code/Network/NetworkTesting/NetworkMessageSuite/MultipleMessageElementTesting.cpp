///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:50)

#include "MultipleMessageElementTesting.h"
#include "Flags/MultipleMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MultipleMessageContainer.h"
#include "Network/NetworkMessage/MultipleMessageElement.h"

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
}

Network::MultipleMessageElementTesting::MultipleMessageElementTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MultipleMessageElementTesting)

void Network::MultipleMessageElementTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::MultipleMessageElementTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void Network::MultipleMessageElementTesting::BaseTest() noexcept
{
    static_assert(MultipleMessageElement<0, MultipleMessageType>::byteType == MultipleMessageByteType::Int8, "MultipleMessageElement int8 error");
    static_assert(MultipleMessageElement<1, MultipleMessageType>::byteType == MultipleMessageByteType::Uint8, "MultipleMessageElement uint8 error");
    static_assert(MultipleMessageElement<2, MultipleMessageType>::byteType == MultipleMessageByteType::Int16, "MultipleMessageElement int16 error");
    static_assert(MultipleMessageElement<3, MultipleMessageType>::byteType == MultipleMessageByteType::Uint16, "MultipleMessageElement uint16 error");
    static_assert(MultipleMessageElement<4, MultipleMessageType>::byteType == MultipleMessageByteType::Int32, "MultipleMessageElement int32 error");
    static_assert(MultipleMessageElement<5, MultipleMessageType>::byteType == MultipleMessageByteType::Uint32, "MultipleMessageElement uint32 error");
    static_assert(MultipleMessageElement<6, MultipleMessageType>::byteType == MultipleMessageByteType::Int64, "MultipleMessageElement int64 error");
    static_assert(MultipleMessageElement<7, MultipleMessageType>::byteType == MultipleMessageByteType::Uint64, "MultipleMessageElement uint64 error");
    static_assert(MultipleMessageElement<8, MultipleMessageType>::byteType == MultipleMessageByteType::String, "MultipleMessageElement string error");
}
