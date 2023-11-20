///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��1.0.0.0 (2023/11/08 09:10)

#ifndef ASSIST_TOOLS_TESTING_TESTING_HELPER_H
#define ASSIST_TOOLS_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace AssistTools
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

        void AddHelperSuite();
        void AddGenerateProjectsSuite();

        NODISCARD Suite GetProjectGenerationSuite();
    };
}

#endif  // ASSIST_TOOLS_TESTING_TESTING_HELPER_H