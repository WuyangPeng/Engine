///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 15:29)

#include "StreamMacroTesting.h"
#include "Detail/TestMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageSource.h"
#include "Network/NetworkMessage/MessageTarget.h"

#include <array>

using std::array;
using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, StreamMacroTesting)

void Network::StreamMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TestMessageTest);
}

void Network::StreamMacroTesting::TestMessageTest()
{
    constexpr auto size = 256;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto testMessage = make_shared<TestMessage>();

#include STSTEM_WARNING_POP

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size1024, 0, ParserStrategy::LittleEndian) };

    MessageTarget messageTarget{ buffer };

    MessageSource messageSource{ buffer };

    testMessage->Load(messageSource);
    testMessage->Save(messageTarget);

    ASSERT_LESS(0, testMessage->GetStreamingSize());
}
