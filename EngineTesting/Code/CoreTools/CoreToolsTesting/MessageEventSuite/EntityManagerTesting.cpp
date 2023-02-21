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
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::make_shared;
using std::shared_ptr;

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

void CoreTools::EntityManagerTesting::ManagerTest() noexcept
{
}
