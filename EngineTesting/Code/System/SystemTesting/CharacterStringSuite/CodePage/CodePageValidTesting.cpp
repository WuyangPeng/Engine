///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/26 18:12)

#include "CodePageValidTesting.h"
#include "System/CharacterString/CodePage.h"
#include "System/CharacterString/Flags/CodePageFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CodePageValidTesting::CodePageValidTesting(const OStreamShared& stream)
    : ParentType{ stream }, codePages{ CodePage::GB2312, CodePage::UTF7, CodePage::UTF8 }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CodePageValidTesting)

void System::CodePageValidTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CodePageValidTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValidTest);
}

void System::CodePageValidTesting::ValidTest()
{
    for (auto codeFlag : codePages)
    {
        ASSERT_TRUE(IsCodePageValid(codeFlag));
    }
}
