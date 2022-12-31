///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/29 0:17)

#include "FormatErrorMessageUseDllMoudleAndLocalAllocTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FormatErrorMessageUseDllMoudleAndLocalAllocTesting::FormatErrorMessageUseDllMoudleAndLocalAllocTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatErrorMessageUseDllMoudleAndLocalAllocTesting)

void System::FormatErrorMessageUseDllMoudleAndLocalAllocTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FormatErrorMessageUseDllMoudleAndLocalAllocTesting::MainTest()
{
    auto dynamicLinkModule = CreateKernel32Dll();

    ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageUseDllMoudleAndLocalAllocTest, dynamicLinkModule);
    ASSERT_NOT_THROW_EXCEPTION_1(FormatComErrorMessageUseDllMoudleAndLocalAllocTest, dynamicLinkModule);

    ASSERT_NOT_THROW_EXCEPTION_1(FreeKernel32Dll, dynamicLinkModule);
}

void System::FormatErrorMessageUseDllMoudleAndLocalAllocTesting::FormatErrorMessageUseDllMoudleAndLocalAllocTest(ConstDynamicLinkModule dynamicLinkModule)
{
    for (auto flag = WindowError::Success; flag <= WindowError::AppHang; ++flag)
    {
        WindowsHLocal errorMessage{ nullptr };

        ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageTest, dynamicLinkModule, flag, errorMessage);
        ASSERT_NOT_THROW_EXCEPTION_1(LocalMemoryFreeTest, errorMessage);
    }
}

void System::FormatErrorMessageUseDllMoudleAndLocalAllocTesting::FormatComErrorMessageUseDllMoudleAndLocalAllocTest(ConstDynamicLinkModule dynamicLinkModule)
{
    for (auto iter = GetComWindowErrorBegin(); iter != GetComWindowErrorEnd(); ++iter)
    {
        WindowsHLocal errorMessage{ nullptr };

        ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageSuccessTest, dynamicLinkModule, *iter, errorMessage);
        ASSERT_NOT_THROW_EXCEPTION_1(LocalMemoryFreeTest, errorMessage);
    }
}

void System::FormatErrorMessageUseDllMoudleAndLocalAllocTesting::FormatErrorMessageTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage)
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

void System::FormatErrorMessageUseDllMoudleAndLocalAllocTesting::FormatErrorMessageValidTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage)
{
    if (IsExistInvalidWindowError())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageSuccessTest, dynamicLinkModule, windowError, errorMessage);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageUnknownTest, dynamicLinkModule, windowError, errorMessage);
    }
}

void System::FormatErrorMessageUseDllMoudleAndLocalAllocTesting::FormatErrorMessageInvalidTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage)
{
    if (IsExistValidWindowError())
    {
        ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageUnknownTest, dynamicLinkModule, windowError, errorMessage);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_3(FormatErrorMessageFailTest, dynamicLinkModule, windowError, errorMessage);
    }
}

void System::FormatErrorMessageUseDllMoudleAndLocalAllocTesting::FormatErrorMessageSuccessTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage)
{
    ASSERT_TRUE(FormatErrorMessage(errorMessage, dynamicLinkModule, windowError));
    ASSERT_UNEQUAL_NULL_PTR(errorMessage);
}

void System::FormatErrorMessageUseDllMoudleAndLocalAllocTesting::FormatErrorMessageFailTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage)
{
    ASSERT_FALSE(FormatErrorMessage(errorMessage, dynamicLinkModule, windowError));
    ASSERT_EQUAL_NULL_PTR(errorMessage);
}

void System::FormatErrorMessageUseDllMoudleAndLocalAllocTesting::FormatErrorMessageUnknownTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage)
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
