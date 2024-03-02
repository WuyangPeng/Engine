///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:08)

#include "FormatErrorMessageReturnStringTesting.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FormatErrorMessageReturnStringTesting::FormatErrorMessageReturnStringTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatErrorMessageReturnStringTesting)

void System::FormatErrorMessageReturnStringTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FormatErrorMessageReturnStringTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FormatErrorMessageReturnStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FormatComErrorMessageReturnStringTest);
}

void System::FormatErrorMessageReturnStringTesting::FormatErrorMessageReturnStringTest()
{
    for (auto windowError = WindowError::Success; windowError <= WindowError::DlpPolicySilentlyFail; ++windowError)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageTest, windowError);
    }
}

void System::FormatErrorMessageReturnStringTesting::FormatComErrorMessageReturnStringTest()
{
    for (auto iter = GetComWindowErrorBegin(); iter != GetComWindowErrorEnd(); ++iter)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageSuccessTest, *iter);
    }
}

void System::FormatErrorMessageReturnStringTesting::FormatErrorMessageTest(WindowError windowError)
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

void System::FormatErrorMessageReturnStringTesting::FormatErrorMessageValidTest(WindowError windowError)
{
    ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageSuccessTest, windowError);
}

void System::FormatErrorMessageReturnStringTesting::FormatErrorMessageInvalidTest(WindowError windowError)
{
    ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageFailTest, windowError);
}

void System::FormatErrorMessageReturnStringTesting::FormatErrorMessageSuccessTest(WindowError windowError)
{
    const auto message = FormatErrorMessage(windowError);
    ASSERT_FALSE(message.empty());
}

void System::FormatErrorMessageReturnStringTesting::FormatErrorMessageFailTest(WindowError windowError)
{
    const auto message = FormatErrorMessage(windowError);
    ASSERT_TRUE(message.empty());
}

void System::FormatErrorMessageReturnStringTesting::FormatErrorMessageUnknownTest(WindowError windowError)
{
    const auto message = FormatErrorMessage(windowError);
    ASSERT_LESS(message.size(), bufferSize);
}
