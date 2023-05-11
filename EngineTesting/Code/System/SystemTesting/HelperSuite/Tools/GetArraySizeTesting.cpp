///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/18 11:06)

#include "GetArraySizeTesting.h"
#include "System/Helper/Tools.h"
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