///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/17 22:24)

#include "ConsoleCodePageTesting.h"
#include "System/CharacterString/Flags/CodePageFlags.h"
#include "System/Console/ConsoleCodePage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConsoleCodePageTesting::ConsoleCodePageTesting(const OStreamShared& stream)
    : ParentType{ stream }, m_CodePageFlags{ CodePage::UTF7, CodePage::UTF8 }
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

    for (auto flag : m_CodePageFlags)
    {
        ASSERT_TRUE(SetConsoleCodePage(flag));

        ASSERT_ENUM_EQUAL(GetConsoleCodePage(), flag);
    }

    ASSERT_TRUE(SetConsoleCodePage(originalCodePage));
}

void System::ConsoleCodePageTesting::OutputCodePageTest()
{
    const auto originalCodePage = GetConsoleOutputCodePage();

    for (auto flag : m_CodePageFlags)
    {
        ASSERT_TRUE(SetConsoleOutputCodePage(flag));

        ASSERT_ENUM_EQUAL(GetConsoleOutputCodePage(), flag);
    }

    ASSERT_TRUE(SetConsoleOutputCodePage(originalCodePage));
}