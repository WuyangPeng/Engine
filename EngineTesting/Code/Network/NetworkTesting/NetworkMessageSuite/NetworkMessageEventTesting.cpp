///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/16 09:51)

#include "NetworkMessageEventTesting.h"
#include "Detail/TestNetworkMessageEvent.h"
#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Network::NetworkMessageEventTesting::NetworkMessageEventTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NetworkMessageEventTesting)

void Network::NetworkMessageEventTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::NetworkMessageEventTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EventTest);
}

void Network::NetworkMessageEventTesting::EventTest()
{
    constexpr auto messageId = 6LL;
    const auto testMessage = std::make_shared<TestNullMessage>(messageId);

    TestNetworkMessageEvent testNetworkMessageEvent{};

    ASSERT_EQUAL(testNetworkMessageEvent.GetValue(), 0);

    const auto nowTime = testNetworkMessageEvent.GetNowTime();

    testNetworkMessageEvent.CallBackEvent(0, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent.GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent.GetNowTime(), nowTime);

    testNetworkMessageEvent.CallBackEvent(1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent.GetValue(), messageId);
    ASSERT_LESS(nowTime, testNetworkMessageEvent.GetNowTime());
}
