///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/03 16:26)

#include "EdgeKeyTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Meshes/EdgeKey.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
Mathematics::EdgeKeyTesting::EdgeKeyTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EdgeKeyTesting)

void Mathematics::EdgeKeyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::EdgeKeyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(KeyTest);
}

void Mathematics::EdgeKeyTesting::KeyTest()
{
    const EdgeKey firstEdgeKey(5, 4);

    ASSERT_EQUAL(firstEdgeKey.GetKey(0), 4);
    ASSERT_EQUAL(firstEdgeKey.GetKey(1), 5);

    const EdgeKey secondEdgeKey(5, 14);

    ASSERT_EQUAL(secondEdgeKey.GetKey(0), 5);
    ASSERT_EQUAL(secondEdgeKey.GetKey(1), 14);
}
