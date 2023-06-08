///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/02 16:30)

#include "Bisect3NodeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
Mathematics::Bisect3NodeTesting::Bisect3NodeTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Bisect3NodeTesting)

void Mathematics::Bisect3NodeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Bisect3NodeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NextNodeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SameSignTest);
}

void Mathematics::Bisect3NodeTesting::ValueTest() noexcept
{
}

void Mathematics::Bisect3NodeTesting::NextNodeTest() noexcept
{
}

void Mathematics::Bisect3NodeTesting::SameSignTest() noexcept
{
}
