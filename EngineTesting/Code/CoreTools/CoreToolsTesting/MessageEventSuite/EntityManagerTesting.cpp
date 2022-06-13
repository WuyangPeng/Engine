///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 17:01)

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
