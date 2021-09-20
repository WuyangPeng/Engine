///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/03 15:51)

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
