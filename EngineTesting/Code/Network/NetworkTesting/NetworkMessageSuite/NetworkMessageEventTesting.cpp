// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 14:52)

#include "NetworkMessageEventTesting.h"
#include "Detail/TestNetworkMessageEvent.h"
#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, NetworkMessageEventTesting)

void Network::NetworkMessageEventTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EventTest);
}

void Network::NetworkMessageEventTesting ::EventTest()
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
