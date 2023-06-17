///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 16:50)

#include "BoundTreeProjectionInfoTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Physics/CollisionDetection/BoundTreeProjectionInfo.h"

Physics::BoundTreeProjectionInfoTesting::BoundTreeProjectionInfoTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    PHYSICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Physics, BoundTreeProjectionInfoTesting)

void Physics::BoundTreeProjectionInfoTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Physics::BoundTreeProjectionInfoTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
}

void Physics::BoundTreeProjectionInfoTesting::InitTest()
{
    const BoundTreeProjectionInfo firstBoundTreeProjectionInfo(5, 1.2f);

    ASSERT_EQUAL(firstBoundTreeProjectionInfo.GetTriangle(), 5);
    ASSERT_APPROXIMATE(firstBoundTreeProjectionInfo.GetProjection(), 1.2f, 1e-8f);

    const BoundTreeProjectionInfo secondBoundTreeProjectionInfo(1, 2.2f);

    ASSERT_EQUAL(secondBoundTreeProjectionInfo.GetTriangle(), 1);
    ASSERT_APPROXIMATE(secondBoundTreeProjectionInfo.GetProjection(), 2.2f, 1e-8f);

    ASSERT_TRUE(firstBoundTreeProjectionInfo < secondBoundTreeProjectionInfo);
}
