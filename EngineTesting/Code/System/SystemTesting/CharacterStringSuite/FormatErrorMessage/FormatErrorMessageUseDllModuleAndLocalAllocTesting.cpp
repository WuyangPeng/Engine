///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:09)

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
    for (auto flag = WindowError::Success; flag <= WindowError::DlpPolicySilentlyFail; ++flag)
    {
        WindowsHLocal errorMessage{ nullptr };

        ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageTest, dynamicLinkModule, flag, errorMessage);
        ASSERT_NOT_THROW_EXCEPTION_1(LocalMemoryFreeTest, errorMessage);
    }
}

void System::FormatErrorMessageUseDllModuleAndLocalAllocTesting::FormatComErrorMessageUseDllModuleAndLocalAllocTest(ConstDynamicLinkModule dynamicLinkModule)
{
    for (auto iter = GetComWindowErrorBegin(); iter != GetComWindowErrorEnd(); ++iter)
    {
        WindowsHLocal errorMessage{ nullptr };

        ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageSuccessTest, dynamicLinkModule, *iter, errorMessage);
        ASSERT_NOT_THROW_EXCEPTION_1(LocalMemoryFreeTest, errorMessage);
    }
}

void System::FormatErrorMessageUseDllModuleAndLocalAllocTesting::FormatErrorMessageTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage)
{
    if (IsWindowErrorValid(windowError))
    {
        ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageValidTest, dynamicLinkModule, windowError, errorMessage);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageInvalidTest, dynamicLinkModule, windowError, errorMessage);
    }
}

void System::FormatErrorMessageUseDllModuleAndLocalAllocTesting::FormatErrorMessageValidTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage)
{
    ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageSuccessTest, dynamicLinkModule, windowError, errorMessage);
}

void System::FormatErrorMessageUseDllModuleAndLocalAllocTesting::FormatErrorMessageInvalidTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage)
{
    ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageFailTest, dynamicLinkModule, windowError, errorMessage);
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

void System::FormatErrorMessageUseDllModuleAndLocalAllocTesting::FormatErrorMessageUnknownTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage)
{
    if (FormatErrorMessage(errorMessage, dynamicLinkModule, windowError))
    {
        ASSERT_UNEQUAL_NULL_PTR(errorMessage);
    }
    else
    {
        ASSERT_EQUAL_NULL_PTR(errorMessage);
    }
}
