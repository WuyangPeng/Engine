///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.3 (2021/05/23 23:05)

#include "ProgrammingWindowsFifthEditionCodeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookOperatingSystem/ProgrammingWindowsFifthEdition/Code/CodeMain.h"
#include "Example/BookOperatingSystem/ProgrammingWindowsFifthEdition/Helper/ProgrammingWindowsFifthEditionClassInvariantMacro.h"

namespace BookWindowsAPI
{
    using TestingType = ProgrammingWindowsFifthEdition::CodeMain;
}

BookWindowsAPI::ProgrammingWindowsFifthEditionCodeTesting::ProgrammingWindowsFifthEditionCodeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    PROGRAMMING_WINDOWS_FIFTH_EDITION_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookWindowsAPI, ProgrammingWindowsFifthEditionCodeTesting)

void BookWindowsAPI::ProgrammingWindowsFifthEditionCodeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookWindowsAPI::ProgrammingWindowsFifthEditionCodeTesting::MainTest()
{
    TestingType codeMain{};

    ASSERT_TRUE(codeMain.Main());
    ASSERT_TRUE(codeMain.ExecuteChapter1());
}
