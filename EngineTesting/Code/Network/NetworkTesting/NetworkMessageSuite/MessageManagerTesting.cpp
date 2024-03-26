///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:48)

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
    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.GetFullVersion(), gTcreTestingVersion);

    MESSAGE_MANAGER_SINGLETON.SetFullVersion(gTcreTestingVersion - 1);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.GetFullVersion(), gTcreTestingVersion - 1);

    MESSAGE_MANAGER_SINGLETON.SetFullVersion(gTcreTestingVersion);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.GetFullVersion(), gTcreTestingVersion);
}

void Network::MessageManagerTesting::ManagerTest()
{
    constexpr auto messageId = 6LL;
    const MessageTypeCondition messageTypeCondition0{ VersionsCondition::Equality, gTcreTestingVersion - 1 };
    const MessageTypeCondition messageTypeCondition1{ VersionsCondition::Equality, gTcreTestingVersion };

    MESSAGE_MANAGER_SINGLETON.Insert(messageId, messageTypeCondition1, TestNullMessage::Factory);
    MESSAGE_MANAGER_SINGLETON.Insert(messageId, messageTypeCondition0, TestDoubleNullMessage::Factory);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageId, gTcreTestingVersion), TestNullMessage::Factory);
    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageId, gTcreTestingVersion - 1), TestDoubleNullMessage::Factory);

    MESSAGE_MANAGER_SINGLETON.Remove(messageId, messageTypeCondition1);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageId, gTcreTestingVersion - 1), TestDoubleNullMessage::Factory);

    MESSAGE_MANAGER_SINGLETON.Remove(messageId, messageTypeCondition0);
}

void Network::MessageManagerTesting::ExceptionTest()
{
    constexpr auto messageId = 6LL;
    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition{ VersionsCondition::Equality, gTcreTestingVersion }, TestNullMessage::Factory);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageId, gTcreTestingVersion), TestNullMessage::Factory);

    MESSAGE_MANAGER_SINGLETON.Remove(messageId);

    MAYBE_UNUSED auto result = MESSAGE_MANAGER_SINGLETON.Find(messageId, gTcreTestingVersion);
}

void Network::MessageManagerTesting::DescribeTest()
{
    constexpr auto messageDescribe = "Describe";
    const MessageTypeCondition messageTypeCondition0{ VersionsCondition::Equality, gTcreTestingVersion - 1 };
    const MessageTypeCondition messageTypeCondition1{ VersionsCondition::Equality, gTcreTestingVersion };

    MESSAGE_MANAGER_SINGLETON.Insert(messageDescribe, messageTypeCondition1, TestNullMessage::Factory);
    MESSAGE_MANAGER_SINGLETON.Insert(messageDescribe, messageTypeCondition0, TestDoubleNullMessage::Factory);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageDescribe, gTcreTestingVersion), TestNullMessage::Factory);
    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageDescribe, gTcreTestingVersion - 1), TestDoubleNullMessage::Factory);
}

void Network::MessageManagerTesting::DescribeExceptionTest()
{
    constexpr auto messageDescribe = "DescribeException";

    MAYBE_UNUSED const auto result = MESSAGE_MANAGER_SINGLETON.Find(messageDescribe, gTcreTestingVersion);
}
