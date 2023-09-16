///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:06)

#include "CodePageTesting.h"
#include "System/CharacterString/CodePage.h"
#include "System/CharacterString/Flags/CodePageFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CodePageTesting::CodePageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CodePageTesting)

void System::CodePageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CodePageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AnsiCodePageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OemCodePageTest);
}

void System::CodePageTesting::AnsiCodePageTest()
{
    const auto ansiCodePage = GetAnsiCodePage();
    ASSERT_TRUE(IsCodePageValid(ansiCodePage));
}

void System::CodePageTesting::OemCodePageTest()
{
    const auto oemCodePage = GetOemCodePage();
    ASSERT_TRUE(IsCodePageValid(oemCodePage));
}
