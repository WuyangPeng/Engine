/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/07 15:23)

#include "StringMacroTesting.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::StringMacroTesting::StringMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StringMacroTesting)

void System::StringMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StringMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StringMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RegexTest);
}

void System::StringMacroTesting::StringMacroTest()
{
    constexpr TChar testChar{ SYSTEM_TEXT('\n') };
    const String testString{ testChar };
    const StringView stringView{ testString };

    ASSERT_EQUAL(testString, SYSTEM_TEXT("\n"));
    ASSERT_EQUAL(testString, stringView.data());
}

void System::StringMacroTesting::RegexTest()
{
    const String testString{ SYSTEM_TEXT("a") };

    const Regex regex{ testString };
    ASSERT_TRUE(regex_search(testString.begin(), testString.end(), regex));
}
