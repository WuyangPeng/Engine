///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:35)

#include "TriangleIndexTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/SceneGraph/TriangleIndex.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Rendering::TriangleIndexTesting::TriangleIndexTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TriangleIndexTesting)

void Rendering::TriangleIndexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
