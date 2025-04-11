/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:11)

#include "FormatErrorMessageTesting.h"
#include "System/CharacterString/Data/FormatErrorMessageParameter.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FormatErrorMessageTesting::FormatErrorMessageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatErrorMessageTesting)

void System::FormatErrorMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FormatErrorMessageTesting::MainTest()
{
    WindowsHLocal errorMessage{};

    ASSERT_NOT_THROW_EXCEPTION_1(FormatErrorMessageTest, errorMessage);

    ASSERT_NOT_THROW_EXCEPTION_1(LocalMemoryFreeTest, errorMessage);
}

void System::FormatErrorMessageTesting::FormatErrorMessageTest(WindowsHLocal errorMessage)
{
    constexpr FormatErrorMessageParameter parameter{ FormatMessageOption::FromSystem | FormatMessageOption::IgnoreInserts | FormatMessageOption::AllocateBuffer };

    const auto size = FormatErrorMessage(parameter.GetOption(),
                                         parameter.GetWidth(),
                                         nullptr,
                                         WindowError::InvalidAccess,
                                         parameter.GetLanguageIdData(),
                                         ReinterpretCast(errorMessage),
                                         0);

    ASSERT_LESS(0u, size);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(errorMessage, "格式化错误码失败。");

    String errorMessageDescribe{ static_cast<TChar*>(errorMessage) };

    ASSERT_EQUAL(errorMessageDescribe.size(), size);
    ASSERT_UNEQUAL(errorMessageDescribe.find(SYSTEM_TEXT("访问码无效。")), String::npos);
}
