/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:07)

#include "FormatErrorMessageParameterTesting.h"
#include "System/CharacterString/Data/FormatErrorMessageParameter.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FormatErrorMessageParameterTesting::FormatErrorMessageParameterTesting(const OStreamShared& stream)
    : ParentType{ stream },
      formatMessageOptions{ FormatMessageOption::AllocateBuffer,
                            FormatMessageOption::IgnoreInserts,
                            FormatMessageOption::FromString,
                            FormatMessageOption::FromHModule,
                            FormatMessageOption::FromSystem,
                            FormatMessageOption::ArgumentArray }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FormatErrorMessageParameterTesting)

void System::FormatErrorMessageParameterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FormatErrorMessageParameterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstexprParameterTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ParameterTest);
}

void System::FormatErrorMessageParameterTesting::ConstexprParameterTest() const noexcept
{
    constexpr auto formatMessageOption = FormatMessageOption::FromString;
    constexpr FormatErrorMessageParameter formatErrorMessageParameter{ formatMessageOption };

    static_assert(formatErrorMessageParameter.GetOption() == formatMessageOption);
    static_assert(FormatErrorMessageParameter::GetWidth() == FormatMessageWidth::NoRestrictions);
    static_assert(FormatErrorMessageParameter::GetWindowError() == WindowError::Success);

    constexpr auto languageIdData = FormatErrorMessageParameter::GetLanguageIdData();
    static_assert(languageIdData.GetPrimaryLanguage() == PrimaryLanguage::Neutral);
    static_assert(languageIdData.GetSubLanguage() == SubLanguage::Neutral);
}

void System::FormatErrorMessageParameterTesting::ParameterTest()
{
    for (const auto formatMessageOption : formatMessageOptions)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoParameterTest, formatMessageOption);
    }
}

void System::FormatErrorMessageParameterTesting::DoParameterTest(FormatMessageOption formatMessageOption)
{
    const FormatErrorMessageParameter formatErrorMessageParameter{ formatMessageOption };

    ASSERT_EQUAL(formatErrorMessageParameter.GetOption(), formatMessageOption);
    static_assert(FormatErrorMessageParameter::GetWidth() == FormatMessageWidth::NoRestrictions);
    static_assert(FormatErrorMessageParameter::GetWindowError() == WindowError::Success);

    constexpr auto languageIdData = FormatErrorMessageParameter::GetLanguageIdData();
    static_assert(languageIdData.GetPrimaryLanguage() == PrimaryLanguage::Neutral);
    static_assert(languageIdData.GetSubLanguage() == SubLanguage::Neutral);
}
