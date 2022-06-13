///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/23 17:01)

#include "MessageManagerTesting.h"
#include "ThreadingCoreRenderEngineTesting/Version.h"
#include "Detail/TestDoubleNullMessage.h"
#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/NetworkMessage/Flags/MessageTypeFlags.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, MessageManagerTesting)

void Network::MessageManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FullVersionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ManagerTest);
    ASSERT_THROW_EXCEPTION_0(ExceptionTest);
}

void Network::MessageManagerTesting::FullVersionTest()
{
    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.GetFullVersion(), g_TCRETestingVersion);

    MESSAGE_MANAGER_SINGLETON.SetFullVersion(g_TCRETestingVersion - 1);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.GetFullVersion(), g_TCRETestingVersion - 1);

    MESSAGE_MANAGER_SINGLETON.SetFullVersion(g_TCRETestingVersion);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.GetFullVersion(), g_TCRETestingVersion);
}

void Network::MessageManagerTesting::ManagerTest()
{
    constexpr auto messageID = 6LL;
    MessageTypeCondition messageTypeCondition1{ VersionsCondition::Equality, g_TCRETestingVersion };
    MessageTypeCondition messageTypeCondition2{ VersionsCondition::Equality, g_TCRETestingVersion - 1 };

    MESSAGE_MANAGER_SINGLETON.Insert(messageID, messageTypeCondition1, TestNullMessage::Factory);
    MESSAGE_MANAGER_SINGLETON.Insert(messageID, messageTypeCondition2, TestDoubleNullMessage::Factory);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageID, g_TCRETestingVersion), TestNullMessage::Factory);
    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageID, g_TCRETestingVersion - 1), TestDoubleNullMessage::Factory);

    MESSAGE_MANAGER_SINGLETON.Remove(messageID, messageTypeCondition1);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageID, g_TCRETestingVersion - 1), TestDoubleNullMessage::Factory);

    MESSAGE_MANAGER_SINGLETON.Remove(messageID, messageTypeCondition2);
}

void Network::MessageManagerTesting::ExceptionTest()
{
    constexpr auto messageID = 6LL;
    MESSAGE_MANAGER_SINGLETON.Insert(messageID, MessageTypeCondition{ VersionsCondition::Equality, g_TCRETestingVersion }, TestNullMessage::Factory);

    ASSERT_EQUAL(MESSAGE_MANAGER_SINGLETON.Find(messageID, g_TCRETestingVersion), TestNullMessage::Factory);

    MESSAGE_MANAGER_SINGLETON.Remove(messageID);

    MAYBE_UNUSED auto value = MESSAGE_MANAGER_SINGLETON.Find(messageID, g_TCRETestingVersion);
}
