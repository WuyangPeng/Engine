///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:00)

#include "Bisect2NodeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Mathematics::Bisect2NodeTesting::Bisect2NodeTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Bisect2NodeTesting)

void Mathematics::Bisect2NodeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Bisect2NodeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NextNodeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SameSignTest);
}

void Mathematics::Bisect2NodeTesting::ValueTest() noexcept
{
}

void Mathematics::Bisect2NodeTesting::NextNodeTest() noexcept
{
}

void Mathematics::Bisect2NodeTesting::SameSignTest() noexcept
{
}
