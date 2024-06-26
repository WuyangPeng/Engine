/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:12)

#include "FormatErrorMessageUseBufferTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FormatErrorMessageUseBufferTesting::FormatErrorMessageUseBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatErrorMessageUseBufferTesting)

void System::FormatErrorMessageUseBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FormatErrorMessageUseBufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FormatErrorMessageUseBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FormatComErrorMessageUseBufferTest);
}

void System::FormatErrorMessageUseBufferTesting::FormatErrorMessageUseBufferTest()
{
    /// 这里只测试到DlpPolicySilentlyFail，之后的Window错误码枚举并未完全补全，测试将失败。
    for (auto windowError = WindowError::Success; windowError <= WindowError::DlpPolicySilentlyFail; ++windowError)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageTest, windowError);
    }
}

void System::FormatErrorMessageUseBufferTesting::FormatComErrorMessageUseBufferTest()
{
    for (auto iter = GetComWindowErrorBegin(); iter != GetComWindowErrorEnd(); ++iter)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageSuccessTest, *iter);
    }
}

void System::FormatErrorMessageUseBufferTesting::FormatErrorMessageTest(WindowError windowError)
{
    if (IsWindowErrorValid(windowError))
    {
        ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageSuccessTest, windowError);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageFailTest, windowError);
    }
}

void System::FormatErrorMessageUseBufferTesting::FormatErrorMessageSuccessTest(WindowError windowError)
{
    TCharBufferType buffer{};
    const auto size = FormatErrorMessage(windowError, buffer.data(), bufferSize - 1);
    ASSERT_LESS(0u, size);

    ASSERT_NOT_THROW_EXCEPTION_2(SizeEqualTest, buffer, size);
}

void System::FormatErrorMessageUseBufferTesting::FormatErrorMessageFailTest(WindowError windowError)
{
    TCharBufferType buffer{};
    const auto size = FormatErrorMessage(windowError, buffer.data(), bufferSize - 1);
    ASSERT_EQUAL(0u, size);

    ASSERT_NOT_THROW_EXCEPTION_1(NullBufferTest, buffer);
}
