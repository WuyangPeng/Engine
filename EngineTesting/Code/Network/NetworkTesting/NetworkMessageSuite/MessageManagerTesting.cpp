///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/12 10:39)

#include "MessageManagerTesting.h"
#include "ThreadingCoreRenderEngineTesting/Version.h"
#include "Detail/TestDoubleNullMessage.h"
#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"

Network::MessageManagerTesting::MessageManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageManagerTesting)

void Network::MessageManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::MessageManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FullVersionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ManagerTest);
    ASSERT_THROW_EXCEPTION_0(ExceptionTest);
    ASSERT_THROW_EXCEPTION_0(DescribeExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DescribeTest);
}

void Network::MessageManagerTesting::FullVersionTest()
{
    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.GetFullVersion(), gTCRETestingVersion);

    MESSAGE_MANAGER_SINGLETON.SetFullVersion(gTCRETestingVersion - 1);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.GetFullVersion(), gTCRETestingVersion - 1);

    MESSAGE_MANAGER_SINGLETON.SetFullVersion(gTCRETestingVersion);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.GetFullVersion(), gTCRETestingVersion);
}

void Network::MessageManagerTesting::ManagerTest()
{
    constexpr auto messageId = 6LL;
    const MessageTypeCondition messageTypeCondition0{ VersionsCondition::Equality, gTCRETestingVersion - 1 };
    const MessageTypeCondition messageTypeCondition1{ VersionsCondition::Equality, gTCRETestingVersion };

    MESSAGE_MANAGER_SINGLETON.Insert(messageId, messageTypeCondition1, TestNullMessage::Factory);
    MESSAGE_MANAGER_SINGLETON.Insert(messageId, messageTypeCondition0, TestDoubleNullMessage::Factory);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageId, gTCRETestingVersion), TestNullMessage::Factory);
    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageId, gTCRETestingVersion - 1), TestDoubleNullMessage::Factory);

    MESSAGE_MANAGER_SINGLETON.Remove(messageId, messageTypeCondition1);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageId, gTCRETestingVersion - 1), TestDoubleNullMessage::Factory);

    MESSAGE_MANAGER_SINGLETON.Remove(messageId, messageTypeCondition0);
}

void Network::MessageManagerTesting::ExceptionTest()
{
    constexpr auto messageID = 6LL;
    MESSAGE_MANAGER_SINGLETON.Insert(messageID, MessageTypeCondition{ VersionsCondition::Equality, gTCRETestingVersion }, TestNullMessage::Factory);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageID, gTCRETestingVersion), TestNullMessage::Factory);

    MESSAGE_MANAGER_SINGLETON.Remove(messageID);

    MAYBE_UNUSED auto result = MESSAGE_MANAGER_SINGLETON.Find(messageID, gTCRETestingVersion);
}

void Network::MessageManagerTesting::DescribeTest()
{
    constexpr auto messageDescribe = "Describe";
    const MessageTypeCondition messageTypeCondition0{ VersionsCondition::Equality, gTCRETestingVersion - 1 };
    const MessageTypeCondition messageTypeCondition1{ VersionsCondition::Equality, gTCRETestingVersion };

    MESSAGE_MANAGER_SINGLETON.Insert(messageDescribe, messageTypeCondition1, TestNullMessage::Factory);
    MESSAGE_MANAGER_SINGLETON.Insert(messageDescribe, messageTypeCondition0, TestDoubleNullMessage::Factory);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageDescribe, gTCRETestingVersion), TestNullMessage::Factory);
    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageDescribe, gTCRETestingVersion - 1), TestDoubleNullMessage::Factory);
}

void Network::MessageManagerTesting::DescribeExceptionTest()
{
    constexpr auto messageDescribe = "DescribeException";
  
    MAYBE_UNUSED auto result = MESSAGE_MANAGER_SINGLETON.Find(messageDescribe, gTCRETestingVersion);
}
