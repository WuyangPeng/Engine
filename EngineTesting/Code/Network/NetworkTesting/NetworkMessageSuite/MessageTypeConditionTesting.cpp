///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 18:32)

#include "MessageTypeConditionTesting.h"
#include "ThreadingCoreRenderEngineTesting/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::set;

Network::MessageTypeConditionTesting::MessageTypeConditionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageTypeConditionTesting)

void Network::MessageTypeConditionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::MessageTypeConditionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RangeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SpecificTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AllTest);
}

void Network::MessageTypeConditionTesting::CompareTest()
{
    constexpr auto version = gTCRETestingVersion - 2;
    MessageTypeCondition messageTypeCondition1{ VersionsCondition::Greater, version };
    MessageTypeCondition messageTypeCondition2{ VersionsCondition::GreaterEqual, version };
    MessageTypeCondition messageTypeCondition3{ VersionsCondition::Equality, version };
    MessageTypeCondition messageTypeCondition4{ VersionsCondition::LessEqual, version };
    MessageTypeCondition messageTypeCondition5{ VersionsCondition::Less, version };

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

    ASSERT_EQUAL(messageTypeCondition1.GetMaxVersion(), gTCRETestingVersion);
    ASSERT_EQUAL(messageTypeCondition2.GetMaxVersion(), gTCRETestingVersion);
    ASSERT_EQUAL(messageTypeCondition3.GetMaxVersion(), version);
    ASSERT_EQUAL(messageTypeCondition4.GetMaxVersion(), version);
    ASSERT_EQUAL(messageTypeCondition5.GetMaxVersion(), version - 1);

    ASSERT_TRUE(messageTypeCondition5 < messageTypeCondition4);
    ASSERT_TRUE(messageTypeCondition4 < messageTypeCondition3);
    ASSERT_TRUE(messageTypeCondition3 < messageTypeCondition2);
    ASSERT_TRUE(messageTypeCondition2 < messageTypeCondition1);
}

void Network::MessageTypeConditionTesting::RangeTest()
{
    constexpr auto version = gTCRETestingVersion - 2;
    MessageTypeCondition messageTypeCondition{ version - 1, version + 1 };

    ASSERT_FALSE(messageTypeCondition.IsVersionsConform(version - 2));
    ASSERT_TRUE(messageTypeCondition.IsVersionsConform(version - 1));
    ASSERT_TRUE(messageTypeCondition.IsVersionsConform(version));
    ASSERT_TRUE(messageTypeCondition.IsVersionsConform(version + 1));
    ASSERT_FALSE(messageTypeCondition.IsVersionsConform(version + 2));

    ASSERT_EQUAL(messageTypeCondition.GetMinVersion(), version - 1);
    ASSERT_EQUAL(messageTypeCondition.GetMaxVersion(), version + 1);
}

void Network::MessageTypeConditionTesting::SpecificTest()
{
    constexpr auto version = gTCRETestingVersion - 5;
    MessageTypeCondition messageTypeCondition{ set<int>{ version - 2, version + 3 } };

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

void Network::MessageTypeConditionTesting::AllTest()
{
    MessageTypeCondition firstMessageTypeCondition = MessageTypeCondition::CreateNullCondition();

    ASSERT_TRUE(firstMessageTypeCondition.IsVersionsConform(gTCRETestingVersion - 3));
    ASSERT_TRUE(firstMessageTypeCondition.IsVersionsConform(gTCRETestingVersion - 2));
    ASSERT_TRUE(firstMessageTypeCondition.IsVersionsConform(gTCRETestingVersion - 1));
    ASSERT_TRUE(firstMessageTypeCondition.IsVersionsConform(gTCRETestingVersion));
    ASSERT_TRUE(firstMessageTypeCondition.IsVersionsConform(gTCRETestingVersion + 1));
    ASSERT_TRUE(firstMessageTypeCondition.IsVersionsConform(gTCRETestingVersion + 2));
    ASSERT_TRUE(firstMessageTypeCondition.IsVersionsConform(gTCRETestingVersion + 3));
}
