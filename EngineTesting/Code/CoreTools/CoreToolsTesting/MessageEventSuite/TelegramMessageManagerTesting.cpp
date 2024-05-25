/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/19 19:51)

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
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    EntityManager::Destroy();
}

void CoreTools::TelegramMessageManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AllEventTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SpecifiedEventTest);
}

void CoreTools::TelegramMessageManagerTesting::AllEventTest()
{
    const auto entity = ENTITY_MANAGER_SINGLETON.MakeEntity<Entity>(1);

    ASSERT_EQUAL(entity->GetValue(), 1);

    const auto telegram = GetTelegram();

    TelegramMessageManager telegramMessageManager{ 5 };

    ASSERT_TRUE(telegramMessageManager.RegisterAllEvent(entity->GetEntityId()));

    ASSERT_NOT_THROW_EXCEPTION_2(CallEventTest, telegramMessageManager, telegram);

    ASSERT_NOT_THROW_EXCEPTION_3(DoAllEventTest, *entity, telegram, telegramMessageManager);
}

void CoreTools::TelegramMessageManagerTesting::DoAllEventTest(const Entity& entity, const TelegramType& telegram, TelegramMessageManagerType& telegramMessageManager)
{
    ASSERT_EQUAL(entity.GetValue(), 1);

    telegramMessageManager.DispatchDelayEvent(5);

    ASSERT_EQUAL(entity.GetValue(), 11);

    ASSERT_TRUE(telegramMessageManager.UnRegisterAllEvent(entity.GetEntityId()));

    telegramMessageManager.CallEvent(telegram);

    telegramMessageManager.DispatchDelayEvent(5);

    ASSERT_EQUAL(entity.GetValue(), 11);
}

CoreTools::TelegramMessageManagerTesting::TelegramType CoreTools::TelegramMessageManagerTesting::GetTelegram()
{
    CallbackParameters callbackParameters{ 0 };
    callbackParameters.SetValue(0, 10);

    const TelegramType telegram{ 1, 3, 2, callbackParameters };

    return telegram;
}

void CoreTools::TelegramMessageManagerTesting::CallEventTest(TelegramMessageManagerType& telegramMessageManager, const TelegramType& telegram) const
{
    /// 只会产生一次事件
    telegramMessageManager.CallEvent(telegram);
    telegramMessageManager.CallEvent(telegram);
    telegramMessageManager.CallEvent(telegram);
}

void CoreTools::TelegramMessageManagerTesting::SpecifiedEventTest()
{
    const auto entity = ENTITY_MANAGER_SINGLETON.MakeEntity<Entity>(1);

    ASSERT_EQUAL(entity->GetValue(), 1);

    const auto telegram = GetTelegram();

    TelegramMessageManager telegramMessageManager{ 5 };

    ASSERT_TRUE(telegramMessageManager.Register(3, entity->GetEntityId()));

    ASSERT_NOT_THROW_EXCEPTION_2(CallEventTest, telegramMessageManager, telegram);

    ASSERT_NOT_THROW_EXCEPTION_2(DispatchDelayEventTest, *entity, telegramMessageManager);

    ASSERT_NOT_THROW_EXCEPTION_2(DoCallEvent0Test, *entity, telegramMessageManager);

    ASSERT_NOT_THROW_EXCEPTION_3(DoCallEvent1Test, *entity, telegram, telegramMessageManager);
}

void CoreTools::TelegramMessageManagerTesting::DoCallEvent0Test(const Entity& entity, TelegramMessageManagerType& telegramMessageManager)
{
    CallbackParameters callbackParameters{ 0 };
    callbackParameters.SetValue(0, 10);

    const Telegram telegram{ 1, entity.GetEntityId() + 1, 3, 2, callbackParameters };

    telegramMessageManager.CallEvent(telegram);

    telegramMessageManager.DispatchDelayEvent(5);

    ASSERT_EQUAL(entity.GetValue(), 11);
}

void CoreTools::TelegramMessageManagerTesting::DoCallEvent1Test(const Entity& entity, const TelegramType& telegram0, TelegramMessageManagerType& telegramMessageManager)
{
    CallbackParameters callbackParameters{ 0 };
    callbackParameters.SetValue(0, 10);

    const Telegram telegram1{ 1, entity.GetEntityId(), 3, 8, callbackParameters };

    telegramMessageManager.CallEventImmediately(9, telegram1);

    ASSERT_EQUAL(entity.GetValue(), 21);

    telegramMessageManager.CallEvent(telegram0);
    telegramMessageManager.CallEvent(telegram1);

    telegramMessageManager.DispatchDelayEvent(9);

    ASSERT_EQUAL(entity.GetValue(), 41);

    ASSERT_TRUE(telegramMessageManager.UnRegister(3, entity.GetEntityId()));

    telegramMessageManager.CallEvent(telegram0);

    telegramMessageManager.DispatchDelayEvent(5);

    ASSERT_EQUAL(entity.GetValue(), 41);
}

void CoreTools::TelegramMessageManagerTesting::DispatchDelayEventTest(const Entity& entity, TelegramMessageManagerType& telegramMessageManager)
{
    ASSERT_EQUAL(entity.GetValue(), 1);

    telegramMessageManager.DispatchDelayEvent(5);

    ASSERT_EQUAL(entity.GetValue(), 11);
}