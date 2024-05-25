/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 13:02)

#include "EventEntityTesting.h"
#include "Detail/Entity.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EntityManagerDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::EventEntityTesting::EventEntityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EventEntityTesting)

void CoreTools::EventEntityTesting::DoRunUnitTest()
{
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    EntityManager::Destroy();
}

void CoreTools::EventEntityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EventTest);
}

void CoreTools::EventEntityTesting::EventTest()
{
    const auto entity = ENTITY_MANAGER_SINGLETON.MakeEntity<Entity>(1);

    ASSERT_EQUAL(entity->GetValue(), 1);

    CallbackParameters callbackParameters{ 0 };
    callbackParameters.SetValue(0, 10);

    ASSERT_NOT_THROW_EXCEPTION_2(DoEventTest, *entity, callbackParameters);
}

void CoreTools::EventEntityTesting::DoEventTest(Entity& entity, const CallbackParameters& callbackParameters)
{
    const Telegram telegram{ 1, 5, 3, 2, callbackParameters };

    ASSERT_TRUE(entity.EventFunction(telegram));

    ASSERT_EQUAL(entity.GetValue(), 11);
}
