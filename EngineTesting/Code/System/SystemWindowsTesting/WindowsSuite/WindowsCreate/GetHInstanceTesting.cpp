/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:16)

#include "GetHInstanceTesting.h"
#include "System/Windows/WindowsCreate.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetHInstanceTesting::GetHInstanceTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream }, instance{ instance }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetHInstanceTesting)

void System::GetHInstanceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetHInstanceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetHInstanceTest);
}

void System::GetHInstanceTesting::GetHInstanceTest()
{
    const auto hInstance = GetHInstance();

    ASSERT_EQUAL(hInstance, instance);
}
