///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 10:47)

#include "MultipleMessageElementTesting.h"
#include "Flags/MultipleMessageType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MultipleMessageContainer.h"
#include "Network/NetworkMessage/MultipleMessageElement.h"

#include <string>

using std::is_same_v;
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
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, MultipleMessageElementTesting)

void Network::MultipleMessageElementTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void Network::MultipleMessageElementTesting::BaseTest() noexcept
{
    static_assert(MultipleMessageElement<0, MultipleMessageType>::sm_ByteType == MultipleMessageByteType::Int8, "MultipleMessageElement int8 error");
    static_assert(MultipleMessageElement<1, MultipleMessageType>::sm_ByteType == MultipleMessageByteType::Uint8, "MultipleMessageElement uint8 error");
    static_assert(MultipleMessageElement<2, MultipleMessageType>::sm_ByteType == MultipleMessageByteType::Int16, "MultipleMessageElement int16 error");
    static_assert(MultipleMessageElement<3, MultipleMessageType>::sm_ByteType == MultipleMessageByteType::Uint16, "MultipleMessageElement uint16 error");
    static_assert(MultipleMessageElement<4, MultipleMessageType>::sm_ByteType == MultipleMessageByteType::Int32, "MultipleMessageElement int32 error");
    static_assert(MultipleMessageElement<5, MultipleMessageType>::sm_ByteType == MultipleMessageByteType::Uint32, "MultipleMessageElement uint32 error");
    static_assert(MultipleMessageElement<6, MultipleMessageType>::sm_ByteType == MultipleMessageByteType::Int64, "MultipleMessageElement int64 error");
    static_assert(MultipleMessageElement<7, MultipleMessageType>::sm_ByteType == MultipleMessageByteType::Uint64, "MultipleMessageElement uint64 error");
    static_assert(MultipleMessageElement<8, MultipleMessageType>::sm_ByteType == MultipleMessageByteType::String, "MultipleMessageElement string error");
}
