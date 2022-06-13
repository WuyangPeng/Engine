///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:09)

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
