///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/18 12:57)

#include "EntityManagerTesting.h"
#include "Detail/Entity.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EntityManagerDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::EntityManagerTesting::EntityManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EntityManagerTesting)

void CoreTools::EntityManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::EntityManagerTesting::MainTest()
{
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(ManagerTest);

    EntityManager::Destroy();
}

void CoreTools::EntityManagerTesting::ManagerTest()
{
    const auto entity = Entity::Create(0);

    ASSERT_TRUE(ENTITY_MANAGER_SINGLETON.Register(entity));

    const auto result = ENTITY_MANAGER_SINGLETON.GetEntity(entity->GetEntityId());

    ASSERT_EQUAL(entity, result);

    ASSERT_TRUE(ENTITY_MANAGER_SINGLETON.UnRegister(entity->GetEntityId()));
    ASSERT_FALSE(ENTITY_MANAGER_SINGLETON.UnRegister(entity->GetEntityId()));

    ASSERT_THROW_EXCEPTION_1(ManagerExceptionalTest, entity->GetEntityId());

    ASSERT_TRUE(ENTITY_MANAGER_SINGLETON.Register(entity));

    const auto makeEntity = ENTITY_MANAGER_SINGLETON.MakeEntity<Entity>(5);
    ASSERT_EQUAL(makeEntity->GetValue(), 5);
}

void CoreTools::EntityManagerTesting::ManagerExceptionalTest(int64_t entityId)
{
    MAYBE_UNUSED const auto result = ENTITY_MANAGER_SINGLETON.GetEntity(entityId);
}
