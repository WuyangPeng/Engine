///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/20 22:21)

#include "BoundTreeProjectionInfoTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Physics/CollisionDetection/BoundTreeProjectionInfo.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Physics, BoundTreeProjectionInfoTesting)

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
