///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.3 (2021/05/23 23:09)

#include "ProgrammingApplicationsForMicrosoftWindowsCodeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookOperatingSystem/ProgrammingApplicationsForMicrosoftWindows/Code/CodeMain.h"
#include "Example/BookOperatingSystem/ProgrammingApplicationsForMicrosoftWindows/Helper/ProgrammingApplicationsForMicrosoftWindowsClassInvariantMacro.h"

namespace BookWindowsAPI
{
    using TestingType = ProgrammingApplicationsForMicrosoftWindows::CodeMain;
}

BookWindowsAPI::ProgrammingApplicationsForMicrosoftWindowsCodeTesting::ProgrammingApplicationsForMicrosoftWindowsCodeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookWindowsAPI, ProgrammingApplicationsForMicrosoftWindowsCodeTesting)

void BookWindowsAPI::ProgrammingApplicationsForMicrosoftWindowsCodeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookWindowsAPI::ProgrammingApplicationsForMicrosoftWindowsCodeTesting::MainTest()
{
    TestingType codeMain{};

    ASSERT_TRUE(codeMain.Main());
    ASSERT_TRUE(codeMain.ExecuteChapter1());
}
