///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/13 10:39)

#ifndef ASSIST_TOOLS_TESTING_HTESTING_HELPER_H
#define ASSIST_TOOLS_TESTING_HTESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace AssistTools
{
    class TestingHelper : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();

        void AddHelperSuite();
        void AddGenerateProjectsSuite();
        void AddFeaturesImporterSuite();
        void AddBmpColorToGraySuite();
        void AddBmpToWmtfSuite();
        void AddWmfxCompilerSuite();
    };
}

#endif  // ASSIST_TOOLS_TESTING_HTESTING_HELPER_H