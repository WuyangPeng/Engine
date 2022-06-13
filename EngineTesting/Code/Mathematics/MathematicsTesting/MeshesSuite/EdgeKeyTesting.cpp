///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/03 16:26)

#include "EdgeKeyTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Meshes/EdgeKey.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, EdgeKeyTesting)

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
