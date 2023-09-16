///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/16 10:10)

#include "StreamMacroTesting.h"
#include "Detail/TestMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"

Network::StreamMacroTesting::StreamMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, StreamMacroTesting)

void Network::StreamMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::StreamMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TestMessageTest);
}

void Network::StreamMacroTesting::TestMessageTest()
{
    TestMessage testMessage{};

    MessageBuffer buffer{ BuffBlockSize::Size1024, 0, ParserStrategy::LittleEndian };

    MessageTarget messageTarget{ buffer };

    MessageSource messageSource{ buffer };

    testMessage.Load(messageSource);
    testMessage.Save(messageTarget);

    ASSERT_LESS(0, testMessage.GetStreamingSize());
}
