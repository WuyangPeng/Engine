/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:15)

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
    /// 这里只测试到DlpPolicySilentlyFail，之后的Window错误码枚举并未完全补全，测试将失败。
    for (auto flag = WindowError::Success; flag <= WindowError::DlpPolicySilentlyFail; ++flag)
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
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageSuccessTest, dynamicLinkModule, windowError);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_2(FormatErrorMessageFailTest, dynamicLinkModule, windowError);
    }
}

void System::FormatErrorMessageUseDllModuleAndUseBufferTesting::FormatErrorMessageSuccessTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError)
{
    TCharBufferType buffer{};
    const auto size = FormatErrorMessage(dynamicLinkModule, windowError, buffer.data(), bufferSize - 1);
    ASSERT_LESS(0u, size);

    ASSERT_NOT_THROW_EXCEPTION_2(SizeEqualTest, buffer, size);
}

void System::FormatErrorMessageUseDllModuleAndUseBufferTesting::FormatErrorMessageFailTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError)
{
    TCharBufferType buffer{};
    const auto size = FormatErrorMessage(dynamicLinkModule, windowError, buffer.data(), bufferSize - 1);
    ASSERT_EQUAL(0u, size);

    ASSERT_NOT_THROW_EXCEPTION_1(NullBufferTest, buffer);
}
