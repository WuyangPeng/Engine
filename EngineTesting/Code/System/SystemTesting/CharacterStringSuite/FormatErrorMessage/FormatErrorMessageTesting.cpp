///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:10)

#include "FormatErrorMessageTesting.h"
#include "System/CharacterString/Flags/FormatMessageFlags.h"
#include "System/CharacterString/FormatErrorMessage.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/LocalTools.h"
#include "System/SystemOutput/Data/LanguageIDData.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(FormatErrorMessageTest);
}

void System::FormatErrorMessageTesting::FormatErrorMessageTest()
{
    WindowsHLocal errorMessage{};
    constexpr LanguageIDData languageID{};

    const auto messageFlag = FormatMessageOption::FromSystem | FormatMessageOption::IgnoreInserts | FormatMessageOption::AllocateBuffer;
    const auto messageWidthFlag = FormatMessageWidth::NoRestrictions;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    const auto size = FormatErrorMessage(messageFlag,
                                         messageWidthFlag,
                                         nullptr,
                                         WindowError::InvalidAccess,
                                         languageID,
                                         reinterpret_cast<TChar*>(&errorMessage),
                                         0,
                                         nullptr);

#include STSTEM_WARNING_POP

    ASSERT_LESS(0u, size);
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(errorMessage, "格式化错误码失败。");

    String errorMessageDescribe{ static_cast<TChar*>(errorMessage) };

    ASSERT_EQUAL(errorMessageDescribe.size(), size);
    ASSERT_UNEQUAL(errorMessageDescribe.find(SYSTEM_TEXT("访问码无效。")), String::npos);

    ASSERT_TRUE(LocalMemoryFree(errorMessage));
}
