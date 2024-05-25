/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 13:01)

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
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    EntityManager::Destroy();
}

void CoreTools::BaseEntityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void CoreTools::BaseEntityTesting::BaseTest()
{
    const auto entity = Entity::Create(0);

    entity->Register();

    ASSERT_LESS(0, entity->GetEntityId());
}
