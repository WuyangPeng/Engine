///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:49)

#include "MessageTypeConditionTesting.h"
#include "ThreadingCoreRenderEngineTesting/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"

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
    constexpr auto version = gTcreTestingVersion - 2;
    const MessageTypeCondition messageTypeCondition0{ VersionsCondition::Less, version };
    const MessageTypeCondition messageTypeCondition1{ VersionsCondition::Greater, version };
    const MessageTypeCondition messageTypeCondition2{ VersionsCondition::GreaterEqual, version };
    const MessageTypeCondition messageTypeCondition3{ VersionsCondition::Equality, version };
    const MessageTypeCondition messageTypeCondition4{ VersionsCondition::LessEqual, version };

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

    ASSERT_TRUE(messageTypeCondition0.IsVersionsConform(version - 1));
    ASSERT_FALSE(messageTypeCondition0.IsVersionsConform(version));
    ASSERT_FALSE(messageTypeCondition0.IsVersionsConform(version + 1));

    ASSERT_EQUAL(messageTypeCondition1.GetMinVersion(), version + 1);
    ASSERT_EQUAL(messageTypeCondition2.GetMinVersion(), version);
    ASSERT_EQUAL(messageTypeCondition3.GetMinVersion(), version);
    ASSERT_EQUAL(messageTypeCondition4.GetMinVersion(), 0);
    ASSERT_EQUAL(messageTypeCondition0.GetMinVersion(), 0);

    ASSERT_EQUAL(messageTypeCondition1.GetMaxVersion(), gTcreTestingVersion);
    ASSERT_EQUAL(messageTypeCondition2.GetMaxVersion(), gTcreTestingVersion);
    ASSERT_EQUAL(messageTypeCondition3.GetMaxVersion(), version);
    ASSERT_EQUAL(messageTypeCondition4.GetMaxVersion(), version);
    ASSERT_EQUAL(messageTypeCondition0.GetMaxVersion(), version - 1);

    ASSERT_TRUE(messageTypeCondition0 < messageTypeCondition4);
    ASSERT_TRUE(messageTypeCondition4 < messageTypeCondition3);
    ASSERT_TRUE(messageTypeCondition3 < messageTypeCondition2);
    ASSERT_TRUE(messageTypeCondition2 < messageTypeCondition1);
}

void Network::MessageTypeConditionTesting::RangeTest()
{
    constexpr auto version = gTcreTestingVersion - 2;
    const MessageTypeCondition messageTypeCondition{ version - 1, version + 1 };

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
    constexpr auto version = gTcreTestingVersion - 5;
    const MessageTypeCondition messageTypeCondition{ std::set{ version - 2, version + 3 } };

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
    const MessageTypeCondition messageTypeCondition = MessageTypeCondition::CreateNullCondition();

    ASSERT_TRUE(messageTypeCondition.IsVersionsConform(gTcreTestingVersion - 3));
    ASSERT_TRUE(messageTypeCondition.IsVersionsConform(gTcreTestingVersion - 2));
    ASSERT_TRUE(messageTypeCondition.IsVersionsConform(gTcreTestingVersion - 1));
    ASSERT_TRUE(messageTypeCondition.IsVersionsConform(gTcreTestingVersion));
    ASSERT_TRUE(messageTypeCondition.IsVersionsConform(gTcreTestingVersion + 1));
    ASSERT_TRUE(messageTypeCondition.IsVersionsConform(gTcreTestingVersion + 2));
    ASSERT_TRUE(messageTypeCondition.IsVersionsConform(gTcreTestingVersion + 3));
}
