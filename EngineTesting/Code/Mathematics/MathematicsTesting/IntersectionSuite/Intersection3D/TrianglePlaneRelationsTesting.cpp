///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:54)

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
