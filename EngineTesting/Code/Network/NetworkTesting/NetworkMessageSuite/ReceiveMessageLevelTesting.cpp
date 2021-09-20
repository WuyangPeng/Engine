// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 14:53)

#include "ReceiveMessageLevelTesting.h" 
#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/AssertMacro.h" 
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/NetworkMessage/ReceiveMessageLevel.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, ReceiveMessageLevel)

void Network::ReceiveMessageLevelTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ReceiveMessageTest);
}

void Network::ReceiveMessageLevelTesting
	::ReceiveMessageTest()
{
	TestingType receiveMessageLevel{};

	ASSERT_EQUAL(receiveMessageLevel.GetTopLevelSize(), 0);

	constexpr int64_t messageID{ 6 };
	TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

	for (auto i = 0; i < GetTestLoopCount(); ++i)
	{
		receiveMessageLevel.Insert(testMessage);

		ASSERT_EQUAL(receiveMessageLevel.GetTopLevelSize(), i + 1);

		ASSERT_EQUAL(receiveMessageLevel[i], testMessage);
	}
}

