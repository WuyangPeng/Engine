///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 1:07)

#include "HResultTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::HResultTesting::HResultTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, HResultTesting)

void System::HResultTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::HResultTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HResultTest);
}

void System::HResultTesting::HResultTest()
{
    ASSERT_FALSE(IsFailed(0));
    ASSERT_TRUE(IsSucceeded(0));

    ASSERT_FALSE(IsFailed(1));
    ASSERT_TRUE(IsSucceeded(1));

    ASSERT_TRUE(IsFailed(-1));
    ASSERT_FALSE(IsSucceeded(-1));

    ASSERT_EQUAL(gFalse, 0);
    ASSERT_EQUAL(gTrue, 1);
}
