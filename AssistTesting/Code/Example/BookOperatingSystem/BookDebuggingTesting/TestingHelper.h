///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.4 (2021/10/10 19:51)

#ifndef BOOK_DEBUGGING_TESTING_HELPER_H
#define BOOK_DEBUGGING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace BookDebugging
{
    class TestingHelper : public CoreTools::CMainFunctionTestingHelper
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

        void AddSafeCppSuite();

        void AddDebuggingCppSuite();

        void AddAdvancedWindowsDebuggingSuite();

        void AddTheDevelopersGuideToDebuggingSuite();
    };
}

#endif  // BOOK_DEBUGGING_TESTING_HELPER_H