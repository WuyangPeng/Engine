///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/17 0:22)

#include "StringMacroTesting.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::StringMacroTesting::StringMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, StringMacroTesting)

void System::StringMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::StringMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StringMacroTest);
}

void System::StringMacroTesting::StringMacroTest()
{
    constexpr TChar testChar{ SYSTEM_TEXT('\n') };
    const String testString{ testChar };
    const StringView stringView{ testString };

    ASSERT_EQUAL(testString, SYSTEM_TEXT("\n"));
    ASSERT_EQUAL(testString, stringView.data());

    const Regex regex{ testString };
    ASSERT_TRUE(regex_search(testString.begin(), testString.end(), regex));
}
