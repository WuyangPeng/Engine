///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/28 16:18)

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
    for (auto flag = WindowError::Success; flag <= WindowError::AppHang; ++flag)
    {
        WindowsHLocal errorMessage{ nullptr };

        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageTest, flag, errorMessage);
        ASSERT_NOT_THROW_EXCEPTION_1(LocalMemoryFreeTest, errorMessage);
    }
}

void System::FormatErrorMessageUseLocalAllocTesting::FormatComErrorMessageUseLocalAllocTest()
{
    for (auto iter = GetComWindowErrorBegin(); iter != GetComWindowErrorEnd(); ++iter)
    {
        WindowsHLocal errorMessage{ nullptr };

        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageSuccessTest, *iter, errorMessage);
        ASSERT_NOT_THROW_EXCEPTION_1(LocalMemoryFreeTest, errorMessage);
    }
}

void System::FormatErrorMessageUseLocalAllocTesting::FormatErrorMessageTest(WindowError windowError, WindowsHLocal& errorMessage)
{
    if (IsWindowErrorValid(windowError))
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageValidTest, windowError, errorMessage);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageInvalidTest, windowError, errorMessage);
    }
}

void System::FormatErrorMessageUseLocalAllocTesting::FormatErrorMessageValidTest(WindowError windowError, WindowsHLocal& errorMessage)
{
    if (IsExistInvalidWindowError())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageSuccessTest, windowError, errorMessage);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageUnknownTest, windowError, errorMessage);
    }
}

void System::FormatErrorMessageUseLocalAllocTesting::FormatErrorMessageInvalidTest(WindowError windowError, WindowsHLocal& errorMessage)
{
    if (IsExistValidWindowError())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageUnknownTest, windowError, errorMessage);
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
    ASSERT_FALSE(FormatErrorMessage(errorMessage, windowError));
    ASSERT_EQUAL_NULL_PTR(errorMessage);
}

void System::FormatErrorMessageUseLocalAllocTesting::FormatErrorMessageUnknownTest(WindowError windowError, WindowsHLocal& errorMessage)
{
    if (FormatErrorMessage(errorMessage, windowError))
    {
        ASSERT_UNEQUAL_NULL_PTR(errorMessage);
    }
    else
    {
        ASSERT_EQUAL_NULL_PTR(errorMessage);
    }
}
