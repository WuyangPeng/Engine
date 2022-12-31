///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/29 20:53)

#include "FormatErrorMessageUseDllMoudleAndUseBufferTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FormatErrorMessageUseDllMoudleAndUseBufferTesting::FormatErrorMessageUseDllMoudleAndUseBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatErrorMessageUseDllMoudleAndUseBufferTesting)

void System::FormatErrorMessageUseDllMoudleAndUseBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FormatErrorMessageUseDllMoudleAndUseBufferTesting::MainTest()
{
    auto dynamicLinkModule = CreateKernel32Dll();

    ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageUseDllMoudleAndUseBufferTest, dynamicLinkModule);
    ASSERT_NOT_THROW_EXCEPTION_1(FormatComErrorMessageUseDllMoudleAndUseBufferTest, dynamicLinkModule);

    ASSERT_NOT_THROW_EXCEPTION_1(FreeKernel32Dll, dynamicLinkModule);
}

void System::FormatErrorMessageUseDllMoudleAndUseBufferTesting::FormatErrorMessageUseDllMoudleAndUseBufferTest(ConstDynamicLinkModule dynamicLinkModule)
{
    for (auto flag = WindowError::Success; flag <= WindowError::AppHang; ++flag)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageTest, dynamicLinkModule, flag);
    }
}

void System::FormatErrorMessageUseDllMoudleAndUseBufferTesting::FormatComErrorMessageUseDllMoudleAndUseBufferTest(ConstDynamicLinkModule dynamicLinkModule)
{
    for (auto iter = GetComWindowErrorBegin(); iter != GetComWindowErrorEnd(); ++iter)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageSuccessTest, dynamicLinkModule, *iter);
    }
}

void System::FormatErrorMessageUseDllMoudleAndUseBufferTesting::FormatErrorMessageTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError)
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

void System::FormatErrorMessageUseDllMoudleAndUseBufferTesting::FormatErrorMessageValidTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError)
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

void System::FormatErrorMessageUseDllMoudleAndUseBufferTesting::FormatErrorMessageInvalidTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError)
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

void System::FormatErrorMessageUseDllMoudleAndUseBufferTesting::FormatErrorMessageSuccessTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError)
{
    BufferType buffer{};
    const auto size = FormatErrorMessage(dynamicLinkModule, windowError, buffer.data(), bufferSize - 1);
    ASSERT_LESS(0u, size);

    ASSERT_NOT_THROW_EXCEPTION_2(SizeEqualTest, buffer, size);
}

void System::FormatErrorMessageUseDllMoudleAndUseBufferTesting::FormatErrorMessageFailTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError)
{
    BufferType buffer{};
    const auto size = FormatErrorMessage(dynamicLinkModule, windowError, buffer.data(), bufferSize - 1);
    ASSERT_EQUAL(0u, size);

    ASSERT_NOT_THROW_EXCEPTION_1(NullBufferTest, buffer);
}

void System::FormatErrorMessageUseDllMoudleAndUseBufferTesting::FormatErrorMessageUnknownTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError)
{
    BufferType buffer{};
    const auto size = FormatErrorMessage(dynamicLinkModule, windowError, buffer.data(), bufferSize - 1);

    if (0 < size)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(SizeEqualTest, buffer, size);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_1(NullBufferTest, buffer);
    }
}
