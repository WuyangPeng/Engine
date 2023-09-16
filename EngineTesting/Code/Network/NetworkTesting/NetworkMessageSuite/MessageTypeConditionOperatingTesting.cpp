///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:49)

#include "MessageTypeConditionOperatingTesting.h"
#include "ThreadingCoreRenderEngineTesting/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/MessageTypeConditionOperating.h"

Network::MessageTypeConditionOperatingTesting::MessageTypeConditionOperatingTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageTypeConditionOperatingTesting)

void Network::MessageTypeConditionOperatingTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::MessageTypeConditionOperatingTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OperatingTest);
}

void Network::MessageTypeConditionOperatingTesting::OperatingTest()
{
    constexpr auto version = gTCRETestingVersion - 4;
    const MessageTypeCondition messageTypeCondition0 = MessageTypeCondition::CreateNullCondition();
    const MessageTypeCondition messageTypeCondition1{ VersionsCondition::Greater, version };
    const MessageTypeCondition messageTypeCondition2{ VersionsCondition::GreaterEqual, version };
    const MessageTypeCondition messageTypeCondition3{ VersionsCondition::Equality, version };
    const MessageTypeCondition messageTypeCondition4{ VersionsCondition::LessEqual, version };
    const MessageTypeCondition messageTypeCondition5{ VersionsCondition::Less, version };
    const MessageTypeCondition messageTypeCondition6{ version - 1, version + 1 };
    const MessageTypeCondition messageTypeCondition7{ std::set<int>{ version - 2, version + 3 } };

    const MessageTypeConditionOperating messageTypeConditionOperating{};

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

    ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition1, messageTypeCondition0));
    ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition2, messageTypeCondition0));
    ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition3, messageTypeCondition0));
    ASSERT_TRUE(messageTypeConditionOperating(messageTypeCondition4, messageTypeCondition0));
    ASSERT_TRUE(messageTypeConditionOperating(messageTypeCondition5, messageTypeCondition0));
}
