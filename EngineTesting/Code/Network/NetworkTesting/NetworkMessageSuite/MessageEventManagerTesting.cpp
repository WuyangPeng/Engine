///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:47)

#include "MessageEventManagerTesting.h"
#include "Detail/TestNetworkMessageEvent.h"
#include "Detail/TestNullMessage.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/NetworkMessage/MessageEventManager.h"

using namespace std::literals;

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
    ASSERT_NOT_THROW_EXCEPTION_0(DescribeTest);
}

void Network::MessageEventManagerTesting::SingleContainerTest()
{
    const auto testNetworkMessageEvent = std::make_shared<TestNetworkMessageEvent>();

    MessageEventManager messageEventContainer = MessageEventManager::Create();

    constexpr auto messageId = 6LL;

    messageEventContainer.Insert(messageId, testNetworkMessageEvent);

    ASSERT_EQUAL(testNetworkMessageEvent->GetValue(), 0);

    const auto testMessage = std::make_shared<TestNullMessage>(messageId);

    messageEventContainer.OnEvent(1, messageId - 1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent->GetValue(), 0);

    messageEventContainer.OnEvent(1, messageId, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent->GetValue(), boost::numeric_cast<int>(messageId));
}

void Network::MessageEventManagerTesting::PriorityContainerTest()
{
    constexpr auto messageId = 6LL;

    const auto testNetworkMessageEvent0 = std::make_shared<TestNetworkMessageEvent>();
    const auto testNetworkMessageEvent1 = std::make_shared<TestNetworkMessageEvent>();

    auto messageEventContainer = MessageEventManager::Create();

    messageEventContainer.Insert(messageId, testNetworkMessageEvent1);
    messageEventContainer.Insert(messageId, testNetworkMessageEvent0, MessageEventPriority::Highest);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent0->GetValue(), 0);

    const auto testMessage = std::make_shared<TestNullMessage>(messageId);

    messageEventContainer.OnEvent(1, messageId - 1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent0->GetValue(), 0);

    messageEventContainer.OnEvent(1, messageId, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), boost::numeric_cast<int>(messageId));
    ASSERT_EQUAL(testNetworkMessageEvent0->GetValue(), boost::numeric_cast<int>(messageId));

    ASSERT_GREATER(testNetworkMessageEvent1->GetNowTime(), testNetworkMessageEvent0->GetNowTime());
}

void Network::MessageEventManagerTesting::MultiContainerTest()
{
    constexpr auto messageId = 6LL;

    const auto testNetworkMessageEvent0 = std::make_shared<TestNetworkMessageEvent>();
    const auto testNetworkMessageEvent1 = std::make_shared<TestNetworkMessageEvent>();

    MessageEventManager messageEventContainer = MessageEventManager::Create();

    messageEventContainer.Insert(messageId, testNetworkMessageEvent1);
    messageEventContainer.Insert(messageId, testNetworkMessageEvent0);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent0->GetValue(), 0);

    const auto testMessage = std::make_shared<TestNullMessage>(messageId);

    messageEventContainer.OnEvent(1, messageId - 1, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent0->GetValue(), 0);

    messageEventContainer.OnEvent(1, messageId, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), boost::numeric_cast<int>(messageId));
    ASSERT_EQUAL(testNetworkMessageEvent0->GetValue(), boost::numeric_cast<int>(messageId));
}

void Network::MessageEventManagerTesting::DescribeTest()
{
    constexpr auto messageId = 6LL;
    const auto messageDescribe = "Describe"s;

    const auto testNetworkMessageEvent0 = std::make_shared<TestNetworkMessageEvent>();
    const auto testNetworkMessageEvent1 = std::make_shared<TestNetworkMessageEvent>();

    MessageEventManager messageEventContainer = MessageEventManager::Create();

    messageEventContainer.Insert(messageDescribe, testNetworkMessageEvent1);
    messageEventContainer.Insert(messageDescribe, testNetworkMessageEvent0);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent0->GetValue(), 0);

    const auto testMessage = std::make_shared<TestNullMessage>(messageId);

    messageEventContainer.OnEvent(1, messageDescribe + "1", testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), 0);
    ASSERT_EQUAL(testNetworkMessageEvent0->GetValue(), 0);

    messageEventContainer.OnEvent(1, messageDescribe, testMessage);

    ASSERT_EQUAL(testNetworkMessageEvent1->GetValue(), boost::numeric_cast<int>(messageId));
    ASSERT_EQUAL(testNetworkMessageEvent0->GetValue(), boost::numeric_cast<int>(messageId));
}
