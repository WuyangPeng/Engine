///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/23 18:32)

#include "MessageTypeConditionOperatingTesting.h"
#include "ThreadingCoreRenderEngineTesting/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/MessageTypeConditionOperating.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::set;

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
    MessageTypeCondition messageTypeCondition1{ VersionsCondition::Greater, version };
    MessageTypeCondition messageTypeCondition2{ VersionsCondition::GreaterEqual, version };
    MessageTypeCondition messageTypeCondition3{ VersionsCondition::Equality, version };
    MessageTypeCondition messageTypeCondition4{ VersionsCondition::LessEqual, version };
    MessageTypeCondition messageTypeCondition5{ VersionsCondition::Less, version };
    MessageTypeCondition messageTypeCondition6{ version - 1, version + 1 };
    MessageTypeCondition messageTypeCondition7{ set<int>{ version - 2, version + 3 } };
    MessageTypeCondition messageTypeCondition8 = MessageTypeCondition::CreateNullCondition();

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

    ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition1, messageTypeCondition8));
    ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition2, messageTypeCondition8));
    ASSERT_FALSE(messageTypeConditionOperating(messageTypeCondition3, messageTypeCondition8));
    ASSERT_TRUE(messageTypeConditionOperating(messageTypeCondition4, messageTypeCondition8));
    ASSERT_TRUE(messageTypeConditionOperating(messageTypeCondition5, messageTypeCondition8));
}
