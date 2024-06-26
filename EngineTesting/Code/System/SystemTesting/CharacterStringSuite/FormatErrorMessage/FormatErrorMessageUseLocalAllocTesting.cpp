/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:15)

#include "FormatErrorMessageUseLocalAllocTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FormatErrorMessageUseLocalAllocTesting::FormatErrorMessageUseLocalAllocTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatErrorMessageUseLocalAllocTesting)

void System::FormatErrorMessageUseLocalAllocTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FormatErrorMessageUseLocalAllocTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FormatErrorMessageUseLocalAllocTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FormatComErrorMessageUseLocalAllocTest);
}

void System::FormatErrorMessageUseLocalAllocTesting::FormatErrorMessageUseLocalAllocTest()
{
    /// 这里只测试到DlpPolicySilentlyFail，之后的Window错误码枚举并未完全补全，测试将失败。
    for (auto flag = WindowError::Success; flag <= WindowError::DlpPolicySilentlyFail; ++flag)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoFormatErrorMessageUseLocalAllocTest, flag);
    }
}

void System::FormatErrorMessageUseLocalAllocTesting::DoFormatErrorMessageUseLocalAllocTest(WindowError flag)
{
    WindowsHLocal errorMessage{ nullptr };

    ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageTest, flag, errorMessage);

    ASSERT_NOT_THROW_EXCEPTION_1(LocalMemoryFreeTest, errorMessage);
}

void System::FormatErrorMessageUseLocalAllocTesting::FormatComErrorMessageUseLocalAllocTest()
{
    for (auto iter = GetComWindowErrorBegin(); iter != GetComWindowErrorEnd(); ++iter)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoFormatComErrorMessageUseLocalAllocTest, *iter);
    }
}

void System::FormatErrorMessageUseLocalAllocTesting::DoFormatComErrorMessageUseLocalAllocTest(WindowError flag)
{
    WindowsHLocal errorMessage{ nullptr };

    ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageSuccessTest, flag, errorMessage);

    ASSERT_NOT_THROW_EXCEPTION_1(LocalMemoryFreeTest, errorMessage);
}

void System::FormatErrorMessageUseLocalAllocTesting::FormatErrorMessageTest(WindowError windowError, WindowsHLocal& errorMessage)
{
    if (IsWindowErrorValid(windowError))
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageSuccessTest, windowError, errorMessage);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageFailTest, windowError, errorMessage);
    }
}

void System::FormatErrorMessageUseLocalAllocTesting::FormatErrorMessageSuccessTest(WindowError windowError, WindowsHLocal& errorMessage)
{
    ASSERT_TRUE(FormatErrorMessage(errorMessage, windowError));
    ASSERT_UNEQUAL_NULL_PTR(errorMessage);
}

void System::FormatErrorMessageUseLocalAllocTesting::FormatErrorMessageFailTest(WindowError windowError, WindowsHLocal& errorMessage)
{
    ASSERT_FALSE_USE_MESSAGE(FormatErrorMessage(errorMessage, windowError), "WindowError = " + std::to_string(System::EnumCastUnderlying(windowError)));
    ASSERT_EQUAL_NULL_PTR(errorMessage);
}
