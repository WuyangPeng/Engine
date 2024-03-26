/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 18:31)

#include "ConsoleCodePageTesting.h"
#include "System/CharacterString/Flags/CodePageFlags.h"
#include "System/Console/ConsoleCodePage.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleCodePageTesting::ConsoleCodePageTesting(const OStreamShared& stream)
    : ParentType{ stream }, codePages{ CodePage::Utf7, CodePage::Utf8, CodePage::Gb2312 }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConsoleCodePageTesting)

void System::ConsoleCodePageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConsoleCodePageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CodePageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OutputCodePageTest);
}

void System::ConsoleCodePageTesting::CodePageTest()
{
    const auto originalCodePage = GetConsoleCodePage();

    for (auto codePage : codePages)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(ConsoleCodePageTest, codePage);
    }

    ASSERT_NOT_THROW_EXCEPTION_1(ConsoleCodePageTest, originalCodePage);
}

void System::ConsoleCodePageTesting::OutputCodePageTest()
{
    const auto originalCodePage = GetConsoleOutputCodePage();

    for (auto codePage : codePages)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(ConsoleOutputCodePageTest, codePage);
    }

    ASSERT_NOT_THROW_EXCEPTION_1(ConsoleOutputCodePageTest, originalCodePage);
}

void System::ConsoleCodePageTesting::ConsoleCodePageTest(CodePage codePage)
{
    ASSERT_TRUE(SetConsoleCodePage(codePage));

    ASSERT_ENUM_EQUAL(GetConsoleCodePage(), codePage);
}

void System::ConsoleCodePageTesting::ConsoleOutputCodePageTest(CodePage codePage)
{
    ASSERT_TRUE(SetConsoleOutputCodePage(codePage));

    ASSERT_ENUM_EQUAL(GetConsoleOutputCodePage(), codePage);
}
