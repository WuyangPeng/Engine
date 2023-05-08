///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 11:27)

#include "NetworkMessageEventTesting.h"
#include "Detail/TestNetworkMessageEvent.h"
#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::make_shared;

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
    constexpr int64_t messageID{ 6 };
    TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

    TestNetworkMessageEvent testNetworkMessageEvent;

    ASSERT_EQUAL(testNetworkMessageEvent.GetValue(), 0);

    const auto nowTime = testNetworkMessageEvent.GetNowTime();

    testNetworkMessageEvent.CallBackEvent(0, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent.GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent.GetNowTime(), nowTime);

    testNetworkMessageEvent.CallBackEvent(1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent.GetValue(), messageID);
    ASSERT_LESS(nowTime, testNetworkMessageEvent.GetNowTime());
}
