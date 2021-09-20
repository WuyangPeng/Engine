///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.3 (2021/05/23 23:08)

#ifndef BOOK_WINDOWS_API_PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_CODE_TESTING_H
#define BOOK_WINDOWS_API_PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_CODE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookWindowsAPI
{
    class ProgrammingApplicationsForMicrosoftWindowsCodeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ProgrammingApplicationsForMicrosoftWindowsCodeTesting;
        using ParentType = UnitTest;

    public:
        explicit ProgrammingApplicationsForMicrosoftWindowsCodeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();
    };
}

#endif  // BOOK_WINDOWS_API_PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_CODE_TESTING_H
