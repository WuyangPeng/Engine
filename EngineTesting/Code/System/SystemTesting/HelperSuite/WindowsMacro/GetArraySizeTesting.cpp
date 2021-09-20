///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/16 19:44)

#include "GetArraySizeTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetArraySizeTesting::GetArraySizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetArraySizeTesting)

void System::GetArraySizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetArraySizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetArraySizeTest);
}

void System::GetArraySizeTesting::GetArraySizeTest() noexcept
{
    constexpr auto arraySize = 6;
    const int test[arraySize]{};

    static_assert(GetArraySize(test) == arraySize);
}
