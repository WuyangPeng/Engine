///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/06 21:39)

#ifndef BOOK_STANDARD_LIBRARY_TESTING_HELPER_H
#define BOOK_STANDARD_LIBRARY_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace BookStandardLibrary
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

        void AddTheCppStandardLibrarySuite();

        void AddCppSTLSuite();

        void AddGenericProgrammingAndTheSTLSuite();

        void AddExtendedSTLSuite();

        void AddStandardCppIOStreamsAndLocalesSuite();

        void AddUsingTheCppStandardTemplateLibrariesSuite();

        void AddSTLTutorialAndReferenceGuideSuite();
    };
}

#endif  // BOOK_STANDARD_LIBRARY_TESTING_HELPER_H