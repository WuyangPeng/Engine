// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 11:42)

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
