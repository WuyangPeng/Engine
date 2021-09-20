// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/06 19:03)

#include "TelegramMessageManagerTesting.h"
#include "Detail/Entity.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EntityManagerDetail.h"
#include "CoreTools/MessageEvent/TelegramMessageManagerDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, TelegramMessageManagerTesting)

void CoreTools::TelegramMessageManagerTesting ::MainTest()
{
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(AllEventTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SpecifiedEventTest);

    EntityManager::Destroy();
}

void CoreTools::TelegramMessageManagerTesting ::AllEventTest()
{
    auto entity = ENTITY_MANAGER_SINGLETON.MakeEntity<Entity>(1);

    ASSERT_EQUAL(entity->GetValue(), 1);

    CallbackParameters callbackParameters{};
    callbackParameters.SetValue(0, 10);

    Telegram<> telegram{ 1, 3, 2, callbackParameters };

    TelegramMessageManager<> telegramMessageManager(5);

    [[maybe_unused]] auto value = telegramMessageManager.RegisterAllEvent(entity->GetEntityID());

    // 只会产生一次事件
    telegramMessageManager.CallEvent(telegram);
    telegramMessageManager.CallEvent(telegram);
    telegramMessageManager.CallEvent(telegram);

    ASSERT_EQUAL(entity->GetValue(), 1);

    telegramMessageManager.DispatchDelayEvent(5);

    ASSERT_EQUAL(entity->GetValue(), 11);

    value = telegramMessageManager.UnregisterAllEvent(entity->GetEntityID());

    telegramMessageManager.CallEvent(telegram);

    telegramMessageManager.DispatchDelayEvent(5);

    ASSERT_EQUAL(entity->GetValue(), 11);
}

void CoreTools::TelegramMessageManagerTesting ::SpecifiedEventTest()
{
    auto entity = ENTITY_MANAGER_SINGLETON.MakeEntity<Entity>(1);

    ASSERT_EQUAL(entity->GetValue(), 1);

    CallbackParameters callbackParameters{};
    callbackParameters.SetValue(0, 10);

    Telegram<> firstTelegram{ 1, entity->GetEntityID(), 3, 2, callbackParameters };

    TelegramMessageManager<> telegramMessageManager(5);

    [[maybe_unused]] auto value = telegramMessageManager.Register(3, entity->GetEntityID());

    // 只会产生一次事件
    telegramMessageManager.CallEvent(firstTelegram);
    telegramMessageManager.CallEvent(firstTelegram);
    telegramMessageManager.CallEvent(firstTelegram);

    ASSERT_EQUAL(entity->GetValue(), 1);

    telegramMessageManager.DispatchDelayEvent(5);

    ASSERT_EQUAL(entity->GetValue(), 11);

    Telegram<> secondTelegram{ 1, entity->GetEntityID() + 1, 3, 2, callbackParameters };

    telegramMessageManager.CallEvent(secondTelegram);

    telegramMessageManager.DispatchDelayEvent(5);

    ASSERT_EQUAL(entity->GetValue(), 11);

    Telegram<> thirdTelegram{ 1, entity->GetEntityID(), 3, 8, callbackParameters };

    telegramMessageManager.CallEventImmediately(9, thirdTelegram);

    ASSERT_EQUAL(entity->GetValue(), 21);

    telegramMessageManager.CallEvent(firstTelegram);
    telegramMessageManager.CallEvent(thirdTelegram);

    telegramMessageManager.DispatchDelayEvent(9);

    ASSERT_EQUAL(entity->GetValue(), 41);

    value = telegramMessageManager.Unregister(3, entity->GetEntityID());

    telegramMessageManager.CallEvent(firstTelegram);

    telegramMessageManager.DispatchDelayEvent(5);

    ASSERT_EQUAL(entity->GetValue(), 41);
}
