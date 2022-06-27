///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/22 15:34)

#ifndef ASSIST_TOOLS_TESTING_HTESTING_HELPER_H
#define ASSIST_TOOLS_TESTING_HTESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

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

        void AddMacroSuite();
        void AddGenerateProjectsSuite();
        void AddFeaturesImporterSuite();
        void AddBmpColorToGraySuite();
        void AddBmpToWmtfSuite();
        void AddWmfxCompilerSuite();
    };
}

#endif  // ASSIST_TOOLS_TESTING_HTESTING_HELPER_H