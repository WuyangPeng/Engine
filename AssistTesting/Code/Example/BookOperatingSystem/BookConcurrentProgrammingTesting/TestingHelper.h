///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.5 (2021/11/02 22:55)

#ifndef BOOK_CONCURRENT_PROGRAMMING_TESTING_HELPER_H
#define BOOK_CONCURRENT_PROGRAMMING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace BookConcurrentProgramming
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

        void AddConcurrentProgrammingOnWindowsSuite();

        void AddParallelAndDistributedProgrammingUsingCppSuite();

        void AddCppConcurrencyInActionSuite();

        void AddCppMultithreadingCookbookSuite();

        void AddMultithreadingApplicationsInWin32Suite();

        void AddProfessionalMulticoreProgrammingSuite();

        void AddObjectOrientedMultithreadingUsingCppSuite();

        void AddDistributedSystemsSuite();
    };
}

#endif  // BOOK_CONCURRENT_PROGRAMMING_TESTING_HELPER_H