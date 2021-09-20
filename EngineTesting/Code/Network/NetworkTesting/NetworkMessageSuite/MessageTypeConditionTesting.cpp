// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 14:04)

#include "MessageTypeConditionTesting.h" 
#include "ThreadingCoreRenderEngineTesting/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"

using std::set;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, MessageTypeCondition)

void Network::MessageTypeConditionTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
	ASSERT_NOT_THROW_EXCEPTION_0(RangeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SpecificTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AllTest);
}

void Network::MessageTypeConditionTesting
	::CompareTest()
{
	auto version = g_TCRETestingVersion - 2;
	TestingType messageTypeCondition1{ VersionsCondition::Greater,version };
	TestingType messageTypeCondition2{ VersionsCondition::GreaterEequal, version };
	TestingType messageTypeCondition3{ VersionsCondition::Equality, version };
	TestingType messageTypeCondition4{ VersionsCondition::LessEequal, version };
	TestingType messageTypeCondition5{ VersionsCondition::Less, version };

	ASSERT_FALSE(messageTypeCondition1.IsVersionsConform(version - 1));
	ASSERT_FALSE(messageTypeCondition1.IsVersionsConform(version));
	ASSERT_TRUE(messageTypeCondition1.IsVersionsConform(version + 1));
	ASSERT_TRUE(messageTypeCondition1.IsVersionsConform(version + 10));

	ASSERT_FALSE(messageTypeCondition2.IsVersionsConform(version - 1));
	ASSERT_TRUE(messageTypeCondition2.IsVersionsConform(version));
	ASSERT_TRUE(messageTypeCondition2.IsVersionsConform(version + 1));
	ASSERT_TRUE(messageTypeCondition2.IsVersionsConform(version + 10));

	ASSERT_FALSE(messageTypeCondition3.IsVersionsConform(version - 1));
	ASSERT_TRUE(messageTypeCondition3.IsVersionsConform(version));
	ASSERT_FALSE(messageTypeCondition3.IsVersionsConform(version + 1));

	ASSERT_TRUE(messageTypeCondition4.IsVersionsConform(version - 1));
	ASSERT_TRUE(messageTypeCondition4.IsVersionsConform(version));
	ASSERT_FALSE(messageTypeCondition4.IsVersionsConform(version + 1));

	ASSERT_TRUE(messageTypeCondition5.IsVersionsConform(version - 1));
	ASSERT_FALSE(messageTypeCondition5.IsVersionsConform(version));
	ASSERT_FALSE(messageTypeCondition5.IsVersionsConform(version + 1));

	ASSERT_EQUAL(messageTypeCondition1.GetMinVersion(), version + 1);
	ASSERT_EQUAL(messageTypeCondition2.GetMinVersion(), version);
	ASSERT_EQUAL(messageTypeCondition3.GetMinVersion(), version);
	ASSERT_EQUAL(messageTypeCondition4.GetMinVersion(), 0);
	ASSERT_EQUAL(messageTypeCondition5.GetMinVersion(), 0);

	ASSERT_EQUAL(messageTypeCondition1.GetMaxVersion(), g_TCRETestingVersion);
	ASSERT_EQUAL(messageTypeCondition2.GetMaxVersion(), g_TCRETestingVersion);
	ASSERT_EQUAL(messageTypeCondition3.GetMaxVersion(), version);
	ASSERT_EQUAL(messageTypeCondition4.GetMaxVersion(), version);
	ASSERT_EQUAL(messageTypeCondition5.GetMaxVersion(), version - 1);

	ASSERT_TRUE(messageTypeCondition5 < messageTypeCondition4);
	ASSERT_TRUE(messageTypeCondition4 < messageTypeCondition3);
	ASSERT_TRUE(messageTypeCondition3 < messageTypeCondition2);
	ASSERT_TRUE(messageTypeCondition2 < messageTypeCondition1);
}

void Network::MessageTypeConditionTesting
	::RangeTest()
{
	auto version = g_TCRETestingVersion - 2;
	TestingType messageTypeCondition{ version - 1, version + 1 };

	ASSERT_FALSE(messageTypeCondition.IsVersionsConform(version - 2));
	ASSERT_TRUE(messageTypeCondition.IsVersionsConform(version - 1));
	ASSERT_TRUE(messageTypeCondition.IsVersionsConform(version));
	ASSERT_TRUE(messageTypeCondition.IsVersionsConform(version + 1));
	ASSERT_FALSE(messageTypeCondition.IsVersionsConform(version + 2));

	ASSERT_EQUAL(messageTypeCondition.GetMinVersion(), version - 1);
	ASSERT_EQUAL(messageTypeCondition.GetMaxVersion(), version + 1);
}

void Network::MessageTypeConditionTesting
	::SpecificTest()
{
	auto version = g_TCRETestingVersion - 5;
	TestingType messageTypeCondition{ set<int>{ version - 2, version + 3 } };

	ASSERT_FALSE(messageTypeCondition.IsVersionsConform(version - 3));
	ASSERT_TRUE(messageTypeCondition.IsVersionsConform(version - 2));
	ASSERT_FALSE(messageTypeCondition.IsVersionsConform(version - 1));
	ASSERT_FALSE(messageTypeCondition.IsVersionsConform(version));
	ASSERT_FALSE(messageTypeCondition.IsVersionsConform(version + 1));
	ASSERT_FALSE(messageTypeCondition.IsVersionsConform(version + 2));
	ASSERT_TRUE(messageTypeCondition.IsVersionsConform(version + 3));

	ASSERT_EQUAL(messageTypeCondition.GetMinVersion(), version - 2);
	ASSERT_EQUAL(messageTypeCondition.GetMaxVersion(), version + 3);
}

void Network::MessageTypeConditionTesting
	::AllTest()
{
	TestingType firstMessageTypeCondition{};

	ASSERT_TRUE(firstMessageTypeCondition.IsVersionsConform(g_TCRETestingVersion - 3));
	ASSERT_TRUE(firstMessageTypeCondition.IsVersionsConform(g_TCRETestingVersion - 2));
	ASSERT_TRUE(firstMessageTypeCondition.IsVersionsConform(g_TCRETestingVersion - 1));
	ASSERT_TRUE(firstMessageTypeCondition.IsVersionsConform(g_TCRETestingVersion));
	ASSERT_TRUE(firstMessageTypeCondition.IsVersionsConform(g_TCRETestingVersion + 1));
	ASSERT_TRUE(firstMessageTypeCondition.IsVersionsConform(g_TCRETestingVersion + 2));
	ASSERT_TRUE(firstMessageTypeCondition.IsVersionsConform(g_TCRETestingVersion + 3));
}

