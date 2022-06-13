///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 17:04)

#include "TelegramMessageManagerTesting.h"
#include "Detail/Entity.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EntityManagerDetail.h"
#include "CoreTools/MessageEvent/TelegramMessageManagerDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, TelegramMessageManagerTesting)

void CoreTools::TelegramMessageManagerTesting::MainTest()
{
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(AllEventTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SpecifiedEventTest);

    EntityManager::Destroy();
}

void CoreTools::TelegramMessageManagerTesting::AllEventTest()
{
    auto entity = ENTITY_MANAGER_SINGLETON.MakeEntity<Entity>(1);

    ASSERT_EQUAL(entity->GetValue(), 1);

    CallbackParameters callbackParameters{ 0 };
    callbackParameters.SetValue(0, 10);

    Telegram<> telegram{ 1, 3, 2, callbackParameters };

    TelegramMessageManager<> telegramMessageManager(5);

    MAYBE_UNUSED auto value = telegramMessageManager.RegisterAllEvent(entity->GetEntityID());

    // ֻ�����һ���¼�
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

void CoreTools::TelegramMessageManagerTesting::SpecifiedEventTest()
{
    auto entity = ENTITY_MANAGER_SINGLETON.MakeEntity<Entity>(1);

    ASSERT_EQUAL(entity->GetValue(), 1);

    CallbackParameters callbackParameters{ 0 };
    callbackParameters.SetValue(0, 10);

    Telegram<> firstTelegram{ 1, entity->GetEntityID(), 3, 2, callbackParameters };

    TelegramMessageManager<> telegramMessageManager(5);

    MAYBE_UNUSED auto value = telegramMessageManager.Register(3, entity->GetEntityID());

    // ֻ�����һ���¼�
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
