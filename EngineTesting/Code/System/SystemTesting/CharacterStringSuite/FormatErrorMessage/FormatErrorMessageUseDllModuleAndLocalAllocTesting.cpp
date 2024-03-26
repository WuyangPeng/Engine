/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:13)

#include "FormatErrorMessageUseDllModuleAndLocalAllocTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FormatErrorMessageUseDllModuleAndLocalAllocTesting::FormatErrorMessageUseDllModuleAndLocalAllocTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatErrorMessageUseDllModuleAndLocalAllocTesting)

void System::FormatErrorMessageUseDllModuleAndLocalAllocTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FormatErrorMessageUseDllModuleAndLocalAllocTesting::MainTest()
{
    auto dynamicLinkModule = CreateKernel32Dll();

    ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageUseDllModuleAndLocalAllocTest, dynamicLinkModule);
    ASSERT_NOT_THROW_EXCEPTION_1(FormatComErrorMessageUseDllModuleAndLocalAllocTest, dynamicLinkModule);

    ASSERT_NOT_THROW_EXCEPTION_1(FreeKernel32Dll, dynamicLinkModule);
}

void System::FormatErrorMessageUseDllModuleAndLocalAllocTesting::FormatErrorMessageUseDllModuleAndLocalAllocTest(ConstDynamicLinkModule dynamicLinkModule)
{
    /// 这里只测试到DlpPolicySilentlyFail，之后的Window错误码枚举并未完全补全，测试将失败。
    for (auto flag = WindowError::Success; flag <= WindowError::DlpPolicySilentlyFail; ++flag)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoFormatErrorMessageUseDllModuleAndLocalAllocTest, dynamicLinkModule, flag);
    }
}

void System::FormatErrorMessageUseDllModuleAndLocalAllocTesting::DoFormatErrorMessageUseDllModuleAndLocalAllocTest(ConstDynamicLinkModule dynamicLinkModule, WindowError flag)
{
    WindowsHLocal errorMessage{ nullptr };

    ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageTest, dynamicLinkModule, flag, errorMessage);

    ASSERT_NOT_THROW_EXCEPTION_1(LocalMemoryFreeTest, errorMessage);
}

void System::FormatErrorMessageUseDllModuleAndLocalAllocTesting::FormatComErrorMessageUseDllModuleAndLocalAllocTest(ConstDynamicLinkModule dynamicLinkModule)
{
    for (auto iter = GetComWindowErrorBegin(); iter != GetComWindowErrorEnd(); ++iter)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoFormatComErrorMessageUseDllModuleAndLocalAllocTest, dynamicLinkModule, *iter);
    }
}

void System::FormatErrorMessageUseDllModuleAndLocalAllocTesting::DoFormatComErrorMessageUseDllModuleAndLocalAllocTest(ConstDynamicLinkModule dynamicLinkModule, WindowError flag)
{
    WindowsHLocal errorMessage{ nullptr };

    ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageSuccessTest, dynamicLinkModule, flag, errorMessage);

    ASSERT_NOT_THROW_EXCEPTION_1(LocalMemoryFreeTest, errorMessage);
}

void System::FormatErrorMessageUseDllModuleAndLocalAllocTesting::FormatErrorMessageTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage)
{
    if (IsWindowErrorValid(windowError))
    {
        ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageSuccessTest, dynamicLinkModule, windowError, errorMessage);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageFailTest, dynamicLinkModule, windowError, errorMessage);
    }
}

void System::FormatErrorMessageUseDllModuleAndLocalAllocTesting::FormatErrorMessageSuccessTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage)
{
    ASSERT_TRUE(FormatErrorMessage(errorMessage, dynamicLinkModule, windowError));
    ASSERT_UNEQUAL_NULL_PTR(errorMessage);
}

void System::FormatErrorMessageUseDllModuleAndLocalAllocTesting::FormatErrorMessageFailTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage)
{
    ASSERT_FALSE(FormatErrorMessage(errorMessage, dynamicLinkModule, windowError));
    ASSERT_EQUAL_NULL_PTR(errorMessage);
}
