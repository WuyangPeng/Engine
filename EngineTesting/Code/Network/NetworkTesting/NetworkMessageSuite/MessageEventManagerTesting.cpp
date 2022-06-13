///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/23 16:33)

#include "MessageEventManagerTesting.h"
#include "Detail/TestNetworkMessageEvent.h"
#include "Detail/TestNullMessage.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/NetworkMessage/MessageEventManager.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, MessageEventManager)

void Network::MessageEventManagerTesting::MainTest() noexcept
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingleContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PriorityContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultiContainerTest);
}

void Network::MessageEventManagerTesting::SingleContainerTest()
{
    TestNetworkMessageEventSharedPtr testNetworkMessageEvent{ make_shared<TestNetworkMessageEvent>() };

    TestingType messageEventContainer = TestingType::Create();

    constexpr int64_t messageID{ 6 };

    messageEventContainer.Insert(messageID, testNetworkMessageEvent);

    ASSERT_EQUAL(testNetworkMessageEvent->GetValue(), 0);

    TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

    messageEventContainer.OnEvent(messageID - 1, 1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent->GetValue(), 0);

    messageEventContainer.OnEvent(messageID, 1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent->GetValue(), boost::numeric_cast<int>(messageID));
}

void Network::MessageEventManagerTesting::PriorityContainerTest()
{
    constexpr int64_t messageID{ 6 };

    TestNetworkMessageEventSharedPtr testNetworkMessageEvent1{ make_shared<TestNetworkMessageEvent>() };
    TestNetworkMessageEventSharedPtr testNetworkMessageEvent2{ make_shared<TestNetworkMessageEvent>() };

    TestingType messageEventContainer = TestingType::Create();

    messageEventContainer.Insert(messageID, testNetworkMessageEvent1);
    messageEventContainer.Insert(messageID, testNetworkMessageEvent2, MessageEventPriority::Highest);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), 0);

    TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

    messageEventContainer.OnEvent(messageID - 1, 1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), 0);

    messageEventContainer.OnEvent(messageID, 1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), boost::numeric_cast<int>(messageID));
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), boost::numeric_cast<int>(messageID));

    ASSERT_GREATER(testNetworkMessageEvent1->GetNowTime(), testNetworkMessageEvent2->GetNowTime());
}

void Network::MessageEventManagerTesting::MultiContainerTest()
{
    constexpr uint32_t messageID{ 6 };

    TestNetworkMessageEventSharedPtr testNetworkMessageEvent1{ make_shared<TestNetworkMessageEvent>() };
    TestNetworkMessageEventSharedPtr testNetworkMessageEvent2{ make_shared<TestNetworkMessageEvent>() };

    TestingType messageEventContainer = TestingType::Create();

    messageEventContainer.Insert(messageID, testNetworkMessageEvent1);
    messageEventContainer.Insert(messageID, testNetworkMessageEvent2);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), 0);

    TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

    messageEventContainer.OnEvent(messageID - 1, 1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), 0);

    messageEventContainer.OnEvent(messageID, 1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), boost::numeric_cast<int>(messageID));
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), boost::numeric_cast<int>(messageID));
}
