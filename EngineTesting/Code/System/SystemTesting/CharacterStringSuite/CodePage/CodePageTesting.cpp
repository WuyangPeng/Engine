///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/03 14:27)

#include "CodePageTesting.h"
#include "System/CharacterString/CodePage.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(ANSICodePageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OEMCodePageTest);
}

void System::CodePageTesting::ANSICodePageTest()
{
    const auto ansiCodePage = GetANSICodePage();

    ASSERT_TRUE(IsCodePageValid(ansiCodePage));
}

void System::CodePageTesting::OEMCodePageTest()
{
    const auto oemCodePage = GetOEMCodePage();
    ASSERT_TRUE(IsCodePageValid(oemCodePage));
}
