///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 17:02)

#include "EventEntityTesting.h"
#include "Detail/Entity.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::EventEntityTesting::MainTest()
{
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(EventTest);

    EntityManager::Destroy();
}

void CoreTools::EventEntityTesting::EventTest()
{
    auto entity = ENTITY_MANAGER_SINGLETON.MakeEntity<Entity>(1);

    ASSERT_EQUAL(entity->GetValue(), 1);

    CallbackParameters callbackParameters{ 0 };
    callbackParameters.SetValue(0, 10);

    Telegram<> telegram{ 1, 5, 3, 2, callbackParameters };

    entity->EventFunction(telegram);

    ASSERT_EQUAL(entity->GetValue(), 11);
}
