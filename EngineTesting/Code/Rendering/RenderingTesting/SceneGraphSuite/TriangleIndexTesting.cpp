///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 14:43)

#include "TriangleIndexTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/SceneGraph/TriangleIndex.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TriangleIndexTesting)

void Rendering::TriangleIndexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
}

void Rendering::TriangleIndexTesting::InitTest()
{
    const TriangleIndex triangleIndex(9, 44, 88);

    ASSERT_EQUAL(triangleIndex.GetFirstIndex(), 9);
    ASSERT_EQUAL(triangleIndex.GetSecondIndex(), 44);
    ASSERT_EQUAL(triangleIndex.GetThirdIndex(), 88);
}
