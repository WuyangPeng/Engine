///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/09 22:19)

#ifndef BOOK_ADVANCED_TESTING_HELPER_H
#define BOOK_ADVANCED_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace BookAdvanced
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

        void AddCleanCppSustainableSoftwareDevelopmentSuite();

        void AddTheDesignAndEvolutionOfCppSuite();

        void AddCrossPlatformDevelopmentInCppSuite();

        void AddAPIDesignForCppSuite();

        void AddDiscoveringModernCppSuite();

        void AddModernCppDesignSuite();

        void AddTheArtOfCppSuite();

        void AddInsideTheCppObjectModelSuite();

        void AddLargeScaleCppSoftwareDesignSuite();

        void AddSecureCodingInCAndCppSuite();

        void AddDesigningAndCodingReusableCppSuite();

        void AddMultiParadigmDesignForCppSuite();

        void AddCppGUIProgrammingWithQt4Suite();

        void AddAdvancedQtProgrammingSuite();
    };
}

#endif  // BOOK_ADVANCED_TESTING_HELPER_H