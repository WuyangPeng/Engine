///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/26 12:43)

#include "FormatErrorMessageParameterTesting.h"
#include "System/CharacterString/Data/FormatErrorMessageParameter.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FormatErrorMessageParameterTesting::FormatErrorMessageParameterTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    ASSERT_NOT_THROW_EXCEPTION_0(ParameterTest);
}

void System::FormatErrorMessageParameterTesting::ParameterTest() noexcept
{
    constexpr auto formatMessageOption = FormatMessageOption::FromString;
    constexpr FormatErrorMessageParameter formatErrorMessageParameter{ formatMessageOption };

    static_assert(formatErrorMessageParameter.GetOption() == formatMessageOption);
    static_assert(formatErrorMessageParameter.GetWidth() == FormatMessageWidth::NoRestrictions);
    static_assert(formatErrorMessageParameter.GetWindowError() == WindowError::Success);

    constexpr auto languageIDData = formatErrorMessageParameter.GetLanguageIDData();
    static_assert(languageIDData.GetPrimaryLanguage() == PrimaryLanguage::Neutral);
    static_assert(languageIDData.GetSubLanguage() == SubLanguage::Neutral);
}
