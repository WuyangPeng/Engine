///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/18 11:33)

#include "BaseEntityTesting.h"
#include "Detail/Entity.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EntityManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::BaseEntityTesting::BaseEntityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BaseEntityTesting)

void CoreTools::BaseEntityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::BaseEntityTesting::MainTest()
{
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);

    EntityManager::Destroy();
}

void CoreTools::BaseEntityTesting::BaseTest()
{
    const auto entity = Entity::Create(0);

    entity->Register();

    ASSERT_LESS(0, entity->GetEntityId());
}
