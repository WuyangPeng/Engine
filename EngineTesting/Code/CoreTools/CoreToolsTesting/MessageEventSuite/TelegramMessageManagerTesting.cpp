///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 15:30)

#include "TelegramMessageManagerTesting.h"
#include "Detail/Entity.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EntityManagerDetail.h"
#include "CoreTools/MessageEvent/TelegramMessageManagerDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::TelegramMessageManagerTesting::TelegramMessageManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TelegramMessageManagerTesting)

void CoreTools::TelegramMessageManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::TelegramMessageManagerTesting::MainTest()
{
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(AllEventTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SpecifiedEventTest);

    EntityManager::Destroy();
}

void CoreTools::TelegramMessageManagerTesting::AllEventTest()
{
    const auto entity = ENTITY_MANAGER_SINGLETON.MakeEntity<Entity>(1);

    ASSERT_EQUAL(entity->GetValue(), 1);

    CallbackParameters callbackParameters{ 0 };
    callbackParameters.SetValue(0, 10);

    const Telegram<> telegram{ 1, 3, 2, callbackParameters };

    TelegramMessageManager<> telegramMessageManager{ 5 };

    ASSERT_TRUE(telegramMessageManager.RegisterAllEvent(entity->GetEntityId()));

    // 只会产生一次事件
    telegramMessageManager.CallEvent(telegram);
    telegramMessageManager.CallEvent(telegram);
    telegramMessageManager.CallEvent(telegram);

    ASSERT_EQUAL(entity->GetValue(), 1);

    telegramMessageManager.DispatchDelayEvent(5);

    ASSERT_EQUAL(entity->GetValue(), 11);

    ASSERT_TRUE(telegramMessageManager.UnRegisterAllEvent(entity->GetEntityId()));

    telegramMessageManager.CallEvent(telegram);

    telegramMessageManager.DispatchDelayEvent(5);

    ASSERT_EQUAL(entity->GetValue(), 11);
}

void CoreTools::TelegramMessageManagerTesting::SpecifiedEventTest()
{
    const auto entity = ENTITY_MANAGER_SINGLETON.MakeEntity<Entity>(1);

    ASSERT_EQUAL(entity->GetValue(), 1);

    CallbackParameters callbackParameters{ 0 };
    callbackParameters.SetValue(0, 10);

    const Telegram<> telegram0{ 1, entity->GetEntityId(), 3, 2, callbackParameters };

    TelegramMessageManager<> telegramMessageManager{ 5 };

    ASSERT_TRUE(telegramMessageManager.Register(3, entity->GetEntityId()));

    // 只会产生一次事件
    telegramMessageManager.CallEvent(telegram0);
    telegramMessageManager.CallEvent(telegram0);
    telegramMessageManager.CallEvent(telegram0);

    ASSERT_EQUAL(entity->GetValue(), 1);

    telegramMessageManager.DispatchDelayEvent(5);

    ASSERT_EQUAL(entity->GetValue(), 11);

    const Telegram<> telegram1{ 1, entity->GetEntityId() + 1, 3, 2, callbackParameters };

    telegramMessageManager.CallEvent(telegram1);

    telegramMessageManager.DispatchDelayEvent(5);

    ASSERT_EQUAL(entity->GetValue(), 11);

    const Telegram<> telegram2{ 1, entity->GetEntityId(), 3, 8, callbackParameters };

    telegramMessageManager.CallEventImmediately(9, telegram2);

    ASSERT_EQUAL(entity->GetValue(), 21);

    telegramMessageManager.CallEvent(telegram0);
    telegramMessageManager.CallEvent(telegram2);

    telegramMessageManager.DispatchDelayEvent(9);

    ASSERT_EQUAL(entity->GetValue(), 41);

    ASSERT_TRUE(telegramMessageManager.UnRegister(3, entity->GetEntityId()));

    telegramMessageManager.CallEvent(telegram0);

    telegramMessageManager.DispatchDelayEvent(5);

    ASSERT_EQUAL(entity->GetValue(), 41);
}
