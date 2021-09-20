///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.4 (2021/06/12 12:53)

#ifndef BOOK_ACE_TESTING_HELPER_H
#define BOOK_ACE_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace BookACE
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

        void AddCppNetworkProgrammingSuite();

        Suite GetCppNetworkProgrammingMasteringComplexityWithACEAndPatternsSuite();

        Suite GetCppNetworkProgrammingSystematicReuseWithACEAndFrameworkSuite();

        void AddTheACEProgrammersGuideSuite();
    };
}

#endif  // BOOK_ACE_TESTING_HELPER_H