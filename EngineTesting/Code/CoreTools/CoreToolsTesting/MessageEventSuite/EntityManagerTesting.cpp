///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 17:01)

#include "EntityManagerTesting.h"
#include "Detail/Entity.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EntityManagerDetail.h"

using std::make_shared;
using std::shared_ptr;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, EntityManagerTesting)

void CoreTools::EntityManagerTesting::MainTest()
{
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(ManagerTest);

    EntityManager::Destroy();
}

void CoreTools::EntityManagerTesting::ManagerTest() noexcept
{
}
