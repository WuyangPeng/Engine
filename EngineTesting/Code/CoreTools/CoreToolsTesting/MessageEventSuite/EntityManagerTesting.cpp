/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:02)

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
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    EntityManager::Destroy();
}

void CoreTools::EntityManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ManagerTest);
}

void CoreTools::EntityManagerTesting::ManagerTest()
{
    const auto entity = Entity::Create(0);

    ASSERT_NOT_THROW_EXCEPTION_1(GetEntityTest, entity);

    ASSERT_NOT_THROW_EXCEPTION_1(UnRegisterTest, *entity);

    ASSERT_THROW_EXCEPTION_1(ManagerExceptionalTest, entity->GetEntityId());

    ASSERT_NOT_THROW_EXCEPTION_1(GetValueTest, entity);
}

void CoreTools::EntityManagerTesting::ManagerExceptionalTest(int64_t entityId)
{
    std::ignore = ENTITY_MANAGER_SINGLETON.GetEntity(entityId);
}

void CoreTools::EntityManagerTesting::GetEntityTest(const EntitySharedPtr& entity)
{
    ASSERT_TRUE(ENTITY_MANAGER_SINGLETON.Register(entity));

    const auto result = ENTITY_MANAGER_SINGLETON.GetEntity(entity->GetEntityId());

    ASSERT_EQUAL(entity, result);
}

void CoreTools::EntityManagerTesting::UnRegisterTest(const Entity& entity)
{
    ASSERT_TRUE(ENTITY_MANAGER_SINGLETON.UnRegister(entity.GetEntityId()));
    ASSERT_FALSE(ENTITY_MANAGER_SINGLETON.UnRegister(entity.GetEntityId()));
}

void CoreTools::EntityManagerTesting::GetValueTest(const EntitySharedPtr& entity)
{
    ASSERT_TRUE(ENTITY_MANAGER_SINGLETON.Register(entity));

    const auto makeEntity = ENTITY_MANAGER_SINGLETON.MakeEntity<Entity>(5);
    ASSERT_EQUAL(makeEntity->GetValue(), 5);
}