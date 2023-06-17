///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:55)

#include "EdgeKeyTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Meshes/EdgeKey.h"

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
