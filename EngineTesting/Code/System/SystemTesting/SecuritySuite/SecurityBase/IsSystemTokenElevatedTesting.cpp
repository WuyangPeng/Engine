///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/11/01 21:43)

#include "IsSystemTokenElevatedTesting.h"
#include "System/Security/SecurityBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::IsSystemTokenElevatedTesting::IsSystemTokenElevatedTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, IsSystemTokenElevatedTesting)

void System::IsSystemTokenElevatedTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::IsSystemTokenElevatedTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IsSystemTokenElevatedTest);
}

void System::IsSystemTokenElevatedTesting::IsSystemTokenElevatedTest() noexcept
{
    MAYBE_UNUSED const auto result = IsSystemTokenElevated();
}
