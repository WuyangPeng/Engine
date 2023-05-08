///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 16:33)

#include "MessageEventManagerTesting.h"
#include "Detail/TestNetworkMessageEvent.h"
#include "Detail/TestNullMessage.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/NetworkMessage/MessageEventManager.h"
using std::make_shared;

Network::MessageEventManagerTesting::MessageEventManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageEventManagerTesting)

void Network::MessageEventManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::MessageEventManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingleContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PriorityContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultiContainerTest);
}

void Network::MessageEventManagerTesting::SingleContainerTest()
{
    TestNetworkMessageEventSharedPtr testNetworkMessageEvent{ make_shared<TestNetworkMessageEvent>() };

    MessageEventManager messageEventContainer = MessageEventManager::Create();

    constexpr int64_t messageID{ 6 };

    messageEventContainer.Insert(messageID, testNetworkMessageEvent);

    ASSERT_EQUAL(testNetworkMessageEvent->GetValue(), 0);

    TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

    messageEventContainer.OnEvent(1, messageID - 1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent->GetValue(), 0);

    messageEventContainer.OnEvent(1, messageID, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent->GetValue(), boost::numeric_cast<int>(messageID));
}

void Network::MessageEventManagerTesting::PriorityContainerTest()
{
    constexpr int64_t messageID{ 6 };

    TestNetworkMessageEventSharedPtr testNetworkMessageEvent1{ make_shared<TestNetworkMessageEvent>() };
    TestNetworkMessageEventSharedPtr testNetworkMessageEvent2{ make_shared<TestNetworkMessageEvent>() };

    MessageEventManager messageEventContainer = MessageEventManager::Create();

    messageEventContainer.Insert(messageID, testNetworkMessageEvent1);
    messageEventContainer.Insert(messageID, testNetworkMessageEvent2, MessageEventPriority::Highest);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), 0);

    TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

    messageEventContainer.OnEvent(1, messageID - 1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), 0);

    messageEventContainer.OnEvent(1, messageID, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), boost::numeric_cast<int>(messageID));
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), boost::numeric_cast<int>(messageID));

    ASSERT_GREATER(testNetworkMessageEvent1->GetNowTime(), testNetworkMessageEvent2->GetNowTime());
}

void Network::MessageEventManagerTesting::MultiContainerTest()
{
    constexpr uint32_t messageID{ 6 };

    TestNetworkMessageEventSharedPtr testNetworkMessageEvent1{ make_shared<TestNetworkMessageEvent>() };
    TestNetworkMessageEventSharedPtr testNetworkMessageEvent2{ make_shared<TestNetworkMessageEvent>() };

    MessageEventManager messageEventContainer = MessageEventManager::Create();

    messageEventContainer.Insert(messageID, testNetworkMessageEvent1);
    messageEventContainer.Insert(messageID, testNetworkMessageEvent2);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), 0);

    TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

    messageEventContainer.OnEvent(1, messageID - 1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), 0);

    messageEventContainer.OnEvent(1, messageID, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), boost::numeric_cast<int>(messageID));
    ASSERT_EQUAL(testNetworkMessageEvent2->GetValue(), boost::numeric_cast<int>(messageID));
}
