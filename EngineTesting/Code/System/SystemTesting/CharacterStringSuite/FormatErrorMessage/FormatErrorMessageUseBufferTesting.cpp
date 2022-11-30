///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/27 23:07)

#include "FormatErrorMessageUseBufferTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

ENUM_INCREMENTABLE_OPERATOR_DEFINE(System::WindowError);

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
    for (auto windowError = WindowError::Success; windowError <= WindowError::AppHang; ++windowError)
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
        ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageValidTest, windowError);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageInvalidTest, windowError);
    }
}

void System::FormatErrorMessageUseBufferTesting::FormatErrorMessageValidTest(WindowError windowError)
{
    if (IsExistInvalidWindowError())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageSuccessTest, windowError);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageUnknownTest, windowError);
    }
}

void System::FormatErrorMessageUseBufferTesting::FormatErrorMessageInvalidTest(WindowError windowError)
{
    if (IsExistValidWindowError())
    {
        ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageUnknownTest, windowError);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageFailTest, windowError);
    }
}

void System::FormatErrorMessageUseBufferTesting::FormatErrorMessageSuccessTest(WindowError windowError)
{
    BufferType buffer{};
    const auto size = FormatErrorMessage(windowError, buffer.data(), bufferSize - 1);
    ASSERT_LESS(0u, size);

    ASSERT_NOT_THROW_EXCEPTION_2(SizeEqualTest, buffer, size);
}

void System::FormatErrorMessageUseBufferTesting::FormatErrorMessageFailTest(WindowError windowError)
{
    BufferType buffer{};
    const auto size = FormatErrorMessage(windowError, buffer.data(), bufferSize - 1);
    ASSERT_EQUAL(0u, size);

    ASSERT_NOT_THROW_EXCEPTION_1(NullBufferTest, buffer);
}

void System::FormatErrorMessageUseBufferTesting::FormatErrorMessageUnknownTest(WindowError windowError)
{
    BufferType buffer{};
    const auto size = FormatErrorMessage(windowError, buffer.data(), bufferSize - 1);

    if (0 < size)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(SizeEqualTest, buffer, size);
    }
    else
    {
        ASSERT_NOT_THROW_EXCEPTION_1(NullBufferTest, buffer);
    }
}

