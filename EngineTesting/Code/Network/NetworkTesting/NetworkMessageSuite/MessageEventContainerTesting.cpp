// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 13:56)

#include "MessageEventContainerTesting.h" 
#include "Detail/TestNullMessage.h"
#include "Detail/TestNetworkMessageEvent.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/NetworkMessage/MessageEventContainer.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

#include <boost/numeric/conversion/cast.hpp>

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, MessageEventContainer)

void Network::MessageEventContainerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SingleContainerTest);
	ASSERT_NOT_THROW_EXCEPTION_0(PriorityContainerTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MultiContainerTest);
}

void Network::MessageEventContainerTesting
	::SingleContainerTest()
{
	TestNetworkMessageEventSharedPtr testNetworkMessageEvent{ make_shared<TestNetworkMessageEvent>() };

	TestingType messageEventContainer{};

	messageEventContainer.Insert(testNetworkMessageEvent);

	ASSERT_EQUAL(testNetworkMessageEvent->GetValue(), 0);

	constexpr int64_t messageID{ 6 };
	TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

	messageEventContainer.OnEvent(0, testMessage);

	ASSERT_EQUAL(testNetworkMessageEvent->GetValue(), 0);

	messageEventContainer.OnEvent(1, testMessage);

	ASSERT_EQUAL(testNetworkMessageEvent->GetValue(), boost::numeric_cast<int>(messageID));
}

void Network::MessageEventContainerTesting
	::PriorityContainerTest()
{
	TestNetworkMessageEventSharedPtr testNetworkMessageEvent1{ make_shared<TestNetworkMessageEvent>() };
	TestNetworkMessageEventSharedPtr testNetworkMessageEvent2{ make_shared<TestNetworkMessageEvent>() };

	TestingType messageEventContainer{};

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

void Network::MessageEventContainerTesting
	::MultiContainerTest()
{
	TestNetworkMessageEventSharedPtr testNetworkMessageEvent1{ make_shared<TestNetworkMessageEvent>() };
	TestNetworkMessageEventSharedPtr testNetworkMessageEvent2{ make_shared<TestNetworkMessageEvent>() };

	TestingType messageEventContainer{};

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

