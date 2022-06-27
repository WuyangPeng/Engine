///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 14:44)

#include "TrianglePositionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Rendering/SceneGraph/TrianglePosition.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TrianglePositionTesting)

void Rendering::TrianglePositionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
}

void Rendering::TrianglePositionTesting::InitTest()
{
    TrianglePosition triangleIndex(TrianglePosition::APoint(1.0f, 5.0f, 6.0f),
                                   TrianglePosition::APoint(11.0f, 15.0f, 16.0f),
                                   TrianglePosition::APoint(21.0f, 25.0f, 26.0f));

    ASSERT_TRUE(Approximate(triangleIndex.GetFirstPosition(),
                            TrianglePosition::APoint(1.0f, 5.0f, 6.0f),
                            1e-8f));
    ASSERT_TRUE(Approximate(triangleIndex.GetSecondPosition(),
                            TrianglePosition::APoint(11.0f, 15.0f, 16.0f),
                            1e-8f));
    ASSERT_TRUE(Approximate(triangleIndex.GetThirdPosition(),
                            TrianglePosition::APoint(21.0f, 25.0f, 26.0f),
                            1e-8f));
}
