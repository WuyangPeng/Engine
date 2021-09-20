///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.3 (2021/05/23 23:05)

#include "ProgrammingWindowsSixthEditionCodeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookOperatingSystem/ProgrammingWindowsSixthEdition/Code/CodeMain.h"
#include "Example/BookOperatingSystem/ProgrammingWindowsSixthEdition/Helper/ProgrammingWindowsSixthEditionClassInvariantMacro.h"

namespace BookWindowsAPI
{
    using TestingType = ProgrammingWindowsSixthEdition::CodeMain;
}

BookWindowsAPI::ProgrammingWindowsSixthEditionCodeTesting::ProgrammingWindowsSixthEditionCodeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    PROGRAMMING_WINDOWS_SIXTH_EDITION_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookWindowsAPI, ProgrammingWindowsSixthEditionCodeTesting)

void BookWindowsAPI::ProgrammingWindowsSixthEditionCodeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookWindowsAPI::ProgrammingWindowsSixthEditionCodeTesting::MainTest()
{
    TestingType codeMain{};

    ASSERT_TRUE(codeMain.Main());
    ASSERT_TRUE(codeMain.ExecuteChapter1());
}
