// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 14:04)

#include "MessageTypeConditionOperatingTesting.h" 
#include "ThreadingCoreRenderEngineTesting/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/MessageTypeConditionOperating.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"

using std::set;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, MessageTypeConditionOperating)

void Network::MessageTypeConditionOperatingTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(OperatingTest);
}

void Network::MessageTypeConditionOperatingTesting
	::OperatingTest()
{
	auto version = g_TCRETestingVersion - 4;
	MessageTypeCondition messageTypeCondition1{ VersionsCondition::Greater,version };
	MessageTypeCondition messageTypeCondition2{ VersionsCondition::GreaterEequal, version };
	MessageTypeCondition messageTypeCondition3{ VersionsCondition::Equality, version };
	MessageTypeCondition messageTypeCondition4{ VersionsCondition::LessEequal, version };
	MessageTypeCondition messageTypeCondition5{ VersionsCondition::Less, version };
	MessageTypeCondition messageTypeCondition6{ version - 1, version + 1 };
	MessageTypeCondition messageTypeCondition7{ set<int>{ version - 2, version + 3 } };
	MessageTypeCondition messageTypeCondition8{};

	TestingType messageTypeConditionOperating{};

	ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition1, messageTypeCondition2));
	ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition2, messageTypeCondition3));
	ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition3, messageTypeCondition4));
	ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition4, messageTypeCondition5));

	ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition1, messageTypeCondition6));
	ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition2, messageTypeCondition6));
	ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition3, messageTypeCondition6));
	ASSERT_TRUE(messageTypeConditionOperating(messageTypeCondition4, messageTypeCondition6));
	ASSERT_TRUE(messageTypeConditionOperating(messageTypeCondition5, messageTypeCondition6));

	ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition1, messageTypeCondition7));
	ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition2, messageTypeCondition7));
	ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition3, messageTypeCondition7));
	ASSERT_TRUE(messageTypeConditionOperating(messageTypeCondition4, messageTypeCondition7));
	ASSERT_TRUE(messageTypeConditionOperating(messageTypeCondition5, messageTypeCondition7));

	ASSERT_TRUE(messageTypeConditionOperating(messageTypeCondition7, messageTypeCondition6));

	ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition1, messageTypeCondition8));
	ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition2, messageTypeCondition8));
	ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition3, messageTypeCondition8));
	ASSERT_TRUE(messageTypeConditionOperating(messageTypeCondition4, messageTypeCondition8));
	ASSERT_TRUE(messageTypeConditionOperating(messageTypeCondition5, messageTypeCondition8));
}


