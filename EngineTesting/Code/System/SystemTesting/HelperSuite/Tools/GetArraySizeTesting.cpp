/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 16:26)

#include "GetArraySizeTesting.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetArraySizeTesting::GetArraySizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
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

void System::GetArraySizeTesting::GetArraySizeTest() const noexcept
{
    constexpr auto arraySize = 6;
    constexpr int test[arraySize]{};

    static_assert(GetArraySize(test) == arraySize);
}
