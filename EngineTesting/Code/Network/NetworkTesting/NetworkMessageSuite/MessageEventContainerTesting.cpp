///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 16:31)

#include "MessageEventContainerTesting.h"
#include "Detail/TestNetworkMessageEvent.h"
#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/NetworkMessage/MessageEventContainer.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, MessageEventContainer)

void Network::MessageEventContainerTesting::MainTest() noexcept
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingleContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PriorityContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultiContainerTest);
}

void Network::MessageEventContainerTesting::SingleContainerTest()
{
    TestNetworkMessageEventSharedPtr testNetworkMessageEvent{ make_shared<TestNetworkMessageEvent>() };

    TestingType messageEventContainer = TestingType::Create();

    messageEventContainer.Insert(testNetworkMessageEvent);

    ASSERT_EQUAL(testNetworkMessageEvent->GetValue(), 0);

    constexpr int64_t messageID{ 6 };
    TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

    messageEventContainer.OnEvent(0, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent->GetValue(), 0);

    messageEventContainer.OnEvent(1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent->GetValue(), boost::numeric_cast<int>(messageID));
}

void Network::MessageEventContainerTesting::PriorityContainerTest()
{
    TestNetworkMessageEventSharedPtr testNetworkMessageEvent1{ make_shared<TestNetworkMessageEvent>() };
    TestNetworkMessageEventSharedPtr testNetworkMessageEvent2{ make_shared<TestNetworkMessageEvent>() };

    TestingType messageEventContainer = TestingType::Create();

    messageEventContainer.Insert(testNetworkMessageEvent1);
    messageEventContainer.Insert(testNetworkMessageEvent2, MessageEventPriority::Highest);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), 0);

    constexpr int64_t messageID{ 6 };
    TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

    messageEventContainer.OnEvent(0, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), 0);

    messageEventContainer.OnEvent(1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), boost::numeric_cast<int>(messageID));
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), boost::numeric_cast<int>(messageID));

    ASSERT_GREATER(testNetworkMessageEvent1->GetNowTime(), testNetworkMessageEvent2->GetNowTime());
}

void Network::MessageEventContainerTesting::MultiContainerTest()
{
    TestNetworkMessageEventSharedPtr testNetworkMessageEvent1{ make_shared<TestNetworkMessageEvent>() };
    TestNetworkMessageEventSharedPtr testNetworkMessageEvent2{ make_shared<TestNetworkMessageEvent>() };

    TestingType messageEventContainer = TestingType::Create();

    messageEventContainer.Insert(testNetworkMessageEvent1);
    messageEventContainer.Insert(testNetworkMessageEvent2);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), 0);

    constexpr int64_t messageID{ 6 };
    TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

    messageEventContainer.OnEvent(0, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), 0);

    messageEventContainer.OnEvent(1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), boost::numeric_cast<int>(messageID));
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), boost::numeric_cast<int>(messageID));
}
