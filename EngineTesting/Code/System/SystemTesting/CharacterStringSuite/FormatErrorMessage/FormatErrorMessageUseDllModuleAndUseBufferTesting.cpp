///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:10)

#include "FormatErrorMessageUseDllModuleAndUseBufferTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FormatErrorMessageUseDllModuleAndUseBufferTesting::FormatErrorMessageUseDllModuleAndUseBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatErrorMessageUseDllModuleAndUseBufferTesting)

void System::FormatErrorMessageUseDllModuleAndUseBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FormatErrorMessageUseDllModuleAndUseBufferTesting::MainTest()
{
    auto dynamicLinkModule = CreateKernel32Dll();

    ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageUseDllModuleAndUseBufferTest, dynamicLinkModule);
    ASSERT_NOT_THROW_EXCEPTION_1(FormatComErrorMessageUseDllModuleAndUseBufferTest, dynamicLinkModule);

    ASSERT_NOT_THROW_EXCEPTION_1(FreeKernel32Dll, dynamicLinkModule);
}

void System::FormatErrorMessageUseDllModuleAndUseBufferTesting::FormatErrorMessageUseDllModuleAndUseBufferTest(ConstDynamicLinkModule dynamicLinkModule)
{
    for (auto flag = WindowError::Success; flag <= WindowError::AppHang; ++flag)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageTest, dynamicLinkModule, flag);
    }
}

void System::FormatErrorMessageUseDllModuleAndUseBufferTesting::FormatComErrorMessageUseDllModuleAndUseBufferTest(ConstDynamicLinkModule dynamicLinkModule)
{
    for (auto iter = GetComWindowErrorBegin(); iter != GetComWindowErrorEnd(); ++iter)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageSuccessTest, dynamicLinkModule, *iter);
    }
}

void System::FormatErrorMessageUseDllModuleAndUseBufferTesting::FormatErrorMessageTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError)
{
    if (IsWindowErrorValid(windowError))
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageValidTest, dynamicLinkModule, windowError);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageInvalidTest, dynamicLinkModule, windowError);
    }
}

void System::FormatErrorMessageUseDllModuleAndUseBufferTesting::FormatErrorMessageValidTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError)
{
    if (IsExistInvalidWindowError())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageSuccessTest, dynamicLinkModule, windowError);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageUnknownTest, dynamicLinkModule, windowError);
    }
}

void System::FormatErrorMessageUseDllModuleAndUseBufferTesting::FormatErrorMessageInvalidTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError)
{
    if (IsExistValidWindowError())
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageUnknownTest, dynamicLinkModule, windowError);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageFailTest, dynamicLinkModule, windowError);
    }
}

void System::FormatErrorMessageUseDllModuleAndUseBufferTesting::FormatErrorMessageSuccessTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError)
{
    BufferType buffer{};
    const auto size = FormatErrorMessage(dynamicLinkModule, windowError, buffer.data(), bufferSize - 1);
    ASSERT_LESS(0u, size);

    ASSERT_NOT_THROW_EXCEPTION_2(SizeEqualTest, buffer, size);
}

void System::FormatErrorMessageUseDllModuleAndUseBufferTesting::FormatErrorMessageFailTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError)
{
    BufferType buffer{};
    const auto size = FormatErrorMessage(dynamicLinkModule, windowError, buffer.data(), bufferSize - 1);
    ASSERT_EQUAL(0u, size);

    ASSERT_NOT_THROW_EXCEPTION_1(NullBufferTest, buffer);
}

void System::FormatErrorMessageUseDllModuleAndUseBufferTesting::FormatErrorMessageUnknownTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError)
{
    BufferType buffer{};

    if (const auto size = FormatErrorMessage(dynamicLinkModule, windowError, buffer.data(), bufferSize - 1);
        0 < size)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(SizeEqualTest, buffer, size);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_1(NullBufferTest, buffer);
    }
}
