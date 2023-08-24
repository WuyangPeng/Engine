///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/11 18:22)

#ifndef FRAMEWORK_TESTING_TESTING_HELPER_H
#define FRAMEWORK_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace Framework
{
    class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
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
        void AddMainFunctionHelperSuite();
        void AddWindowCreateSuite();
        void AddWindowProcessSuite();
        void AddWindowRegisterSuite();
        void AddApplicationSuite();
        void AddMiddleLayerSuite();
        void AddWindowsAPIFrameSuite();
        void AddOpenGLGlutFrameSuite();
        void AddAndroidFrameSuite();
        void AddLinuxFrameSuite();
        void AddMacintoshFrameSuite();
        void AddConsoleFrameSuite();
        void AddProjectSuite();
    };
}

#endif  // FRAMEWORK_TESTING_TESTING_HELPER_H
