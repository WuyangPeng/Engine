///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 16:23)

#include "BaseEntityTesting.h"
#include "Detail/Entity.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EntityManager.h"

using std::make_shared;
using std::shared_ptr;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, BaseEntityTesting)

void CoreTools::BaseEntityTesting::MainTest()
{
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);

    EntityManager::Destroy();
}

void CoreTools::BaseEntityTesting::BaseTest()
{
    auto entity = Entity::Create(0);

    entity->Register();

    ASSERT_LESS(0, entity->GetEntityID());
}
