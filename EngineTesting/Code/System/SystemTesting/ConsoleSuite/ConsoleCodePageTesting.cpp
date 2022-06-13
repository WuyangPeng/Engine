///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:05)

#include "ConsoleCodePageTesting.h"
#include "System/CharacterString/Flags/CodePageFlags.h"
#include "System/Console/ConsoleCodePage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleCodePageTesting::ConsoleCodePageTesting(const OStreamShared& stream)
    : ParentType{ stream }, codePageFlags{ CodePage::UTF7, CodePage::UTF8 }
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

    for (auto flag : codePageFlags)
    {
        ASSERT_TRUE(SetConsoleCodePage(flag));

        ASSERT_ENUM_EQUAL(GetConsoleCodePage(), flag);
    }

    ASSERT_TRUE(SetConsoleCodePage(originalCodePage));
}

void System::ConsoleCodePageTesting::OutputCodePageTest()
{
    const auto originalCodePage = GetConsoleOutputCodePage();

    for (auto flag : codePageFlags)
    {
        ASSERT_TRUE(SetConsoleOutputCodePage(flag));

        ASSERT_ENUM_EQUAL(GetConsoleOutputCodePage(), flag);
    }

    ASSERT_TRUE(SetConsoleOutputCodePage(originalCodePage));
}