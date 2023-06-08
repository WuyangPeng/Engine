///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/06 21:09)

#include "TrianglePlaneRelationsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

Mathematics::TrianglePlaneRelationsTesting::TrianglePlaneRelationsTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, TrianglePlaneRelationsTesting)

void Mathematics::TrianglePlaneRelationsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::TrianglePlaneRelationsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RelationsTest);
}

void Mathematics::TrianglePlaneRelationsTesting::RelationsTest() noexcept
{
}
