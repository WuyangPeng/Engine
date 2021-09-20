///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.3 (2021/05/23 22:54)

#ifndef BOOK_WINDOWS_API_TESTING_HELPER_H
#define BOOK_WINDOWS_API_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace BookWindowsAPI
{
    class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;
        using Suite = CoreTools::Suite;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();

        void AddProgrammingWindowsSuite();

        Suite GetProgrammingWindowsFifthEditionSuite();
        Suite GetProgrammingWindowsSixthEditionSuite();

        void AddProgrammingApplicationsForMicrosoftWindowsSuite();
        void AddWindowsSystemProgrammingSuite();

        void AddMicrosoftWindowsInternalsSuite();

        Suite GetMicrosoftWindowsInternalFourthEditionSuite();
        Suite GetMicrosoftWindowsInternalSixthEditionSuite();

        void AddIvorHortonsBeginningVisualCppSuite();

        Suite GetIvorHortonsBeginningVisualCppFifthEditionSuite();
        Suite GetIvorHortonsBeginningVisualCppSeventhEditionSuite();

        void AddTheOldNewThingSuite();
    };
}

#endif  // BOOK_WINDOWS_API_TESTING_HELPER_H