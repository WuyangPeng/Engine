///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:35)

#include "TrianglePositionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Rendering/SceneGraph/TrianglePosition.h"

Rendering::TrianglePositionTesting::TrianglePositionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TrianglePositionTesting)

void Rendering::TrianglePositionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
