///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:55)

#include "TriangleKeyTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Meshes/TriangleKey.h"

Mathematics::TriangleKeyTesting::TriangleKeyTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, TriangleKeyTesting)

void Mathematics::TriangleKeyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::TriangleKeyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(KeyTest);
}

void Mathematics::TriangleKeyTesting::KeyTest()
{
    const TriangleKey firstTriangleKey(5, 4, 6);

    ASSERT_EQUAL(firstTriangleKey.GetKey(0), 4);
    ASSERT_EQUAL(firstTriangleKey.GetKey(1), 6);
    ASSERT_EQUAL(firstTriangleKey.GetKey(2), 5);

    const TriangleKey secondTriangleKey(5, 14, 18);

    ASSERT_EQUAL(secondTriangleKey.GetKey(0), 5);
    ASSERT_EQUAL(secondTriangleKey.GetKey(1), 14);
    ASSERT_EQUAL(secondTriangleKey.GetKey(2), 18);

    const TriangleKey thirdTriangleKey(5, 14, 1);

    ASSERT_EQUAL(thirdTriangleKey.GetKey(0), 1);
    ASSERT_EQUAL(thirdTriangleKey.GetKey(1), 5);
    ASSERT_EQUAL(thirdTriangleKey.GetKey(2), 14);

    const TriangleKey fourthTriangleKey(15, 14, 1);

    ASSERT_EQUAL(fourthTriangleKey.GetKey(0), 1);
    ASSERT_EQUAL(fourthTriangleKey.GetKey(1), 15);
    ASSERT_EQUAL(fourthTriangleKey.GetKey(2), 14);

    const TriangleKey fifthTriangleKey(15, 2, 13);

    ASSERT_EQUAL(fifthTriangleKey.GetKey(0), 2);
    ASSERT_EQUAL(fifthTriangleKey.GetKey(1), 13);
    ASSERT_EQUAL(fifthTriangleKey.GetKey(2), 15);

    const TriangleKey sixthTriangleKey(1, 112, 13);

    ASSERT_EQUAL(sixthTriangleKey.GetKey(0), 1);
    ASSERT_EQUAL(sixthTriangleKey.GetKey(1), 112);
    ASSERT_EQUAL(sixthTriangleKey.GetKey(2), 13);
}
